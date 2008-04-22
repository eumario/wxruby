// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%module(directors="1") wxruby2

%include "common.i"

%{

#include <wx/gdicmn.h>
#include <wx/image.h>
#include <wx/xrc/xmlres.h>

#include <wx/filesys.h>
#include <wx/fs_zip.h>


// Mapping of known wxRuby classes to SWIG type information
WX_DECLARE_HASH_MAP(VALUE, 
					swig_type_info*, 
					wxIntegerHash,
					wxIntegerEqual,
					SwigTypeHash);

SwigTypeHash Global_Type_Map;

// Record swig_type_info for a wxRuby class; called in class
// initialisation
void wxRuby_SetSwigTypeForClass(VALUE cls, swig_type_info* ty) {
  Global_Type_Map[cls] = ty;
}

// Retrieve swig_type_info for a ruby class - needed by functions which
// wrap objects whose type is not known in advance - eg
// Window#find_window_by_index (see Window.i)
swig_type_info* wxRuby_GetSwigTypeForClass(VALUE cls) {
  return Global_Type_Map[cls];
}

// Returns a ruby object wrapped around a wxObject. This is used for
// methods whose return type is a generic C++ class (eg wxWindow), but
// whose return values are actually instances of specific C++ classes
// (eg wxButton) and so must be wrapped in the right Ruby class
// (Wx::Button). It must check if the ruby wrapper object already
// exists, and if not, wrap it in the correct class, and ensure that
// future calls return the same object. Most of this is handled by the
// SWIG API - the main additional complexity is using Wx's RTTI system
// to discover the specific C++ class, then find a ruby class, and the
// SWIG type info struct with the appropriate mark & free funcs to wrap
// it in.
// 
// This is useful for methods which return arbitrary windows - for
// example, Window::FindWindowById or the FindWindowByPoint global
// function; and in circumstances, especially XRC-loading, where
// complete Windows are created in C++ without ruby code.
VALUE wxRuby_WrapWxObjectInRuby(wxObject *wx_obj)
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

%include "mark_free_impl.i"

%init %{
    // Load all the other known wxRuby modules; the function is built by rake
    extern void InitializeOtherModules();
    InitializeOtherModules();

    // Set up all image formats
    wxInitAllImageHandlers();

    // Load handlers on the global resources object
    wxXmlResource::Get()->InitAllHandlers();

	// This is needed so HtmlHelp can load docs from a zip file
	wxFileSystem::AddHandler(new wxArchiveFSHandler);
%}

#define VERSION_STRING "wxRuby2"
