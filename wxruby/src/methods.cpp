/**********************************************************************

  module.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

#include "wx.h"
#include "wx/colordlg.h"
#include "evthandler.h"
#include "dialog.h"
#include "colour.h"

VALUE rb_cRbApp;

VALUE WxGetApp(VALUE self)
{
    return rb_cRbApp;
}


static VALUE
WxMessageBox(int argc, VALUE *argv, VALUE self)
{
    wxString message = StringValuePtr(argv[0]);
    wxString caption = "Message";
    int style = wxOK | wxCENTRE;
    wxWindow *parent = NULL;
    int x = -1;
    int y = -1;
    if(argc>1 && TYPE(argv[1])==T_STRING)
      caption = StringValuePtr(argv[1]);
    if(argc>2 && TYPE(argv[2])==T_FIXNUM)
      style = NUM2INT(argv[2]);
    if(argc>3 && TYPE(argv[3])==T_DATA)
    	Data_Get_Struct(self, wxWindow, parent);

    return INT2NUM(wxMessageBox(message,caption,style,parent,x,y));
}

static void
WxBell(VALUE self)
{
    wxBell();
}

static VALUE
WxYield(VALUE self)
{
    return (wxYield() ? Qtrue : Qfalse);
}

static VALUE
WxSetWorkingDirectory(VALUE self,VALUE vd)
{
    return (wxSetWorkingDirectory(StringValuePtr(vd)) ? Qtrue : Qfalse);
}

static VALUE
WxGetCwd(VALUE self)
{
    return rb_str_new2(wxGetCwd());
}

static VALUE
WxGetEmailAddress(VALUE self)
{
    return rb_str_new2(wxGetEmailAddress());
}

static VALUE
WxGetHostName(VALUE self)
{
    return rb_str_new2(wxGetHostName());
}

static VALUE
WxGetFullHostName(VALUE self)
{
    return rb_str_new2(wxGetFullHostName());
}

static VALUE
WxGetUserId(VALUE self)
{
    return rb_str_new2(wxGetUserId());
}

static VALUE
WxGetUserName(VALUE self)
{
    return rb_str_new2(wxGetUserName());
}

static VALUE
WxGetHomeDir(VALUE self)
{
    return rb_str_new2(wxGetHomeDir());
}

static void
WxLogMessage(int argc, VALUE *argv, VALUE self)
{
    VALUE str = rb_f_sprintf(argc, argv);
    wxLogMessage(StringValuePtr(str));
}

static void
WxLogError(int argc, VALUE *argv, VALUE self)
{
    VALUE str = rb_f_sprintf(argc, argv);
    wxLogError(StringValuePtr(str));
}

static void
WxLogWarning(int argc, VALUE *argv, VALUE self)
{
    VALUE str = rb_f_sprintf(argc, argv);
    wxLogWarning(StringValuePtr(str));
}

static void
WxLogStatus(int argc, VALUE *argv, VALUE self)
{
    if(TYPE(argv[0])==T_DATA) {
        wxFrame *ptr;
        Data_Get_Struct(argv[0], wxFrame, ptr);
        VALUE str = rb_f_sprintf(argc-1, &argv[1]);
        wxLogStatus(ptr,StringValuePtr(str));
    }
    else {
        VALUE str = rb_f_sprintf(argc, argv);
        wxLogStatus(StringValuePtr(str));
    }
}

static VALUE
WxGetNumberFromUser(int argc, VALUE *argv, VALUE self)
{
    wxString message = StringValuePtr(argv[0]);
    wxString prompt = StringValuePtr(argv[1]);
    wxString caption = StringValuePtr(argv[2]);
    long value = 0;
    if(argc>3) value = NUM2INT(argv[3]);
    long min = 0;
    if(argc>4) min = NUM2INT(argv[4]);
    long max = 100;
    if(argc>5) max = NUM2INT(argv[5]);
    wxWindow *parent = (wxWindow *)NULL;
    if(argc>6) {
        Data_Get_Struct(argv[6], wxWindow, parent);
    }
    wxPoint pos = wxDefaultPosition;
    if(argc>7) {
        wxPoint *ptr;
        Data_Get_Struct(argv[7], wxPoint, ptr);
        pos = *ptr;
    }
    return INT2NUM(wxGetNumberFromUser(message,prompt,caption,value,min,max,parent,pos));
}

static VALUE
WxGetTextFromUser(int argc, VALUE *argv, VALUE self)
{
    wxString message = StringValuePtr(argv[0]);
    wxString caption = wxGetTextFromUserPromptStr;
    if(argc>1) caption = StringValuePtr(argv[1]);
    wxString default_value = wxEmptyString;
    if(argc>2) default_value = StringValuePtr(argv[2]);
    wxWindow *parent = (wxWindow *)NULL;
    if(argc>3) {
        Data_Get_Struct(argv[3], wxWindow, parent);
    }
    int x = -1;
    if(argc>4) x = NUM2INT(argv[4]);
    int y = -1;
    if(argc>5) x = NUM2INT(argv[5]);
    bool centre = TRUE;
    if(argc>6 && argv[6]==Qfalse) centre = FALSE;
    return rb_str_new2(wxGetTextFromUser(message,caption,default_value,parent,x,y,centre));
}

static VALUE
WxGetPasswordFromUser(int argc, VALUE *argv, VALUE self)
{
    wxString message = StringValuePtr(argv[0]);
    wxString caption = wxGetTextFromUserPromptStr;
    if(argc>1) caption = StringValuePtr(argv[1]);
    wxString default_value = wxEmptyString;
    if(argc>2) default_value = StringValuePtr(argv[2]);
    wxWindow *parent = (wxWindow *)NULL;
    if(argc>3) {
        Data_Get_Struct(argv[3], wxWindow, parent);
    }
    return rb_str_new2(wxGetPasswordFromUser(message,caption,default_value,parent));
}

static VALUE
WxGetSingleChoice(int argc, VALUE *argv, VALUE self)
{
    wxString message = StringValuePtr(argv[0]);
    wxString caption = wxGetTextFromUserPromptStr;
    if(argc>1) caption = StringValuePtr(argv[1]);
    int n;
    wxString *choices;
    n = RARRAY(argv[2])->len;
    choices = new wxString[n];
    for (int i = 0; i < n; i++) {
        choices[i] = StringValuePtr(RARRAY(argv[2])->ptr[i]);
    }
    wxWindow *parent = (wxWindow *)NULL;
    if(argc>3) {
        Data_Get_Struct(argv[3], wxWindow, parent);
    }
    int x = -1;
    if(argc>4) x = NUM2INT(argv[4]);
    int y = -1;
    if(argc>5) y = NUM2INT(argv[5]);
    bool centre = TRUE;
    if(argc>6 && argv[6]==Qfalse) centre = FALSE;
    int width = wxCHOICE_WIDTH;
    if(argc>7) width = NUM2INT(argv[7]);
    int height = wxCHOICE_HEIGHT;
    if(argc>8) height = NUM2INT(argv[8]);

    return rb_str_new2(wxGetSingleChoice(message,caption,n,choices,parent,x,y,centre,width,height));
}

static VALUE
WxGetSingleChoiceIndex(int argc, VALUE *argv, VALUE self)
{
    wxString message = StringValuePtr(argv[0]);
    wxString caption = wxGetTextFromUserPromptStr;
    if(argc>1) caption = StringValuePtr(argv[1]);
    int n;
    wxString *choices;
    n = RARRAY(argv[2])->len;
    choices = new wxString[n];
    for (int i = 0; i < n; i++) {
        choices[i] = StringValuePtr(RARRAY(argv[2])->ptr[i]);
    }
    wxWindow *parent = (wxWindow *)NULL;
    if(argc>3) {
        Data_Get_Struct(argv[3], wxWindow, parent);
    }
    int x = -1;
    if(argc>4) x = NUM2INT(argv[4]);
    int y = -1;
    if(argc>5) y = NUM2INT(argv[5]);
    bool centre = TRUE;
    if(argc>6 && argv[6]==Qfalse) centre = FALSE;
    int width = wxCHOICE_WIDTH;
    if(argc>7) width = NUM2INT(argv[7]);
    int height = wxCHOICE_HEIGHT;
    if(argc>8) height = NUM2INT(argv[8]);

    return INT2NUM(wxGetSingleChoiceIndex(message,caption,n,choices,parent,x,y,centre,width,height));
}

static VALUE
WxGetMultipleChoices(int argc, VALUE *argv, VALUE self)
{
    wxArrayInt selections;
    wxString message = StringValuePtr(argv[0]);
    wxString caption = wxGetTextFromUserPromptStr;
    if(argc>1) caption = StringValuePtr(argv[1]);
    int n,i;
    wxString *choices;
    n = RARRAY(argv[2])->len;
    choices = new wxString[n];
    for (i = 0; i < n; i++) {
        choices[i] = StringValuePtr(RARRAY(argv[2])->ptr[i]);
    }
    wxWindow *parent = (wxWindow *)NULL;
    if(argc>3) {
        Data_Get_Struct(argv[3], wxWindow, parent);
    }
    int x = -1;
    if(argc>4) x = NUM2INT(argv[4]);
    int y = -1;
    if(argc>5) y = NUM2INT(argv[5]);
    bool centre = TRUE;
    if(argc>6 && argv[6]==Qfalse) centre = FALSE;
    int width = wxCHOICE_WIDTH;
    if(argc>7) width = NUM2INT(argv[7]);
    int height = wxCHOICE_HEIGHT;
    if(argc>8) height = NUM2INT(argv[8]);

    int r = wxGetMultipleChoices(selections,message,caption,n,choices,parent,x,y,centre,width,height);
    VALUE ary = rb_ary_new();
    for(i=0;i<r;i++)
        rb_ary_push(ary,INT2NUM(selections[i]));
    return ary;
}

static VALUE
WxCreateFileTipProvider(VALUE self,VALUE vfilename,VALUE vcurrentTip)
{
    wxString filename = StringValuePtr(vfilename);
    size_t currentTip = NUM2INT(vcurrentTip);
    return WxTipProvider::init0(wxCreateFileTipProvider(filename,currentTip));
}

static VALUE
WxShowTip(int argc, VALUE *argv, VALUE self)
{
    wxWindow *parent;
    Data_Get_Struct(argv[0], wxWindow, parent);
    wxTipProvider *tipProvider;
    Data_Get_Struct(argv[1], wxTipProvider, tipProvider);
    bool showAtStartup = TRUE;
    if(argc>2 && argv[2]==Qfalse) showAtStartup = FALSE;
    return (wxShowTip(parent,tipProvider,showAtStartup) ? Qtrue : Qfalse);
}

static VALUE
WxFileSelector(int argc, VALUE *argv, VALUE self)
{
    wxChar *message = (wxChar *)wxFileSelectorPromptStr;
    if(argc>0) message = StringValuePtr(argv[0]);
    wxChar *default_path = NULL;
    if(argc>1) default_path = StringValuePtr(argv[1]);
    wxChar *default_filename = NULL;
    if(argc>2) default_filename = StringValuePtr(argv[2]);
    wxChar *default_extension = NULL;
    if(argc>3) default_extension = StringValuePtr(argv[3]);
    wxChar *wildcard = (wxChar *)wxFileSelectorDefaultWildcardStr;
    if(argc>4) wildcard = StringValuePtr(argv[4]);
    int flags = 0;
    if(argc>5) flags = NUM2INT(argv[5]);
    wxWindow *parent = NULL;
    if(argc>6)
        Data_Get_Struct(argv[6], wxWindow, parent);
    int x = -1;
    if(argc>7) x = NUM2INT(argv[7]);
    int y = -1;
    if(argc>8) y = NUM2INT(argv[8]);

    return rb_str_new2(wxFileSelector(message,default_path,default_filename,default_extension,wildcard,flags,parent,x,y));
}

static VALUE
WxLoadFileSelector(int argc, VALUE *argv, VALUE self)
{
    wxChar *what = StringValuePtr(argv[0]);
    wxChar *extension = StringValuePtr(argv[1]);
    wxChar *default_name = NULL;
    if(argc>2) default_name = StringValuePtr(argv[2]);
    wxWindow *parent = NULL;
    if(argc>3)
        Data_Get_Struct(argv[3], wxWindow, parent);

    return rb_str_new2(wxLoadFileSelector(what,extension,default_name,parent));
}

static VALUE
WxSaveFileSelector(int argc, VALUE *argv, VALUE self)
{
    wxChar *what = StringValuePtr(argv[0]);
    wxChar *extension = StringValuePtr(argv[1]);
    wxChar *default_name = NULL;
    if(argc>2) default_name = StringValuePtr(argv[2]);
    wxWindow *parent = NULL;
    if(argc>3)
        Data_Get_Struct(argv[3], wxWindow, parent);

    return rb_str_new2(wxSaveFileSelector(what,extension,default_name,parent));
}

static VALUE
WxGetColourFromUser(int argc, VALUE *argv, VALUE self)
{
    wxWindow *parent = (wxWindow *)NULL;
    wxColour colInit = wxNullColour;
    if(argc>0)
        Data_Get_Struct(argv[0], wxWindow, parent);
    if(argc>1) {
        wxColour *ptr;
        Data_Get_Struct(argv[1], wxColour, ptr);
        colInit = *ptr;
    }
    return WxColour::init0(wxGetColourFromUser(parent,colInit));
}

void DefineModuleMethods()
{
    rb_define_module_function(GetWxModule(), "message_box", VALUEFUNC(WxMessageBox), -1);
    rb_define_module_function(GetWxModule(), "get_app", VALUEFUNC(WxGetApp), 0);
    rb_define_module_function(GetWxModule(), "bell", VALUEFUNC(WxBell), 0);
    rb_define_module_function(GetWxModule(), "yield", VALUEFUNC(WxYield), 0);
    rb_define_module_function(GetWxModule(), "get_cwd", VALUEFUNC(WxGetCwd), 0);
    rb_define_module_function(GetWxModule(), "get_email_address", VALUEFUNC(WxGetEmailAddress), 0);
    rb_define_module_function(GetWxModule(), "get_host_name", VALUEFUNC(WxGetHostName), 0);
    rb_define_module_function(GetWxModule(), "get_full_host_name", VALUEFUNC(WxGetFullHostName), 0);
    rb_define_module_function(GetWxModule(), "get_user_id", VALUEFUNC(WxGetUserId), 0);
    rb_define_module_function(GetWxModule(), "get_user_name", VALUEFUNC(WxGetUserName), 0);
    rb_define_module_function(GetWxModule(), "get_home_dir", VALUEFUNC(WxGetHomeDir), 0);
    rb_define_module_function(GetWxModule(), "set_working_directory", VALUEFUNC(WxSetWorkingDirectory), 1);
    rb_define_module_function(GetWxModule(), "log_message", VALUEFUNC(WxLogMessage), -1);
    rb_define_module_function(GetWxModule(), "log_error", VALUEFUNC(WxLogError), -1);
    rb_define_module_function(GetWxModule(), "log_warning", VALUEFUNC(WxLogWarning), -1);
    rb_define_module_function(GetWxModule(), "log_status", VALUEFUNC(WxLogStatus), -1);
    rb_define_module_function(GetWxModule(), "get_number_from_user", VALUEFUNC(WxGetNumberFromUser), -1);
    rb_define_module_function(GetWxModule(), "get_text_from_user", VALUEFUNC(WxGetTextFromUser), -1);
    rb_define_module_function(GetWxModule(), "get_password_from_user", VALUEFUNC(WxGetPasswordFromUser), -1);
    rb_define_module_function(GetWxModule(), "get_single_choice_index", VALUEFUNC(WxGetSingleChoiceIndex), -1);
    rb_define_module_function(GetWxModule(), "get_single_choice", VALUEFUNC(WxGetSingleChoice), -1);
    rb_define_module_function(GetWxModule(), "get_multiple_choices", VALUEFUNC(WxGetMultipleChoices), -1);
    rb_define_module_function(GetWxModule(), "create_file_tip_provider", VALUEFUNC(WxCreateFileTipProvider), 2);
    rb_define_module_function(GetWxModule(), "show_tip", VALUEFUNC(WxShowTip), -1);
    rb_define_module_function(GetWxModule(), "file_selector", VALUEFUNC(WxFileSelector), -1);
    rb_define_module_function(GetWxModule(), "load_file_selector", VALUEFUNC(WxLoadFileSelector), -1);
    rb_define_module_function(GetWxModule(), "save_file_selector", VALUEFUNC(WxSaveFileSelector), -1);
    rb_define_module_function(GetWxModule(), "get_colour_from_user", VALUEFUNC(WxGetColourFromUser), -1);

}
