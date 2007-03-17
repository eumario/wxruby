//   Copyright 2004-2007 by Kevin Smith
//   released under the MIT-style wxruby2 license


#if !defined(_wxFontDialog_h_)
#define _wxFontDialog_h_
class wxFontDialog : public wxDialog
{
public:
   wxFontDialog() ;
   wxFontDialog(wxWindow*  parent , const wxFontData&  data ) ;
#if !defined(__WXMAC__)
   wxFontDialog(wxWindow*  parent ) ;
#endif

  bool Create() ;
  bool Create(wxWindow*  parent , const wxFontData&  data ) ;
#if !defined(__WXMAC__)
  bool Create(wxWindow*  parent ) ;
#endif


  virtual  ~wxFontDialog() ;
  const wxFontData& GetFontData() const;
  wxFontData& GetFontData() ;
  int ShowModal() ;
};


#endif
