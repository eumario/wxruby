#if !defined(_wxFileDialog_h_)
#define _wxFileDialog_h_
class wxFileDialog : public wxDialog
{
public:
  wxFileDialog(wxWindow* parent, 
               const wxString& message = wxT("Choose a file"), 
               const wxString& defaultDir = wxT(""), 
               const wxString& defaultFile = wxT(""), 
               const wxString& wildcard = wxT("*.*"), 
               long  style = wxFD_DEFAULT_STYLE, 
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& sz = wxDefaultSize,
               const wxString& name = wxFileDialogNameStr) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxFileDialog() ;
	/**
	 * \brief Returns the default directory. 
	*/

  wxString GetDirectory() const;
	/**
	 * \brief Returns the default filename. 
	*/

  wxString GetFilename() const;
	/**
	 * \brief Fills the array   with the names of the files chosen. This
function should only be used with the dialogs which have   style,
use   for the others.

Note that under Windows, if the user selects shortcuts, the filenames
include paths, since the application cannot determine the full path
of each referenced file by appending the directory containing the shortcuts
to the filename. 
	 * \param wxArrayString&   
	*/

  void GetFilenames(wxArrayString&  filenames ) const;
	/**
	 * \brief Returns the index into the list of filters supplied, optionally, in the wildcard parameter.
Before the dialog is shown, this is the index which will be used when the dialog is first displayed.
After the dialog is shown, this is the index selected by the user. 
	*/

  int GetFilterIndex() const;
	/**
	 * \brief Returns the message that will be displayed on the dialog. 
	*/

  wxString GetMessage() const;
	/**
	 * \brief Returns the full path (directory and filename) of the selected file. 
	*/

  wxString GetPath() const;
	/**
	 * \brief Fills the array   with the full paths of the files chosen. This
function should only be used with the dialogs which have   style,
use   for the others. 
	 * \param wxArrayString&   
	*/

  void GetPaths(wxArrayString&  paths ) const;
	/**
	 * \brief Returns the file dialog wildcard. 
	*/

  wxString GetWildcard() const;
	/**
	 * \brief Sets the default directory. 
	 * \param const wxString&   
	*/

  void SetDirectory(const wxString&  directory ) ;
	/**
	 * \brief Sets the default filename. 
	 * \param const wxString&   
	*/

  void SetFilename(const wxString&  setfilename ) ;
	/**
	 * \brief Sets the default filter index, starting from zero. 
	 * \param int   
	*/

  void SetFilterIndex(int  filterIndex ) ;
	/**
	 * \brief Sets the message that will be displayed on the dialog. 
	 * \param const wxString&   
	*/

  void SetMessage(const wxString&  message ) ;
	/**
	 * \brief Sets the path (the combined directory and filename that will be returned when the dialog is dismissed). 
	 * \param const wxString&   
	*/

  void SetPath(const wxString&  path ) ;
	/**
	 * \brief Sets the wildcard, which can contain multiple file types, for example:

``BMP files (&#42;.bmp)|&#42;.bmp|GIF files (&#42;.gif)|&#42;.gif&quot;

Note that the native Motif dialog has some limitations with respect to
wildcards; see the Remarks section above. 
	 * \param const wxString&   
	*/

  void SetWildcard(const wxString&  wildCard ) ;
	/**
	 * \brief Shows the dialog, returning wxID_OK if the user pressed OK, and wxID_CANCEL
otherwise. 
	*/

  int ShowModal() ;
};


#endif
