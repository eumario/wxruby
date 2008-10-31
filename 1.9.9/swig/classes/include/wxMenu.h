// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxMenu_h_)
#define _wxMenu_h_
class wxMenu : public wxEvtHandler
{
public:
   wxMenu(const wxString&  title = wxT(""), long style = 0) ;
   wxMenu(long  style ) ;
  virtual  ~wxMenu() ;
  wxMenuItem* Append(int itemid, 
                     const wxString& item = wxEmptyString, 
                     const wxString& help = wxEmptyString, 
                     wxItemKind kind = wxITEM_NORMAL);
  wxMenuItem* Append(int itemid, 
                     const wxString& text, 
                     wxMenu *submenu, 
                     const wxString& help = wxEmptyString);
  wxMenuItem* Append(wxMenuItem *item);
  wxMenuItem* AppendCheckItem(int  id, 
                              const wxString& item , 
                              const wxString& helpString = wxT(""));
  wxMenuItem* AppendRadioItem(int id, 
                              const wxString& item, 
                              const wxString&  helpString = wxT(""));
  wxMenuItem* AppendSubMenu(wxMenu *submenu, 
                            const wxString& text, 
                            const wxString& help = wxEmptyString);
  void AppendSeparator();
  void Break();
  void Check(int id, const bool check );
  void Delete(int id);
  void Delete(wxMenuItem * item );
  void Destroy(int  id ) ;
  void Destroy(wxMenuItem * item ) ;
  void Enable(int  id , const bool  enable ) ;
  int FindItem(const wxString&  itemString ) const;
  wxMenuItem* FindItem(int id, wxMenu ** menu = NULL) const;
  wxMenuItem* FindItemByPosition(size_t position) const;
  wxString GetHelpString(int  id ) const;
  wxString GetLabel(int  id ) const;
  wxString GetLabelText(int id) const;
  size_t GetMenuItemCount() const;
  const wxMenuItemList& GetMenuItems() const;
  wxString GetTitle() const;
  wxMenuItem* Insert(size_t pos, wxMenuItem * item );
  wxMenuItem* Insert(size_t  pos, 
                     int  id, 
                     const wxString& item = wxEmptyString, 
                     const wxString& helpString = wxT(""), 
                     wxItemKind kind = wxITEM_NORMAL);
  wxMenuItem* InsertCheckItem(size_t pos , 
                              int  id, 
                              const wxString& item, 
                              const wxString& helpString = wxT(""));
  wxMenuItem* InsertRadioItem(size_t pos, 
                              int id, 
                              const wxString& item, 
                              const wxString&  helpString = wxT(""));
  wxMenuItem* InsertSeparator(size_t pos);
  bool IsChecked(int id) const;
  bool IsEnabled(int id) const;
  wxMenuItem* Prepend(wxMenuItem * item );
  wxMenuItem* Prepend(int id, 
                      const wxString& item, 
                      const wxString& helpString = wxT(""), 
                      wxItemKind kind = wxITEM_NORMAL);
  wxMenuItem* PrependCheckItem(int id, 
                               const wxString& item, 
                               const wxString& helpString = wxT(""));
  wxMenuItem* PrependRadioItem(int id, 
                               const wxString& item, 
                               const wxString& helpString = wxT(""));
  wxMenuItem* PrependSeparator();
  wxMenuItem* Remove(int id);
  wxMenuItem* Remove(wxMenuItem* item );

  void SetHelpString(int id, 
                     const wxString& helpString );
  void SetLabel(int id,
                const wxString& label);
  void SetTitle(const wxString& title);
  void UpdateUI(wxEvtHandler* source = NULL);
  static void LockAccels(bool locked);    
};


#endif
