// wxBufferedOutputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxBufferedOutputStream_h_)
#define _wxBufferedOutputStream_h_
class wxBufferedOutputStream : public wxFilterOutputStream
{
public:
   wxBufferedOutputStream(const wxOutputStream&  parent ) ;
  virtual  ~wxBufferedOutputStream() ;
  off_t SeekO(off_t  pos , wxSeekMode  mode ) ;
  void Sync() ;
};


#endif
