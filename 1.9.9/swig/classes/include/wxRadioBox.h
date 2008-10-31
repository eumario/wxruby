// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxRadioBox_h_)
#define _wxRadioBox_h_
class wxRadioBox : public wxControl
{
public:
  wxRadioBox() ;
  wxRadioBox(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  point = wxDefaultPosition, const wxSize&  size = wxDefaultSize, int n = 0, const wxString choices[] = NULL, int majorDimension = 0, long style = wxRA_SPECIFY_COLS, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("radioBox")) ;
  virtual  ~wxRadioBox() ;

  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  point = wxDefaultPosition, const wxSize&  size = wxDefaultSize, int n = 0, const wxString choices[] = NULL, int majorDimension = 0, long style = wxRA_SPECIFY_COLS, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("radioBox")) ;
  virtual bool Enable(bool enable = true) ;
  virtual bool Enable(int  n , bool enable = true) ;
  int FindString(const wxString&  string ) const;
  virtual unsigned int GetCount() const;
  virtual wxString GetLabel() const;
  virtual int GetSelection() const;
  wxString GetStringSelection() const;

  // deprecated
  //int Number() const;
  //wxString GetLabel(int  n ) const;
  //void SetLabel(int  n , const wxString&  label ) ;
  
  virtual void SetLabel(const wxString&  label ) ;
  virtual void SetSelection(int  n ) ;
  virtual bool SetStringSelection(const wxString&  string ) ;
  virtual bool Show(bool show = true);
  virtual bool Show(int item, bool show = true);
  virtual wxString GetString(int  n ) const;
};


#endif
