//   Copyright 2004-2005 by Kevin Smith
//   released under the MIT-style wxruby2 license


#if !defined(_wxFontDialog_h_)
#define _wxFontDialog_h_
class wxFontDialog : public wxDialog
{
public:
   wxFontDialog() ;
#if !defined(__WXMAC__)
   wxFontDialog(wxWindow*  parent ) ;
#endif
   wxFontDialog(wxWindow*  parent , const wxFontData&  data ) ;
  bool Create() ;
  bool Create(wxWindow*  parent ) ;
  bool Create(wxWindow*  parent , const wxFontData&  data ) ;
  virtual  ~wxFontDialog() ;
  const wxFontData& GetFontData() const;
  wxFontData& GetFontData() ;
  int ShowModal() ;
};


#endif
