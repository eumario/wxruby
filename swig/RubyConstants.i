#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%module(directors="1") wxRubyConstants

%include "common.i"

%{
//NO_CLASS - This tells fixmodule not to expect a class

#include <wx/gdicmn.h>
#include <wx/fdrepdlg.h>
#include <wx/artprov.h>

//
// All of these exist on only one platform, so in those
// cases I'm defining them so the compiler doesn't freak out
//
#ifndef __WXGTK__
#define    wxCURSOR_DEFAULT 0
#endif
#ifndef __WXMAC__
#define        wxCURSOR_COPY_ARROW 0
#endif
#ifndef __X__
    // Not yet implemented for Windows
#define    wxCURSOR_CROSS_REVERSE 0
#define    wxCURSOR_DOUBLE_ARROW 0
#define    wxCURSOR_BASED_ARROW_UP 0
#define    wxCURSOR_BASED_ARROW_DOWN 0
#endif // X11

%}

enum
{
    wxUNKNOWN_PLATFORM,
    wxCURSES,                 // Text-only CURSES
    wxXVIEW_X,                // Sun's XView OpenLOOK toolkit
    wxMOTIF_X,                // OSF Motif 1.x.x
    wxCOSE_X,                 // OSF Common Desktop Environment
    wxNEXTSTEP,               // NeXTStep
    wxMAC,                    // Apple Mac OS 8/9/X with Mac paths
    wxMAC_DARWIN,             // Apple Mac OS X with Unix paths
    wxBEOS,                   // BeOS
    wxGTK,                    // GTK on X
    wxGTK_WIN32,              // GTK on Win32
    wxGTK_OS2,                // GTK on OS/2
    wxGTK_BEOS,               // GTK on BeOS
    wxGEOS,                   // GEOS
    wxOS2_PM,                 // OS/2 Workplace
    wxWINDOWS,                // Windows or WfW
    wxMICROWINDOWS,           // MicroWindows
    wxPENWINDOWS,             // Windows for Pen Computing
    wxWINDOWS_NT,             // Windows NT
    wxWIN32S,                 // Windows 32S API
    wxWIN95,                  // Windows 95
    wxWIN386,                 // Watcom 32-bit supervisor modus
    wxMGL_UNIX,               // MGL with direct hardware access
    wxMGL_X,                  // MGL on X
    wxMGL_WIN32,              // MGL on Win32
    wxMGL_OS2,                // MGL on OS/2
    wxMGL_DOS,                // MGL on MS-DOS
    wxWINDOWS_OS2,            // Native OS/2 PM
    wxUNIX,                   // wxBase under Unix
    wxX11                     // Plain X11 and Universal widgets
};

// ----------------------------------------------------------------------------
// Geometric flags
// ----------------------------------------------------------------------------

enum wxGeometryCentre
{
    wxCENTRE                  = 0x0001,
    wxCENTER                  = wxCENTRE
};

// centering into frame rather than screen (obsolete)
#define wxCENTER_FRAME          0x0000
// centre on screen rather than parent
#define wxCENTRE_ON_SCREEN      0x0002
// wxCENTER_ON_SCREEN      wxCENTRE_ON_SCREEN

enum wxOrientation
{
    wxHORIZONTAL              = 0x0004,
    wxVERTICAL                = 0x0008,

    wxBOTH                    = (wxVERTICAL | wxHORIZONTAL)
};

enum wxDirection
{
    
    wxRIGHT                   = 0x0020,
    wxUP                      = 0x0040,
    wxDOWN                    = 0x0080,

    wxTOP                     = wxUP,
    wxBOTTOM                  = wxDOWN,

    wxNORTH                   = wxUP,
    wxSOUTH                   = wxDOWN,
    wxWEST                    = wxLEFT,
    wxEAST                    = wxRIGHT,

    wxALL                     = (wxUP | wxDOWN | wxRIGHT | wxLEFT)
};

enum wxAlignment
{
    wxALIGN_NOT               = 0x0000,
    wxALIGN_CENTER_HORIZONTAL = 0x0100,
    wxALIGN_CENTRE_HORIZONTAL = wxALIGN_CENTER_HORIZONTAL,
    wxALIGN_LEFT              = wxALIGN_NOT,
    wxALIGN_TOP               = wxALIGN_NOT,
    wxALIGN_RIGHT             = 0x0200,
    wxALIGN_BOTTOM            = 0x0400,
    wxALIGN_CENTER_VERTICAL   = 0x0800,
    wxALIGN_CENTRE_VERTICAL   = wxALIGN_CENTER_VERTICAL,

    wxALIGN_CENTER            = (wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL),
    wxALIGN_CENTRE            = wxALIGN_CENTER,

    // a mask to extract alignment from the combination of flags
    wxALIGN_MASK              = 0x0f00
};

enum wxStretch
{
    wxSTRETCH_NOT             = 0x0000,
    wxSHRINK                  = 0x1000,
    wxGROW                    = 0x2000,
    wxEXPAND                  = wxGROW,
    wxSHAPED                  = 0x4000,
    wxADJUST_MINSIZE          = 0x8000,
    wxTILE                    = 0xc000
};

// border flags: the values are chosen for backwards compatibility
enum wxBorder
{
    // this is different from wxBORDER_NONE as by default the controls do have
    // border
    wxBORDER_DEFAULT = 0,

    wxBORDER_NONE   = 0x00200000,
    wxBORDER_STATIC = 0x01000000,
    wxBORDER_SIMPLE = 0x02000000,
    wxBORDER_RAISED = 0x04000000,
    wxBORDER_SUNKEN = 0x08000000,
    wxBORDER_DOUBLE = 0x10000000,

    // a mask to extract border style from the combination of flags
    wxBORDER_MASK   = 0x1f200000
};

enum
{
    wxOPEN              = 0x0001,
    wxSAVE              = 0x0002,
    wxOVERWRITE_PROMPT  = 0x0004,
    wxHIDE_READONLY     = 0x0008,
    wxFILE_MUST_EXIST   = 0x0010,
    wxMULTIPLE          = 0x0020,
    wxCHANGE_DIR        = 0x0040
};

// flages used by wxFindDialogEvent::GetFlags()
enum wxFindReplaceFlags
{
    // downward search/replace selected (otherwise - upwards)
    wxFR_DOWN       = 1,

    // whole word search/replace selected
    wxFR_WHOLEWORD  = 2,

    // case sensitive search/replace selected (otherwise - case insensitive)
    wxFR_MATCHCASE  = 4
};

enum wxFindReplaceDialogStyles
{
    // replace dialog (otherwise find dialog)
    wxFR_REPLACEDIALOG = 1,

    // don't allow changing the search direction
    wxFR_NOUPDOWN      = 2,

    // don't allow case sensitive searching
    wxFR_NOMATCHCASE   = 4,

    // don't allow whole word searching
    wxFR_NOWHOLEWORD   = 8
};



// ----------------------------------------------------------------------------
// Window style flags
// ----------------------------------------------------------------------------

/*
 * Values are chosen so they can be |'ed in a bit list.
 * Some styles are used across more than one group,
 * so the values mustn't clash with others in the group.
 * Otherwise, numbers can be reused across groups.
 *
 * From version 1.66:
 * Window (cross-group) styles now take up the first half
 * of the flag, and control-specific styles the
 * second half.
 *
 */

/*
 * Window (Frame/dialog/subwindow/panel item) style flags
 */
#define wxVSCROLL               0x80000000
#define wxHSCROLL               0x40000000
#define wxCAPTION               0x20000000

