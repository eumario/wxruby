// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxSymbolPickerDialog_h_)
#define _wxSymbolPickerDialog_h_

class wxSymbolPickerDialog: public wxDialog
{

 public:
  wxSymbolPickerDialog( );
  wxSymbolPickerDialog(const wxString& symbol, 
                       const wxString& fontName, 
                       const wxString& normalTextFont,
                       wxWindow* parent, 
                       wxWindowID id = wxID_ANY, 
                       const wxString& caption = wxGetTranslation(_T("Symbols")),
                       const wxPoint& pos = wxDefaultPosition, 
                       const wxSize& size = SYMBOL_WXSYMBOLPICKERDIALOG_SIZE, 
                       long style = SYMBOL_WXSYMBOLPICKERDIALOG_STYLE );

  bool Create(const wxString& symbol, 
              const wxString& fontName, 
              const wxString& normalTextFont,
              wxWindow* parent, 
              wxWindowID id = wxID_ANY, 
              const wxString& caption = wxGetTranslation(_T("Symbols")), 
              const wxPoint& pos = wxDefaultPosition, 
              const wxSize& size = SYMBOL_WXSYMBOLPICKERDIALOG_SIZE, 
              long style = SYMBOL_WXSYMBOLPICKERDIALOG_STYLE );
  void Init();
  void CreateControls();
  void UpdateSymbolDisplay(bool updateSymbolList = true, 
                           bool showAtSubset = true);

  void OnSymbolSelected( wxCommandEvent& event );
  void SetUnicodeMode(bool unicodeMode);
  void ShowAtSubset();
  int GetSymbolChar() const;
  bool HasSelection() const;
  bool UseNormalFont() const;
  static bool ShowToolTips();
  static void SetShowToolTips(bool show);
  virtual bool TransferDataToWindow();
  wxString GetFontName() const;
  void SetFontName(wxString value);
  wxString GetSymbol() const;
  void SetSymbol(wxString value);
  bool GetFromUnicode() const;
  void SetFromUnicode(bool value);
  wxString GetNormalTextFontName() const;
  void SetNormalTextFontName(wxString value);
  wxBitmap GetBitmapResource( const wxString& name );
  wxIcon GetIconResource( const wxString& name );
};


#endif
