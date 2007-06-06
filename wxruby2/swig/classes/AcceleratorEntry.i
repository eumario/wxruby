// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxAcceleratorEntry
GC_MANAGE(wxAcceleratorEntry);

%{
#include <wx/accel.h>
%}

// wxAcceleratorEntry flags
enum
{
    wxACCEL_NORMAL  = 0x0000,   // no modifiers
    wxACCEL_ALT     = 0x0001,   // hold Alt key down
    wxACCEL_CTRL    = 0x0002,   // hold Ctrl key down
    wxACCEL_SHIFT   = 0x0004    // hold Shift key down
};

%include "include/wxAcceleratorEntry.h"