/*
// New styles (border styles are now in their own enum)
#define wxDOUBLE_BORDER         wxBORDER_DOUBLE
#define wxSUNKEN_BORDER         wxBORDER_SUNKEN
#define wxRAISED_BORDER         wxBORDER_RAISED
#define wxBORDER                wxBORDER_SIMPLE
#define wxSIMPLE_BORDER         wxBORDER_SIMPLE
#define wxSTATIC_BORDER         wxBORDER_STATIC
#define wxNO_BORDER             wxBORDER_NONE
*/

// Override CTL3D etc. control colour processing to allow own background
// colour.
// Override CTL3D or native 3D styles for children
#define wxNO_3D                 0x00800000

// OBSOLETE - use wxNO_3D instead
#define wxUSER_COLOURS          wxNO_3D

// wxALWAYS_SHOW_SB: instead of hiding the scrollbar when it is not needed,
// disable it - but still show (see also wxLB_ALWAYS_SB style)
//
// NB: as this style is only supported by wxUniversal so far as it doesn't use
//     wxUSER_COLOURS/wxNO_3D, we reuse the same style value
#define wxALWAYS_SHOW_SB        0x00800000

// Clip children when painting, which reduces flicker in e.g. frames and
// splitter windows, but can't be used in a panel where a static box must be
// 'transparent' (panel paints the background for it)
#define wxCLIP_CHILDREN         0x00400000

// Note we're reusing the wxCAPTION style because we won't need captions
// for subwindows/controls
#define wxCLIP_SIBLINGS         0x20000000

#define wxTRANSPARENT_WINDOW    0x00100000

// Add this style to a panel to get tab traversal working outside of dialogs
// (on by default for wxPanel, wxDialog, wxScrolledWindow)
#define wxTAB_TRAVERSAL         0x00080000

// Add this style if the control wants to get all keyboard messages (under
// Windows, it won't normally get the dialog navigation key events)
#define wxWANTS_CHARS           0x00040000

// Make window retained (mostly Motif, I think) -- obsolete (VZ)?
#define wxRETAINED              0x00020000
#define wxBACKINGSTORE          wxRETAINED

// set this flag to create a special popup window: it will be always shown on
// top of other windows, will capture the mouse and will be dismissed when the
// mouse is clicked outside of it or if it loses focus in any other way
#define wxPOPUP_WINDOW          0x00020000

// don't invalidate the whole window (resulting in a PAINT event) when the
// window is resized (currently, makes sense for wxMSW only)
#define wxNO_FULL_REPAINT_ON_RESIZE 0x00010000

/*
 * Extra window style flags (use wxWS_EX prefix to make it clear that they
 * should be passed to wxWindow::SetExtraStyle(), not SetWindowStyle())
 */

// by default, TransferDataTo/FromWindow() only work on direct children of the
// window (compatible behaviour), set this flag to make them recursively
// descend into all subwindows
#define wxWS_EX_VALIDATE_RECURSIVELY    0x00000001

// wxCommandEvents and the objects of the derived classes are forwarded to the
// parent window and so on recursively by default. Using this flag for the
// given window allows to block this propagation at this window, i.e. prevent
// the events from being propagated further upwards. The dialogs have this
// flag on by default.
#define wxWS_EX_BLOCK_EVENTS            0x00000002

// don't use this window as an implicit parent for the other windows: this must
// be used with transient windows as otherwise there is the risk of creating a
// dialog/frame with this window as a parent which would lead to a crash if the
// parent is destroyed before the child
#define wxWS_EX_TRANSIENT               0x00000004

// Use this style to add a context-sensitive help to the window (currently for
// Win32 only and it doesn't work if wxMINIMIZE_BOX or wxMAXIMIZE_BOX are used)
#define wxFRAME_EX_CONTEXTHELP  0x00000004
#define wxDIALOG_EX_CONTEXTHELP 0x00000004

/*
 * wxFrame/wxDialog style flags
 */
#define wxSTAY_ON_TOP           0x8000
#define wxICONIZE               0x4000
#define wxMINIMIZE              wxICONIZE
#define wxMAXIMIZE              0x2000
                                        // free flag value: 0x1000
#define wxSYSTEM_MENU           0x0800
#define wxMINIMIZE_BOX          0x0400
#define wxMAXIMIZE_BOX          0x0200
#define wxTINY_CAPTION_HORIZ    0x0100
#define wxTINY_CAPTION_VERT     0x0080
#define wxRESIZE_BORDER         0x0040

#define wxDIALOG_NO_PARENT      0x0001  // Don't make owned by apps top window
#define wxFRAME_NO_TASKBAR      0x0002  // No taskbar button (MSW only)
#define wxFRAME_TOOL_WINDOW     0x0004  // No taskbar button, no system menu
#define wxFRAME_FLOAT_ON_PARENT 0x0008  // Always above its parent
#define wxFRAME_SHAPED          0x0010  // Create a window that is able to be shaped

// deprecated versions defined for compatibility reasons
#define wxRESIZE_BOX            wxMAXIMIZE_BOX
#define wxTHICK_FRAME           wxRESIZE_BORDER

// obsolete styles, unused any more
#define wxDIALOG_MODAL          0x0020  // free flag value 0x0020
#define wxDIALOG_MODELESS       0x0000

/*
 * MDI parent frame style flags
 * Can overlap with some of the above.
 */

#define wxFRAME_NO_WINDOW_MENU  0x0100

#define wxDEFAULT_FRAME_STYLE \
  (wxSYSTEM_MENU | wxRESIZE_BORDER | \
   wxMINIMIZE_BOX | wxMAXIMIZE_BOX | \
   wxCAPTION | wxCLIP_CHILDREN)

#if defined(__WXMSW__) || defined(__WXPM__) || defined(__WXMGL__)
#   define wxDEFAULT_DIALOG_STYLE  (wxSYSTEM_MENU | wxCAPTION)
#else
//  Under Unix, the dialogs don't have a system menu. Specifying wxSYSTEM_MENU
//  here will make a close button appear.
#   define wxDEFAULT_DIALOG_STYLE  wxCAPTION
#endif

/*
 * wxExtDialog style flags
 */
#define wxED_CLIENT_MARGIN      0x0004
#define wxED_BUTTONS_BOTTOM     0x0000  // has no effect
#define wxED_BUTTONS_RIGHT      0x0002
#define wxED_STATIC_LINE        0x0001

#if defined(__WXMSW__) || defined(__WXMAC__)
#   define wxEXT_DIALOG_STYLE  (wxDEFAULT_DIALOG_STYLE|wxED_CLIENT_MARGIN)
#else
#   define wxEXT_DIALOG_STYLE  (wxDEFAULT_DIALOG_STYLE|wxED_CLIENT_MARGIN|wxED_STATIC_LINE)
#endif

/*
 * wxMenuBar style flags
 */
// use native docking
#define wxMB_DOCKABLE       0x0001

/*
 * wxMenu style flags
 */
#define wxMENU_TEAROFF      0x0001

/*
 * Apply to all panel items
 */
#define wxCOLOURED          0x0800
#define wxFIXED_LENGTH      0x0400

/*
 * Styles for wxListBox
 */
#define wxLB_SORT           0x0010
#define wxLB_SINGLE         0x0020
#define wxLB_MULTIPLE       0x0040
#define wxLB_EXTENDED       0x0080
// wxLB_OWNERDRAW is Windows-only
#define wxLB_OWNERDRAW      0x0100
#define wxLB_NEEDED_SB      0x0200
#define wxLB_ALWAYS_SB      0x0400
#define wxLB_HSCROLL        wxHSCROLL
// always show an entire number of rows
#define wxLB_INT_HEIGHT     0x0800

