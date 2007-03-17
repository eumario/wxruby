// wxHtmlHelpController.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlHelpController_h_)
#define _wxHtmlHelpController_h_
class wxHtmlHelpController
{
public:
	/**
	 * \brief Constructor.



  is combination of these flags: 
	 * \param int   
	*/

   wxHtmlHelpController(int  style = wxHF_DEFAULT_STYLE) ;
	/**
	 * \brief  
	 * \param const wxFileName&   
	 * \param bool   
	*/

  bool AddBook(const wxFileName&  book_file , bool  show_wait_msg ) ;
	/**
	 * \brief Adds book (  - HTML Help Workshop project file) into the list of loaded books.
This must be called at least once before displaying  any help.

  or    may be either .hhp file or ZIP archive
that contains arbitrary number of .hhp files in 
top-level directory. This ZIP archive must have .zip or .htb extension
(the latter stands for &quot;HTML book&quot;). In other words,
 
is possible and, in fact, recommended way. 
	 * \param const wxString&   
	 * \param bool   
	*/

  bool AddBook(const wxString&  book_url , bool  show_wait_msg ) ;
	/**
	 * \brief This protected virtual method may be overridden so that the controller
uses slightly different frame. See   sample for
an example. 
	 * \param wxHtmlHelpData *   
	*/

  virtual wxHtmlHelpFrame* CreateHelpFrame(wxHtmlHelpData *  data ) ;
	/**
	 * \brief Displays page  . This is THE important function - it is used to display
the help in application.

You can specify the page in many ways:

 

Looking for the page runs in these steps:

\begin{enumerate}\itemsep=0pt
\item try to locate file named x (if x is for example &quot;doc/howto.htm&quot;)
\item try to open starting page of book named x
\item try to find x in contents (if x is for example &quot;How To ...&quot;)
\item try to find x in index (if x is for example &quot;How To ...&quot;)
\item switch to Search panel and start searching
\end{enumerate} 
	 * \param const wxString&   
	*/

  void Display(const wxString&  x ) ;
	/**
	 * \brief This alternative form is used to search help contents by numeric IDs.

\pythonnote{The second form of this method is named DisplayId in
wxPython.} 
	 * \param const int   
	*/

  void Display(const int  id ) ;
	/**
	 * \brief Displays help window and focuses contents panel. 
	*/

  void DisplayContents() ;
	/**
	 * \brief Displays help window and focuses index panel. 
	*/

  void DisplayIndex() ;
	/**
	 * \brief Displays help window, focuses search panel and starts searching.
Returns true if the keyword was found.

  KeywordSearch searches only pages listed in .hhc file(s).
You should list all pages in the contents file. 
	 * \param const wxString&   
	*/

  bool KeywordSearch(const wxString&  keyword ) ;
	/**
	 * \brief Reads the controller's setting (position of window, etc.) 
	 * \param wxConfigBase*   
	 * \param wxString   
	*/

  void ReadCustomization(wxConfigBase*  cfg , wxString  path = wxEmptyString) ;
	/**
	 * \brief Sets the path for storing temporary files - cached binary versions of index and contents files. These binary
forms are much faster to read. Default value is empty string (empty string means
that no cached data are stored). Note that these files are   
deleted when program exits.

Once created these cached files will be used in all subsequent executions 
of your application. If cached files become older than corresponding .hhp
file (e.g. if you regenerate documentation) it will be refreshed. 
	 * \param const wxString&   
	*/

  void SetTempDir(const wxString&  path ) ;
	/**
	 * \brief Sets format of title of the frame. Must contain exactly one &quot;\(for title of displayed HTML page). 
	 * \param const wxString&   
	*/

  void SetTitleFormat(const wxString&  format ) ;
	/**
	 * \brief Associates   object with the controller.

If there is associated config object, wxHtmlHelpController automatically
reads and writes settings (including wxHtmlWindow's settings) when needed.

The only thing you must do is create wxConfig object and call UseConfig.

If you do not use  , wxHtmlHelpController will use 
default wxConfig object if available (for details see 
  and 
 ). 
	 * \param wxConfigBase*   
	 * \param const wxString&   
	*/

  void UseConfig(wxConfigBase*  config , const wxString&  rootpath = wxEmptyString) ;
	/**
	 * \brief Stores controllers setting (position of window etc.) 
	 * \param wxConfigBase*   
	 * \param wxString   
	*/

  void WriteCustomization(wxConfigBase*  cfg , wxString  path = wxEmptyString) ;
};


#endif
