// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license


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

  bool Create(wxWindow*  parent , const wxFontData&  data ) ;
#if !defined(__WXMAC__)
  bool Create(wxWindow*  parent ) ;
#endif


  virtual  ~wxFontDialog() ;
#if defined(__WXMAC__)
  wxFontData& GetFontData();
#else
	const wxFontData& GetFontData() const;
#endif

  wxFontData& GetFontData() ;
  int ShowModal() ;
};


#endif
