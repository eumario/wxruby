// wxTextOutputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTextOutputStream_h_)
#define _wxTextOutputStream_h_
class wxTextOutputStream
{
public:
   wxTextOutputStream(wxOutputStream&  stream , wxEOL mode = wxEOL_NATIVE) ;
  virtual  ~wxTextOutputStream() ;
  wxEOL GetMode() ;
  void SetMode() ;
  void Write8() ;
  void Write16() ;
  void Write32() ;
  virtual void WriteDouble() ;
  virtual void WriteString() ;
};


#endif
