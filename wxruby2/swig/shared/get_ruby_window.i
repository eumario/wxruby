// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

// Returns a ruby wrapper around a wxObject whose wx class is not known
// in advance - needed for find_window, get_children etc This is a bit
// complicated because it must check if the ruby object already exists,
// and if not, wrap it in the correct class, and ensure that future
// calls return the same object. Fortunately, most of this is handled by
// the SWIG API - the main additional complexity is using Wx's RTTI
// system to discover the C++ class, then find a ruby class, and the
// SWIG type info struct with the appropriate mark & free funcs to wrap
// it in.
// 
// This is useful for methoda which return arbitrary windows - for
// example, Window::FindWindowById or the FindWindowByPoint global
// function

%{
static VALUE get_ruby_window_wrapper(wxObject *wx_obj)
{
  // If no object was passed to be wrapped; this could be a normal state
  // (eg if get_sizer was called on a Window with no sizer set), or
  // could be an error, eg if calling get_window_by_id and no window
  // matched the id, or an error arose from incorrect XML syntax
  if ( ! wx_obj ) 
    return Qnil;

  // Get the wx class and the ruby class we are converting into  
  wxString class_name( wx_obj->GetClassInfo()->GetClassName() );
  VALUE r_class_name = rb_intern(class_name.mb_str() + 2);
  VALUE r_class;

  // If the class is loadable from XML, but not yet supported in wxRuby,
  // raise an error because class-specific methods won't be accessible
  if ( class_name.Len() > 2 && rb_const_defined(mWxruby2, r_class_name) )
	r_class = rb_const_get(mWxruby2, r_class_name);
  else 
    rb_raise(rb_eNotImpError, 
             "Error wrapping object; class `%s' is not supported in wxRuby",
             (const char *)class_name.mb_str() );

  // Otherwise, retrieve the swig type info for this class and wrap it
  // in Ruby. wxRuby_GetSwigTypeForClass is defined in wx.i
  swig_type_info* swig_type = wxRuby_GetSwigTypeForClass(r_class);
  VALUE r_obj = SWIG_NewPointerObj(wx_obj, swig_type, 1);
  return r_obj;
}
%}
