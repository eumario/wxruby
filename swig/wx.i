//  Copyright 2004-2007, wxRuby development team
//  released under the MIT-style wxruby2 license

%module(directors="1") wxruby2

%include "common.i"

%{

#include <wx/gdicmn.h>
#include <wx/image.h>

#include <wx/filesys.h>
#include <wx/fs_zip.h>


// Mapping of known wxRuby classes to SWIG type information
WX_DECLARE_HASH_MAP(VALUE, 
					swig_type_info*, 
					wxIntegerHash,
					wxIntegerEqual,
					SwigTypeHash);

SwigTypeHash Global_Type_Map;

// Record swig_type_info for a wxRuby class; called in class
// initialisation
void wxRuby_SetSwigTypeForClass(VALUE cls, swig_type_info* ty) {
  Global_Type_Map[cls] = ty;
}

// Retrieve swig_type_info for a ruby class - needed by functions which
// wrap objects whose type is not known in advance - eg
// Window#find_window_by_index (see Window.i)
swig_type_info* wxRuby_GetSwigTypeForClass(VALUE cls) {
  return Global_Type_Map[cls];
}

%} 

%include "mark_free_impl.i"

%init %{
    extern void InitializeOtherModules();
    InitializeOtherModules();
    wxInitAllImageHandlers();

	// This is needed so HtmlHelp can load docs from a zip file
	wxFileSystem::AddHandler(new wxArchiveFSHandler);
%}

#define VERSION_STRING "wxRuby2"
