/**********************************************************************

MDIParentFrame.t

$Author$
    Hand-modified by Kevin Smith
$Date$

**********************************************************************/

//--$$ ABSTRACT
//$$ CLASS MDIParentFrame : Frame
//$$ NEEDS_WRAPPING_CONSTRUCTOR
//$$ NO_CLIENT_DATA

//$$ METHODS_BEGIN
  
  wxMDIParentFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE | wxVSCROLL | wxHSCROLL, const wxString& name = "frame");
  void ActivateNext();
  void ActivatePrevious();
  void ArrangeIcons();
  void Cascade();
#(1)  bool Create(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE | wxVSCROLL | wxHSCROLL, const wxString& name = "frame");
  virtual wxMDIClientWindow* OnCreateClient();
  virtual void SetToolBar(wxToolBar* toolbar);
#(2)  void SetWindowMenu(wxMenu* menu);
  void Tile();

  // manually added
  wxMDIChildFrame* GetActiveChild() const;
  wxMDIClientWindow* GetClientWindow() const;
  
//$$ METHODS_END
#(1) Not needed
#(2) MSWindows only


//$$ BEGIN_H_FILE
  

    #include <wx/mdi.h>
    

  //$$ RB_DECLARE_CLASS
//$$ END_H_FILE

//$$ BEGIN_CPP_FILE
#include "mdiclientwindow.h"
#include "mdichildframe.h"

  //$$ RB_IMPLEMENT_CLASS
//$$ END_CPP_FILE
