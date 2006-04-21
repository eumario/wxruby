#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license


##############################################################
%typemap(in) wxString& {
	// $argnum: $1_type $1_name ($1_mangle) [$1_ltype]
	$1 = new wxString(STR2CSTR($input), wxConvUTF8);
}

%typemap(in) const wxString& {
	$1 = new wxString(STR2CSTR($input), wxConvUTF8);
}

%typemap(in) wxString* {
	$1 = new wxString(STR2CSTR($input), wxConvUTF8);
}

%typemap(directorout) wxString, wxString& "$result = wxString(STR2CSTR($input), wxConvUTF8);";


/*
Currently incompatible with the ruby post-processing of swigged .cpp files
Needs to be fixed in fixdeleting.rb before this can be uncommented out
%typemap(freearg) wxString & {
	delete $1;
}

%typemap(freearg) const wxString& {
	delete $1;
}

 Removed temporarily 2006-04-16 kbs
%typemap(freearg) wxString* {
	delete $1;
}
*/

%typemap(directorin) wxString, const wxString &, wxString & "$input = rb_str_new2((const char *)$1.mb_str());";

%typemap(directorin) wxString *, const wxString * "TODO: $1_name->mb_str()";
                                                                                                   
%typemap(out) wxString {
	$result = rb_str_new2((const char *)$1.mb_str(wxConvUTF8));
}

%typemap(out) wxString& {
	$result = rb_str_new2((const char *)$1.mb_str(wxConvUTF8));
}

%typemap(out) const wxString& {
	$result = rb_str_new2((const char *)$1.mb_str(wxConvUTF8));
}

%apply wxString& { wxString* }
                                                                               
%typemap(varout) wxString {
	$result = rb_str_new2((const char *)$1.mb_str(wxConvUTF8));
}

%typemap(typecheck, precedence=SWIG_TYPECHECK_STRING) wxString {
	$1 = (TYPE($input) == T_STRING);
}

%typemap(typecheck, precedence=SWIG_TYPECHECK_STRING) wxString & {
	$1 = (TYPE($input) == T_STRING);
}


%typemap(typecheck, precedence=SWIG_TYPECHECK_STRING) wxString const & {
	$1 = (TYPE($input) == T_STRING);
}

%typemap(typecheck, precedence=SWIG_TYPECHECK_STRING) wxString *{
	$1 = (TYPE($input) == T_STRING);
}

%typemap(out) void * {
  $result = INT2NUM((int)$1);
}


##############################################################

%typemap(in) void* {
	$1 = (void*)($input);
}

%typemap(out) void* {
    $result = (VALUE)($1);
}

##############################################################

##############################################################
%typemap(in) wxItemKind {
	$1 = (wxItemKind)NUM2INT($input);
}

%typemap(out) wxItemKind {
    $result = INT2NUM((int)$1);
}

# fixes mixup between 
# wxMenuItem* wxMenu::Append(int itemid, const wxString& text, const wxString& help = wxEmptyString, wxItemKind kind = wxITEM_NORMAL)
# and
# void wxMenu::Append(int itemid, const wxString& text, const wxString& help, bool isCheckable);
%typemap(typecheck, precedence=SWIG_TYPECHECK_INTEGER) wxItemKind {
	$1 = (TYPE($input) == T_FIXNUM && TYPE($input) != T_TRUE && TYPE($input) != T_FALSE);
}

##############################################################

%typemap(in) wxCalendarDateBorder {
	$1 = (wxCalendarDateBorder)NUM2INT($input);
}

%typemap(out) wxCalendarDateBorder {
    $result = INT2NUM((int)$1);
}

##############################################################

%{
#include <wx/datetime.h>
%}

%typemap(in) const wxDateTime& {
    int y = NUM2INT(rb_funcall($input, rb_intern("year"), 0));
    int rMonth = NUM2INT(rb_funcall($input, rb_intern("month"), 0));
    int rDay = NUM2INT(rb_funcall($input, rb_intern("mday"), 0));
    int rHour = NUM2INT(rb_funcall($input, rb_intern("hour"), 0));
    int rMinute = NUM2INT(rb_funcall($input, rb_intern("min"), 0));
    int rSecond = NUM2INT(rb_funcall($input, rb_intern("sec"), 0));
    wxDateTime::Month mon = (wxDateTime::Month)(rMonth-1);
    wxDateTime::wxDateTime_t d = (wxDateTime::wxDateTime_t)rDay;
    wxDateTime::wxDateTime_t h = (wxDateTime::wxDateTime_t)rHour;
    wxDateTime::wxDateTime_t min = (wxDateTime::wxDateTime_t)rMinute;
    wxDateTime::wxDateTime_t s = (wxDateTime::wxDateTime_t)rSecond;
    
	$1 = new wxDateTime(d, mon, y, h, min, s, 0);
}

