// wxTempFile.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTempFile_h_)
#define _wxTempFile_h_
class wxTempFile
{
public:
   wxTempFile() ;
   wxTempFile(const wxString&  strName ) ;
  bool Open(const wxString&  strName ) ;
  bool IsOpened() const;
  bool Write(const void  *p , size_t  n ) ;
  bool Write(const wxString&  str , wxMBConv& conv = wxConvLibc) ;
  bool Commit() ;
  void Discard() ;
  virtual  ~wxTempFile() ;
};


#endif
