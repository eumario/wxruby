// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%module(directors="1") wxFunctions
%include "common.i"

// This file defines a set of top-level functions used across the
// wxLibrary:
// * shortcut methods for displaying simple dialogs
// * logging functions
// * the xrcid macro

%{
//NO_CLASS - This tells fixmodule not to expect a class


#include <wx/image.h>
#include <wx/app.h>
#include <wx/choicdlg.h>
#include <wx/numdlg.h>
#include <wx/xrc/xmlres.h>
#include <wx/utils.h>

class wxRubyApp
{
public:

};

void log_message(int argc, VALUE *argv, VALUE self)
{
    VALUE str = rb_f_sprintf(argc, argv);
    wxLogMessage(wxString(StringValuePtr(str), wxConvUTF8));

}

void log_status(int argc, VALUE *argv, VALUE self)
{
    if(TYPE(argv[0])==T_DATA) {
        wxFrame *ptr;
        Data_Get_Struct(argv[0], wxFrame, ptr);
        VALUE str = rb_f_sprintf(argc-1, &argv[1]);
        wxLogStatus(ptr,wxString(StringValuePtr(str), wxConvUTF8));
    }
    else {
        VALUE str = rb_f_sprintf(argc, argv);
        wxLogStatus(wxString(StringValuePtr(str), wxConvUTF8));
    }

}


static void
log_warning(int argc, VALUE *argv, VALUE self)
{
    VALUE str = rb_f_sprintf(argc, argv);
    wxLogWarning(wxString(StringValuePtr(str), wxConvUTF8));
}


static void
log_error(int argc, VALUE *argv, VALUE self)
{
    VALUE str = rb_f_sprintf(argc, argv);
    wxLogError(wxString(StringValuePtr(str), wxConvUTF8));
}


static VALUE get_app(VALUE self)
{
  return rb_const_get(mWxruby2, rb_intern("THE_APP"));
}

static VALUE
wx_yield(VALUE self)
{
    return (wxYield() ? Qtrue : Qfalse);
}

static VALUE 
xrcid(VALUE self,VALUE str_id)  
{
  wxString temp(StringValuePtr(str_id), wxConvUTF8);
  int ret = wxXmlResource::GetXRCID(temp);
  return INT2NUM(ret);
}
%} // end of Header code


// All the functions which take a parent argument in this file display
// dialogs, so the parent argument can be nil (which is not permitted in
// the normal typemap defined in typemap.i). So override the standard
// typemap and just check that the App has been started.
%typemap(check) wxWindow* parent {
  if ( ! rb_const_defined(mWxruby2, rb_intern("THE_APP") ) )
	{ rb_raise(rb_eRuntimeError,
			   "Cannot display dialog before App.main_loop has been called");}
}


// All the functions in here are static, so free-ing of wxString
// arguments needs to be adjusted to be "-1" instead of "-2" avoid
// crashes. This is because there is no "self" argument in the C++ arg
// list. See typemap.i for more info.
%typemap(freearg) wxString & "if ( argc > $argnum - 1 ) delete $1;"
%typemap(freearg) wxString* "if ( argc > $argnum - 1 ) delete $1;"


void wxBeginBusyCursor(wxCursor *cursor = wxHOURGLASS_CURSOR);
void wxEndBusyCursor();
void wxBell();
bool wxYield();

void wxInitAllImageHandlers();

wxString wxGetCwd();
wxString wxGetEmailAddress();
wxString wxGetHostName();
wxString wxGetFullHostName();
wxString wxGetUserId();
wxString wxGetUserName();
wxString wxGetHomeDir();
void wxSetWorkingDirectory(const wxString &);

bool wxGetKeyState(wxKeyCode key);

int wxMessageBox(const wxString& message, 
				 const wxString& caption = wxT("Message"), 
				 int style = wxOK, 
				 wxWindow *parent = NULL, 
				 int x = -1, 
				 int y = -1);

// Fix selections to be the return value to ruby
%include "shared/arrayint_selections.i"
size_t wxGetMultipleChoices(wxArrayInt& selections,
							const wxString& message,
							const wxString& caption,int n, 
							const wxString choices[],
							wxWindow *parent = NULL,
							int x = -1, 
							int y = -1,
							bool centre = TRUE,
							int width=150, 
							int height=200);
long wxGetNumberFromUser(const wxString& message, 
						 const wxString& prompt,  
						 const wxString& caption, 
						 long value, long min = 0, long max = 100, 
						 wxWindow *parent = NULL, 
						 const wxPoint& pos = wxDefaultPosition);
wxString wxGetTextFromUser(const wxString& message, 
						   const wxString& caption = wxT("Input text"),
						   const wxString& default_value = wxT(""), 
						   wxWindow *parent = NULL);
wxString wxGetPasswordFromUser(const wxString& message, 
							   const wxString& caption = wxT("Input text"),
							   const wxString& default_value = wxT(""), 
							   wxWindow *parent = NULL);
wxString wxFileSelector(const wxString& message, 
						const wxString& default_path = wxT(""),
						const wxString& default_filename = wxT(""), 
						const wxString& default_extension = wxT(""),
						const wxString& wildcard = wxT("*.*"), 
						int flags = 0, 
						wxWindow *parent = 0,
						int x = -1, 
						int y = -1);

int wxDisplayDepth();
void wxDisplaySize(int *width, int *height);
wxSize wxGetDisplaySize();
void wxDisplaySizeMM(int *width, int *height);
wxSize wxGetDisplaySizeMM();

%init %{
    rb_define_module_function(mWxruby2, "log_message", VALUEFUNC(log_message), -1);
    rb_define_module_function(mWxruby2, "log_warning", VALUEFUNC(log_warning), -1);
    rb_define_module_function(mWxruby2, "log_status", VALUEFUNC(log_status), -1);
    rb_define_module_function(mWxruby2, "log_error", VALUEFUNC(log_error), -1);
    rb_define_module_function(mWxruby2, "get_app", VALUEFUNC(get_app), 0);
    rb_define_module_function(mWxruby2, "xrcid", VALUEFUNC(xrcid), 1);
%}
