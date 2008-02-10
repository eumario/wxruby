// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxMenuItem_h_)
#define _wxMenuItem_h_
class wxMenuItem : public wxObject
{
public:
  wxMenuItem(wxMenu *parentMenu = (wxMenu *)NULL,
             int id = wxID_SEPARATOR,
             const wxString& name = wxEmptyString,
             const wxString& help = wxEmptyString,
             wxItemKind kind = wxITEM_NORMAL,
             wxMenu *subMenu = (wxMenu *)NULL);
  virtual  ~wxMenuItem() ;

  void Check(bool bDoCheck = true);
  void Enable(bool bDoEnable = true);

  wxString GetHelp() const;
  int GetId() const;
  wxString GetItemLabel() const;
  wxString GetItemLabelText() const;
  wxItemKind GetKind() const;
  wxString GetLabel() const; // deprecated
  static wxString GetLabelText(const wxString& text) const;
  wxString GetText() const; // deprecated

  wxMenu *GetMenu() const;
  wxMenu* GetSubMenu() const;

  bool IsCheckable() const;
  bool IsChecked() const;
  bool IsEnabled() const;
  bool IsSeparator() const;
  bool IsSubMenu() const;

  void SetHelp(const wxString& str);
  void SetId(int itemid);
  void SetItemLabel(const wxString& label);
  void SetKind(wxItemKind kind);
  void SetMenu(wxMenu* menu);
  void SetSubMenu(wxMenu *menu);
  void SetText(const wxString& strName);

  void Toggle();


// Various methods available only on Windows
#if defined(__WXMSW__)
  void SetAsRadioGroupStart();
  void SetRadioGroupStart(int start);
  void SetRadioGroupEnd(int end);
  wxColour& GetBackgroundColour() const;
  const wxBitmap& GetBitmap(bool checked = true) const;
  wxFont& GetFont() const;
  int GetMarginWidth();
  wxColour& GetTextColour();

  void SetBackgroundColour(const wxColour& colour);
  void SetBitmaps(const wxBitmap& checked, 
                  const wxBitmap& unchecked = wxNullBitmap);
  void SetFont(const wxFont& font);
  void SetMarginWidth(int width);
  void SetTextColour(const wxColour& colour);
#endif

#if defined(__WXMSW__) || defined (__WXGTK__)
  void SetBitmap(const wxBitmap& bmp);
#endif

#if wxUSE_ACCEL
  static wxAcceleratorEntry *GetAccelFromString(const wxString& label);
  virtual wxAcceleratorEntry *GetAccel();
  virtual void SetAccel(wxAcceleratorEntry *accel);
#endif // wxUSE_ACCEL  
};


#endif
