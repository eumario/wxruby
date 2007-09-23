// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module wxSound
GC_MANAGE_AS_OBJECT(wxSound);

%{
#include <wx/sound.h>
%}

// disambiguate static method from instance method, otherwise SWIG gets
// confused and only wraps the static method
%rename(PlaySound) wxSound::Play(const wxString& filename, 
								 unsigned flags = wxSOUND_ASYNC);

#define wxSOUND_SYNC  0
#define wxSOUND_ASYNC 1
#define wxSOUND_LOOP  2

%import "include/wxObject.h"
%include "include/wxSound.h"
