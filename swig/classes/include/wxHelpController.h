// wxHelpController.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHelpController_h_)
#define _wxHelpController_h_
class wxHelpController : public wxObject
{
public:
	/**
	 * \brief Constructs a help instance object, but does not invoke the help viewer. 
	*/

   wxHelpController() ;
	/**
	 * \brief Destroys the help instance, closing down the viewer if it is running. 
	*/

  virtual  ~wxHelpController() ;
	/**
	 * \brief  
	 * \param const wxString&   
	*/

  virtual void Initialize(const wxString&  file ) ;
	/**
	 * \brief Initializes the help instance with a help filename, and optionally a server socket
number if using wxHelp (now obsolete). Does not invoke the help viewer.
This must be called directly after the help instance object is created and before
any attempts to communicate with the viewer.

You may omit the file extension and a suitable one will be chosen. For
wxHtmlHelpController, the extensions zip, htb and hhp will be appended while searching for
a suitable file. For WinHelp, the hlp extension is appended. 
	 * \param const wxString&   
	 * \param int  
	*/

  virtual void Initialize(const wxString&  file , int  server ) ;
	/**
	 * \brief If the help viewer is not running, runs it and displays the file at the given block number.

  Refers to the context number.

  Refers to the context number.

  the same as for  .

    is an identifier as specified in the   file. See  .

This function is for backward compatibility only, and applications should use   instead. 
	 * \param long  
	*/

  virtual bool DisplayBlock(long  blockNo ) ;
	/**
	 * \brief If the help viewer is not running, runs it and displays the
contents. 
	*/

  virtual bool DisplayContents() ;
	/**
	 * \brief Displays the section as a popup window using a context id.

Returns false if unsuccessful or not implemented. 
	 * \param int   
	*/

  virtual bool DisplayContextPopup(int  contextId ) ;
	/**
	 * \brief If the help viewer is not running, runs it and displays the given section.

The interpretation of   differs between help viewers. For most viewers,
this call is equivalent to KeywordSearch. For MS HTML Help, wxHTML help and external HTML help,
if   has a .htm
or .html extension, that HTML file will be displayed; otherwise
a keyword search is done. 
	 * \param const wxString&  
	*/

  virtual bool DisplaySection(const wxString&  section ) ;
	/**
	 * \brief If the help viewer is not running, runs it and displays the given section.

    is a context id.

  wxExtHelpController implements   as an id in a map file, which is of the form:

 

    is an identifier as specified in the   file. See  .

See also the help sample for notes on how to specify section numbers for various help file formats. 
	 * \param int  
	*/

  virtual bool DisplaySection(int  sectionNo ) ;
	/**
	 * \brief Displays the text in a popup window, if possible.

Returns false if unsuccessful or not implemented. 
	 * \param const wxString&  
	 * \param const wxPoint&   
	*/

  virtual bool DisplayTextPopup(const wxString&  text , const wxPoint&  pos ) ;
	/**
	 * \brief wxHtmlHelpController returns the frame, size and position.

For all other help controllers, this function does nothing
and just returns NULL. 
	 * \param const wxSize *   
	 * \param const wxPoint *   
	 * \param bool *  
	*/

  virtual wxFrame * GetFrameParameters(const wxSize *  size = NULL, const wxPoint *  pos = NULL, bool * newFrameEachTime = NULL) ;
	/**
	 * \brief If the help viewer is not running, runs it, and searches for sections matching the given keyword. If one
match is found, the file is displayed at this section.

  If more than one match is found, 
the first topic is displayed.

  If more than one match is found, 
a choice of topics is displayed.

  see  . 
	 * \param const wxString&   
	*/

  virtual bool KeywordSearch(const wxString&  keyWord ) ;
	/**
	 * \brief If the help viewer is not running, runs it and loads the given file.
If the filename is not supplied or is
empty, the file specified in   is used. If the viewer is
already displaying the specified file, it will not be reloaded. This
member function may be used before each display call in case the user
has opened another file.

wxHtmlHelpController ignores this call. 
	 * \param const wxString&   
	*/

  virtual bool LoadFile(const wxString&  file = "") ;
	/**
	 * \brief Overridable member called when this application's viewer is quit by the user.

This does not work for all help controllers. 
	*/

  virtual bool OnQuit() ;
	/**
	 * \brief For wxHtmlHelpController, the title is set (again with \page title) and also the size and position of the frame if the frame is already
open.   is ignored.

For all other help controllers this function has no effect. 
	 * \param const wxString &   
	 * \param const wxSize &   
	 * \param const wxPoint &   
	 * \param bool   
	*/

  virtual void SetFrameParameters(const wxString &  title , const wxSize &  size , const wxPoint &  pos = wxDefaultPosition, bool  newFrameEachTime = false) ;
	/**
	 * \brief Sets detailed viewer information. So far this is only relevant to wxExtHelpController.

Some examples of usage: 
	 * \param const wxString&   
	 * \param long  
	*/

  virtual void SetViewer(const wxString&  viewer , long  flags ) ;
	/**
	 * \brief If the viewer is running, quits it by disconnecting.

For Windows Help, the viewer will only close if no other application is using it. 
	*/

  virtual bool Quit() ;
};


#endif
