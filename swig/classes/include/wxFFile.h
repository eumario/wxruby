// wxFFile.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFFile_h_)
#define _wxFFile_h_
class wxFFile
{
public:
   wxFFile() ;
   wxFFile(const char*  filename , const char* mode = "r") ;
   wxFFile(FILE*  fp ) ;
  virtual  ~wxFFile() ;
  void Attach(FILE*  fp ) ;
  bool Close() ;
  void Detach() ;
  FILE * fp() const;
  bool Eof() const;
  bool Flush() ;
  bool IsOpened() const;
  size_t Length() const;
  bool Open(const char*  filename , const char* mode = "r") ;
  size_t Read(void*  buffer , off_t  count ) ;
  bool Seek(long  ofs , wxSeekMode  mode = wxFromStart) ;
  bool SeekEnd(long  ofs = 0) ;
  size_t Tell() const;
  size_t Write(const void*  buffer , size_t  count ) ;
  bool Write(const wxString&  s , wxMBConv& conv = wxConvUTF8) ;
};


#endif
