// wxDirTraverser.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDirTraverser_h_)
#define _wxDirTraverser_h_
class wxDirTraverser
{
public:
  virtual wxDirTraverseResult OnDir(const wxString&  dirname ) ;
  virtual wxDirTraverseResult OnFile(const wxString&  filename ) ;
  virtual wxOpenErrorTraverseResult OnOpenError(const wxString&  openerrorname ) ;
};


#endif
