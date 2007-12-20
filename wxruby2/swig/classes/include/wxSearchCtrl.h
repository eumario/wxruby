// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxSearchCtrl_h_)
#define _wxSearchCtrl_h_
class wxSearchCtrl : public wxTextCtrl
{
public:
  wxSearchCtrl();
  wxSearchCtrl(wxWindow *parent, wxWindowID id,
               const wxString& value = wxEmptyString,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = 0,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxSearchCtrlNameStr);

  virtual ~wxSearchCtrl();

  bool Create(wxWindow *parent, wxWindowID id,
              const wxString& value = wxEmptyString,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize,
              long style = 0,
              const wxValidator& validator = wxDefaultValidator,
              const wxString& name = wxSearchCtrlNameStr);

    // search control
   void SetMenu(wxMenu *menu);
   wxMenu *GetMenu();

   // get/set options
   void ShowSearchButton(bool show);
   bool IsSearchButtonVisible() const;

   void ShowCancelButton(bool show);
   bool IsCancelButtonVisible() const;

};


#endif