// deprecated synonyms
#define wxPROCESS_ENTER     0x0400  // wxTE_PROCESS_ENTER
#define wxPASSWORD          0x0800  // wxTE_PASSWORD

/*
 * wxComboBox style flags
 */
#define wxCB_SIMPLE         0x0004
#define wxCB_SORT           0x0008
#define wxCB_READONLY       0x0010
#define wxCB_DROPDOWN       0x0020

/*
 * wxRadioBox style flags
 */
// should we number the items from left to right or from top to bottom in a 2d
// radiobox?
#define wxRA_LEFTTORIGHT    0x0001
#define wxRA_TOPTOBOTTOM    0x0002

// New, more intuitive names to specify majorDim argument
#define wxRA_SPECIFY_COLS   0x0004
#define wxRA_SPECIFY_ROWS   0x0008

// Old names for compatibility
#define wxRA_HORIZONTAL     0x0004
#define wxRA_VERTICAL       0x0008

/*
 * wxRadioButton style flag
 */
#define wxRB_GROUP          0x0004
#define wxRB_SINGLE         0x0008

/*
 * wxGauge flags
 */
#define wxGA_HORIZONTAL      0x0004
#define wxGA_VERTICAL        0x0008
#define wxGA_PROGRESSBAR     0x0010
// Windows only
#define wxGA_SMOOTH          0x0020

/*
 * wxSlider flags
 */
#define wxSL_HORIZONTAL      0x0004
#define wxSL_VERTICAL        0x0008
// The next one is obsolete - use scroll events instead
#define wxSL_NOTIFY_DRAG     0x0000
#define wxSL_TICKS           0x0010
#define wxSL_AUTOTICKS       wxSL_TICKS // we don't support manual ticks
#define wxSL_LABELS          0x0020
#define wxSL_LEFT            0x0040
#define wxSL_TOP             0x0080
#define wxSL_RIGHT           0x0100
#define wxSL_BOTTOM          0x0200
#define wxSL_BOTH            0x0400
#define wxSL_SELRANGE        0x0800

/*
 * wxScrollBar flags
 */
#define wxSB_HORIZONTAL      wxHORIZONTAL
#define wxSB_VERTICAL        wxVERTICAL

/*
 * wxSpinButton flags.
 * Note that a wxSpinCtrl is sometimes defined as
 * a wxTextCtrl, and so the flags must be different
 * from wxTextCtrl's.
 */
#define wxSP_HORIZONTAL       wxHORIZONTAL // 4
#define wxSP_VERTICAL         wxVERTICAL   // 8
#define wxSP_ARROW_KEYS       0x1000
#define wxSP_WRAP             0x2000

/*
 * wxSplitterWindow flags
 */
#define wxSP_NOBORDER         0x0000
#define wxSP_NOSASH           0x0010
#define wxSP_BORDER           0x0020
#define wxSP_PERMIT_UNSPLIT   0x0040
#define wxSP_LIVE_UPDATE      0x0080
#define wxSP_3DSASH           0x0100
#define wxSP_3DBORDER         0x0200
#define wxSP_FULLSASH         0x0400
#define wxSP_3D               (wxSP_3DBORDER | wxSP_3DSASH)
#define wxSP_SASH_AQUA        0x0800

/*
 * wxNotebook flags
 */
#define wxNB_FIXEDWIDTH       0x0010
#define wxNB_TOP              0x0000    // default
#define wxNB_LEFT             0x0020
#define wxNB_RIGHT            0x0040
#define wxNB_BOTTOM           0x0080
#define wxNB_MULTILINE        0x0100

/*
 * wxTabCtrl flags
 */
#define wxTC_RIGHTJUSTIFY     0x0010
#define wxTC_FIXEDWIDTH       0x0020
#define wxTC_TOP              0x0000    // default
#define wxTC_LEFT             0x0020
#define wxTC_RIGHT            0x0040
#define wxTC_BOTTOM           0x0080
#define wxTC_MULTILINE        wxNB_MULTILINE
#define wxTC_OWNERDRAW        0x0200

// wxToolBar style flags
#define wxTB_HORIZONTAL     0x0004
#define wxTB_VERTICAL       0x0008
#define wxTB_3DBUTTONS      0x0010
#define wxTB_FLAT           0x0020          // supported only under Win98+/GTK
#define wxTB_DOCKABLE       0x0040          // use native docking under GTK
#define wxTB_NOICONS        0x0080          // don't show the icons
#define wxTB_TEXT           0x0100          // show the text
#define wxTB_NODIVIDER      0x0200          // don't show the divider (Windows)
#define wxTB_NOALIGN        0x0400          // no automatic alignment (Windows)

/*
 * wxStatusBar95 flags
 */
#define wxST_SIZEGRIP         0x0010

/*
 * wxStaticText flags
 */
#define wxST_NO_AUTORESIZE    0x0001

/*
 * wxStaticBitmap flags
 */
#define wxBI_EXPAND           wxEXPAND

/*
 * wxStaticLine flags
 */
#define wxLI_HORIZONTAL         wxHORIZONTAL
#define wxLI_VERTICAL           wxVERTICAL

/*
 * wxProgressDialog flags
 */
#define wxPD_CAN_ABORT          0x0001
#define wxPD_APP_MODAL          0x0002
#define wxPD_AUTO_HIDE          0x0004
#define wxPD_ELAPSED_TIME       0x0008
#define wxPD_ESTIMATED_TIME     0x0010
// wxGA_SMOOTH = 0x0020 may also be used with wxProgressDialog
// NO!!! This is wxDIALOG_MODAL and will cause the progress dialog to
// be modal. No progress will then be made at all.
#define wxPD_REMAINING_TIME     0x0040

/*
 * wxDirDialog styles
 */

#define wxDD_NEW_DIR_BUTTON     0x0080

/*
 * extended dialog specifiers. these values are stored in a different
 * flag and thus do not overlap with other style flags. note that these
 * values do not correspond to the return values of the dialogs (for
 * those values, look at the wxID_XXX defines).
 */

// wxCENTRE already defined as  0x00000001
#define wxYES                   0x00000002
#define wxOK                    0x00000004
#define wxNO                    0x00000008
#define wxYES_NO                (wxYES | wxNO)
#define wxCANCEL                0x00000010

#define wxYES_DEFAULT           0x00000000  // has no effect (default)
#define wxNO_DEFAULT            0x00000080

#define wxICON_EXCLAMATION      0x00000100
#define wxICON_HAND             0x00000200
#define wxICON_WARNING          wxICON_EXCLAMATION
#define wxICON_ERROR            wxICON_HAND
#define wxICON_QUESTION         0x00000400
#define wxICON_INFORMATION      0x00000800
#define wxICON_STOP             wxICON_HAND
#define wxICON_ASTERISK         wxICON_INFORMATION
#define wxICON_MASK             (0x00000100|0x00000200|0x00000400|0x00000800)

#define  wxFORWARD              0x00001000
#define  wxBACKWARD             0x00002000
#define  wxRESET                0x00004000
#define  wxHELP                 0x00008000
#define  wxMORE                 0x00010000
#define  wxSETUP                0x00020000

// ----------------------------------------------------------------------------
// standard IDs
// ----------------------------------------------------------------------------

