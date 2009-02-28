// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxScrollBar_h_)
#define _wxScrollBar_h_

class wxScrollBar : public wxControl
{
public:
   wxScrollBar() ;
   wxScrollBar(wxWindow*  parent , wxWindowID  id , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxSB_HORIZONTAL, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("scrollBar")) ;
  virtual  ~wxScrollBar() ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxSB_HORIZONTAL, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("scrollBar")) ;
  int GetRange() const;
  int GetPageSize() const;
  int GetThumbPosition() const;

  // These functions do not appear in the main wx headers and appear to be
  // for backwards compatability in the C++ API only

  // int GetThumbLength() const;
  // void SetObjectLength(int  objectLength ) ;
  // void SetPageSize(int  pageSize ) ; 
  
  void SetThumbPosition(int  viewStart ) ;
  virtual void SetScrollbar(int  position , int  thumbSize , int  range , int  pageSize , bool  refresh = true) ;

  // Also not in main header - C++ backwards compatability only
  // void SetViewLength(int  viewLength );
};


#endif
