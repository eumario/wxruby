#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxWindow

# Not present in wxGTK
%feature("nodirector") wxWindow::SetScrollPage;
%ignore wxWindow::SetScrollPage;
%feature("nodirector") wxWindow::SetScrollRange;
%ignore wxWindow::SetScrollRange;

# Obsolete
%feature("nodirector") wxWindow::SetPalette;
%ignore wxWindow::SetPalette;

%ignore wxWindow::Clear;
%ignore wxWindow::GetAccessible;
%ignore wxWindow::GetTextExtent;
%ignore wxWindow::GetFont;
%ignore wxWindow::GetChildren;
%ignore wxWindow::GetValidator;
%ignore wxWindow::PopEventHandler;
# %ignore wxWindow::SetCaret;

%rename(SetDimensions) wxWindow::SetSize(int  x , int  y , int  width , int  height , int sizeFlags = wxSIZE_AUTO) ;



%include "include/wxWindow.h"

%extend wxWindow {
    VALUE this_should_never_be_called(wxDC *tmp) {
	    return Qnil;
    }

    VALUE paint()
    {   
	   wxWindow *ptr = self;
	
	   if(rb_block_given_p()) 
	   {
	      wxPaintDC dc(ptr);
	      
	      VALUE dcVal = SWIG_NewPointerObj((void *) &dc, SWIGTYPE_p_wxDC, 0);
	      printf("dcVal = %d\n",dcVal);
	      rb_yield(dcVal);
	
	      DATA_PTR(dcVal) = NULL;
	   }
	   return Qnil;	
   
  }
    
}