// any id: means that we don't care about the id, whether when installing an
// event handler or when creating a new window
enum
{
    wxID_ANY = -1
};

// id for a separator line in the menu (invalid for normal item)
enum
{
    wxID_SEPARATOR = -1
};

// Standard menu IDs
enum
{
    wxID_LOWEST = 4999,

    wxID_OPEN,
    wxID_CLOSE,
    wxID_NEW,
    wxID_SAVE,
    wxID_SAVEAS,
    wxID_REVERT,
    wxID_EXIT,
    wxID_UNDO,
    wxID_REDO,
    wxID_HELP,
    wxID_PRINT,
    wxID_PRINT_SETUP,
    wxID_PREVIEW,
    wxID_ABOUT,
    wxID_HELP_CONTENTS,
    wxID_HELP_COMMANDS,
    wxID_HELP_PROCEDURES,
    wxID_HELP_CONTEXT,
    wxID_CLOSE_ALL,

    wxID_CUT = 5030,
    wxID_COPY,
    wxID_PASTE,
    wxID_CLEAR,
    wxID_FIND,
    wxID_DUPLICATE,
    wxID_SELECTALL,

    wxID_FILE1 = 5050,
    wxID_FILE2,
    wxID_FILE3,
    wxID_FILE4,
    wxID_FILE5,
    wxID_FILE6,
    wxID_FILE7,
    wxID_FILE8,
    wxID_FILE9,

    // Standard button IDs
    wxID_OK = 5100,
    wxID_CANCEL,
    wxID_APPLY,
    wxID_YES,
    wxID_NO,
    wxID_STATIC,
    wxID_FORWARD,
    wxID_BACKWARD,
    wxID_DEFAULT,
    wxID_MORE,
    wxID_SETUP,
    wxID_RESET,
    wxID_CONTEXT_HELP,
    wxID_YESTOALL,
    wxID_NOTOALL,
    wxID_ABORT,
    wxID_RETRY,
    wxID_IGNORE,

    // System menu IDs (used by wxUniv):
    wxID_SYSTEM_MENU = 5200,
    wxID_CLOSE_FRAME,
    wxID_MOVE_FRAME,
    wxID_RESIZE_FRAME,
    wxID_MAXIMIZE_FRAME,
    wxID_ICONIZE_FRAME,
    wxID_RESTORE_FRAME,

    // IDs used by generic file dialog (13 consecutive starting from this value)
    wxID_FILEDLGG = 5900,

    wxID_HIGHEST = 5999
};

// ----------------------------------------------------------------------------
// other constants
// ----------------------------------------------------------------------------

// menu and toolbar item kinds
enum wxItemKind
{
    wxITEM_SEPARATOR = -1,
    wxITEM_NORMAL,
    wxITEM_CHECK,
    wxITEM_RADIO,
    wxITEM_MAX
};

// hit test results
enum wxHitTest
{
    wxHT_NOWHERE,

    // scrollbar
    wxHT_SCROLLBAR_FIRST = wxHT_NOWHERE,
    wxHT_SCROLLBAR_ARROW_LINE_1,    // left or upper arrow to scroll by line
    wxHT_SCROLLBAR_ARROW_LINE_2,    // right or down
    wxHT_SCROLLBAR_ARROW_PAGE_1,    // left or upper arrow to scroll by page
    wxHT_SCROLLBAR_ARROW_PAGE_2,    // right or down
    wxHT_SCROLLBAR_THUMB,           // on the thumb
    wxHT_SCROLLBAR_BAR_1,           // bar to the left/above the thumb
    wxHT_SCROLLBAR_BAR_2,           // bar to the right/below the thumb
    wxHT_SCROLLBAR_LAST,

    // window
    wxHT_WINDOW_OUTSIDE,            // not in this window at all
    wxHT_WINDOW_INSIDE,             // in the client area
    wxHT_WINDOW_VERT_SCROLLBAR,     // on the vertical scrollbar
    wxHT_WINDOW_HORZ_SCROLLBAR,     // on the horizontal scrollbar
    wxHT_WINDOW_CORNER,             // on the corner between 2 scrollbars

    wxHT_MAX
};

// ----------------------------------------------------------------------------
// Possible SetSize flags
// ----------------------------------------------------------------------------

// Use internally-calculated width if -1
#define wxSIZE_AUTO_WIDTH       0x0001
// Use internally-calculated height if -1
#define wxSIZE_AUTO_HEIGHT      0x0002
// Use internally-calculated width and height if each is -1
#define wxSIZE_AUTO             (wxSIZE_AUTO_WIDTH|wxSIZE_AUTO_HEIGHT)
// Ignore missing (-1) dimensions (use existing).
// For readability only: test for wxSIZE_AUTO_WIDTH/HEIGHT in code.
#define wxSIZE_USE_EXISTING     0x0000
// Allow -1 as a valid position
#define wxSIZE_ALLOW_MINUS_ONE  0x0004
// Don't do parent client adjustments (for implementation only)
#define wxSIZE_NO_ADJUSTMENTS   0x0008


// VZ: why doesn't it start with "wx"? FIXME
#define IS_HATCH(s)    ((s)>=wxBDIAGONAL_HATCH && (s)<=wxVERTICAL_HATCH)

// Logical ops
typedef enum
{
  wxCLEAR,        wxROP_BLACK = wxCLEAR,             wxBLIT_BLACKNESS = wxCLEAR,        // 0
  wxXOR,          wxROP_XORPEN = wxXOR,              wxBLIT_SRCINVERT = wxXOR,          // src XOR dst
  wxINVERT,       wxROP_NOT = wxINVERT,              wxBLIT_DSTINVERT = wxINVERT,       // NOT dst
  wxOR_REVERSE,   wxROP_MERGEPENNOT = wxOR_REVERSE,  wxBLIT_00DD0228 = wxOR_REVERSE,    // src OR (NOT dst)
  wxAND_REVERSE,  wxROP_MASKPENNOT = wxAND_REVERSE,  wxBLIT_SRCERASE = wxAND_REVERSE,   // src AND (NOT dst)
  wxCOPY,         wxROP_COPYPEN = wxCOPY,            wxBLIT_SRCCOPY = wxCOPY,           // src
  wxAND,          wxROP_MASKPEN = wxAND,             wxBLIT_SRCAND = wxAND,             // src AND dst
  wxAND_INVERT,   wxROP_MASKNOTPEN = wxAND_INVERT,   wxBLIT_00220326 = wxAND_INVERT,    // (NOT src) AND dst
  wxNO_OP,        wxROP_NOP = wxNO_OP,               wxBLIT_00AA0029 = wxNO_OP,         // dst
  wxNOR,          wxROP_NOTMERGEPEN = wxNOR,         wxBLIT_NOTSRCERASE = wxNOR,        // (NOT src) AND (NOT dst)
  wxEQUIV,        wxROP_NOTXORPEN = wxEQUIV,         wxBLIT_00990066 = wxEQUIV,         // (NOT src) XOR dst
  wxSRC_INVERT,   wxROP_NOTCOPYPEN = wxSRC_INVERT,   wxBLIT_NOTSCRCOPY = wxSRC_INVERT,  // (NOT src)
  wxOR_INVERT,    wxROP_MERGENOTPEN = wxOR_INVERT,   wxBLIT_MERGEPAINT = wxOR_INVERT,   // (NOT src) OR dst
  wxNAND,         wxROP_NOTMASKPEN = wxNAND,         wxBLIT_007700E6 = wxNAND,          // (NOT src) OR (NOT dst)
  wxOR,           wxROP_MERGEPEN = wxOR,             wxBLIT_SRCPAINT = wxOR,            // src OR dst
  wxSET,          wxROP_WHITE = wxSET,               wxBLIT_WHITENESS = wxSET           // 1
} form_ops_t;

