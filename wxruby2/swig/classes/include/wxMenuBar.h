// wxMenuBar.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMenuBar_h_)
#define _wxMenuBar_h_
class wxMenuBar : public wxEvtHandler
{
public:
   wxMenuBar(long  style = 0) ;
   wxMenuBar(int  n , wxMenu*  menus[] , const wxString  titles[] ) ;
  virtual  ~wxMenuBar() ;
  bool Append(wxMenu * menu , const wxString&  title ) ;
  void Check(int  id , const bool  check ) ;
  void Enable(int  id , const bool  enable ) ;
  void EnableTop(int  pos , const bool  enable ) ;
  int FindMenu(const wxString&  title ) const;
  int FindMenuItem(const wxString&  menuString , const wxString&  itemString ) const;
  wxMenuItem * FindItem(int  id , wxMenu **menu = NULL) const;
  wxString GetHelpString(int  id ) const;
  wxString GetLabel(int  id ) const;
  wxString GetLabelTop(int  pos ) const;
  wxMenu* GetMenu(int  menuIndex ) const;
  int GetMenuCount() const;
  bool Insert(size_t  pos , wxMenu * menu , const wxString&  title ) ;
  bool IsChecked(int  id ) const;
  bool IsEnabled(int  id ) const;
  void Refresh() ;
  wxMenu * Remove(size_t  pos ) ;
  wxMenu * Replace(size_t  pos , wxMenu * menu , const wxString&  title ) ;
  void SetHelpString(int  id , const wxString&  helpString ) ;
  void SetLabel(int  id , const wxString&  label ) ;
  void SetLabelTop(int  pos , const wxString&  label ) ;
};


#endif
