//   Copyright 2004-2005 by Kevin Smith
//   released under the MIT-style wxruby2 license

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
