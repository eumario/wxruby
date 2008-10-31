// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxControl_h_)
#define _wxControl_h_
class wxControl : public wxWindow
{
public:
  wxControl();
  wxControl(wxWindow *parent, wxWindowID id,
      const wxPoint& pos = wxDefaultPosition,
      const wxSize& size = wxDefaultSize, long style = 0,
      const wxValidator& validator = wxDefaultValidator,
      const wxString& name = wxT("control"));

  virtual ~wxControl();
  bool Create(wxWindow *parent, wxWindowID id,
      const wxPoint& pos = wxDefaultPosition,
      const wxSize& size = wxDefaultSize, long style = 0,
      const wxValidator& validator = wxDefaultValidator,
      const wxString& name = wxT("control"));

  void Command(wxCommandEvent&  event ) ;
  int GetAlignment() const;

  virtual bool ShouldInheritColours() const;

  virtual wxString GetLabel() const;
  wxString GetLabelText() const;
  static wxString GetLabelText(wxString& label) const;
  virtual void SetLabel(const wxString&  label ) ;
  virtual bool SetFont(const wxFont& font);
};


#endif
