// Copyright 2006 by Kevin Smith
// released under the MIT-style wxruby2 license

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

  wxString GetLabelText() const;
  virtual bool ShouldInheritColours() const;

  virtual wxString GetLabel() const;
  virtual void SetLabel(const wxString&  label ) ;
  virtual bool SetFont(const wxFont& font);
};


#endif
