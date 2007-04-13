#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%module(directors="1") wxruby2

%include "common.i"

%{


#include <wx/hashmap.h>
#include <wx/gdicmn.h>
#include <wx/image.h>

#include <wx/filesys.h>
#include <wx/fs_zip.h>

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
    rb_hash_aset(GcRubyHash, INT2NUM((long)ptr), val);
}

VALUE GcGetValueFromPtr(void *ptr)
{
    if (GcRubyHash == Qnil)
    {
        rb_global_variable(&GcRubyHash);
        GcRubyHash = rb_hash_new();
    }
    return rb_hash_aref(GcRubyHash, INT2NUM((long)ptr));
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

void GcFreefunc(void *ptr)
{
  SWIG_RubyUnlinkObjects(ptr);
  SWIG_RubyRemoveTracking(ptr);
}

///////////////////////////////////////////////////
extern "C" void Init_wxRubyEventTypes();

%} 

%init %{

    extern void InitializeOtherModules();
    InitializeOtherModules();
    wxInitAllImageHandlers();

	// Load the event type constants
	Init_wxRubyEventTypes();

	// This is needed so HtmlHelp can load docs from a zip file
	wxFileSystem::AddHandler(new wxArchiveFSHandler);
%}

#define VERSION_STRING "wxRuby2"

int wxMessageBox(const wxString& message, const wxString& caption = wxT("Message"), int style = wxOK, wxWindow *parent = NULL, int x = -1, int y = -1);
