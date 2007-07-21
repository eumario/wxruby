//  Copyright 2004-2007, wxRuby development team
//  released under the MIT-style wxruby2 license

%module(directors="1") wxruby2

%include "common.i"

%{

#include <wx/gdicmn.h>
#include <wx/image.h>

#include <wx/filesys.h>
#include <wx/fs_zip.h>

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