%typemap(out) wxDateTime& {
    VALUE y = INT2NUM($1->GetYear());
    VALUE mon = INT2NUM($1->GetMonth() + 1);
    VALUE d = INT2NUM($1->GetDay());
    VALUE h = INT2NUM($1->GetHour());
    VALUE min = INT2NUM($1->GetMinute());
    VALUE s = INT2NUM($1->GetSecond());
    
    VALUE cDateTime = rb_iv_get(rb_cObject, "DateTime");
    $result = rb_funcall(cDateTime, rb_intern("new"), 6, y, mon, d, h, min, s);
}

# Need to have this to over-ride the default which does not work
%typemap(typecheck) const wxDateTime& {
	$1 = (TYPE($input) != T_NONE);
}

%apply int { wxDateTime::WeekDay  }

##############################################################


%typemap(in,numinputs=1) (int n, const wxString choices []) (wxString *arr)
{
  if (($input == Qnil) || (TYPE($input) != T_ARRAY))
  {
    $1 = 0;
    $2 = NULL;
  }
  else
  {
    arr = new wxString[RARRAY($input)->len];
    for (int i = 0; i < RARRAY($input)->len; i++)
    {
        arr[i] = wxString(STR2CSTR(rb_ary_entry($input,i)), wxConvUTF8);
    }
    $1 = RARRAY($input)->len;
    $2 = arr;
  }
}

%typemap(default,numinputs=1) (int n, const wxString choices[]) 
{
    $1 = 0;
    $2 = NULL;
}

%typemap(freearg) (int n , const wxString choices[])
{
    if ($2 != NULL) delete [] $2;
}

%typemap(typecheck) (int n , const wxString choices[])
{
   $1 = (TYPE($input) == T_ARRAY);
}

%apply (int n, const wxString choices []) { (int n, const wxString* choices),(int nItems, const wxString *items) }

##############################################################

%typemap(in,numinputs=1) (int n, wxPoint points[]) (wxPoint *arr)
{
  if (($input == Qnil) || (TYPE($input) != T_ARRAY))
  {
    $1 = 0;
    $2 = NULL;
  }
  else
  {
    wxPoint *ptmp;
    arr = new wxPoint[RARRAY($input)->len];
    for (int i = 0; i < RARRAY($input)->len; i++)
    {
	SWIG_ConvertPtr(rb_ary_entry($input,i), (void **) &ptmp, SWIGTYPE_p_wxPoint, 1);
	if (ptmp == NULL)
		rb_raise(rb_eTypeError, "null reference");
        arr[i] = *ptmp;
    }
    $1 = RARRAY($input)->len;
    $2 = arr;
  }
}

%typemap(default,numinputs=1) (int n, wxPoint points[]) 
{
    $1 = 0;
    $2 = NULL;
}

%typemap(freearg) (int n , wxPoint points [])
{
    if ($2 != NULL) delete [] $2;
}

%typemap(typecheck) (int n , wxPoint points[])
{
   $1 = (TYPE($input) == T_ARRAY);
}

%apply (int n, wxPoint points []) { (int n, wxPoint* points),(int nItems, wxPoint *points) }

##############################################################

%typemap(in) wxArrayString & (wxArrayString tmp){
 
  if (($input == Qnil) || (TYPE($input) != T_ARRAY))
  {
    $1 = &tmp;
  }
  else
  {
    
    for (int i = 0; i < RARRAY($input)->len; i++)
    {
		wxString item(STR2CSTR(rb_ary_entry($input,i)),wxConvUTF8);
        tmp.Add(item);
    }
    
    $1 = &tmp;
  }

}

%typemap(out) wxArrayString & {

  $result = rb_ary_new();

  for (int i = 0; i < $1->GetCount(); i++)
  {
    rb_ary_push($result,rb_str_new2((const char *)(*$1)[i].mb_str()));
  }
}

