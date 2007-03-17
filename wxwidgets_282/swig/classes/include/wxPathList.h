// wxPathList.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPathList_h_)
#define _wxPathList_h_
class wxPathList : public wxList
{
public:
	/**
	 * \brief Constructor. 
	*/

   wxPathList() ;
	/**
	 * \brief Finds the value of the given environment variable, and adds all paths
to the path list. Useful for finding files in the PATH variable, for
example. 
	 * \param const wxString&   
	*/

  void AddEnvList(const wxString&  env_variable ) ;
	/**
	 * \brief Adds the given directory to the path list, but does not
check if the path was already on the list (use wxPathList::Member)
for this). 
	 * \param const wxString&   
	*/

  void Add(const wxString&  path ) ;
	/**
	 * \brief Given a full filename (with path), ensures that files in the same path
can be accessed using the pathlist. It does this by stripping the
filename and adding the path to the list if not already there. 
	 * \param const wxString&   
	*/

  void EnsureFileAccessible(const wxString&  filename ) ;
	/**
	 * \brief Searches for a full path for an existing file by appending   to
successive members of the path list.  If the file exists, a temporary
pointer to the absolute path is returned. 
	 * \param const wxString&   
	*/

  wxString FindAbsoluteValidPath(const wxString&  file ) ;
	/**
	 * \brief Searches for a full path for an existing file by appending   to
successive members of the path list.  If the file exists, a temporary
pointer to the full path is returned. This path may be relative to the current
working directory. 
	 * \param const wxString&   
	*/

  wxString FindValidPath(const wxString&  file ) ;
	/**
	 * \brief true if the path is in the path list (ignoring case). 
	 * \param const wxString&   
	*/

  bool Member(const wxString&  file ) ;
};


#endif
