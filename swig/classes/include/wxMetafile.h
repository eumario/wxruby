// wxMetafile.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMetafile_h_)
#define _wxMetafile_h_
class wxMetafile : public wxObject
{
public:
   wxMetafile(const wxString&  filename = "") ;
  virtual  ~wxMetafile() ;
  bool Ok() ;
  bool Play(wxDC * dc ) ;
  bool SetClipboard(int width = 0, int height = 0) ;
};


#endif
