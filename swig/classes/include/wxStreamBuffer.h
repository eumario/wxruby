// wxStreamBuffer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxStreamBuffer_h_)
#define _wxStreamBuffer_h_
class wxStreamBuffer
{
public:
   wxStreamBuffer(wxStreamBase&  stream , BufMode  mode ) ;
   wxStreamBuffer(BufMode  mode ) ;
   wxStreamBuffer(const wxStreamBuffer& buffer ) ;
  virtual  ~wxStreamBuffer() ;
  size_t Read(void * buffer , size_t  size ) ;
  size_t Read(wxStreamBuffer * buffer ) ;
  size_t Write(const void * buffer , size_t  size ) ;
  size_t Write(wxStreamBuffer * buffer ) ;
  char GetChar() ;
  void PutChar(char  c ) ;
  off_t Tell() const;
  off_t Seek(off_t  pos , wxSeekMode  mode ) ;
  void ResetBuffer() ;
  void SetBufferIO(char*  buffer_start , char*  buffer_end ) ;
  void SetBufferIO(size_t  bufsize ) ;
  char * GetBufferStart() const;
  char * GetBufferEnd() const;
  char * GetBufferPos() const;
  off_t GetIntPosition() const;
  void SetIntPosition() ;
  size_t GetLastAccess() const;
  void Fixed(bool  fixed ) ;
  void Flushable(bool  flushable ) ;
  bool FlushBuffer() ;
  bool FillBuffer() ;
  size_t GetDataLeft() ;
  wxStreamBase* Stream() ;
};


#endif
