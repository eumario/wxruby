// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxToolBarToolBase;
GC_MANAGE_AS_OBJECT(wxToolBarToolBase);

%{
#include <wx/toolbar.h>
%}

#define wxToolBarBase wxToolBar

// Give the class a better name
%rename(ToolBarTool) wxToolBarToolBase;

// This class is an 'opaque handle' so these methods don't actually
// work to change the state; therefore hide them.
%ignore wxToolBarToolBase::Enable;
%ignore wxToolBarToolBase::Toggle;
%ignore wxToolBarToolBase::SetToggle;
%ignore wxToolBarToolBase::SetShortHelp;
%ignore wxToolBarToolBase::SetLongHelp;
%ignore wxToolBarToolBase::SetNormalBitmap;
%ignore wxToolBarToolBase::SetDisabledBitmap;
%ignore wxToolBarToolBase::SetLabel;
%ignore wxToolBarToolBase::SetClientData;
%ignore wxToolBarToolBase::Detach;
%ignore wxToolBarToolBase::Attach;

%import "include/wxObject.h"
%include "include/wxToolBarToolBase.h"
