/**********************************************************************

  frame.t -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2004 

**********************************************************************/

//$$ CLASS ScrollBar : Control
//$$ NEEDS_WRAPPING_CONSTRUCTOR
//$$ METHODS_BEGIN
	wxScrollBar(wxWindow* parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxSB_HORIZONTAL, const wxValidator& validator = wxDefaultValidator, const wxString& name = "scrollBar")

    bool Create(wxWindow *parent,wxWindowID id,const wxPoint& pos = wxDefaultPosition,const wxSize& size = wxDefaultSize,long style = wxSB_HORIZONTAL,const wxValidator& validator = wxDefaultValidator,const wxString& name = wxScrollBarNameStr);

    // accessors
	int GetThumbPosition();
    int GetThumbSize();
    int GetPageSize();
    int GetRange();

    bool IsVertical();

    void SetThumbPosition(int viewStart);
    void SetScrollbar(int position, int thumbSize,int range, int pageSize,bool refresh = TRUE) = 0;

//$$ METHODS_END

//$$ BEGIN_H_FILE
//$$ RB_DECLARE_CLASS
//$$ END_H_FILE

//$$ BEGIN_CPP_FILE
#include "scrollbar.h"
#include "control.h"
#include "point.h"
#include "window.h"

//$$ RB_IMPLEMENT_CLASS

//$$ END_CPP_FILE