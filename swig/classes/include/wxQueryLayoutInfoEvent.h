// wxQueryLayoutInfoEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxQueryLayoutInfoEvent_h_)
#define _wxQueryLayoutInfoEvent_h_
class wxQueryLayoutInfoEvent : public wxEvent
{
public:
   wxQueryLayoutInfoEvent(wxWindowID  id = 0) ;
  void GetAlignment() const;
  int GetFlags() const;
  wxLayoutOrientation GetOrientation() const;
  int GetRequestedLength() const;
  wxSize GetSize() const;
  void SetAlignment(wxLayoutAlignment  alignment ) ;
  void SetFlags(int  flags ) ;
  void SetOrientation(wxLayoutOrientation  orientation ) ;
  void SetRequestedLength(int  length ) ;
  void SetSize(const wxSize&  size ) ;
};


#endif
