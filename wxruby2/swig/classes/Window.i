#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxWindow

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

// Caret set by set_caret becomes owned by C++
%apply SWIGTYPE *DISOWN {wxCaret*  caret};

// Any sizers passed in to wx become owned by C++
%apply SWIGTYPE *DISOWN {wxSizer*  sizer};

%apply int * INOUT { int * x_INOUT, int * y_INOUT }

// Typemap for GetChildren - casts wxObjects to correct ruby wrappers
%typemap(out) wxWindowList& {
  $result = rb_ary_new();

  wxWindowListNode *node = $1->GetFirst();
  while (node)
  {
    wxObject *obj = node->GetData();
    rb_ary_push($result, get_ruby_object(obj));
    node = node->GetNext();
  }
}

// Returns a ruby wrapper around a wxObject whose wx class is not known
// in advance - needed for find_window, get_children etc This is a bit
// complicated because it must check if the ruby object already exists,
// and if not, wrap it in the correct class, and ensure that future
// calls return the same object.
%{
static VALUE get_ruby_object(wxObject *wx_obj)
{
  if ( ! wx_obj ) return Qnil;

  // Get the wx class and the ruby class we are converting into  
  wxString class_name( wx_obj->GetClassInfo()->GetClassName() );
  VALUE r_class;
  if ( class_name.Len() > 2 )
	{
	  r_class = rb_iv_get(mWxruby2, class_name.mb_str() + 2);
	}
  else return Qnil;

  // First, Try fetching a tracked (previously seen) object
  VALUE r_obj = SWIG_RubyInstanceFor(wx_obj);
  if ( r_obj != Qnil ) // Found a tracked object
	{
	  // Check the types match (see SWIG_NewPointerObj)
	  VALUE r_swigtype = rb_iv_get(r_obj, "__swigtype__");
	  if ( r_swigtype != Qnil && rb_obj_is_kind_of(r_obj, r_class) )
		return r_obj;
	}
  
  // Otherwise - no previously tracked object found - so wrap a new one.
  // Get a string with the internal SWIG name tag of the class (eg _p_wxButton)
  char *swigtype = (char *) malloc(3 + class_name.Len() + 1);
  sprintf(swigtype, "_p_%s", (const char *)(class_name.mb_str()));
  
  // Wrap the object, tag its swigtype (core Wx type), and track it
  // Imitates latter part of SWIG_NewPointerObj
  r_obj = Data_Wrap_Struct(r_class, 0, 0, wx_obj);
  rb_iv_set(r_obj, "__swigtype__", rb_str_new2(swigtype));
  SWIG_RubyAddTracking(wx_obj, r_obj);
  
  free((void *) swigtype);
  return r_obj;
}

%}

// This is the instance method - implemented instead in Ruby - see window.rb
%ignore wxWindow::FindWindow;

// These are class methods implemented below by hand so casting of types
// is correct, which is very important when using XRC.
%ignore wxWindow::FindWindowById;
%ignore wxWindow::FindWindowByName;
%ignore wxWindow::FindWindowByLabel;

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"

// needed for SWIG's knowledge of PaintDC type, for paint() method
%import "include/wxDC.h"
%import "include/wxWindowDC.h"
%import "include/wxPaintDC.h"
%import "include/wxClientDC.h"


%include "include/wxWindow.h"

%extend wxWindow {
  static VALUE find_window_by_id(long  id , wxWindow* parent = NULL)
  {
    VALUE returnVal = Qnil;

    wxObject* obj = wxWindow::FindWindowById(id,parent); 
    returnVal = get_ruby_object(obj);
  
    return returnVal;    
  }  
  
  static VALUE find_window_by_name(const wxString&  name , wxWindow* parent = NULL)
  {
    VALUE returnVal = Qnil;
    
    wxObject* obj = wxWindow::FindWindowByName(name,parent); 
    returnVal = get_ruby_object(obj);
  
    return returnVal;    
  }
  
  static VALUE find_window_by_label(const wxString&  label , wxWindow* parent = NULL)
  {
    VALUE returnVal = Qnil;
    
    wxObject* obj = wxWindow::FindWindowByLabel(label,parent); 
    returnVal = get_ruby_object(obj);
  
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
