// wxToolBar.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

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
  wxToolBarTool* AddTool(int  toolId , const wxString&  label , const wxBitmap&  bitmap1 , const wxString&  shortHelpString = "", wxItemKind kind = wxITEM_NORMAL) ;
  wxToolBarTool* AddTool(int  toolId , const wxString&  label , const wxBitmap&  bitmap1 , const wxBitmap& bitmap2 = wxNullBitmap, wxItemKind kind = wxITEM_NORMAL, const wxString&  shortHelpString = "", const wxString&  longHelpString = "", wxObject*  clientData = NULL) ;
  //wxToolBarTool* AddTool(wxToolBarTool*  tool );
  wxToolBarTool* AddCheckTool(int  toolId , const wxString&  label , const wxBitmap&  bitmap1 , const wxBitmap&  bitmap2 , const wxString&  shortHelpString = "", const wxString&  longHelpString = "", wxObject*  clientData = NULL) ;
  wxToolBarTool* AddRadioTool(int  toolId , const wxString&  label , const wxBitmap&  bitmap1 , const wxBitmap&  bitmap2 , const wxString&  shortHelpString = "", const wxString&  longHelpString = "", wxObject*  clientData = NULL) ;
  bool DeleteTool(int  toolId ) ;
  bool DeleteToolByPos(size_t  pos ) ;
  void EnableTool(int  toolId , const bool  enable ) ;
  wxControl* FindControl(int  id ) ;
  wxToolBarTool* FindToolForPosition(const float  x , const float  y ) const;
  wxSize GetToolSize() ;
  wxSize GetToolBitmapSize() ;
  wxSize GetMargins() const;
  wxObject* GetToolClientData(int  toolId ) const;
  bool GetToolEnabled(int  toolId ) const;
  wxString GetToolLongHelp(int  toolId ) const;
  int GetToolPacking() const;
  //int GetToolPos(int  toolId ) const;
  int GetToolSeparation() const;
  wxString GetToolShortHelp(int  toolId ) const;
  bool GetToolState(int  toolId ) const;
  wxToolBarTool * InsertControl(size_t  pos , wxControl * control ) ;
  wxToolBarTool * InsertSeparator(size_t  pos ) ;
  wxToolBarTool * InsertTool(size_t  pos , int  toolId , const wxBitmap&  bitmap1 , const wxBitmap& bitmap2 = wxNullBitmap, bool isToggle = false, wxObject*  clientData = NULL, const wxString&  shortHelpString = "", const wxString&  longHelpString = "") ;
  //wxToolBarTool * InsertTool(size_t  pos , wxToolBarTool*  tool );
  virtual bool OnLeftClick(int  toolId , bool  toggleDown ) ;
  virtual void OnMouseEnter(int  toolId ) ;
  virtual void OnRightClick(int  toolId , float  x , float  y ) ;
  bool Realize() ;
  wxToolBarTool * RemoveTool(int  id ) ;
  void SetMargins(const wxSize&  size ) ;
  void SetMargins(int  x , int  y ) ;
  void SetToolBitmapSize(const wxSize&  size ) ;
  void SetToolClientData(int  id , wxObject*  clientData ) ;
  void SetToolLongHelp(int  toolId , const wxString&  helpString ) ;
  void SetToolPacking(int  packing ) ;
  void SetToolShortHelp(int  toolId , const wxString&  helpString ) ;
  void SetToolSeparation(int  separation ) ;
  void ToggleTool(int  toolId , const bool  toggle ) ;
  // the following were missing from the xml
  void SetRows(int rows);
};


#endif
