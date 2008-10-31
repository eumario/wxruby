// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxToolBarToolBase_h_)
#define _wxToolBarToolBase_h_

class wxToolBarToolBase : public wxObject
{
 public:
  // ctors & dtor
  // ------------

  wxToolBarToolBase(wxToolBarBase *tbar = (wxToolBarBase *)NULL,
                    int toolid = wxID_SEPARATOR,
                    const wxString& label = wxEmptyString,
                    const wxBitmap& bmpNormal = wxNullBitmap,
                    const wxBitmap& bmpDisabled = wxNullBitmap,
                    wxItemKind kind = wxITEM_NORMAL,
                    wxObject *clientData = (wxObject *) NULL,
                    const wxString& shortHelpString = wxEmptyString,
                    const wxString& longHelpString = wxEmptyString);
  wxToolBarToolBase(wxToolBarBase *tbar, wxControl *control);
  virtual ~wxToolBarToolBase(){}

  // general
  int GetId() const;

  wxControl *GetControl() const;
  wxToolBarBase *GetToolBar() const;

  // style
  bool IsButton() const;
  bool IsControl() const;
  bool IsSeparator() const;
  int GetStyle() const;
  wxItemKind GetKind() const;

  // state
  bool IsEnabled() const;
  bool IsToggled() const;
  bool CanBeToggled() const;

  // attributes
  const wxBitmap& GetNormalBitmap() const;
  const wxBitmap& GetDisabledBitmap() const;

  const wxBitmap& GetBitmap() const;
  const wxString& GetLabel() const;
  const wxString& GetShortHelp() const;
  const wxString& GetLongHelp() const;

  wxObject *GetClientData() const;

  // modifiers: return true if the state really changed
  bool Enable(bool enable);
  bool Toggle(bool toggle);
  bool SetToggle(bool toggle);
  bool SetShortHelp(const wxString& help);
  bool SetLongHelp(const wxString& help);

  void Toggle();

  void SetNormalBitmap(const wxBitmap& bmp);
  void SetDisabledBitmap(const wxBitmap& bmp);

  virtual void SetLabel(const wxString& label);

  void SetClientData(wxObject *clientData);

  // add tool to/remove it from a toolbar
  virtual void Detach();
  virtual void Attach(wxToolBarBase *tbar);
};

#endif
