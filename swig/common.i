#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project

%feature("director");

%{
#  undef GetClassName
#  undef GetClassInfo
#  undef Yield
#  undef GetMessage
#  undef FindWindow
#  undef GetCharWidth
#  undef DrawText
#  undef StartDoc
#  undef CreateDialog
#  undef Sleep
#  undef _
#  undef Connect
#  undef connect

#include <wx/wx.h>
%}

%include "typedefs.i"
%include "typemap.i"

%{
class wxRbCallback : public wxObject 
{
    DECLARE_ABSTRACT_CLASS(wxRbCallback);
public:
    wxRbCallback(VALUE func) { m_func = func; }
    wxRbCallback(const wxRbCallback &other) { m_func = other.m_func; }
 
    void GenericEventThunker(wxEvent &event)
    {
        extern swig_class cWxEvent;
        EventThunker(event, cWxEvent.klass);
    }
    
    void CalendarEventThunker(wxEvent &event)
    {
        extern swig_class cWxCalendarEvent;
        EventThunker(event, cWxCalendarEvent.klass);
    }
    
    void CloseEventThunker(wxEvent &event)
    {
        extern swig_class cWxCloseEvent;
        EventThunker(event, cWxCloseEvent.klass);
    }
    
    void CommandEventThunker(wxEvent &event)
    {
        extern swig_class cWxCommandEvent;
        EventThunker(event, cWxCommandEvent.klass);
    }
    
    void PaintEventThunker(wxEvent &event)
    {
        extern swig_class cWxPaintEvent;
        EventThunker(event, cWxPaintEvent.klass);
    }
    
    void UpdateUIEventThunker(wxEvent &event)
    {
        extern swig_class cWxUpdateUIEvent;
        EventThunker(event, cWxUpdateUIEvent.klass);
    }
    
    void EventThunker(wxEvent &event, VALUE cEvent)
    {
        static VALUE vevent;
        vevent = Data_Wrap_Struct(cEvent, 0, 0, 0);
        DATA_PTR(vevent) = &event;
        
        wxRbCallback *cb = (wxRbCallback *)event.m_callbackUserData;
        rb_funcall(cb->m_func, rb_intern("call"),1,vevent);
    }
                                                                                
    VALUE       m_func;
};
%}
