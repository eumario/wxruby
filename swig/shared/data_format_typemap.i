
%typemap(in) wxDataFormat & {
  wxDataFormat wx_fmt = wxDataFormat();
  if ( TYPE($input) == T_FIXNUM )
    wx_fmt.SetType( (wxDataFormatId)NUM2INT($input) );
  else if ( TYPE($input) == T_STRING )
    wx_fmt.SetId( wxString(StringValuePtr($input), wxConvUTF8) );
  $1 = &wx_fmt;
 }

%typemap(in) wxDataFormat {
  $1 = wxDataFormat();
  if ( TYPE($input) == T_FIXNUM )
    $1.SetType( (wxDataFormatId)NUM2INT($input) );
  else if ( TYPE(rb_fmt) == T_STRING )
    $1.SetId( wxString(StringValuePtr($input), wxConvUTF8) );
 }

%typemap(out) wxDataFormat {
  if ( $1.GetType() )
      $result = INT2NUM( $1.GetType() );
  else
    $result = rb_str_new2((const char *)$1.GetId().mb_str(wxConvUTF8));
 }

%typemap(directorin) wxDataFormat {
  if ( $1.GetType() )
    $input = INT2NUM( $1.GetType() );
  else
    $input = rb_str_new2((const char *)$1.GetId().mb_str(wxConvUTF8));
 }

%typemap(directorout) wxDataFormat {
  $result = wxDataFormat();
  if ( TYPE($input) == T_FIXNUM )
    $result.SetType( (wxDataFormatId)NUM2INT($input) );
  else if ( TYPE($input) == T_STRING )
    $result.SetId( wxString(StringValuePtr($input), wxConvUTF8) );
 }




