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

%ignore wxWindow::GetAccessible;
%ignore wxWindow::GetTextExtent;
%ignore wxWindow::GetFont;
%ignore wxWindow::GetChildren;
%ignore wxWindow::GetValidator;
%ignore wxWindow::PopEventHandler;
%ignore wxWindow::SetCaret;

%include "include/wxWindow.h"


%extend wxWindow {
    VALUE paint()
    {
        static VALUE paintDC = Qnil;
        rb_global_variable(&paintDC);

        if(rb_block_given_p()) 
        {
            // avoid quoted constant inside rb_intern because
            // it will be "fixed" by our post-swig processing
            char* PAINTDC_CLASS = "PaintDC";
            VALUE cPaintDC = rb_ivar_get(mWx, rb_intern(PAINTDC_CLASS));
            
            VALUE rubySelf = SWIG_NewPointerObj((void *) self, SWIGTYPE_p_wxWindow, 0);
            paintDC = rb_funcall(cPaintDC, rb_intern("new"), 1, rubySelf);
            rb_yield(paintDC);
            paintDC = Qnil;
        }
        return Qnil;
    }
}
