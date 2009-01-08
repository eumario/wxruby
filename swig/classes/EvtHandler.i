// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxEvtHandler
GC_MANAGE_AS_OBJECT(wxEvtHandler);

%ignore wxEvtHandler::Connect;
%ignore wxEvtHandler::Disconnect;

%import "include/wxObject.h"
%include "include/wxEvtHandler.h"

%runtime{
extern swig_class cWxEvtHandler;

// Internally, all event handlers are anonymous ruby Proc objects,
// created by EvtHandler#connect. These need to be preserved from Ruby's
// GC until the EvtHandler object itself is destroyed. So we keep a hash
// which maps C++ pointer addresses of EvtHandlers to Ruby arrays of
// the Proc objects which handle their events.
WX_DECLARE_VOIDPTR_HASH_MAP(VALUE, PtrToEvtHandlerProcs);
PtrToEvtHandlerProcs Evt_Handler_Handlers;

// Add a proc to the list of protected handler for an EvtHandler object
void wxRuby_ProtectEvtHandlerProc(void* evt_handler, VALUE proc) {
  if ( Evt_Handler_Handlers.count(evt_handler) == 0 )
    Evt_Handler_Handlers[evt_handler] = rb_ary_new();
  VALUE protected_procs = Evt_Handler_Handlers[evt_handler];
  rb_ary_push(protected_procs, proc);
}

// Called by App's mark function; protect all currently needed procs
void wxRuby_MarkProtectedEvtHandlerProcs() {
  PtrToEvtHandlerProcs::iterator it;
  for( it = Evt_Handler_Handlers.begin(); 
       it != Evt_Handler_Handlers.end(); 
       ++it )
    rb_gc_mark( it->second );
}

// Called when a Window is destroyed; allows handler procs associated
// with this object to be garbage collected at next run. See
// swig/mark_free_impl.i
void wxRuby_ReleaseEvtHandlerProcs(void* evt_handler) {
  Evt_Handler_Handlers.erase(evt_handler);
}

// Class which stores the ruby proc associated with an event handler. We
// also cache the "call" symbol as this improves speed for event
// handlers which are called many times (eg evt_motion)
class wxRbCallback : public wxObject 
{

public:
    wxRbCallback(VALUE func) { m_func = func; 
                               m_call_id = rb_intern("call"); }
    wxRbCallback(const wxRbCallback &other) { m_func = other.m_func; 
                                             m_call_id = rb_intern("call"); }

    // This method handles all events on the WxWidgets/C++ side. It link
    // inspects the event and based on the event's type wraps it in the
    // appropriate class (the mapping can be found in
    // lib/wx/classes/evthandler.rb). This wrapped event is then passed
    // into the ruby proc for handling on the ruby side
    void EventThunker(wxEvent &event)
    {
      VALUE rb_event = wxRuby_WrapWxEventInRuby(&event);
      wxRbCallback *cb = (wxRbCallback *)event.m_callbackUserData;
      rb_funcall(cb->m_func, cb->m_call_id, 1, rb_event);
    }

    ID m_call_id;
    VALUE m_func;
};
}


// The EvtHandler instance event methods (evt_xxx) are not defined
// here. Rather, they are set up in ruby in
// lib/wx/classes/evthandler.rb, using the public 'connect' method below
%extend wxEvtHandler {
  // This provides the public Ruby 'connect' method
  VALUE connect(int firstId, int lastId, wxEventType eventType)
  {
    VALUE func = rb_funcall(rb_cProc, rb_intern("new"), 0);
    wxRuby_ProtectEvtHandlerProc((void *)$self, func);

    wxObject* userData = new wxRbCallback(func);
    wxObjectEventFunction function = 
        (wxObjectEventFunction )&wxRbCallback::EventThunker;
    self->Connect(firstId, lastId, eventType, function, userData);
	return Qtrue;
  }

  // Implementation of disconnect, accepting either an EVT_XXX constant
  // or a symbol name of an event handler method
  VALUE disconnect(int firstId, 
				   int lastId = wxID_ANY, 
				   VALUE evtSpecifier = Qnil)
  {
	wxEventType event_type;

	if ( TYPE(evtSpecifier) == T_FIXNUM ) // simply an Integer id
	  event_type = NUM2INT(evtSpecifier);
	else if ( TYPE(evtSpecifier) == T_NIL ) // Not defined = any type
	  event_type = wxEVT_NULL;
	else if ( TYPE(evtSpecifier) == T_SYMBOL ) // Symbol handler method
	  {
		VALUE rb_evt_type = rb_funcall(cWxEvtHandler.klass, 
									   rb_intern("event_type_for_name"),
									   1, evtSpecifier);
		if ( rb_evt_type )
		  event_type = NUM2INT( rb_evt_type );
		else
		  rb_raise(rb_eTypeError, "Unknown event handler %s", 
				   STR2CSTR(rb_inspect(evtSpecifier)));
	  }
	else 
	  rb_raise(rb_eTypeError, "Invalid specifier for event type");


	// TODO - enable switching off all handlers by type only - this
	// version doesn't work if the first arg is wxID_ANY
	if ( self->Disconnect(firstId, lastId, event_type))
	  return Qtrue;
	else
	  return Qfalse;
  }

}

