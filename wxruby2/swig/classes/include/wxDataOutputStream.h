// wxDataOutputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDataOutputStream_h_)
#define _wxDataOutputStream_h_
class wxDataOutputStream
{
public:
   wxDataOutputStream(wxOutputStream&  stream ) ;
   wxDataOutputStream(wxOutputStream&  stream , wxMBConv& conv = wxMBConvUTF8) ;
  virtual  ~wxDataOutputStream() ;
  void BigEndianOrdered(bool  be_order ) ;
  void Write8() ;
  void Write16() ;
  void Write32() ;
  void Write64() ;
  void WriteDouble() ;
  void WriteString() ;
};


#endif
