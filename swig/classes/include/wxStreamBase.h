// wxStreamBase.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxStreamBase_h_)
#define _wxStreamBase_h_
class wxStreamBase
{
public:
   wxStreamBase() ;
  virtual  ~wxStreamBase() ;
  wxStreamError IsOk() const;
  wxStreamError LastError() const;
  virtual size_t OnSysRead(void*  buffer , size_t  bufsize ) ;
  virtual off_t OnSysSeek(off_t  pos , wxSeekMode  mode ) ;
  virtual off_t OnSysTell() const;
  virtual size_t OnSysWrite(void * buffer , size_t  bufsize ) ;
  size_t GetSize() const;
};


#endif
