// wxFindDialogEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFindDialogEvent_h_)
#define _wxFindDialogEvent_h_
class wxFindDialogEvent : public wxCommandEvent
{
public:
   wxFindDialogEvent(wxEventType  commandType = wxEVT_NULL, int  id = 0) ;
  int GetFlags() const;
  wxString GetFindString() const;
  wxString GetReplaceString() const;
  wxFindReplaceDialog* GetDialog() const;
};


#endif
