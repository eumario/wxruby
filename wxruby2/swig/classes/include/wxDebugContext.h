// wxDebugContext.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDebugContext_h_)
#define _wxDebugContext_h_
class wxDebugContext
{
public:
  int Check() ;
  bool Dump() ;
  bool GetCheckPrevious() ;
  bool GetDebugMode() ;
  int GetLevel() ;
  ostream& GetStream() ;
  streambuf* GetStreamBuf() ;
  bool HasStream() ;
  bool PrintClasses() ;
  bool PrintStatistics(bool detailed = true) ;
  void SetCheckpoint(bool all = false) ;
  void SetCheckPrevious(bool  check ) ;
  void SetDebugMode(bool  debug ) ;
  bool SetFile(const wxString&  filename ) ;
  void SetLevel(int  level ) ;
  bool SetStandardError() ;
  void SetStream(ostream*  stream , streambuf*  streamBuf = NULL) ;
};


#endif
