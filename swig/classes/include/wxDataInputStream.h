// wxDataInputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDataInputStream_h_)
#define _wxDataInputStream_h_
class wxDataInputStream
{
public:
   wxDataInputStream(wxInputStream&  stream ) ;
   wxDataInputStream(wxInputStream&  stream , wxMBConv& conv = wxMBConvUTF8) ;
  virtual  ~wxDataInputStream() ;
  void BigEndianOrdered(bool  be_order ) ;
  wxUint8 Read8() ;
  wxUint16 Read16() ;
  wxUint32 Read32() ;
  wxUint64 Read64() ;
  double ReadDouble() ;
  wxString ReadString() ;
};


#endif
