// wxInputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxInputStream_h_)
#define _wxInputStream_h_
class wxInputStream : public wxStreamBase
{
public:
   wxInputStream() ;
  virtual  ~wxInputStream() ;
  char GetC() ;
  wxInputStream Eof() const;
  size_t LastRead() const;
  char Peek() ;
  wxInputStream& Read(void * buffer , size_t  size ) ;
  wxInputStream& Read(wxOutputStream&  stream_out ) ;
  off_t SeekI(off_t  pos , wxSeekMode mode = wxFromStart) ;
  off_t TellI() const;
  size_t Ungetch(const char*  buffer , size_t  size ) ;
  bool Ungetch(char  c ) ;
};


#endif
