// wxHtmlWindow.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlWindow_h_)
#define _wxHtmlWindow_h_
class wxHtmlWindow : public wxScrolledWindow
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxHtmlWindow() ;
	/**
	 * \brief Constructor. The parameters are the same as for the   constructor. 
	 * \param wxWindow   
	 * \param wxWindowID   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long   
	 * \param const wxString&   
	*/

   wxHtmlWindow(wxWindow  *parent , wxWindowID  id = -1, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxHW_SCROLLBAR_AUTO, const wxString&  name = wxT("htmlWindow")) ;
	/**
	 * \brief Adds   to the static list of available
filters. These filters are present by default: 
	 * \param wxHtmlFilter   
	*/

  static void AddFilter(wxHtmlFilter  *filter ) ;
	/**
	 * \brief Appends HTML fragment to currently displayed text and refreshes the window. 
	 * \param const wxString&   
	*/

  bool AppendToPage(const wxString&  source ) ;
	/**
	 * \brief Returns pointer to the top-level container.

See also:  , 
	*/

  wxHtmlContainerCell* GetInternalRepresentation() const;
	/**
	 * \brief Returns anchor within currently opened page
(see  ). 
If no page is opened or if the displayed page wasn't
produced by call to LoadPage, empty string is returned. 
	*/

  wxString GetOpenedAnchor() ;
	/**
	 * \brief Returns full location of the opened page. If no page is opened or if the displayed page wasn't
produced by call to LoadPage, empty string is returned. 
	*/

  wxString GetOpenedPage() ;
	/**
	 * \brief Returns title of the opened page or wxEmptyString if current page does not contain   tag. 
	*/

  wxString GetOpenedPageTitle() ;
	/**
	 * \brief Returns the related frame. 
	*/

  wxFrame* GetRelatedFrame() const;
	/**
	 * \brief Moves back to the previous page. (each page displayed using 
  is stored in history list.) 
	*/

  bool HistoryBack() ;
	/**
	 * \brief Returns true if it is possible to go back in the history (i.e. HistoryBack()
won't fail). 
	*/

  bool HistoryCanBack() ;
	/**
	 * \brief Returns true if it is possible to go forward in the history (i.e. HistoryBack()
won't fail). 
	*/

  bool HistoryCanForward() ;
	/**
	 * \brief Clears history. 
	*/

  void HistoryClear() ;
	/**
	 * \brief Moves to next page in history. 
	*/

  bool HistoryForward() ;
	/**
	 * \brief Loads HTML page from file and displays it. 
	 * \param const wxFileName&   
	*/

  virtual bool LoadFile(const wxFileName&  filename ) ;
	/**
	 * \brief Unlike SetPage this function first loads HTML page from   
and then displays it. See example: 
	 * \param const wxString&   
	*/

  virtual bool LoadPage(const wxString&  location ) ;
	/**
	 * \brief This method is called when a mouse button is clicked inside wxHtmlWindow.
The default behaviour is to call 
  if the cell contains a
hypertext link. 
	 * \param wxHtmlCell   
	 * \param wxCoord   
	 * \param wxCoord   
	 * \param const wxMouseEvent&   
	*/

  virtual void OnCellClicked(wxHtmlCell  *cell , wxCoord  x , wxCoord  y , const wxMouseEvent&  event ) ;
	/**
	 * \brief This method is called when a mouse moves over an HTML cell. 
	 * \param wxHtmlCell   
	 * \param wxCoord   
	 * \param wxCoord   
	*/

  virtual void OnCellMouseHover(wxHtmlCell  *cell , wxCoord  x , wxCoord  y ) ;
	/**
	 * \brief Called when user clicks on hypertext link. Default behaviour is to call 
  and do nothing else.

Also see  . 
	 * \param const wxHtmlLinkInfo&   
	*/

  virtual void OnLinkClicked(const wxHtmlLinkInfo&  link ) ;
	/**
	 * \brief Called when an URL is being opened (either when the user clicks on a link or
an image is loaded). The URL will be opened only if OnOpeningURL returns 
 . This method is called by
 .
You can override OnOpeningURL to selectively block some
URLs (e.g. for security reasons) or to redirect them elsewhere. Default
behaviour is to always return  . 
	 * \param wxHtmlURLType   
	 * \param const wxString&   
	 * \param wxString *  
	*/

  virtual wxHtmlOpeningStatus OnOpeningURL(wxHtmlURLType  type , const wxString&  url , wxString * redirect ) ;
	/**
	 * \brief Called on parsing   tag. 
	 * \param const wxString&   
	*/

  virtual void OnSetTitle(const wxString&  title ) ;
	/**
	 * \brief This reads custom settings from wxConfig. It uses the path 'path'
if given, otherwise it saves info into currently selected path.
The values are stored in sub-path  

Read values: all things set by SetFonts, SetBorders. 
	 * \param wxConfigBase   
	 * \param wxString   
	*/

  virtual void ReadCustomization(wxConfigBase  *cfg , wxString  path = wxEmptyString) ;
	/**
	 * \brief This function sets the space between border of window and HTML contents. See image:

\helponly{\image{}{border.bmp}} 
	 * \param int   
	*/

  void SetBorders(int  b ) ;
	/**
	 * \brief This function sets font sizes and faces.









\wxheading{Defaults}

Default font sizes are defined by constants wxHTML_FONT_SIZE_1,
wxHTML_FONT_SIZE_2, ..., wxHTML_FONT_SIZE_7. Note that they differ among
platforms. Default face names are empty strings. 
	 * \param wxString   
	 * \param wxString   
	 * \param const int   
	*/

  void SetFonts(wxString  normal_face , wxString  fixed_face , const int  *sizes = NULL) ;
	/**
	 * \brief Sets HTML page and display it. This won't   the page!!
It will display the  . See example:

 

If you want to load a document from some location use 
  instead. 
	 * \param const wxString&   
	*/

  bool SetPage(const wxString&  source ) ;
	/**
	 * \brief Sets the frame in which page title will be displayed.   is format of
frame title, e.g. &quot;HtmlHelp : 
	 * \param wxFrame*   
	 * \param const wxString&   
	*/

  void SetRelatedFrame(wxFrame*  frame , const wxString&  format ) ;
	/**
	 * \brief calling  ,
this sets statusbar slot where messages will be displayed.
(Default is -1 = no messages.) 
	 * \param int   
	*/

  void SetRelatedStatusBar(int  bar ) ;
	/**
	 * \brief Saves custom settings into wxConfig. It uses the path 'path'
if given, otherwise it saves info into currently selected path.
Regardless of whether the path is given or not, the function creates sub-path 
 .

Saved values: all things set by SetFonts, SetBorders. 
	 * \param wxConfigBase   
	 * \param wxString   
	*/

  virtual void WriteCustomization(wxConfigBase  *cfg , wxString  path = wxEmptyString) ;
};


#endif
