/**********************************************************************

MDIChildFrame.t

$Author$
    Hand-modified by Kevin Smith
$Date$

**********************************************************************/

//--$$ ABSTRACT
//$$ CLASS MDIChildFrame : Frame
//$$ NEEDS_WRAPPING_CONSTRUCTOR
//$$ NO_CLIENT_DATA

//$$ METHODS_BEGIN
  
  wxMDIChildFrame(wxMDIParentFrame* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString& name = "frame");
  
  void Activate();
#  bool Create(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString& name = "frame");
  void Maximize(bool WXUNUSED(maximize));
  void Restore();

//$$ METHODS_END

//$$ BEGIN_H_FILE
  

    #include <wx/mdi.h>
    

  //$$ RB_DECLARE_CLASS
//$$ END_H_FILE

//$$ BEGIN_CPP_FILE
  //$$ RB_IMPLEMENT_CLASS
//$$ END_CPP_FILE