// Flood styles
enum
{
    wxFLOOD_SURFACE = 1,
    wxFLOOD_BORDER
};

// Polygon filling mode
enum
{
    wxODDEVEN_RULE = 1,
    wxWINDING_RULE
};

// ToolPanel in wxFrame (VZ: unused?)
enum
{
    wxTOOL_TOP = 1,
    wxTOOL_BOTTOM,
    wxTOOL_LEFT,
    wxTOOL_RIGHT
};

// the values of the format constants should be the same as correspondign
// CF_XXX constants in Windows API
enum wxDataFormatId
{
    wxDF_INVALID =          0,
    wxDF_TEXT =             1,  /* CF_TEXT */
    wxDF_BITMAP =           2,  /* CF_BITMAP */
    wxDF_METAFILE =         3,  /* CF_METAFILEPICT */
    wxDF_SYLK =             4,
    wxDF_DIF =              5,
    wxDF_TIFF =             6,
    wxDF_OEMTEXT =          7,  /* CF_OEMTEXT */
    wxDF_DIB =              8,  /* CF_DIB */
    wxDF_PALETTE =          9,
    wxDF_PENDATA =          10,
    wxDF_RIFF =             11,
    wxDF_WAVE =             12,
    wxDF_UNICODETEXT =      13,
    wxDF_ENHMETAFILE =      14,
    wxDF_FILENAME =         15, /* CF_HDROP */
    wxDF_LOCALE =           16,
    wxDF_PRIVATE =          20,
    wxDF_HTML =             30, /* Note: does not correspond to CF_ constant */
    wxDF_MAX
};

// Virtual keycodes
enum wxKeyCode
{
    WXK_BACK    =    8,
    WXK_TAB     =    9,
    WXK_RETURN  =    13,
    WXK_ESCAPE  =    27,
    WXK_SPACE   =    32,
    WXK_DELETE  =    127,

    WXK_START   = 300,
    WXK_LBUTTON,
    WXK_RBUTTON,
    WXK_CANCEL,
    WXK_MBUTTON,
    WXK_CLEAR,
    WXK_SHIFT,
    WXK_ALT,
    WXK_CONTROL,
    WXK_MENU,
    WXK_PAUSE,
    WXK_CAPITAL,
    WXK_PRIOR,  // Page up
    WXK_NEXT,   // Page down
    WXK_END,
    WXK_HOME,
    WXK_LEFT,
    WXK_UP,
    WXK_RIGHT,
    WXK_DOWN,
    WXK_SELECT,
    WXK_PRINT,
    WXK_EXECUTE,
    WXK_SNAPSHOT,
    WXK_INSERT,
    WXK_HELP,
    WXK_NUMPAD0,
    WXK_NUMPAD1,
    WXK_NUMPAD2,
    WXK_NUMPAD3,
    WXK_NUMPAD4,
    WXK_NUMPAD5,
    WXK_NUMPAD6,
    WXK_NUMPAD7,
    WXK_NUMPAD8,
    WXK_NUMPAD9,
    WXK_MULTIPLY,
    WXK_ADD,
    WXK_SEPARATOR,
    WXK_SUBTRACT,
    WXK_DECIMAL,
    WXK_DIVIDE,
    WXK_F1,
    WXK_F2,
    WXK_F3,
    WXK_F4,
    WXK_F5,
    WXK_F6,
    WXK_F7,
    WXK_F8,
    WXK_F9,
    WXK_F10,
    WXK_F11,
    WXK_F12,
    WXK_F13,
    WXK_F14,
    WXK_F15,
    WXK_F16,
    WXK_F17,
    WXK_F18,
    WXK_F19,
    WXK_F20,
    WXK_F21,
    WXK_F22,
    WXK_F23,
    WXK_F24,
    WXK_NUMLOCK,
    WXK_SCROLL,
    WXK_PAGEUP,
    WXK_PAGEDOWN,

    WXK_NUMPAD_SPACE,
    WXK_NUMPAD_TAB,
    WXK_NUMPAD_ENTER,
    WXK_NUMPAD_F1,
    WXK_NUMPAD_F2,
    WXK_NUMPAD_F3,
    WXK_NUMPAD_F4,
    WXK_NUMPAD_HOME,
    WXK_NUMPAD_LEFT,
    WXK_NUMPAD_UP,
    WXK_NUMPAD_RIGHT,
    WXK_NUMPAD_DOWN,
    WXK_NUMPAD_PRIOR,
    WXK_NUMPAD_PAGEUP,
    WXK_NUMPAD_NEXT,
    WXK_NUMPAD_PAGEDOWN,
    WXK_NUMPAD_END,
    WXK_NUMPAD_BEGIN,
    WXK_NUMPAD_INSERT,
    WXK_NUMPAD_DELETE,
    WXK_NUMPAD_EQUAL,
    WXK_NUMPAD_MULTIPLY,
    WXK_NUMPAD_ADD,
    WXK_NUMPAD_SEPARATOR,
    WXK_NUMPAD_SUBTRACT,
    WXK_NUMPAD_DECIMAL,
    WXK_NUMPAD_DIVIDE
};

// Mapping modes (same values as used by Windows, don't change)
enum
{
    wxMM_TEXT = 1,
    wxMM_LOMETRIC,
    wxMM_HIMETRIC,
    wxMM_LOENGLISH,
    wxMM_HIENGLISH,
    wxMM_TWIPS,
    wxMM_ISOTROPIC,
    wxMM_ANISOTROPIC,
    wxMM_POINTS,
    wxMM_METRIC
};

/* Shortcut for easier dialog-unit-to-pixel conversion */
#define wxDLG_UNIT(parent, pt) parent->ConvertDialogToPixels(pt)

