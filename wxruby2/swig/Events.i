#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license
%include "common.i"

%module(directors="1") wxEvents;

%{
//NO_CLASS - This tells fixmodule not to expect a class

#include <wx/calctrl.h>
#include <wx/choicebk.h>
#include <wx/fdrepdlg.h>
#include <wx/notebook.h>
#include <wx/listbook.h>
#include <wx/listctrl.h>
#include <wx/treectrl.h>
#include <wx/dialup.h>
#include <wx/sashwin.h>
#include <wx/taskbar.h>
#include <wx/tabctrl.h>
#include <wx/wizard.h>
#include <wx/splitter.h>
#include <wx/grid.h>
#include <wx/laywin.h>
#include <wx/process.h>
#include <wx/tglbtn.h>

#ifdef WXSCINTILLA
#    include <wx/wxscintilla.h>
#endif
%}


#############################################################################
#### NOTE: Before adding anything below this line, consider whether it really
#### belongs in swig/classes/include/events.rb instead!!!
#############################################################################



%{
extern swig_class cWxEvtHandler;

void internal_connect(VALUE self, int firstId, int lastId, 
                wxEventType eventType);


static VALUE internal_evt_with_id(int argc, VALUE *argv, VALUE self, 
        wxEventType eventType) 
{
    if (argc != 1)
        rb_raise(rb_eArgError, "wrong # of arguments(%d for 1)",argc);
        
    int id = NUM2INT(argv[0]);
    //printf("evt_with_id(%d) %s\n", id, rb_block_given_p() ? "with block" : "");

    internal_connect(self, id, id, eventType);
    return Qnil;
}

static VALUE internal_evt_with_id_range(int argc, VALUE *argv, VALUE self, 
        wxEventType eventType)
{
    if (argc != 2)
        rb_raise(rb_eArgError, "wrong # of arguments(%d for 1)",argc);
        
    int idStart = NUM2INT(argv[0]);
    int idEnd = NUM2INT(argv[1]);
    //printf("evt_with_id(%d) %s\n", id, rb_block_given_p() ? "with block" : "");

    internal_connect(self, idStart, idEnd, eventType);
    return Qnil;
}

static VALUE internal_evt_no_parameters(int argc, VALUE *argv, VALUE self, 
        wxEventType eventType) 
{
    if (argc != 0)
        rb_raise(rb_eArgError, "wrong # of arguments(%d for 0)",argc);
        
    //printf("evt_no_parameters() %s\n", rb_block_given_p() ? "with block" : "");
    internal_connect(self, -1, -1, eventType);
    return Qnil;
}

static VALUE connect_fnc(int argc, VALUE *argv, VALUE self) 
{
    if (argc != 3)
        rb_raise(rb_eArgError, "wrong # of arguments(%d for 3)", argc);

    int id = NUM2INT(argv[0]);
    int lastId = NUM2INT(argv[1]);
    int type = NUM2INT(argv[2]);
    
    internal_connect(self, id, lastId, type);
    return Qnil;
}

%}
