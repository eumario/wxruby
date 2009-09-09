// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxAuiManager
GC_MANAGE_AS_OBJECT(wxAuiManager);

%{
// Workaround for wx's auibar.h incompatibility 2.8.10 with OS X compiler
// Should be fixed by future wxWidgets 
#ifdef __WXMAC__
#define id toolid
#endif

#include <wx/aui/aui.h>
%}

enum wxAuiManagerDock
  {
    wxAUI_DOCK_NONE = 0,
    wxAUI_DOCK_TOP = 1,
    wxAUI_DOCK_RIGHT = 2,
    wxAUI_DOCK_BOTTOM = 3,
    wxAUI_DOCK_LEFT = 4,
    wxAUI_DOCK_CENTER = 5,
    wxAUI_DOCK_CENTRE = wxAUI_DOCK_CENTER
  };

enum wxAuiManagerOption
  {
    wxAUI_MGR_ALLOW_FLOATING           = 1 << 0,
    wxAUI_MGR_ALLOW_ACTIVE_PANE        = 1 << 1,
    wxAUI_MGR_TRANSPARENT_DRAG         = 1 << 2,
    wxAUI_MGR_TRANSPARENT_HINT         = 1 << 3,
    wxAUI_MGR_VENETIAN_BLINDS_HINT     = 1 << 4,
    wxAUI_MGR_RECTANGLE_HINT           = 1 << 5,
    wxAUI_MGR_HINT_FADE                = 1 << 6,
    wxAUI_MGR_NO_VENETIAN_BLINDS_FADE  = 1 << 7,

    wxAUI_MGR_DEFAULT = wxAUI_MGR_ALLOW_FLOATING |
                        wxAUI_MGR_TRANSPARENT_HINT |
                        wxAUI_MGR_HINT_FADE |
                        wxAUI_MGR_NO_VENETIAN_BLINDS_FADE
  };

enum wxAuiPaneDockArtSetting
  {
    wxAUI_DOCKART_SASH_SIZE = 0,
    wxAUI_DOCKART_CAPTION_SIZE = 1,
    wxAUI_DOCKART_GRIPPER_SIZE = 2,
    wxAUI_DOCKART_PANE_BORDER_SIZE = 3,
    wxAUI_DOCKART_PANE_BUTTON_SIZE = 4,
    wxAUI_DOCKART_BACKGROUND_COLOUR = 5,
    wxAUI_DOCKART_SASH_COLOUR = 6,
    wxAUI_DOCKART_ACTIVE_CAPTION_COLOUR = 7,
    wxAUI_DOCKART_ACTIVE_CAPTION_GRADIENT_COLOUR = 8,
    wxAUI_DOCKART_INACTIVE_CAPTION_COLOUR = 9,
    wxAUI_DOCKART_INACTIVE_CAPTION_GRADIENT_COLOUR = 10,
    wxAUI_DOCKART_ACTIVE_CAPTION_TEXT_COLOUR = 11,
    wxAUI_DOCKART_INACTIVE_CAPTION_TEXT_COLOUR = 12,
    wxAUI_DOCKART_BORDER_COLOUR = 13,
    wxAUI_DOCKART_GRIPPER_COLOUR = 14,
    wxAUI_DOCKART_CAPTION_FONT = 15,
    wxAUI_DOCKART_GRADIENT_TYPE = 16
  };

enum wxAuiPaneDockArtGradients
  {
    wxAUI_GRADIENT_NONE = 0,
    wxAUI_GRADIENT_VERTICAL = 1,
    wxAUI_GRADIENT_HORIZONTAL = 2
  };

enum wxAuiPaneButtonState
  {
    wxAUI_BUTTON_STATE_NORMAL = 0,
    wxAUI_BUTTON_STATE_HOVER = 1,
    wxAUI_BUTTON_STATE_PRESSED = 2
  };

enum wxAuiButtonId
  {
    wxAUI_BUTTON_CLOSE = 101,
    wxAUI_BUTTON_MAXIMIZE_RESTORE = 102,
    wxAUI_BUTTON_MINIMIZE = 103,
    wxAUI_BUTTON_PIN = 104,
    wxAUI_BUTTON_OPTIONS = 105,
    wxAUI_BUTTON_WINDOWLIST = 106,
    wxAUI_BUTTON_LEFT = 107,
    wxAUI_BUTTON_RIGHT = 108,
    wxAUI_BUTTON_UP = 109,
    wxAUI_BUTTON_DOWN = 110,
    wxAUI_BUTTON_CUSTOM1 = 201,
    wxAUI_BUTTON_CUSTOM2 = 202,
    wxAUI_BUTTON_CUSTOM3 = 203
};

// A ruby-based subclass of AuiDockArt may provide custom drawing of AUI
// docks. Once set, the DockArt belongs to the AuiManager and will be
// automatically deleted by wxWidgets, so should not be GC'd
%apply SWIGTYPE *DISOWN { wxAuiDockArt* art_provider };

// Any set AuiDockArt ruby object must be protected from GC once set,
// even if it is no longer referenced anywhere else.
%{
  static void mark_wxAuiManager(void *ptr)
  {
    wxAuiManager* mgr = (wxAuiManager*)ptr;
    wxAuiDockArt* art_prov = mgr->GetArtProvider();
    VALUE rb_art_prov = SWIG_RubyInstanceFor( (void *)art_prov );
    rb_gc_mark( rb_art_prov );
  }
%}
%markfunc wxAuiManager "mark_wxAuiManager";

// An alternative is provided below
%ignore wxAuiManager::GetAllPanes;

// Provide a method for iterating over all the constituent panes
%extend wxAuiManager {
  VALUE each_pane() {
	wxAuiPaneInfoArray panes = self->GetAllPanes();
	for (size_t i = 0; i < panes.GetCount(); i++)
	  {
		wxAuiPaneInfo &pi_ref = self->GetPane( panes.Item(i).name );
		wxAuiPaneInfo *pi = (wxAuiPaneInfo*)&pi_ref;
		VALUE r_pi = SWIG_NewPointerObj(pi, SWIGTYPE_p_wxAuiPaneInfo, 0);
		rb_yield(r_pi);
	  }	
	return Qnil;
	}
}


%import "include/wxEvtHandler.h"
%import "include/wxObject.h"

%include "include/wxAuiManager.h"
