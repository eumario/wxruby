// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxCollapsiblePane_h_)
#define _wxCollapsiblePane_h_

class wxCollapsiblePane : public wxControl
{
 public:
  wxCollapsiblePane();
  wxCollapsiblePane(wxWindow *parent,
                    wxWindowID winid,
                    const wxString& label,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    long style = wxCP_DEFAULT_STYLE,
                    const wxValidator& val = wxDefaultValidator,
                    const wxString& name = wxCollapsiblePaneNameStr);

  bool Create(wxWindow *parent,
              wxWindowID winid,
              const wxString& label,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize,
              long style = wxCP_DEFAULT_STYLE,
              const wxValidator& val = wxDefaultValidator,
              const wxString& name = wxCollapsiblePaneNameStr);

  void Collapse(bool collapse = true);
  void Expand();
  
  bool IsCollapsed();
  bool IsExpanded() const;

  wxWindow *GetPane();
    
  wxString GetLabel() const;
  void SetLabel(const wxString& label);
};

#endif
