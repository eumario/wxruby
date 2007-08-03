// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxEvtHandler
GC_MANAGE_AS_OBJECT(wxEvtHandler);

%ignore wxEvtHandler::Connect;
%ignore wxEvtHandler::Disconnect;

%import "include/wxObject.h"
%include "include/wxEvtHandler.h"


// The EvtHandler instance event methods (evt_xxx) are not defined
// here. Rather, they are set up in ruby in
// lib/wx/classes/evthandler.rb, using the public 'connect' method below
%extend wxEvtHandler {
  // This provides the public Ruby 'connect' method
  VALUE connect(int firstId, int lastId, wxEventType eventType)
  {
    VALUE func = rb_funcall(rb_cProc, rb_intern("new"), 0);
    rb_global_variable(&callbacks);
    if(callbacks == Qnil)
        callbacks = rb_ary_new();
    rb_ary_push(callbacks, func);

    wxObject* userData = new wxRbCallback(func);
    wxObjectEventFunction function = 
        (wxObjectEventFunction )&wxRbCallback::EventThunker;
    self->Connect(firstId, lastId, eventType, function, userData);
	return Qtrue;
  }
}


%runtime{

extern swig_class cWxEvtHandler;
static VALUE callbacks = Qnil;

// Class which stores the ruby proc associated with an event handler. 
class wxRbCallback : public wxObject 
{

public:
    wxRbCallback(VALUE func) { m_func = func; }
    wxRbCallback(const wxRbCallback &other) { m_func = other.m_func; }

    // This method handles all events on the WxWidgets/C++ side. It link
    // inspects the event and based on the event's type wraps it in the
    // appropriate class (the mapping can be found in
    // lib/wx/classes/evthandler.rb). This wrapped event is then passed
    // into the ruby proc for handling on the ruby side
    void EventThunker(wxEvent &event)
    {
        VALUE event_type_id =  INT2NUM(event.GetEventType());
        VALUE cEvent = rb_funcall(cWxEvtHandler.klass, 
								  rb_intern("event_class_for_type"),
								  1, event_type_id ); 	  
        
        static VALUE vevent;
        vevent = Data_Wrap_Struct(cEvent, 0, 0, 0);
        DATA_PTR(vevent) = &event;
        
        wxRbCallback *cb = (wxRbCallback *)event.m_callbackUserData;
        rb_funcall(cb->m_func, rb_intern("call"),1,vevent);
    }

    VALUE m_func;
};
}