/* Paper types */
typedef enum
{
    wxPAPER_NONE,               // Use specific dimensions
    wxPAPER_LETTER,             // Letter, 8 1/2 by 11 inches
    wxPAPER_LEGAL,              // Legal, 8 1/2 by 14 inches
    wxPAPER_A4,                 // A4 Sheet, 210 by 297 millimeters
    wxPAPER_CSHEET,             // C Sheet, 17 by 22 inches
    wxPAPER_DSHEET,             // D Sheet, 22 by 34 inches
    wxPAPER_ESHEET,             // E Sheet, 34 by 44 inches
    wxPAPER_LETTERSMALL,        // Letter Small, 8 1/2 by 11 inches
    wxPAPER_TABLOID,            // Tabloid, 11 by 17 inches
    wxPAPER_LEDGER,             // Ledger, 17 by 11 inches
    wxPAPER_STATEMENT,          // Statement, 5 1/2 by 8 1/2 inches
    wxPAPER_EXECUTIVE,          // Executive, 7 1/4 by 10 1/2 inches
    wxPAPER_A3,                 // A3 sheet, 297 by 420 millimeters
    wxPAPER_A4SMALL,            // A4 small sheet, 210 by 297 millimeters
    wxPAPER_A5,                 // A5 sheet, 148 by 210 millimeters
    wxPAPER_B4,                 // B4 sheet, 250 by 354 millimeters
    wxPAPER_B5,                 // B5 sheet, 182-by-257-millimeter paper
    wxPAPER_FOLIO,              // Folio, 8-1/2-by-13-inch paper
    wxPAPER_QUARTO,             // Quarto, 215-by-275-millimeter paper
    wxPAPER_10X14,              // 10-by-14-inch sheet
    wxPAPER_11X17,              // 11-by-17-inch sheet
    wxPAPER_NOTE,               // Note, 8 1/2 by 11 inches
    wxPAPER_ENV_9,              // #9 Envelope, 3 7/8 by 8 7/8 inches
    wxPAPER_ENV_10,             // #10 Envelope, 4 1/8 by 9 1/2 inches
    wxPAPER_ENV_11,             // #11 Envelope, 4 1/2 by 10 3/8 inches
    wxPAPER_ENV_12,             // #12 Envelope, 4 3/4 by 11 inches
    wxPAPER_ENV_14,             // #14 Envelope, 5 by 11 1/2 inches
    wxPAPER_ENV_DL,             // DL Envelope, 110 by 220 millimeters
    wxPAPER_ENV_C5,             // C5 Envelope, 162 by 229 millimeters
    wxPAPER_ENV_C3,             // C3 Envelope, 324 by 458 millimeters
    wxPAPER_ENV_C4,             // C4 Envelope, 229 by 324 millimeters
    wxPAPER_ENV_C6,             // C6 Envelope, 114 by 162 millimeters
    wxPAPER_ENV_C65,            // C65 Envelope, 114 by 229 millimeters
    wxPAPER_ENV_B4,             // B4 Envelope, 250 by 353 millimeters
    wxPAPER_ENV_B5,             // B5 Envelope, 176 by 250 millimeters
    wxPAPER_ENV_B6,             // B6 Envelope, 176 by 125 millimeters
    wxPAPER_ENV_ITALY,          // Italy Envelope, 110 by 230 millimeters
    wxPAPER_ENV_MONARCH,        // Monarch Envelope, 3 7/8 by 7 1/2 inches
    wxPAPER_ENV_PERSONAL,       // 6 3/4 Envelope, 3 5/8 by 6 1/2 inches
    wxPAPER_FANFOLD_US,         // US Std Fanfold, 14 7/8 by 11 inches
    wxPAPER_FANFOLD_STD_GERMAN, // German Std Fanfold, 8 1/2 by 12 inches
    wxPAPER_FANFOLD_LGL_GERMAN, // German Legal Fanfold, 8 1/2 by 13 inches

    wxPAPER_ISO_B4,             // B4 (ISO) 250 x 353 mm
    wxPAPER_JAPANESE_POSTCARD,  // Japanese Postcard 100 x 148 mm
    wxPAPER_9X11,               // 9 x 11 in
    wxPAPER_10X11,              // 10 x 11 in
    wxPAPER_15X11,              // 15 x 11 in
    wxPAPER_ENV_INVITE,         // Envelope Invite 220 x 220 mm
    wxPAPER_LETTER_EXTRA,       // Letter Extra 9 \275 x 12 in
    wxPAPER_LEGAL_EXTRA,        // Legal Extra 9 \275 x 15 in
    wxPAPER_TABLOID_EXTRA,      // Tabloid Extra 11.69 x 18 in
    wxPAPER_A4_EXTRA,           // A4 Extra 9.27 x 12.69 in
    wxPAPER_LETTER_TRANSVERSE,  // Letter Transverse 8 \275 x 11 in
    wxPAPER_A4_TRANSVERSE,      // A4 Transverse 210 x 297 mm
    wxPAPER_LETTER_EXTRA_TRANSVERSE, // Letter Extra Transverse 9\275 x 12 in
    wxPAPER_A_PLUS,             // SuperA/SuperA/A4 227 x 356 mm
    wxPAPER_B_PLUS,             // SuperB/SuperB/A3 305 x 487 mm
    wxPAPER_LETTER_PLUS,        // Letter Plus 8.5 x 12.69 in
    wxPAPER_A4_PLUS,            // A4 Plus 210 x 330 mm
    wxPAPER_A5_TRANSVERSE,      // A5 Transverse 148 x 210 mm
    wxPAPER_B5_TRANSVERSE,      // B5 (JIS) Transverse 182 x 257 mm
    wxPAPER_A3_EXTRA,           // A3 Extra 322 x 445 mm
    wxPAPER_A5_EXTRA,           // A5 Extra 174 x 235 mm
    wxPAPER_B5_EXTRA,           // B5 (ISO) Extra 201 x 276 mm
    wxPAPER_A2,                 // A2 420 x 594 mm
    wxPAPER_A3_TRANSVERSE,      // A3 Transverse 297 x 420 mm
    wxPAPER_A3_EXTRA_TRANSVERSE // A3 Extra Transverse 322 x 445 mm

} wxPaperSize;

/* Printing orientation */
#ifndef wxPORTRAIT
#define wxPORTRAIT      1
#define wxLANDSCAPE     2
#endif

/* Duplex printing modes
 */

enum wxDuplexMode
{
    wxDUPLEX_SIMPLEX, // Non-duplex
    wxDUPLEX_HORIZONTAL,
    wxDUPLEX_VERTICAL
};

/* Print quality.
 */

#define wxPRINT_QUALITY_HIGH    -1
#define wxPRINT_QUALITY_MEDIUM  -2
#define wxPRINT_QUALITY_LOW     -3
#define wxPRINT_QUALITY_DRAFT   -4

typedef int wxPrintQuality;

/* Print mode (currently PostScript only)
 */

enum wxPrintMode
{
    wxPRINT_MODE_NONE =    0,
    wxPRINT_MODE_PREVIEW = 1,   // Preview in external application
    wxPRINT_MODE_FILE =    2,   // Print to file
    wxPRINT_MODE_PRINTER = 3    // Send to printer
};

// ----------------------------------------------------------------------------
// wxTextCtrl style flags
// ----------------------------------------------------------------------------

// the flag bits 0x0001, and 0x0004 are free but should be used only for the
// things which don't make sense for a text control used by wxTextEntryDialog
// because they would otherwise conflict with wxOK, wxCANCEL, wxCENTRE

#define wxTE_NO_VSCROLL     0x0002
#define wxTE_AUTO_SCROLL    0x0008

#define wxTE_READONLY       0x0010
#define wxTE_MULTILINE      0x0020
#define wxTE_PROCESS_TAB    0x0040

// alignment flags
#define wxTE_LEFT           0x0000                    // 0x0000
#define wxTE_CENTER         wxALIGN_CENTER_HORIZONTAL // 0x0100
#define wxTE_RIGHT          wxALIGN_RIGHT             // 0x0200
#define wxTE_CENTRE         wxTE_CENTER

// this style means to use RICHEDIT control and does something only under wxMSW
// and Win32 and is silently ignored under all other platforms
#define wxTE_RICH           0x0080

#define wxTE_PROCESS_ENTER  0x0400
#define wxTE_PASSWORD       0x0800

// automatically detect the URLs and generate the events when mouse is
// moved/clicked over an URL
//
// this is for Win32 richedit controls only so far
#define wxTE_AUTO_URL       0x1000

// by default, the Windows text control doesn't show the selection when it
// doesn't have focus - use this style to force it to always show it
#define wxTE_NOHIDESEL      0x2000

// use wxHSCROLL to not wrap text at all, wxTE_LINEWRAP to wrap it at any
// position and wxTE_WORDWRAP to wrap at words boundary
#define wxTE_DONTWRAP       wxHSCROLL
#define wxTE_LINEWRAP       0x4000
#define wxTE_WORDWRAP       0x0000  // it's just == !wxHSCROLL

