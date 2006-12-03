#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxWindow

%ignore wxWindow::Clear;
%ignore wxWindow::GetAccessible;
%ignore wxWindow::GetChildren;
%ignore wxWindow::PopEventHandler;
# %ignore wxWindow::SetCaret;

// LayoutConstraints are deprecated and not supported in WxRuby
%ignore wxWindow::SetConstraints;

// only support the variants that return an object
%ignore wxWindow::GetSize(int*  width , int*  height ) const;
%ignore wxWindow::GetPosition(int*  x , int*  y ) const;

%rename(SetDimensions) wxWindow::SetSize(int  x , int  y , int  width , int  height , int sizeFlags = wxSIZE_AUTO) ;

// Any sizers passed in to wx become owned by C++
%apply SWIGTYPE *DISOWN {wxSizer*  sizer};

%apply int * INOUT { int * x_INOUT, int * y_INOUT }

%{

static VALUE get_ruby_object(wxObject *obj)
{
	if ( ! obj )
	{
	  return Qnil;
	}
	
	VALUE returnVal = Qnil;
	wxString classNameString(obj->GetClassInfo()->GetClassName());
	if(classNameString.Len() > 2)
	{
		VALUE ruby_class = rb_iv_get(mWxruby2, classNameString.mb_str()+2);
		returnVal = Data_Wrap_Struct(ruby_class,0,0,obj);
	}
	
	return returnVal;
}

%}

# These are implemented below by hand so casting of types are correct which is 
# very important when using XRC.
%ignore wxWindow::FindWindow;
%ignore wxWindow::FindWindowById;
%ignore wxWindow::FindWindowByName;
%ignore wxWindow::FindWindowByLabel;

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"

%include "include/wxWindow.h"

%extend wxWindow {
  VALUE find_window(long  id)
  {
    VALUE returnVal = Qnil;
    
    wxObject* obj = self->FindWindow(id); 
    returnVal = get_ruby_object(obj);
  
    return returnVal;    
  }
  
  VALUE find_window(const wxString&  name)
  {
    VALUE returnVal = Qnil;
    
    wxObject* obj = self->FindWindow(name); 
    returnVal = get_ruby_object(obj);
  
    return returnVal;    
  }  
  
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
  
}
