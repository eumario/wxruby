// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxStaticText_h_)
#define _wxStaticText_h_
class wxStaticText : public wxControl
{
public:
   wxStaticText() ;
   wxStaticText(wxWindow* parent, 
                wxWindowID  id, 
                const wxString& label, 
                const wxPoint& pos = wxDefaultPosition, 
                const wxSize& size = wxDefaultSize, 
                long style = 0, 
                const wxString&  name = wxT("staticText") );
  virtual ~wxStaticText();

  bool Create(wxWindow*  parent, 
              wxWindowID  id, 
              const wxString& label, 
              const wxPoint& pos = wxDefaultPosition, 
              const wxSize& size = wxDefaultSize, 
              long style = 0, 
              const wxString& name = wxT("staticText") );
  wxString GetLabel() const;
  virtual void SetLabel(const wxString&   label ) ;
  void Wrap(int width);
};


#endif
