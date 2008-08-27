// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxWindow
GC_MANAGE_AS_WINDOW(wxWindow);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxWindow);

enum wxWindowVariant
{
  wxWINDOW_VARIANT_NORMAL, // Normal size
  wxWINDOW_VARIANT_SMALL,  // Smaller size (about 25 % smaller than normal )
  wxWINDOW_VARIANT_MINI,   // Mini size (about 33 % smaller than normal )
  wxWINDOW_VARIANT_LARGE,  // Large size (about 25 % larger than normal )
};

// Not supported
%ignore wxWindow::Clear;
%ignore wxWindow::GetAccessible;
%ignore wxWindow::PopEventHandler;

// LayoutConstraints are deprecated and not supported in WxRuby
%ignore wxWindow::SetConstraints;

// These are windows only and work with HWNDs; custom methods are
// required to do the correct casting - see below
%ignore wxWindow::GetHandle;
%ignore wxWindow::AssociateHandle;

// only support the variants that return an Point or Size object
%ignore wxWindow::GetSize(int*  width , int*  height ) const;
%ignore wxWindow::GetPosition(int*  x , int*  y ) const;
%ignore wxWindow::GetScreenPosition(int* x, int* y) const;

%rename(SetDimensions) wxWindow::SetSize(int  x , int  y , int  width , int  height , int sizeFlags = wxSIZE_AUTO) ;

// This is the instance method - implemented instead in Ruby - see window.rb
%ignore wxWindow::FindWindow;

// Any of these following kind of objects become owned by the window
// when passed into Wx, and so will be deleted automatically; using
// DISOWN resets their %freefunc to avoid deleting the object twice
%apply SWIGTYPE *DISOWN {wxCaret* caret};
%apply SWIGTYPE *DISOWN {wxSizer* sizer};
%apply SWIGTYPE *DISOWN {wxToolTip* tip};
%apply SWIGTYPE *DISOWN {wxDropTarget* target};

%apply int * INOUT { int * x_INOUT, int * y_INOUT }

// Typemap for GetChildren - casts wxObjects to correct ruby wrappers
%typemap(out) wxWindowList& {
  $result = rb_ary_new();

  wxWindowList::compatibility_iterator node = $1->GetFirst();
  while (node)
  {
    wxObject *obj = node->GetData();
    rb_ary_push($result, wxRuby_WrapWxObjectInRuby(obj));
    node = node->GetNext();
  }
}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"

// needed for SWIG's knowledge of PaintDC type, for paint() method
%import "include/wxDC.h"
%import "include/wxWindowDC.h"
%import "include/wxPaintDC.h"
%import "include/wxClientDC.h"


%include "include/wxWindow.h"

%extend wxWindow {
  // passes a DC for drawing on Window into a passed ruby block, and
  // ensure that the DC is correctly deleted when drawing is
  // completed. This is important to avoid entering an endless loop of
  // paint events. The DC will be a PaintDC if used within a evt_paint handler
  // (recommended) or else a ClientDC.
  VALUE paint()
  {  
	if ( ! rb_block_given_p() )
	  rb_raise(rb_eArgError, "No block given for Window#paint");

	wxWindow *ptr = self;
	VALUE rb_win = SWIG_RubyInstanceFor(ptr);
	// see if within an evt_paint block - see classes/window.rb
	// if so, supply a PaintDC to the block
	if ( rb_ivar_defined(rb_win, rb_intern("@__painting__") ) == Qtrue ) 
	  {
		wxPaintDC dc(ptr);
		VALUE dcVal = SWIG_NewPointerObj((void *) &dc,SWIGTYPE_p_wxPaintDC, 0);
		rb_yield(dcVal);
		SWIG_RubyRemoveTracking((void *) &dc);
		DATA_PTR(dcVal) = NULL;
	  }
	else // supply a ClientDC
	  {
		wxClientDC dc(ptr);
		VALUE dcVal = SWIG_NewPointerObj((void *) &dc,SWIGTYPE_p_wxClientDC, 0);
		rb_yield(dcVal);
		SWIG_RubyRemoveTracking((void *) &dc);
		DATA_PTR(dcVal) = NULL;
	  }

	return Qnil;
  }

  // Return a window handle as a platform-specific ruby integer
  VALUE get_handle()
  {
	wxWindow *win = self;
    long handle = (long)win->GetHandle();
	return LONG2NUM(handle);
  }

  // Attach a wx Object to an existing Windows handle (MSW only)
  VALUE associate_handle(long handle)
	{
	  WXWidget wx_handle = (WXWidget)handle;
	  $self->AssociateHandle(wx_handle);
	  return Qnil;
	}

}
