// wxFile.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFile_h_)
#define _wxFile_h_
class wxFile
{
public:
   wxFile() ;
   wxFile(const char*  filename , wxFile::OpenMode mode = wxFile::read) ;
   wxFile(int  fd ) ;
  virtual  ~wxFile() ;
  static bool Access(const char *  name , OpenMode  mode ) ;
  void Attach(int  fd ) ;
  void Close() ;
  bool Create(const char*  filename , bool overwrite = false, int  access = wxS_DEFAULT) ;
  void Detach() ;
  int fd() const;
  bool Eof() const;
  static bool Exists(const char*  filename ) ;
  bool Flush() ;
  bool IsOpened() const;
  off_t Length() const;
  bool Open(const char*  filename , wxFile::OpenMode mode = wxFile::read) ;
  off_t Read(void*  buffer , off_t  count ) ;
  off_t Seek(off_t  ofs , wxSeekMode  mode = wxFromStart) ;
  off_t SeekEnd(off_t  ofs = 0) ;
  off_t Tell() const;
  size_t Write(const void*  buffer , off_t  count ) ;
  bool Write(const wxString&  s , wxMBConv& conv = wxConvUTF8) ;
};


#endif
