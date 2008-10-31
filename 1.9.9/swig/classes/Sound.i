// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxSound
GC_MANAGE_AS_OBJECT(wxSound);

%{
#include <wx/sound.h>
%}

%ignore wxSound::Create;

// SWIG gets confused and only wraps the static method; easier to create
// to the shortcut method in lib/wx/classes/sound.rb
%ignore wxSound::Play(const wxString& filename, unsigned flags = wxSOUND_ASYNC);

#define wxSOUND_SYNC  0
#define wxSOUND_ASYNC 1
#define wxSOUND_LOOP  2

%import "include/wxObject.h"
%include "include/wxSound.h"
