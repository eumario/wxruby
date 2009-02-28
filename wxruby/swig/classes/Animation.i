// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxAnimation
GC_MANAGE_AS_OBJECT(wxAnimation);

%{
#include <wx/animate.h>
%}

enum wxAnimationType
{
    wxANIMATION_TYPE_INVALID,
    wxANIMATION_TYPE_GIF,
    wxANIMATION_TYPE_ANI,
    wxANIMATION_TYPE_ANY
};

// This one is documented and the main constructor, but missing from the
// wx generic headers. So instead it is emulated in ruby.
%ignore wxAnimation(const wxString& name, 
                    wxAnimationType type = wxANIMATION_TYPE_ANY);

%import "include/wxObject.h"
%import "include/wxGDIObject.h"

%include "include/wxAnimation.h"
