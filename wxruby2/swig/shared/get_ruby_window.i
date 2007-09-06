// Returns a ruby wrapper around a wxObject whose wx class is not known
// in advance - needed for find_window, get_children etc This is a bit
// complicated because it must check if the ruby object already exists,
// and if not, wrap it in the correct class, and ensure that future
// calls return the same object.
// 
// This is useful for methoda which return arbitrary windows - for
// example, Window::FindWindowById or the FindWindowByPoint global
// function

%{
static VALUE get_ruby_window_wrapper(wxObject *wx_obj)
{
  if ( ! wx_obj ) return Qnil;

  // Get the wx class and the ruby class we are converting into  
  wxString class_name( wx_obj->GetClassInfo()->GetClassName() );
  VALUE r_class;
  if ( class_name.Len() > 2 )
	r_class = rb_iv_get(mWxruby2, class_name.mb_str() + 2);
  else 
	return Qnil;

  // Otherwise, retrieve the swig type info for this class and wrap it
  // in Ruby
  swig_type_info* swig_type = wxRuby_GetSwigTypeForClass(r_class);
  VALUE r_obj = SWIG_NewPointerObj(wx_obj, swig_type, 1);
  return r_obj;
}

%}
