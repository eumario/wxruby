// wxOutputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxOutputStream_h_)
#define _wxOutputStream_h_
class wxOutputStream : public wxStreamBase
{
public:
   wxOutputStream() ;
  virtual  ~wxOutputStream() ;
  size_t LastWrite() const;
  void PutC(char  c ) ;
  off_t SeekO(off_t  pos , wxSeekMode  mode ) ;
  off_t TellO() const;
  wxOutputStream& Write(const void * buffer , size_t  size ) ;
  wxOutputStream& Write(wxInputStream&  stream_in ) ;
};


#endif
