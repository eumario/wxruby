// wxRadioBox.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxRadioBox_h_)
#define _wxRadioBox_h_
class wxRadioBox : public wxControl
{
public:
   wxRadioBox() ;
   wxRadioBox(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  point = wxDefaultPosition, const wxSize&  size = wxDefaultSize, int n = 0, const wxString choices[] = NULL, int majorDimension = 0, long style = wxRA_SPECIFY_COLS, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "radioBox") ;
  virtual  ~wxRadioBox() ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  point = wxDefaultPosition, const wxSize&  size = wxDefaultSize, int n = 0, const wxString choices[] = NULL, int majorDimension = 0, long style = wxRA_SPECIFY_COLS, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "radioBox") ;
  void Enable(bool enable = true) ;
  void Enable(int  n , bool enable = true) ;
  int FindString(const wxString&  string ) const;
  int GetCount() const;
  wxString GetLabel() const;
  wxString GetLabel(int  n ) const;
  int GetSelection() const;
  wxString GetStringSelection() const;
  int Number() const;
  void SetLabel(const wxString&  label ) ;
  void SetLabel(int  n , const wxString&  label ) ;
  void SetSelection(int  n ) ;
  void SetStringSelection(const wxString&  string ) ;
  void Show(const bool  show ) ;
  void Show(int  item , const bool  show ) ;
  wxString GetString(int  n ) const;
};


#endif
