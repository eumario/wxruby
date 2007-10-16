// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxCaret_h_)
#define _wxCaret_h_
class wxCaret
{
public:
   wxCaret() ;
   wxCaret(wxWindow*  window , int  width , int  height ) ;
  wxCaret(wxWindow*  window , const wxSize&  size );
  bool Create(wxWindowBase*  window , int  width , int  height ) ;
  bool Create(wxWindowBase*  window , const wxSize&  size ) ;
  static int GetBlinkTime() ;

  //In wxPerl there are two methods instead of one
  void GetPosition(int*  x , int*  y ) const;
  wxPoint GetPosition() const;

  //In wxPerl there are two methods instead of one
  void GetSize(int*  width , int*  height ) const;

  wxSize GetSize() const;
  wxWindow* GetWindow() const;
  virtual void Hide() ;
  bool IsOk() const;
  bool IsVisible() const;
  void Move(int  x , int  y ) ;
  void Move(const wxPoint&  pt ) ;
  static void SetBlinkTime(int  milliseconds ) ;
  void SetSize(int  width , int  height ) ;
  void SetSize(const wxSize&  size ) ;
  virtual void Show(bool  show = true) ;
};


#endif