// force using RichEdit version 2.0 or 3.0 instead of 1.0 (default) for
// wxTE_RICH controls - can be used together with or instead of wxTE_RICH
#define wxTE_RICH2          0x8000


// ----------------------------------------------------------------------------
// miscellaneous
// ----------------------------------------------------------------------------

// define this macro if font handling is done using the X font names
#if (defined(__WXGTK__) && !defined(__WXGTK20__)) || defined(__X__)
    #define _WX_X_FONTLIKE
#endif

// macro to specify "All Files" on different platforms
#if defined(__WXMSW__) || defined(__WXPM__)
#   define wxALL_FILES_PATTERN   wxT("*.*")
#   define wxALL_FILES           gettext_noop("All files (*.*)|*.*")
#else
#   define wxALL_FILES_PATTERN   wxT("*")
#   define wxALL_FILES           gettext_noop("All files (*)|*")
#endif

enum wxBitmapType
{
    wxBITMAP_TYPE_INVALID,          // should be == 0 for compatibility!
    wxBITMAP_TYPE_BMP,
    wxBITMAP_TYPE_BMP_RESOURCE,
    wxBITMAP_TYPE_RESOURCE = wxBITMAP_TYPE_BMP_RESOURCE,
    wxBITMAP_TYPE_ICO,
    wxBITMAP_TYPE_ICO_RESOURCE,
    wxBITMAP_TYPE_CUR,
    wxBITMAP_TYPE_CUR_RESOURCE,
    wxBITMAP_TYPE_XBM,
    wxBITMAP_TYPE_XBM_DATA,
    wxBITMAP_TYPE_XPM,
    wxBITMAP_TYPE_XPM_DATA,
    wxBITMAP_TYPE_TIF,
    wxBITMAP_TYPE_TIF_RESOURCE,
    wxBITMAP_TYPE_GIF,
    wxBITMAP_TYPE_GIF_RESOURCE,
    wxBITMAP_TYPE_PNG,
    wxBITMAP_TYPE_PNG_RESOURCE,
    wxBITMAP_TYPE_JPEG,
    wxBITMAP_TYPE_JPEG_RESOURCE,
    wxBITMAP_TYPE_PNM,
    wxBITMAP_TYPE_PNM_RESOURCE,
    wxBITMAP_TYPE_PCX,
    wxBITMAP_TYPE_PCX_RESOURCE,
    wxBITMAP_TYPE_PICT,
    wxBITMAP_TYPE_PICT_RESOURCE,
    wxBITMAP_TYPE_ICON,
    wxBITMAP_TYPE_ICON_RESOURCE,
    wxBITMAP_TYPE_ANI,
    wxBITMAP_TYPE_IFF,
    wxBITMAP_TYPE_MACCURSOR,
    wxBITMAP_TYPE_MACCURSOR_RESOURCE,
    wxBITMAP_TYPE_ANY = 50
};


%constant wxDD_NEW_DIR_BUTTON = 0x0080 
/*
 * Just include the font encodings
 */
// ----------------------------------------------------------------------------
// GDI descriptions
// ----------------------------------------------------------------------------

enum
{
    // Text font families
    wxDEFAULT    = 70,
    wxDECORATIVE,
    wxROMAN,
    wxSCRIPT,
    wxSWISS,
    wxMODERN,
    wxTELETYPE,  /* @@@@ */

    // Proportional or Fixed width fonts (not yet used)
    wxVARIABLE   = 80,
    wxFIXED,

    wxNORMAL     = 90,
    wxLIGHT,
    wxBOLD,
    // Also wxNORMAL for normal (non-italic text)
    wxITALIC,
    wxSLANT,

    // Pen styles
    wxSOLID      =   100,
    wxDOT,
    wxLONG_DASH,
    wxSHORT_DASH,
    wxDOT_DASH,
    wxUSER_DASH,

    wxTRANSPARENT,

    // Brush & Pen Stippling. Note that a stippled pen cannot be dashed!!
    // Note also that stippling a Pen IS meaningfull, because a Line is
    wxSTIPPLE_MASK_OPAQUE, //mask is used for blitting monochrome using text fore and back ground colors
    wxSTIPPLE_MASK,        //mask is used for masking areas in the stipple bitmap (TO DO)
    // drawn with a Pen, and without any Brush -- and it can be stippled.
    wxSTIPPLE =          110,
    wxBDIAGONAL_HATCH,
    wxCROSSDIAG_HATCH,
    wxFDIAGONAL_HATCH,
    wxCROSS_HATCH,
    wxHORIZONTAL_HATCH,
    wxVERTICAL_HATCH,

    wxJOIN_BEVEL =     120,
    wxJOIN_MITER,
    wxJOIN_ROUND,

    wxCAP_ROUND =      130,
    wxCAP_PROJECTING,
    wxCAP_BUTT
};

 
// Standard cursors
enum wxStockCursor
{
    wxCURSOR_NONE,          // should be 0
    wxCURSOR_ARROW,
    wxCURSOR_RIGHT_ARROW,
    wxCURSOR_BULLSEYE,
    wxCURSOR_CHAR,
    wxCURSOR_CROSS,
    wxCURSOR_HAND,
    wxCURSOR_IBEAM,
    wxCURSOR_LEFT_BUTTON,
    wxCURSOR_MAGNIFIER,
    wxCURSOR_MIDDLE_BUTTON,
    wxCURSOR_NO_ENTRY,
    wxCURSOR_PAINT_BRUSH,
    wxCURSOR_PENCIL,
    wxCURSOR_POINT_LEFT,
    wxCURSOR_POINT_RIGHT,
    wxCURSOR_QUESTION_ARROW,
    wxCURSOR_RIGHT_BUTTON,
    wxCURSOR_SIZENESW,
    wxCURSOR_SIZENS,
    wxCURSOR_SIZENWSE,
    wxCURSOR_SIZEWE,
    wxCURSOR_SIZING,
    wxCURSOR_SPRAYCAN,
    wxCURSOR_WAIT,
    wxCURSOR_WATCH,
    wxCURSOR_BLANK,
#ifdef __WXGTK__
    wxCURSOR_DEFAULT, // standard X11 cursor
#endif
#ifdef __WXMAC__
        wxCURSOR_COPY_ARROW , // MacOS Theme Plus arrow
#endif
#ifdef __X__
    // Not yet implemented for Windows
    wxCURSOR_CROSS_REVERSE,
    wxCURSOR_DOUBLE_ARROW,
    wxCURSOR_BASED_ARROW_UP,
    wxCURSOR_BASED_ARROW_DOWN,
#endif // X11
 
    wxCURSOR_ARROWWAIT,
 
    wxCURSOR_MAX
};

#define wxLC_VRULES          0x0001
#define wxLC_HRULES          0x0002

#define wxLC_ICON            0x0004
#define wxLC_SMALL_ICON      0x0008
#define wxLC_LIST            0x0010
#define wxLC_REPORT          0x0020

#define wxLC_ALIGN_TOP       0x0040
#define wxLC_ALIGN_LEFT      0x0080
#define wxLC_AUTOARRANGE     0x0100
#define wxLC_VIRTUAL         0x0200
#define wxLC_EDIT_LABELS     0x0400
#define wxLC_NO_HEADER       0x0800
#define wxLC_NO_SORT_HEADER  0x1000
#define wxLC_SINGLE_SEL      0x2000
#define wxLC_SORT_ASCENDING  0x4000
#define wxLC_SORT_DESCENDING 0x8000

