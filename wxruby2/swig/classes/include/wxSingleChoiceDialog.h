// wxSingleChoiceDialog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSingleChoiceDialog_h_)
#define _wxSingleChoiceDialog_h_
class wxSingleChoiceDialog : public wxDialog
{
public:
  wxSingleChoiceDialog(wxWindow*  parent , const wxString&  message , const wxString&  caption , int  n , const wxString  choices[] , char** clientData = NULL, long  style = wxOK, const wxPoint&  pos = wxDefaultPosition);
  virtual  ~wxSingleChoiceDialog() ;
  int GetSelection() const;
  char* GetSelectionClientData() const;
  wxString GetStringSelection() const;
  void SetSelection(int  selection ) ;
  int ShowModal() ;
};


#endif
