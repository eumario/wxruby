// wxControl.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxControl_h_)
#define _wxControl_h_
class wxControl : public wxWindow
{
public:
  void Command(wxCommandEvent&  event ) ;
  wxString GetLabel();
  void SetLabel(const wxString&  label ) ;
  // the following were missing from the xml
  virtual ~wxControl();
};


#endif
