// wxFFileInputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFFileInputStream_h_)
#define _wxFFileInputStream_h_
class wxFFileInputStream : public wxInputStream
{
public:
   wxFFileInputStream(const wxString&  ifileName ) ;
   wxFFileInputStream(wxFFile&  file ) ;
   wxFFileInputStream(FILE *  fp ) ;
  virtual  ~wxFFileInputStream() ;
  bool Ok() const;
};


#endif
