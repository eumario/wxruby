// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxStyledTextEvent
GC_MANAGE_AS_EVENT(wxStyledTextEvent);

%{
#include <wx/stc/stc.h>
%}

enum {
  wxEVT_STC_CHANGE,
  wxEVT_STC_STYLENEEDED,
  wxEVT_STC_CHARADDED,
  wxEVT_STC_SAVEPOINTREACHED,
  wxEVT_STC_SAVEPOINTLEFT,
  wxEVT_STC_ROMODIFYATTEMPT,
  wxEVT_STC_KEY,
  wxEVT_STC_DOUBLECLICK,
  wxEVT_STC_UPDATEUI,
  wxEVT_STC_MODIFIED,
  wxEVT_STC_MACRORECORD,
  wxEVT_STC_MARGINCLICK,
  wxEVT_STC_NEEDSHOWN,
  wxEVT_STC_PAINTED,
  wxEVT_STC_USERLISTSELECTION,
  wxEVT_STC_URIDROPPED,
  wxEVT_STC_DWELLSTART,
  wxEVT_STC_DWELLEND,
  wxEVT_STC_START_DRAG,
  wxEVT_STC_DRAG_OVER,
  wxEVT_STC_DO_DROP,
  wxEVT_STC_ZOOM,
  wxEVT_STC_HOTSPOT_CLICK,
  wxEVT_STC_HOTSPOT_DCLICK,
  wxEVT_STC_CALLTIP_CLICK,
  wxEVT_STC_AUTOCOMP_SELECTION
};

%import "include/wxObject.h"
%import "include/wxEvent.h"
%import "include/wxCommandEvent.h"

%include "include/wxStyledTextEvent.h"

