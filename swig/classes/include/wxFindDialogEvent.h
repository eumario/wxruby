// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

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
