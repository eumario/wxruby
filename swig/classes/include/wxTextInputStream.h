// wxTextInputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTextInputStream_h_)
#define _wxTextInputStream_h_
class wxTextInputStream
{
public:
   wxTextInputStream(wxInputStream&  stream ) ;
  virtual  ~wxTextInputStream() ;
  wxUint8 Read8() ;
  wxUint16 Read16() ;
  wxUint32 Read32() ;
  double ReadDouble() ;
  wxString ReadLine() ;
  wxString ReadString() ;
  wxString ReadWord() ;
  void SetStringSeparators(const wxString&  sep ) ;
};


#endif
