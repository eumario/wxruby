// wxCaret.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

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
  void GetPosition(int*  x , int*  y ) const;
  wxPoint GetPosition() const;
  void GetSize(int*  width , int*  height ) const;
  wxSize GetSize() const;
  wxWindow* GetWindow() const;
  void Hide() ;
  bool IsOk() const;
  bool IsVisible() const;
  void Move(int  x , int  y ) ;
  void Move(const wxPoint&  pt ) ;
  static void SetBlinkTime(int  milliseconds ) ;
  void SetSize(int  width , int  height ) ;
  void SetSize(const wxSize&  size ) ;
  void Show(bool  show = true) ;
};


#endif
