// wxStatusBar.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxStatusBar_h_)
#define _wxStatusBar_h_
class wxStatusBar : public wxWindow
{
public:
   wxStatusBar() ;
   wxStatusBar(wxWindow*  parent , wxWindowID  id , long style = wxST_SIZEGRIP, const wxString&  name = "statusBar") ;
  virtual  ~wxStatusBar() ;
  bool Create(wxWindow*  parent , wxWindowID  id , long style = wxST_SIZEGRIP, const wxString&  name = "statusBar") ;
  virtual bool GetFieldRect(int  i , wxRect&  rect ) const;
  int GetFieldsCount() const;
  virtual wxString GetStatusText(int ir = 0) const;
  void PopStatusText(int field = 0) ;
  void PushStatusText(const wxString&  string , int field = 0) ;
  virtual void SetFieldsCount(int number = 1, int*  widths = NULL) ;
  void SetMinHeight(int  height ) ;
  virtual void SetStatusText(const wxString&  text , int i = 0) ;
  virtual void SetStatusWidths(int  n , int * widths ) ;
};


#endif
