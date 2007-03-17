// wxDirTraverser.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDirTraverser_h_)
#define _wxDirTraverser_h_
class wxDirTraverser
{
public:
	/**
	 * \brief This function is called for each directory. It may return   
to abort traversing completely,   to skip this directory but
continue with others or   to enumerate all files and
subdirectories in this directory.

This is a pure virtual function and must be implemented in the derived class. 
	 * \param const wxString&   
	*/

  virtual wxDirTraverseResult OnDir(const wxString&  dirname ) ;
	/**
	 * \brief This function is called for each file. It may return   to abort
traversing (for example, if the file being searched is found) or 
  to proceed.

This is a pure virtual function and must be implemented in the derived class. 
	 * \param const wxString&   
	*/

  virtual wxDirTraverseResult OnFile(const wxString&  filename ) ;
	/**
	 * \brief This function is called for each directory which we failed to open for
enumerating. It may return   to abort traversing completely,
  to skip this directory but continue with others or 
  to retry opening this directory once again.

The base class version always returns  . 
	 * \param const wxString&   
	*/

  virtual wxOpenErrorTraverseResult OnOpenError(const wxString&  openerrorname ) ;
};


#endif
