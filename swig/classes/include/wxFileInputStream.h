// wxFileInputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFileInputStream_h_)
#define _wxFileInputStream_h_
class wxFileInputStream : public wxInputStream
{
public:
   wxFileInputStream(const wxString&  ifileName ) ;
   wxFileInputStream(wxFile&  file ) ;
   wxFileInputStream(int  fd ) ;
  virtual  ~wxFileInputStream() ;
  bool Ok() const;
};


#endif
