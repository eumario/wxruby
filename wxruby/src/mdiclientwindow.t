/**********************************************************************

MDIClientWindow.t

$Author$
    Hand-modified by Kevin Smith
$Date$

**********************************************************************/

//--$$ ABSTRACT
//$$ CLASS MDIClientWindow : Window
//$$ NEEDS_WRAPPING_CONSTRUCTOR
//$$ NO_CLIENT_DATA

//$$ METHODS_BEGIN
  
  wxMDIClientWindow(wxMDIParentFrame* parent, long style = 0);
  bool CreateClient(wxMDIParentFrame* parent, long style = 0);

//$$ METHODS_END

//$$ BEGIN_H_FILE
  

    #include <wx/mdi.h>
    

  //$$ RB_DECLARE_CLASS
//$$ END_H_FILE

//$$ BEGIN_CPP_FILE
  //$$ RB_IMPLEMENT_CLASS
//$$ END_CPP_FILE
