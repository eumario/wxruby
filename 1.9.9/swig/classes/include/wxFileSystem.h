// wxFileSystem.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFileSystem_h_)
#define _wxFileSystem_h_
class wxFileSystem : public wxObject
{
public:
	/**
	 * \brief Constructor. 
	*/

   wxFileSystem() ;
	/**
	 * \brief This static function adds new handler into the list of handlers.
The   provide access to virtual FS. 
	 * \param wxFileSystemHandler   
	*/

  static void AddHandler(wxFileSystemHandler  *handler ) ;
	/**
	 * \brief Sets the current location.   parameter passed to 
  is relative to this path.

  Unless   is true the   parameter
is not the directory name but the name of the file in this directory. All these
commands change the path to &quot;dir/subdir/&quot;: 
	 * \param const wxString&   
	 * \param bool   
	*/

  void ChangePathTo(const wxString&  location , bool  is_dir = false) ;
	/**
	 * \brief Returns actual path (set by  ). 
	*/

  wxString GetPath() ;
	/**
	 * \brief Converts filename into URL. 
	 * \param wxFileName   
	*/

  static wxString FileNameToURL(wxFileName  filename ) ;
	/**
	 * \brief Works like  . Returns name of the first
filename (within filesystem's current path) that matches  .   may be one of
wxFILE (only files), wxDIR (only directories) or 0 (both). 
	 * \param const wxString&   
	 * \param int   
	*/

  wxString FindFirst(const wxString&  wildcard , int  flags = 0) ;
	/**
	 * \brief Returns the next filename that matches parameters passed to  . 
	*/

  wxString FindNext() ;
	/**
	 * \brief Opens the file and returns a pointer to a   object
or NULL if failed. It first tries to open the file in relative scope
(based on value passed to ChangePathTo() method) and then as an
absolute path. 
	 * \param const wxString&   
	*/

  wxFSFile* OpenFile(const wxString&  location ) ;
	/**
	 * \brief  
	 * \param const wxString&   
	*/

  static wxFileName URLToFileName(const wxString&  url ) ;
};


#endif
