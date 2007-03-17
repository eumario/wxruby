// wxGenericDirCtrl.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGenericDirCtrl_h_)
#define _wxGenericDirCtrl_h_
class wxGenericDirCtrl : public wxControl
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxGenericDirCtrl() ;
	/**
	 * \brief Main constructor. 
	 * \param wxWindow*   
	 * \param const wxWindowID   
	 * \param const wxString&   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long   
	 * \param const wxString&   
	 * \param int   
	 * \param const wxString&   
	*/

   wxGenericDirCtrl(wxWindow*  parent , const wxWindowID  id = -1, const wxString&  dir = wxDirDialogDefaultFolderStr, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxDIRCTRL_3D_INTERNAL|wxSUNKEN_BORDER, const wxString&  filter = wxEmptyString, int  defaultFilter = 0, const wxString&  name = wxTreeCtrlNameStr) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxGenericDirCtrl() ;
	/**
	 * \brief Create function for two-step construction. See   for details. 
	 * \param wxWindow*   
	 * \param const wxWindowID   
	 * \param const wxString&   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long   
	 * \param const wxString&   
	 * \param int   
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , const wxWindowID  id = -1, const wxString&  dir = wxDirDialogDefaultFolderStr, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxDIRCTRL_3D_INTERNAL|wxSUNKEN_BORDER, const wxString&  filter = wxEmptyString, int  defaultFilter = 0, const wxString&  name = wxTreeCtrlNameStr) ;
	/**
	 * \brief Initializes variables. 
	*/

  void Init() ;
	/**
	 * \brief Tries to expand as much of the given path as possible, so that the filename or directory is visible in the tree control. 
	 * \param const wxString&   
	*/

  bool ExpandPath(const wxString&  path ) ;
	/**
	 * \brief Gets the default path. 
	*/

  wxString GetDefaultPath() const;
	/**
	 * \brief Gets the currently-selected directory or filename. 
	*/

  wxString GetPath() const;
	/**
	 * \brief Gets selected filename path only (else empty string).

This function doesn't count a directory as a selection. 
	*/

  wxString GetFilePath() const;
	/**
	 * \brief Returns the filter string. 
	*/

  wxString GetFilter() const;
	/**
	 * \brief Returns the current filter index (zero-based). 
	*/

  int GetFilterIndex() const;
	/**
	 * \brief Returns a pointer to the filter list control (if present). 
	*/

  wxDirFilterListCtrl* GetFilterListCtrl() const;
	/**
	 * \brief Returns the root id for the tree control. 
	*/

  wxTreeItemId GetRootId() ;
	/**
	 * \brief Returns a pointer to the tree control. 
	*/

  wxTreeCtrl* GetTreeCtrl() const;
	/**
	 * \brief Sets the default path. 
	 * \param const wxString&   
	*/

  void SetDefaultPath(const wxString&  path ) ;
	/**
	 * \brief Sets the filter string. 
	 * \param const wxString&   
	*/

  void SetFilter(const wxString&  filter ) ;
	/**
	 * \brief Sets the current filter index (zero-based). 
	 * \param int   
	*/

  void SetFilterIndex(int  n ) ;
	/**
	 * \brief Sets the current path. 
	 * \param const wxString&   
	*/

  void SetPath(const wxString&  path ) ;
};


#endif