#define wxLC_MASK_TYPE       (wxLC_ICON | wxLC_SMALL_ICON | wxLC_LIST | wxLC_REPORT)
#define wxLC_MASK_ALIGN      (wxLC_ALIGN_TOP | wxLC_ALIGN_LEFT)
#define wxLC_MASK_SORT       (wxLC_SORT_ASCENDING | wxLC_SORT_DESCENDING)

// for compatibility only
#define wxLC_USER_TEXT       wxLC_VIRTUAL


 
#ifndef __WXGTK__
    #define wxCURSOR_DEFAULT wxCURSOR_ARROW
#endif





%constant const wxSize DEFAULT_SIZE = wxDefaultSize;
%constant const wxPoint DEFAULT_POSITION = wxDefaultPosition;

# I don't know why SWIG didn't already handle this--it seems 
# to be confused because the original values were enums
%constant wxBorder wxDOUBLE_BORDER = wxBORDER_DOUBLE;
%constant wxBorder wxSUNKEN_BORDER = wxBORDER_SUNKEN;
%constant wxBorder wxRAISED_BORDER = wxBORDER_RAISED;
%constant wxBorder wxBORDER = wxBORDER_SIMPLE;
%constant wxBorder wxSIMPLE_BORDER = wxBORDER_SIMPLE;
%constant wxBorder wxSTATIC_BORDER = wxBORDER_STATIC;
%constant wxBorder wxNO_BORDER = wxBORDER_NONE;


    // Text font families
%constant int FONTFAMILY_DEFAULT =    wxDEFAULT;
%constant int FONTFAMILY_DECORATIVE =     wxDECORATIVE;
%constant int FONTFAMILY_ROMAN =     wxROMAN;
%constant int FONTFAMILY_SCRIPT =     wxSCRIPT;
%constant int FONTFAMILY_SWISS =    wxSWISS;
%constant int FONTFAMILY_MODERN =     wxMODERN;
%constant int FONTFAMILY_TELETYPE =    wxTELETYPE;  /* @@@@ */

%constant int FONTWEIGHT_NORMAL =     wxNORMAL;
%constant int FONTWEIGHT_LIGHT =     wxLIGHT;
%constant int FONTWEIGHT_BOLD =     wxBOLD;
%constant int FONTSTYLE_NORMAL =     wxNORMAL;
%constant int FONTSTYLE_ITALIC =   wxITALIC;
%constant int FONTSTYLE_SLANT =     wxSLANT;
    // Pen styles
%constant int SOLID       =    wxSOLID;
%constant int DOT         =    wxDOT;
%constant int LONG_DASH   =    wxLONG_DASH;
%constant int SHORT_DASH  =    wxSHORT_DASH;
%constant int DOT_DASH    =    wxDOT_DASH;
%constant int USER_DASH   =    wxUSER_DASH;
%constant int TRANSPARENT =    wxTRANSPARENT;

%constant const char *FILE_SELECTOR_DEFAULT_WILDCARD_STR = "*.*";



%constant const char * ART_TOOLBAR               = wxART_TOOLBAR_C;
%constant const char * ART_MENU                  = wxART_MENU_C;
%constant const char * ART_FRAME_ICON            = wxART_FRAME_ICON_C;
%constant const char * ART_CMN_DIALOG            = wxART_CMN_DIALOG_C;
%constant const char * ART_HELP_BROWSER          = wxART_HELP_BROWSER_C;
%constant const char * ART_MESSAGE_BOX           = wxART_MESSAGE_BOX_C;
%constant const char * ART_OTHER                 = wxART_OTHER_C;

%constant const char * ART_ADD_BOOKMARK          = wxART_ADD_BOOKMARK;
%constant const char * ART_DEL_BOOKMARK          = wxART_DEL_BOOKMARK;
%constant const char * ART_HELP_SIDE_PANEL       = wxART_HELP_SIDE_PANEL;
%constant const char * ART_HELP_SETTINGS         = wxART_HELP_SETTINGS;
%constant const char * ART_HELP_BOOK             = wxART_HELP_BOOK;
%constant const char * ART_HELP_FOLDER           = wxART_HELP_FOLDER;
%constant const char * ART_HELP_PAGE             = wxART_HELP_PAGE;
%constant const char * ART_GO_BACK               = wxART_GO_BACK;
%constant const char * ART_GO_FORWARD            = wxART_GO_FORWARD;
%constant const char * ART_GO_UP                 = wxART_GO_UP;
%constant const char * ART_GO_DOWN               = wxART_GO_DOWN;
%constant const char * ART_GO_TO_PARENT          = wxART_GO_TO_PARENT;
%constant const char * ART_GO_HOME               = wxART_GO_HOME;
%constant const char * ART_FILE_OPEN             = wxART_FILE_OPEN;
%constant const char * ART_PRINT                 = wxART_PRINT;
%constant const char * ART_HELP                  = wxART_HELP;
%constant const char * ART_TIP                   = wxART_TIP;
%constant const char * ART_REPORT_VIEW           = wxART_REPORT_VIEW;
%constant const char * ART_LIST_VIEW             = wxART_LIST_VIEW;
%constant const char * ART_NEW_DIR               = wxART_NEW_DIR;
%constant const char * ART_FOLDER                = wxART_FOLDER;
%constant const char * ART_GO_DIR_UP             = wxART_GO_DIR_UP;
%constant const char * ART_EXECUTABLE_FILE       = wxART_EXECUTABLE_FILE;
%constant const char * ART_NORMAL_FILE           = wxART_NORMAL_FILE;
%constant const char * ART_TICK_MARK             = wxART_TICK_MARK;
%constant const char * ART_CROSS_MARK            = wxART_CROSS_MARK;
%constant const char * ART_ERROR                 = wxART_ERROR;
%constant const char * ART_QUESTION              = wxART_QUESTION;
%constant const char * ART_WARNING               = wxART_WARNING;
%constant const char * ART_INFORMATION           = wxART_INFORMATION;
%constant const char * ART_MISSING_IMAGE         = wxART_MISSING_IMAGE;

%constant const int LAYOUT_UNCONSTRAIINED = wxUnconstrained;
%constant const int LAYOUT_AS_IS = wxAsIs;
%constant const int LAYOUT_PERCENT_OF = wxPercentOf;
%constant const int LAYOUT_ABOVE = wxAbove;
%constant const int LAYOUT_BELOW = wxBelow;
%constant const int LAYOUT_LEFT_OF = wxLeftOf;
%constant const int LAYOUT_RIGHT_OF = wxRightOf;
%constant const int LAYOUT_SAME_AS = wxSameAs;
%constant const int LAYOUT_ABSOLUTE = wxAbsolute;

%constant const int LAYOUT_LEFT =wxLeft; 
%constant const int LAYOUT_TOP =wxTop; 
%constant const int LAYOUT_RIGHT =wxRight; 
%constant const int LAYOUT_BOTTOM =wxBottom; 
%constant const int LAYOUT_WIDTH =wxWidth; 
%constant const int LAYOUT_HEIGHT =wxHeight;
%constant const int LAYOUT_CENTRE =wxCentre; 
%constant const int LAYOUT_CENTER =wxCenter; 
%constant const int LAYOUT_CENTRE_X =wxCentreX; 
%constant const int LAYOUT_CENTRE_Y =wxCentreY;

%constant const int NOT_FOUND = -1;

%constant const char * wxEmptyString = "";
