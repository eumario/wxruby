// wxSizer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSizer_h_)
#define _wxSizer_h_
class wxSizer : public wxObject
{
public:
   wxSizer() ;
  virtual  ~wxSizer() ;
  void Add(wxWindow*  window , int  proportion = 0, int  flag = 0, int  border = 0, wxObject*  userData = NULL) ;
  void Add(wxSizer*  sizer , int  proportion = 0, int  flag = 0, int  border = 0, wxObject*  userData = NULL) ;
  void Add(int  width , int  height , int  proportion = 0, int  flag = 0, int  border = 0, wxObject*  userData = NULL) ;
  wxSize CalcMin()  = 0;
  bool Detach(wxWindow*  window ) ;
  bool Detach(wxSizer*  sizer ) ;
  bool Detach(size_t  index ) ;
  wxSize Fit(wxWindow*  window ) ;
  void FitInside(wxWindow*  window ) ;
  wxSize GetSize() ;
  wxPoint GetPosition() ;
  wxSize GetMinSize() ;
  void Insert(size_t  index , wxWindow*  window , int  proportion = 0, int  flag = 0, int  border = 0, wxObject*  userData = NULL) ;
  void Insert(size_t  index , wxSizer*  sizer , int  proportion = 0, int  flag = 0, int  border = 0, wxObject*  userData = NULL) ;
  void Insert(size_t  index , int  width , int  height , int  proportion = 0, int  flag = 0, int  border = 0, wxObject*  userData = NULL) ;
  void Layout() ;
  void Prepend(wxWindow*  window , int  proportion = 0, int  flag = 0, int  border = 0, wxObject*  userData = NULL) ;
  void Prepend(wxSizer*  sizer , int  proportion = 0, int  flag = 0, int  border = 0, wxObject*  userData = NULL) ;
  void Prepend(int  width , int  height , int  proportion = 0, int  flag = 0, int  border = 0, wxObject*  userData = NULL) ;
  void RecalcSizes()  = 0;
  bool Remove(wxWindow*  window ) ;
  bool Remove(wxSizer*  sizer ) ;
  bool Remove(size_t  index ) ;
  void SetDimension(int  x , int  y , int  width , int  height ) ;
  void SetMinSize(int  width , int  height ) ;
  void SetMinSize(wxSize  size ) ;
  void SetItemMinSize(wxWindow*  window , int  width , int  height ) ;
  void SetItemMinSize(wxSizer*  sizer , int  width , int  height ) ;
  void SetItemMinSize(size_t  index , int  width , int  height ) ;
  void SetSizeHints(wxWindow*  window ) ;
  void SetVirtualSizeHints(wxWindow*  window ) ;
  void Show(wxWindow*  window , bool  show = true) ;
  void Show(wxSizer*  sizer , bool  show = true) ;
  void Show(size_t  index , bool  show = true) ;
};


#endif
