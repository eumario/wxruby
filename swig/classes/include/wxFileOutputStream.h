// wxFileOutputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFileOutputStream_h_)
#define _wxFileOutputStream_h_
class wxFileOutputStream : public wxOutputStream
{
public:
   wxFileOutputStream(const wxString&  ofileName ) ;
   wxFileOutputStream(wxFile&  file ) ;
   wxFileOutputStream(int  fd ) ;
  virtual  ~wxFileOutputStream() ;
  bool Ok() const;
};


#endif
