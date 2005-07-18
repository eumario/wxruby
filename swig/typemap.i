#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project


##############################################################
%typemap(in) wxString& {
	$1 = new wxString((wxChar *)STR2CSTR($input));
}

%typemap(in) const wxString& {
	$1 = new wxString((wxChar *)STR2CSTR($input));
}

%typemap(in) wxString* {
	$1 = new wxString((wxChar *)STR2CSTR($input));
}
/**
%typemap(freearg) wxString & {
	delete $1;
}

%typemap(freearg) const wxString& {
	delete $1;
}

%typemap(freearg) wxString* {
	delete $1;
}
*/
%typemap(directorin) wxString, const wxString &, wxString & "$input = rb_str_new2((const char *)$1.c_str());";

%typemap(directorin) wxString *, const wxString * "TODO: $1_name->c_str()";
                                                                                                   
%typemap(out) wxString {
	$result = rb_str_new2((const char *)$1.c_str());
}

%typemap(out) wxString& {
	$result = rb_str_new2((const char *)$1.c_str());
}

%typemap(out) const wxString& {
	$result = rb_str_new2((const char *)$1.c_str());
}

%apply wxString& { wxString* }
                                                                               
%typemap(varout) wxString {
	$result = rb_str_new2((const char *)$1.c_str());
}

%typemap(typecheck) wxString {
	$1 = (TYPE($input) == T_STRING);
}

%typemap(typecheck) wxString & {
	$1 = (TYPE($input) == T_STRING);
}


%typemap(typecheck) wxString const & {
	$1 = (TYPE($input) == T_STRING);
}


%typemap(typecheck) wxString *{
	$1 = (TYPE($input) == T_STRING);
}

##############################################################

%typemap(in) void* {
	$1 = (void*)($input);
}

%typemap(out) void* {
    $result = (VALUE)($1);
}

##############################################################

%typemap(in) wxItemKind {
	$1 = (wxItemKind)NUM2INT($input);
}

%typemap(out) wxItemKind {
    $result = INT2NUM((int)$1);
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
        arr[i] = (wxChar *)STR2CSTR(rb_ary_entry($input,i));
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

##############################################################

%typemap(in) wxArrayString & (wxArrayString tmp){
 
  if (($input = Qnil) || (TYPE($input) != T_ARRAY))
  {
    $1 = &tmp;
  }
  else
  {
    
    for (int i = 0; i < RARRAY($input)->len; i++)
    {
        wxString item = (wxChar *)STR2CSTR(rb_ary_entry($input,i));
        tmp.Add(item);
    }
    
    $1 = &tmp;
  }

}

%apply wxArrayString & { const wxArrayString &};

%typemap(out) wxArrayString & {

  $result = rb_ary_new();

  for (int i = 0; i < $1->GetCount(); i++)
  {
    rb_ary_push($result,rb_str_new2((const char *)(*$1)[i].c_str()));
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
