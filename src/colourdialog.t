/**********************************************************************

  colourdialog.t -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

//$$ CLASS ColourDialog : Dialog

//$$ METHODS_BEGIN
	wxColourDialog(wxWindow* parent, wxColourData* data = NULL);
	
	bool Create(wxWindow* parent, wxColourData* data = NULL);
	wxColourData& GetColourData();
	int ShowModal();
//$$ METHODS_END


//$$ BEGIN_H_FILE
#include "wx/colordlg.h"

//$$ RB_DECLARE_CLASS
//$$ END_H_FILE


//$$ BEGIN_CPP_FILE
#include "window.h"
#include "colourdata.h"

//$$ RB_IMPLEMENT_CLASS
//$$ END_CPP_FILE
