// wxMenu.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMenu_h_)
#define _wxMenu_h_
class wxMenu : public wxEvtHandler
{
public:
   wxMenu(const wxString&  title = "", long style = 0) ;
   wxMenu(long  style ) ;
  virtual  ~wxMenu() ;
  void Append(int  id , const wxString&   item , const wxString&  helpString = "", wxItemKind kind = wxITEM_NORMAL) ;
  void Append(int  id , const wxString&   item , wxMenu * subMenu , const wxString&  helpString = "") ;
  void Append(wxMenuItem*  menuItem ) ;
  void AppendCheckItem(int  id , const wxString&   item , const wxString&  helpString = "") ;
  void AppendRadioItem(int  id , const wxString&   item , const wxString&  helpString = "") ;
  void AppendSeparator() ;
  void Break() ;
  void Check(int  id , const bool  check ) ;
  void Delete(int  id ) ;
  void Delete(wxMenuItem * item ) ;
  void Destroy(int  id ) ;
  void Destroy(wxMenuItem * item ) ;
  void Enable(int  id , const bool  enable ) ;
  int FindItem(const wxString&  itemString ) const;
  wxMenuItem * FindItem(int  id , wxMenu ** menu = NULL) const;
  wxMenuItem* FindItemByPosition(size_t  position ) const;
  wxString GetHelpString(int  id ) const;
  wxString GetLabel(int  id ) const;
  size_t GetMenuItemCount() const;
  wxMenuItemList& GetMenuItems() const;
  wxString GetTitle() const;
  bool Insert(size_t  pos , wxMenuItem * item ) ;
  void Insert(size_t  pos , int  id , const wxString&   item , const wxString&  helpString = "", wxItemKind kind = wxITEM_NORMAL) ;
  void InsertCheckItem(size_t  pos , int  id , const wxString&   item , const wxString&  helpString = "") ;
  void InsertRadioItem(size_t  pos , int  id , const wxString&   item , const wxString&  helpString = "") ;
  void InsertSeparator(size_t  pos ) ;
  bool IsChecked(int  id ) const;
  bool IsEnabled(int  id ) const;
  void Prepend(wxMenuItem * item );
  void Prepend(int  id , const wxString&   item , const wxString&  helpString = "", wxItemKind kind = wxITEM_NORMAL) ;
  void PrependCheckItem(int  id , const wxString&   item , const wxString&  helpString = "") ;
  void PrependRadioItem(int  id , const wxString&   item , const wxString&  helpString = "") ;
  void PrependSeparator();
  wxMenuItem * Remove(int  id ) ;
  wxMenuItem * Remove(wxMenuItem * item ) ;
  void SetHelpString(int  id , const wxString&  helpString ) ;
  void SetLabel(int  id , const wxString&  label ) ;
  void SetTitle(const wxString&  title ) ;
  void UpdateUI(wxEvtHandler* source = NULL);
};


#endif