%typemap(typecheck, precedence=SWIG_TYPECHECK_STRING_ARRAY) wxArrayString &
{
   $1 = (TYPE($input) == T_ARRAY);
}

%apply wxArrayString & { const wxArrayString &}

##############################################################

%typemap(in) wxArrayInt (wxArrayInt tmp){
 
  if (($input == Qnil) || (TYPE($input) != T_ARRAY))
  {
    $1 = &tmp;
  }
  else
  {
    
    for (int i = 0; i < RARRAY($input).len; i++)
    {
      int item = NUM2INT(rb_ary_entry($input,i));
      tmp.Add(item);
    }
    
    $1 = &tmp;
  }

}

%typemap(out) wxArrayInt {

  $result = rb_ary_new();

  for (int i = 0; i < $1.GetCount(); i++)
  {
    rb_ary_push($result,INT2NUM( $1.Item(i) ) );
  }
}

%typemap(typecheck) wxArrayInt
{
   $1 = (TYPE($input) == T_ARRAY);
}

##############################################################

%typemap(in,numinputs=0) (wxArrayInt& selections) (wxArrayInt tmp) {
  $1 = &tmp;
}

%typemap(out) (wxArrayInt& selections) {

  $result = rb_ary_new();

  for (int i = 0; i < $1.GetCount(); i++)
  {
    rb_ary_push($result,INT2NUM( $1.Item(i) ) );
  }
}

##############################################################

%typemap(in) wxEdge {
	$1 = (wxEdge)NUM2INT($input);
}

%typemap(out) wxEdge {
    $result = INT2NUM((int)$1);
}

%typemap(typecheck) wxEdge {
	$1 = TYPE($input) == T_FIXNUM;
}

%typemap(in) wxRelationship {
	$1 = (wxRelationship)NUM2INT($input);
}

%typemap(out) wxRelationship {
    $result = INT2NUM((int)$1);
}

%typemap(typecheck) wxRelationship {
	$1 = TYPE($input) == T_FIXNUM;
}


##############################################################

%typemap(in,numinputs=0) (wxCoord * w , wxCoord * h , wxCoord * descent, wxCoord * externalLeading) (wxCoord a, wxCoord b, wxCoord c, wxCoord d) {
	$1=&a;
	$2=&b;
	$3=&c;
	$4=&d;
}

%typemap(argout) (wxCoord * w , wxCoord * h , wxCoord * descent, wxCoord * externalLeading) {
	$result = rb_ary_new();
	rb_ary_push($result, INT2NUM(*$1));
	rb_ary_push($result, INT2NUM(*$2));
	rb_ary_push($result, INT2NUM(*$3));
	rb_ary_push($result, INT2NUM(*$4));
}

%typemap(in,numinputs=0) (wxCoord * width , wxCoord * height , wxCoord * heightLine) (wxCoord a, wxCoord b, wxCoord c) {
	$1=&a;
	$2=&b;
	$3=&c;
}

%typemap(argout) (wxCoord * width , wxCoord * height , wxCoord * heightLine) {
	$result = rb_ary_new();
	rb_ary_push($result, INT2NUM(*$1));
	rb_ary_push($result, INT2NUM(*$2));
	rb_ary_push($result, INT2NUM(*$3));
}

%typemap(in,numinputs=0) (int * x , int * y , int * descent, int * externalLeading) (int a, int b, int c, int d) {
	$1=&a;
	$2=&b;
	$3=&c;
	$4=&d;
}

%typemap(argout) (int * x , int * y , int * descent, int * externalLeading) {
	$result = rb_ary_new();
	rb_ary_push($result, INT2NUM(*$1));
	rb_ary_push($result, INT2NUM(*$2));
	rb_ary_push($result, INT2NUM(*$3));
	rb_ary_push($result, INT2NUM(*$4));
}

##############################################################

%typemap(in) wxSystemColour {
	$1 = (wxSystemColour)NUM2INT($input);
}

%typemap(out) wxSystemColour {
    $result = INT2NUM((int)$1);
}

%typemap(in) wxSystemFont {
	$1 = (wxSystemFont)NUM2INT($input);
}

%typemap(out) wxSystemFont {
    $result = INT2NUM((int)$1);
}

%typemap(in) wxSystemMetric {
	$1 = (wxSystemMetric)NUM2INT($input);
}

%typemap(out) wxSystemMetric {
    $result = INT2NUM((int)$1);
}
