// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxWindow
GC_MANAGE_AS_WINDOW(wxWindow);

enum wxWindowVariant
{
  wxWINDOW_VARIANT_NORMAL, // Normal size
  wxWINDOW_VARIANT_SMALL,  // Smaller size (about 25 % smaller than normal )
  wxWINDOW_VARIANT_MINI,   // Mini size (about 33 % smaller than normal )
  wxWINDOW_VARIANT_LARGE,  // Large size (about 25 % larger than normal )
};

%ignore wxWindow::Clear;
%ignore wxWindow::GetAccessible;
%ignore wxWindow::PopEventHandler;

// A custom method is required to do the correct casting - see below
%ignore wxWindow::GetHandle;

// LayoutConstraints are deprecated and not supported in WxRuby
%ignore wxWindow::SetConstraints;

// only support the variants that return an object
%ignore wxWindow::GetSize(int*  width , int*  height ) const;
%ignore wxWindow::GetPosition(int*  x , int*  y ) const;
%ignore wxWindow::GetScreenPosition(int* x, int* y) const;

%rename(SetDimensions) wxWindow::SetSize(int  x , int  y , int  width , int  height , int sizeFlags = wxSIZE_AUTO) ;

// Any of these following kind of objects become owned by the window
// when passed into Wx, and so will be deleted automatically; using
// DISOWN resets their %freefunc to avoid deleting the object twice
%apply SWIGTYPE *DISOWN {wxCaret* caret};
%apply SWIGTYPE *DISOWN {wxSizer* sizer};
%apply SWIGTYPE *DISOWN {wxToolTip* tip};

%apply int * INOUT { int * x_INOUT, int * y_INOUT }


%include "../shared/get_ruby_window.i"

// Typemap for GetChildren - casts wxObjects to correct ruby wrappers
%typemap(out) wxWindowList& {
  $result = rb_ary_new();

  wxWindowListNode *node = $1->GetFirst();
  while (node)
  {
    wxObject *obj = node->GetData();
    rb_ary_push($result, get_ruby_window_wrapper(obj));
    node = node->GetNext();
  }
}

// This is the instance method - implemented instead in Ruby - see window.rb
%ignore wxWindow::FindWindow;

// These class methods return a wxWindow in C++. If a layout has been
// loaded from XRC, it is possible - even likely - that the C++ object
// is new to Ruby. Therefore, we need to make sure that the object is
// wrapped with the correct Ruby class; by default, SWIG just maps these
// to the base class Wx::Window which won't have the right methods
// see '../shared/get_ruby_window.i'
%ignore wxWindow::FindWindowById;
%ignore wxWindow::FindWindowByName;
%ignore wxWindow::FindWindowByLabel;

// Likewise for these instance methods which return Sizers or Windows
%ignore wxWindow::GetParent;
%ignore wxWindow::GetContainingSizer;
%ignore wxWindow::GetSizer;

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"

// needed for SWIG's knowledge of PaintDC type, for paint() method
%import "include/wxDC.h"
%import "include/wxWindowDC.h"
%import "include/wxPaintDC.h"
%import "include/wxClientDC.h"


%include "include/wxWindow.h"


// Implement various methods %ignore'd above - these are methods which
// require the return value to be wrapped in an appropriate Ruby class
// which is not known in advance. 
// TODO - could these be done with %typemap - without trampling on the ctor?
%extend wxWindow {
  static VALUE find_window_by_id(long  id , wxWindow* parent = NULL)
  {
    VALUE returnVal = Qnil;
    wxObject* obj = wxWindow::FindWindowById(id,parent); 
    returnVal = get_ruby_window_wrapper(obj);
    return returnVal;    
  }  
  
  static VALUE find_window_by_name(const wxString&  name, 
								   wxWindow* parent = NULL)
  {
    VALUE returnVal = Qnil;
	wxObject* obj = wxWindow::FindWindowByName(name,parent); 
    returnVal = get_ruby_window_wrapper(obj);
    return returnVal;    
  }
  
  static VALUE find_window_by_label(const wxString&  label , 
									wxWindow* parent = NULL)
  {
    VALUE returnVal = Qnil;
    wxObject* obj = wxWindow::FindWindowByLabel(label,parent); 
    returnVal = get_ruby_window_wrapper(obj);
    return returnVal;    
  }  

  VALUE get_containing_sizer()
  {
    VALUE returnVal = Qnil;
    wxObject* obj = self->GetContainingSizer(); 
    returnVal = get_ruby_window_wrapper(obj);
    return returnVal;    
  }

  VALUE get_parent()
  {
    VALUE returnVal = Qnil;
    wxObject* obj = self->GetParent(); 
    returnVal = get_ruby_window_wrapper(obj);
    return returnVal;    
  }

  VALUE get_sizer()
  {
    VALUE returnVal = Qnil;
    wxObject* obj = self->GetSizer(); 
    returnVal = get_ruby_window_wrapper(obj);
    return returnVal;    
  }

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
	if ( rb_ivar_get(rb_win, rb_intern("@__painting__") ) == Qtrue ) 
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
}
