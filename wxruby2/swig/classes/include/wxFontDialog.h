// wxFontDialog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFontDialog_h_)
#define _wxFontDialog_h_
class wxFontDialog : public wxDialog
{
public:
   wxFontDialog() ;
   wxFontDialog(wxWindow*  parent ) ;
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
