#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project

%module(directors="1") wxFunctions

%include "common.i"


%{

#include <wx/image.h>
#include <wx/app.h>
#include <wx/choicdlg.h>


class wxRubyApp
{
public:
	static VALUE app_ptr;
};

void log_message(int argc, VALUE *argv, VALUE self)
{
    VALUE str = rb_f_sprintf(argc, argv);
    wxLogWarning((wxChar *)StringValuePtr(str));

}

void log_status(int argc, VALUE *argv, VALUE self)
{
    if(TYPE(argv[0])==T_DATA) {
        wxFrame *ptr;
        Data_Get_Struct(argv[0], wxFrame, ptr);
        VALUE str = rb_f_sprintf(argc-1, &argv[1]);
        wxLogStatus(ptr,(wxChar *)StringValuePtr(str));
    }
    else {
        VALUE str = rb_f_sprintf(argc, argv);
        wxLogStatus((wxChar *)StringValuePtr(str));
    }

}


static void
log_warning(int argc, VALUE *argv, VALUE self)
{
    VALUE str = rb_f_sprintf(argc, argv);
    wxLogWarning((wxChar *)StringValuePtr(str));
}


static void
log_error(int argc, VALUE *argv, VALUE self)
{
    VALUE str = rb_f_sprintf(argc, argv);
    wxLogError((wxChar *)StringValuePtr(str));
}


static VALUE get_app(VALUE self)
{
    VALUE ret = wxRubyApp::app_ptr;
    
    return ret;
}

static VALUE
wx_yield(VALUE self)
{
    return (wxYield() ? Qtrue : Qfalse);
}




%}

void wxInitAllImageHandlers();

void wxBell();

bool wxYield();

wxString wxGetCwd();

wxString wxGetEmailAddress();

wxString wxGetHostName();

wxString wxGetFullHostName();

wxString wxGetUserId();

wxString wxGetUserName();

wxString wxGetHomeDir();

void wxSetWorkingDirectory(const wxString &);

%typemap(in,numinputs=0) wxArrayInt &selections (wxArrayInt sel)
{
	$1 = &sel;
}

%typemap(argout) wxArrayInt &selections {
  $result = rb_ary_new();
  for (int i = 0; i < $1->GetCount(); i++)
    rb_ary_push($result,INT2NUM((*$1)[i]));
}


size_t wxGetMultipleChoices(wxArrayInt& selections,const wxString& message,const wxString& caption,int n, const wxString choices[],wxWindow *parent = NULL,int x = -1, int y = -1,bool centre = TRUE,int width=150, int height=200);

long wxGetNumberFromUser(  const wxString& message,  const wxString& prompt,  const wxString& caption,  long value,  long min = 0,  long max = 100,  wxWindow *parent = NULL,  const wxPoint& pos = wxDefaultPosition);

wxString wxGetTextFromUser(const wxString& message, const wxString& caption = wxT("Input text"),
const wxString& default_value = wxT(""), wxWindow *parent = NULL);

wxString wxGetPasswordFromUser(const wxString& message, const wxString& caption = wxT("Input text"),
const wxString& default_value = wxT(""), wxWindow *parent = NULL);


wxString wxFileSelector(const wxString& message, const wxString& default_path = wxT(""),const wxString& default_filename = wxT(""), const wxString& default_extension = wxT(""),const wxString& wildcard = wxT("*.*"), int flags = 0, wxWindow *parent = 0,int x = -1, int y = -1);







%init %{
    extern VALUE mWx;
    rb_define_method(mWx, "log_message", VALUEFUNC(log_message), -1);
    rb_define_method(mWx, "log_warning", VALUEFUNC(log_warning), -1);
    rb_define_method(mWx, "log_status", VALUEFUNC(log_status), -1);
    rb_define_method(mWx, "log_error", VALUEFUNC(log_error), -1);
    rb_define_method(mWx, "get_app", VALUEFUNC(get_app), 0);


%}

