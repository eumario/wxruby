// wxHtmlHelpFrame.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlHelpFrame_h_)
#define _wxHtmlHelpFrame_h_
class wxHtmlHelpFrame : public wxFrame
{
public:
	/**
	 * \brief  
	 * \param wxHtmlHelpData*   
	*/

   wxHtmlHelpFrame(wxHtmlHelpData*  data = NULL) ;
	/**
	 * \brief Constructor.

  is combination of these flags: 
	 * \param wxWindow*   
	 * \param int   
	 * \param const wxString&   
	 * \param int   
	 * \param wxHtmlHelpData*   
	*/

   wxHtmlHelpFrame(wxWindow*  parent , int  wxWindowID , const wxString&  title = wxEmptyString, int  style = wxHF_DEFAULT_STYLE, wxHtmlHelpData*  data = NULL) ;
	/**
	 * \brief Creates the frame. See  
for parameters description. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxString&   
	 * \param int   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  title = wxEmptyString, int  style = wxHF_DEFAULT_STYLE) ;
	/**
	 * \brief Creates contents panel. (May take some time.) 
	 * \param bool   
	*/

  void CreateContents(bool  show_progress = false) ;
	/**
	 * \brief Creates index panel. (May take some time.) 
	 * \param bool   
	*/

  void CreateIndex(bool  show_progress = false) ;
	/**
	 * \brief Creates search panel. 
	*/

  void CreateSearch() ;
	/**
	 * \brief  
	 * \param const wxString&   
	*/

  bool Display(const wxString&  x ) ;
	/**
	 * \brief Displays page x. If not found it will give the user the choice of
searching books.
Looking for the page runs in these steps:

\begin{enumerate}\itemsep=0pt
\item try to locate file named x (if x is for example &quot;doc/howto.htm&quot;)
\item try to open starting page of book x
\item try to find x in contents (if x is for example &quot;How To ...&quot;)
\item try to find x in index (if x is for example &quot;How To ...&quot;)
\end{enumerate}

The second form takes numeric ID as the parameter.
(uses extension to MS format, &lt;param name=&quot;ID&quot; value=id&gt;)

\pythonnote{The second form of this method is named DisplayId in
wxPython.} 
	 * \param const int   
	*/

  bool Display(const int  id ) ;
	/**
	 * \brief Displays contents panel. 
	*/

  bool DisplayContents() ;
	/**
	 * \brief Displays index panel. 
	*/

  bool DisplayIndex() ;
	/**
	 * \brief Return wxHtmlHelpData object. 
	*/

  wxHtmlHelpData* GetData() ;
	/**
	 * \brief Search for given keyword. 
	 * \param const wxString&   
	*/

  bool KeywordSearch(const wxString&  keyword ) ;
	/**
	 * \brief Reads user's settings for this frame (see  ) 
	 * \param wxConfigBase*   
	 * \param const wxString&   
	*/

  void ReadCustomization(wxConfigBase*  cfg , const wxString&  path = wxEmptyString) ;
	/**
	 * \brief Refresh all panels. This is necessary if a new book was added. 
	 * \param bool   
	*/

  void RefreshLists(bool  show_progress = false) ;
	/**
	 * \brief Sets the frame's title format.   must contain exactly one &quot;\(it will be replaced by the page title). 
	 * \param const wxString&   
	*/

  void SetTitleFormat(const wxString&  format ) ;
	/**
	 * \brief Add books to search choice panel. 
	 * \param wxConfigBase*   
	 * \param const wxString&   
	*/

  void UseConfig(wxConfigBase*  config , const wxString&  rootpath = wxEmptyString) ;
	/**
	 * \brief Saves user's settings for this frame (see  ). 
	 * \param wxConfigBase*   
	 * \param const wxString&   
	*/

  void WriteCustomization(wxConfigBase*  cfg , const wxString&  path = wxEmptyString) ;
	/**
	 * \brief You may override this virtual method to add more buttons into help frame's
toolbar.   is a pointer to the toolbar and   is the style
flag as passed to Create method.

wxToolBar::Realize is called immediately after returning from this function.

See   for an example. 
	 * \param wxToolBar *  
	 * \param int   
	*/

  virtual void AddToolbarButtons(wxToolBar * toolBar , int  style ) ;
};


#endif
