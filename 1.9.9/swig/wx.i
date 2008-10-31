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

%}

// Some common functions
%{
// Mapping of known wxRuby classes to SWIG type information
WX_DECLARE_HASH_MAP(VALUE, 
					swig_type_info*, 
					wxIntegerHash,
					wxIntegerEqual,
					RbClassToSwigTypeHash);
RbClassToSwigTypeHash Global_Type_Map;

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

// Overriding standard SWIG tracking - SWIG's implementation is not
// compatible with ruby 1.8.7 / 1.9.x as it can allocate BigNum objects
// during GC , which is an error. So instead we provide a C++ ptr->Ruby
// object map using Wx's hashmap class.
WX_DECLARE_VOIDPTR_HASH_MAP(VALUE,
                            PtrToRbObjHash);
PtrToRbObjHash Global_Ptr_Map;

// Add a tracking from ptr -> object
void wxRuby_AddTracking(void* ptr, VALUE object) {
  Global_Ptr_Map[ptr] = object;
}

// Return the ruby object for ptr
VALUE wxRuby_FindTracking(void* ptr) {
  if ( Global_Ptr_Map.count(ptr) == 0 )
    return Qnil;
  else
    return Global_Ptr_Map[ptr];
}

// Remove the tracking for ptr
void wxRuby_RemoveTracking(void* ptr) {
  Global_Ptr_Map.erase(ptr);
}

// Iterate over all the trackings, calling the passed-in method on each
void wxRuby_IterateTracking( void(*meth)(void* ptr, VALUE obj) ) {
  PtrToRbObjHash::iterator it;
  for( it = Global_Ptr_Map.begin(); it != Global_Ptr_Map.end(); ++it )
    {
      void* ptr = it->first;
      VALUE obj = it->second;
      (*meth)(ptr, obj);
    }
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


// The passage of wxEvents from the C++ to the ruby side has to be
// controlled carefully because normal Wx events are created on the
// stack, and hence the underlying object is often deleted while the
// ruby object is still around. This (plus typemap in typemap.i) gets
// round this by tracking Event objects created on the ruby side with eg
// CommandEvent.new, but never tracking, marking or freeing those
// generated on the C++ side.
extern swig_class cWxEvtHandler; 
extern swig_class cWxEvent;
// Cached reference to EvtHandler evt_type_id -> ruby_event_class map
VALUE Evt_Type_Map = NULL;

VALUE wxRuby_WrapWxEventInRuby(wxEvent *wx_event)
{
  // Test for tracked instances
  VALUE rb_event = SWIG_RubyInstanceFor((void *)wx_event);
  // An event created on the ruby side and hence tracked; return
  // relevant instance.
  if ( rb_event != Qnil )
    return rb_event;

  // An event from the C++ side; wrap simply without associating
  // mark/free functions as these are all dealt with by Wx.
  // First, get the hash mapping of event types to classes from EvtHandler
  if ( ! Evt_Type_Map )
    {
      VALUE map_name = rb_str_new2("EVENT_TYPE_CLASS_MAP");
      Evt_Type_Map = rb_const_get(cWxEvtHandler.klass, 
                                  rb_to_id(map_name) );
    }
  // Then, look up the event type in this hash (MUCH faster than calling
  // EvtHandler.evt_class_for_type method)
  VALUE event_type_id =  INT2NUM( wx_event->GetEventType() );
  VALUE cEvent = rb_hash_aref(Evt_Type_Map, event_type_id);

  // Check we have a valid class; warn and map to default Wx::Event if not
  if ( NIL_P(cEvent) )
    {
      cEvent = cWxEvent.klass;
      rb_warning("Unmapped event type %i", wx_event->GetEventType());
    }
  
  // Wrap without mark or free functions - Wx deals with this
  rb_event = Data_Wrap_Struct(cEvent, 0, 0, 0);
  DATA_PTR(rb_event) = wx_event;
  return rb_event;
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
