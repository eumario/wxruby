#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project

%module(directors="1") wx

%include "common.i"

%{


#include <wx/hashmap.h>

WX_DECLARE_VOIDPTR_HASH_MAP(VALUE,GcHashMap);
WX_DECLARE_VOIDPTR_HASH_MAP(bool,DeletedHashMap);

static GcHashMap GcHash;
static DeletedHashMap DeletedHash;
static VALUE GcRubyHash = Qnil;

void GcMapPtrToValue(void *ptr, VALUE val)
{
    if (GcRubyHash == Qnil)
    {
        rb_global_variable(&GcRubyHash);
        GcRubyHash = rb_hash_new();
    }
    rb_hash_aset(GcRubyHash, INT2NUM((int)ptr), val);
}

VALUE GcGetValueFromPtr(void *ptr)
{
    if (GcRubyHash == Qnil)
    {
        rb_global_variable(&GcRubyHash);
        GcRubyHash = rb_hash_new();
    }
    return rb_hash_aref(GcRubyHash, INT2NUM((int)ptr));
}

void GcMarkDeleted(void *ptr)
{
    DeletedHash[ptr] = true;
}

bool GcIsDeleted(void *ptr)
{
    if (DeletedHash.find(ptr) == DeletedHash.end())
        return false;
    else return true;
}

void GcFreefunc(void *)
{

}

%} 

%init %{


    extern void InitializeOtherModules();
    InitializeOtherModules();
%}

#define VERSION_STRING "wxRuby-SWIG 0.0.3"

int wxMessageBox(const wxString& message, const wxString& caption = wxT("Message"), int style = wxOK, wxWindow *parent = NULL, int x = -1, int y = -1);
