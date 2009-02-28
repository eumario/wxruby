// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxToolBar_h_)
#define _wxToolBar_h_
class wxToolBar : public wxControl
{
public:
   wxToolBar() ;
   wxToolBar(wxWindow*  parent , wxWindowID  id , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxTB_HORIZONTAL, const wxString&  name = wxPanelNameStr) ;
  virtual  ~wxToolBar() ;
  bool AddControl(wxControl*  control ) ;
  void AddSeparator() ;
  wxToolBarToolBase* AddTool(int  toolId , const wxString&  label , const wxBitmap&  bitmap1 , const wxString&  shortHelpString = wxT(""), wxItemKind kind = wxITEM_NORMAL) ;
  wxToolBarToolBase* AddTool(int  toolId , const wxString&  label , const wxBitmap&  bitmap1 , const wxBitmap& bitmap2 = wxNullBitmap, wxItemKind kind = wxITEM_NORMAL, const wxString&  shortHelpString = wxT(""), const wxString&  longHelpString = wxT(""), wxObject*  clientData = NULL) ;
  wxToolBarToolBase* AddTool(wxToolBarToolBase*  tool );
  wxToolBarToolBase* AddCheckTool(int  toolId , const wxString&  label , const wxBitmap&  bitmap1 , const wxBitmap&  bitmap2 , const wxString&  shortHelpString = wxT(""), const wxString&  longHelpString = wxT(""), wxObject*  clientData = NULL) ;
  wxToolBarToolBase* AddRadioTool(int  toolId , const wxString&  label , const wxBitmap&  bitmap1 , const wxBitmap&  bitmap2 , const wxString&  shortHelpString = wxT(""), const wxString&  longHelpString = wxT(""), wxObject*  clientData = NULL) ;
  void ClearTools();
  bool DeleteTool(int  toolId ) ;
  bool DeleteToolByPos(size_t  pos ) ;
  void EnableTool(int  toolId , const bool  enable ) ;
  wxToolBarToolBase* FindById(int  id) ;
  wxControl* FindControl(int  id) ;
  wxToolBarToolBase* FindToolForPosition(wxCoord x, wxCoord y) const;
  int GetToolsCount() ;
  wxSize GetToolSize() ;
  wxSize GetToolBitmapSize() ;
  wxSize GetMargins() const;
  wxObject* GetToolClientData(int  toolId ) const;
  bool GetToolEnabled(int  toolId ) const;
  wxString GetToolLongHelp(int  toolId ) const;
  int GetToolPacking() const;
  int GetToolPos(int  toolId ) const;
  int GetToolSeparation() const;
  wxString GetToolShortHelp(int  toolId ) const;
  bool GetToolState(int  toolId ) const;
  wxToolBarToolBase * InsertControl(size_t  pos , wxControl * control ) ;
  wxToolBarToolBase * InsertSeparator(size_t  pos ) ;
  wxToolBarToolBase * InsertTool(size_t  pos, 
							 int  toolId,
							 const wxString& label,
							 const wxBitmap&  bitmap, 
							 const wxBitmap& bmpDisabled = wxNullBitmap, 
							 wxItemKind kind = wxITEM_NORMAL,
							 const wxString&  shortHelp = wxEmptyString, 
							 const wxString&  longHelp = wxEmptyString,
							 wxObject *clientData = NULL) ;
  wxToolBarToolBase * InsertTool(size_t  pos , wxToolBarToolBase*  tool );
  virtual bool OnLeftClick(int  toolId , bool  toggleDown ) ;
  virtual void OnMouseEnter(int  toolId ) ;
  virtual void OnRightClick(int  toolId , float  x , float  y ) ;
  bool Realize() ;
  wxToolBarToolBase * RemoveTool(int  id ) ;
  void SetMargins(const wxSize&  size ) ;
  void SetMargins(int  x , int  y ) ;
  void SetRows(int rows);
  void SetToolBitmapSize(const wxSize&  size ) ;
  void SetToolClientData(int  id , wxObject*  clientData ) ;
  void SetToolDisabledBitmap(int id, const wxBitmap& bitmap);
  void SetToolLongHelp(int  toolId , const wxString&  helpString ) ;
  void SetToolNormalBitmap(int id, const wxBitmap& bitmap);
  void SetToolPacking(int  packing ) ;
  void SetToolShortHelp(int  toolId , const wxString&  helpString ) ;
  void SetToolSeparation(int  separation ) ;
  void ToggleTool(int  toolId , const bool  toggle ) ;
};


#endif
