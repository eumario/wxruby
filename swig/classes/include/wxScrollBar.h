// wxScrollBar.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxScrollBar_h_)
#define _wxScrollBar_h_
class wxScrollBar : public wxControl
{
public:
   wxScrollBar() ;
   wxScrollBar(wxWindow*  parent , wxWindowID  id , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxSB_HORIZONTAL, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "scrollBar") ;
  virtual  ~wxScrollBar() ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxSB_HORIZONTAL, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "scrollBar") ;
  int GetRange() const;
  int GetPageSize() const;
  int GetThumbPosition() const;
  int GetThumbLength() const;
  void SetObjectLength(int  objectLength ) ;
  void SetPageSize(int  pageSize ) ;
  void SetThumbPosition(int  viewStart ) ;
  virtual void SetScrollbar(int  position , int  thumbSize , int  range , int  pageSize , const bool  refresh = true) ;
  void SetViewLength(int  viewLength ) ;
};


#endif
