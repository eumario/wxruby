// wxMenuItem.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMenuItem_h_)
#define _wxMenuItem_h_
class wxMenuItem : public wxObject
{
public:
   wxMenuItem(wxMenu* parentMenu = NULL, int id = ID_SEPARATOR, const wxString&  text = "", const wxString&  helpString = "", wxItemKind  kind = wxITEM_NORMAL, wxMenu* subMenu = NULL) ;
  virtual  ~wxMenuItem() ;
  void Check(bool  check ) ;
  void DeleteSubMenu() ;
  void Enable(bool  enable ) ;
  wxColour& GetBackgroundColour() const;
  wxBitmap& GetBitmap(bool checked = true) const;
  wxFont& GetFont() const;
  wxString GetHelp() const;
  int GetId() const;
  wxItemKind GetKind() const;
  wxString GetLabel() const;
  static wxString GetLabelFromText(const wxString&  text ) ;
  int GetMarginWidth() const;
  wxString GetName() const;
  wxString GetText() const;
  wxMenu* GetSubMenu() const;
  wxColour& GetTextColour() const;
  bool IsCheckable() const;
  bool IsChecked() const;
  bool IsEnabled() const;
  bool IsSeparator() const;
  void SetBackgroundColour(const wxColour&  colour ) const;
  void SetBitmap(const wxBitmap&  bmp ) const;
  void SetBitmaps(const wxBitmap&  checked , const wxBitmap&  unchecked = wxNullBitmap) const;
  void SetFont(const wxFont&  font ) const;
  void SetHelp(const wxString&  helpString ) const;
  void SetMarginWidth(int  width ) const;
  void SetText(const wxString&  text ) const;
  void SetTextColour(const wxColour&  colour ) const;
};


#endif
