// wxFFileOutputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFFileOutputStream_h_)
#define _wxFFileOutputStream_h_
class wxFFileOutputStream : public wxOutputStream
{
public:
   wxFFileOutputStream(const wxString&  ofileName ) ;
   wxFFileOutputStream(wxFFile&  file ) ;
   wxFFileOutputStream(FILE *  fp ) ;
  virtual  ~wxFFileOutputStream() ;
  bool Ok() const;
};


#endif
