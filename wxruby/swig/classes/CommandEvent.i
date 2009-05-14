// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxCommandEvent
GC_MANAGE_AS_EVENT(wxCommandEvent);

%rename(wxCommandEvent) wxRubyCommandEvent;


// Cf wxEvent - has to be written as a C+++ subclass to ensure correct
// GC/thread protection of Ruby instance variables when user-written
// event classes are queued.
//
//
// FIXME : intermittent errors with CommandEvent losing the tracked
// object before handling - though the same code works fine with Wx::Event
%{
class wxRubyCommandEvent : public wxCommandEvent
{
public:
  wxRubyCommandEvent(wxEventType commandType = wxEVT_NULL, 
                     int id = 0) : 
    wxCommandEvent(commandType, id) { }

  // When the C++ side event is destroyed, unlink from the Ruby object
  // and remove that object from the tracking hash so it can be
  // collected by GC.
  virtual ~wxRubyCommandEvent() {
    wxRuby_RemoveTracking( (void*)this );
  }

  // Will be called when add_pending_event is used to queue an event
  // (often when using Threads), because a clone is queued. So copy the
  // Wx C++ event, create a shallow (dup) of the Ruby event object, and
  // add to the tracking hash so that it is GC-protected
  virtual wxEvent* Clone() const {
    wxRubyCommandEvent* wx_ev = new wxRubyCommandEvent(GetEventType(), 
                                                       GetId());

    VALUE r_obj = SWIG_RubyInstanceFor((void *)this);
    VALUE r_obj_dup = rb_obj_clone(r_obj);

    DATA_PTR(r_obj_dup) = wx_ev;
    wxRuby_AddTracking( (void*)wx_ev, r_obj_dup );
    return wx_ev;
  }
  
  wxCommandEvent* __bogus() { return (wxCommandEvent*)this; }
};
%}

// deprecated
%ignore wxCommandEvent::Checked;
// Should use get_client_data
%ignore wxCommandEvent::GetClientObject;
%ignore wxCommandEvent::SetClientObject;
// This doesn't do anything that can't be done using better-named equivalents
%ignore wxCommandEvent::GetExtraLong;

%import "include/wxObject.h"
%import "include/wxEvent.h"

class wxRubyCommandEvent : public wxCommandEvent
{
public:
  wxRubyCommandEvent(WXTYPE commandEventType = 0, 
                     int id = 0);
   
  virtual ~wxRubyCommandEvent();
  virtual wxEvent* Clone() const;

  bool Checked() const;
  void* GetClientData() ;
  long GetExtraLong() const;
  int GetInt() const;
  int GetSelection() const;
  wxString GetString() const;
  bool IsChecked() const;
  bool IsSelection() const;
  void SetClientData(void*  clientData ) ;
  void SetExtraLong(int  extraLong ) ;
  void SetInt(int  intCommand ) ;
  void SetString(const wxString&  string ) ;


  // pointless method to ensure SWIGTYPE_p_wxCommandEvent is
  // created. Wish I knew a better way to fix this.
  wxCommandEvent* __bogus();
};

