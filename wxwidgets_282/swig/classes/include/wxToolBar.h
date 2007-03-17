// wxToolBar.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxToolBar_h_)
#define _wxToolBar_h_
class wxToolBar : public wxControl
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxToolBar() ;
	/**
	 * \brief Constructs a toolbar. 
	 * \param wxWindow*  
	 * \param wxWindowID   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long   
	 * \param const wxString&   
	*/

   wxToolBar(wxWindow*  parent , wxWindowID  id , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxTB_HORIZONTAL, const wxString&  name = wxPanelNameStr) ;
	/**
	 * \brief Toolbar destructor. 
	*/

  virtual  ~wxToolBar() ;
	/**
	 * \brief Adds any control to the toolbar, typically e.g. a combobox. 
	 * \param wxControl*  
	*/

  bool AddControl(wxControl*  control ) ;
	/**
	 * \brief  
	*/

  void AddSeparator() ;
	/**
	 * \brief  
	 * \param int  
	 * \param const wxString&  
	 * \param const wxBitmap&  
	 * \param const wxString&   
	 * \param wxItemKind  
	*/

  wxToolBarTool* AddTool(int  toolId , const wxString&  label , const wxBitmap&  bitmap1 , const wxString&  shortHelpString = wxT(""), wxItemKind kind = wxITEM_NORMAL) ;
	/**
	 * \brief  
	 * \param int  
	 * \param const wxString&  
	 * \param const wxBitmap&  
	 * \param const wxBitmap&  
	 * \param wxItemKind  
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param wxObject*   
	*/

  wxToolBarTool* AddTool(int  toolId , const wxString&  label , const wxBitmap&  bitmap1 , const wxBitmap& bitmap2 = wxNullBitmap, wxItemKind kind = wxITEM_NORMAL, const wxString&  shortHelpString = wxT(""), const wxString&  longHelpString = wxT(""), wxObject*  clientData = NULL) ;
	/**
	 * \brief Adds a tool to the toolbar. The first (short and most commonly used) version
has fewer parameters than the full version at the price of not being able to
specify some of the more rarely used button features. The last version allows
to add an existing tool. 
	 * \param wxToolBarTool*   
	*/

  //wxToolBarTool* AddTool(wxToolBarTool*  tool );
	/**
	 * \brief Adds a new check (or toggle) tool to the toolbar. The parameters are the same
as in  . 
	 * \param int  
	 * \param const wxString&  
	 * \param const wxBitmap&  
	 * \param const wxBitmap&  
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param wxObject*   
	*/

  wxToolBarTool* AddCheckTool(int  toolId , const wxString&  label , const wxBitmap&  bitmap1 , const wxBitmap&  bitmap2 , const wxString&  shortHelpString = wxT(""), const wxString&  longHelpString = wxT(""), wxObject*  clientData = NULL) ;
	/**
	 * \brief Adds a new radio tool to the toolbar. Consecutive radio tools form a radio
group such that exactly one button in the group is pressed at any moment, in
other words whenever a button in the group is pressed the previously pressed
button is automatically released. You should avoid having the radio groups of
only one element as it would be impossible for the user to use such button.

By default, the first button in the radio group is initially pressed, the
others are not. 
	 * \param int  
	 * \param const wxString&  
	 * \param const wxBitmap&  
	 * \param const wxBitmap&  
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param wxObject*   
	*/

  wxToolBarTool* AddRadioTool(int  toolId , const wxString&  label , const wxBitmap&  bitmap1 , const wxBitmap&  bitmap2 , const wxString&  shortHelpString = wxT(""), const wxString&  longHelpString = wxT(""), wxObject*  clientData = NULL) ;
	/**
	 * \brief Removes the specified tool from the toolbar and deletes it. If you don't want
to delete the tool, but just to remove it from the toolbar (to possibly add it
back later), you may use   instead.

Note that it is unnecessary to call   for the
change to take place, it will happen immediately.

Returns true if the tool was deleted, false otherwise. 
	 * \param int   
	*/

  bool DeleteTool(int  toolId ) ;
	/**
	 * \brief This function behaves like   but it
deletes the tool at the specified position and not the one with the given id. 
	 * \param size_t   
	*/

  bool DeleteToolByPos(size_t  pos ) ;
	/**
	 * \brief Enables or disables the tool.







  This function should only be called after 
 . 
	 * \param int   
	 * \param const bool  
	*/

  void EnableTool(int  toolId , const bool  enable ) ;
	/**
	 * \brief Returns a pointer to the control identified by   or
NULL if no corresponding control is found. 
	 * \param int   
	*/

  wxControl* FindControl(int  id ) ;
	/**
	 * \brief Finds a tool for the given mouse position. 
	 * \param const float  
	 * \param const float  
	*/

  wxToolBarTool* FindToolForPosition(const float  x , const float  y ) const;
	/**
	 * \brief Returns the size of a whole button, which is usually larger than a tool bitmap because
of added 3D effects. 
	*/

  wxSize GetToolSize() ;
	/**
	 * \brief Returns the size of bitmap that the toolbar expects to have. The default bitmap size is 16 by 15 pixels. 
	*/

  wxSize GetToolBitmapSize() ;
	/**
	 * \brief Returns the left/right and top/bottom margins, which are also used for inter-toolspacing. 
	*/

  wxSize GetMargins() const;
	/**
	 * \brief Get any client data associated with the tool. 
	 * \param int   
	*/

  wxObject* GetToolClientData(int  toolId ) const;
	/**
	 * \brief Called to determine whether a tool is enabled (responds to user input). 
	 * \param int   
	*/

  bool GetToolEnabled(int  toolId ) const;
	/**
	 * \brief Returns the long help for the given tool. 
	 * \param int   
	*/

  wxString GetToolLongHelp(int  toolId ) const;
	/**
	 * \brief Returns the value used for packing tools. 
	*/

  int GetToolPacking() const;
	/**
	 * \brief Returns the tool position in the toolbar, or wxNOT_FOUND if the tool is not found. 
	 * \param int   
	*/

  //int GetToolPos(int  toolId ) const;
	/**
	 * \brief Returns the default separator size. 
	*/

  int GetToolSeparation() const;
	/**
	 * \brief Returns the short help for the given tool. 
	 * \param int   
	*/

  wxString GetToolShortHelp(int  toolId ) const;
	/**
	 * \brief Gets the on/off state of a toggle tool. 
	 * \param int   
	*/

  bool GetToolState(int  toolId ) const;
	/**
	 * \brief Inserts the control into the toolbar at the given position.

You must call   for the change to take place. 
	 * \param size_t   
	 * \param wxControl *  
	*/

  wxToolBarTool * InsertControl(size_t  pos , wxControl * control ) ;
	/**
	 * \brief Inserts the separator into the toolbar at the given position.

You must call   for the change to take place. 
	 * \param size_t   
	*/

  wxToolBarTool * InsertSeparator(size_t  pos ) ;
	/**
	 * \brief  
	 * \param size_t   
	 * \param int  
	 * \param const wxBitmap&  
	 * \param const wxBitmap&  
	 * \param bool  
	 * \param wxObject*   
	 * \param const wxString&   
	 * \param const wxString&   
	*/

  wxToolBarTool * InsertTool(size_t  pos , int  toolId , const wxBitmap&  bitmap1 , const wxBitmap& bitmap2 = wxNullBitmap, bool isToggle = false, wxObject*  clientData = NULL, const wxString&  shortHelpString = wxT(""), const wxString&  longHelpString = wxT("")) ;
	/**
	 * \brief Inserts the tool with the specified attributes into the toolbar at the given
position.

You must call   for the change to take place. 
	 * \param size_t   
	 * \param wxToolBarTool*   
	*/

  //wxToolBarTool * InsertTool(size_t  pos , wxToolBarTool*  tool );
	/**
	 * \brief Called when the user clicks on a tool with the left mouse button.

This is the old way of detecting tool clicks; although it will still work,
you should use the EVT_MENU or EVT_TOOL macro instead. 
	 * \param int  
	 * \param bool  
	*/

  virtual bool OnLeftClick(int  toolId , bool  toggleDown ) ;
	/**
	 * \brief This is called when the mouse cursor moves into a tool or out of
the toolbar.

This is the old way of detecting mouse enter events; although it will still work,
you should use the EVT_TOOL_ENTER macro instead. 
	 * \param int  
	*/

  virtual void OnMouseEnter(int  toolId ) ;
	/**
	 * \brief Called when the user clicks on a tool with the right mouse button. The
programmer should override this function to detect right tool clicks.

This is the old way of detecting tool right clicks; although it will still work,
you should use the EVT_TOOL_RCLICKED macro instead. 
	 * \param int  
	 * \param float  
	 * \param float  
	*/

  virtual void OnRightClick(int  toolId , float  x , float  y ) ;
	/**
	 * \brief This function should be called after you have added tools.

If you are using absolute positions for your tools when using a wxToolBarSimple object,
do not call this function. You must call it at all other times. 
	*/

  bool Realize() ;
	/**
	 * \brief Removes the given tool from the toolbar but doesn't delete it. This allows to
insert/add this tool back to this (or another) toolbar later.

Note that it is unnecessary to call   for the
change to take place, it will happen immediately. 
	 * \param int   
	*/

  wxToolBarTool * RemoveTool(int  id ) ;
	/**
	 * \brief  
	 * \param const wxSize&  
	*/

  void SetMargins(const wxSize&  size ) ;
	/**
	 * \brief  
	 * \param int  
	 * \param int  
	*/

  void SetMargins(int  x , int  y ) ;
	/**
	 * \brief Sets the default size of each tool bitmap. The default bitmap size is 16 by 15 pixels. 
	 * \param const wxSize&  
	*/

  void SetToolBitmapSize(const wxSize&  size ) ;
	/**
	 * \brief Sets the client data associated with the tool. 
	 * \param int   
	 * \param wxObject*   
	*/

  void SetToolClientData(int  id , wxObject*  clientData ) ;
	/**
	 * \brief Sets the long help for the given tool. 
	 * \param int   
	 * \param const wxString&   
	*/

  void SetToolLongHelp(int  toolId , const wxString&  helpString ) ;
	/**
	 * \brief Sets the value used for spacing tools. The default value is 1. 
	 * \param int  
	*/

  void SetToolPacking(int  packing ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param const wxString&   
	*/

  void SetToolShortHelp(int  toolId , const wxString&  helpString ) ;
	/**
	 * \brief Sets the default separator size. The default value is 5. 
	 * \param int  
	*/

  void SetToolSeparation(int  separation ) ;
	/**
	 * \brief Toggles a tool on or off. This does not cause any event to get emitted. 
	 * \param int   
	 * \param const bool  
	*/

  void ToggleTool(int  toolId , const bool  toggle ) ;
  // the following were missing from the xml
  void SetRows(int rows);
};


#endif
