#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project

%module(directors="1") wxRubyStockObjects

%include "common.i"

%constant wxFont* const     wxNORMAL_FONT;
%constant wxFont* const     wxSMALL_FONT;
%constant wxFont* const     wxITALIC_FONT;
%constant wxFont* const     wxSWISS_FONT;
                                                                                
%constant wxPen* const     wxRED_PEN;
%constant wxPen* const     wxCYAN_PEN;
%constant wxPen* const     wxGREEN_PEN;
%constant wxPen* const     wxBLACK_PEN;
%constant wxPen* const     wxWHITE_PEN;
%constant wxPen* const     wxTRANSPARENT_PEN;
%constant wxPen* const     wxBLACK_DASHED_PEN;
%constant wxPen* const     wxGREY_PEN;
%constant wxPen* const     wxMEDIUM_GREY_PEN;
%constant wxPen* const     wxLIGHT_GREY_PEN;
                                                                                
%constant wxBrush* const   wxBLUE_BRUSH;
%constant wxBrush* const   wxGREEN_BRUSH;
%constant wxBrush* const   wxWHITE_BRUSH;
%constant wxBrush* const   wxBLACK_BRUSH;
%constant wxBrush* const   wxGREY_BRUSH;
%constant wxBrush* const   wxMEDIUM_GREY_BRUSH;
%constant wxBrush* const   wxLIGHT_GREY_BRUSH;
%constant wxBrush* const   wxTRANSPARENT_BRUSH;
%constant wxBrush* const   wxCYAN_BRUSH;
%constant wxBrush* const   wxRED_BRUSH;

%constant wxColour* const   wxBLACK;
%constant wxColour* const   wxWHITE;
%constant wxColour* const   wxRED;
%constant wxColour* const   wxBLUE;
%constant wxColour* const   wxGREEN;
%constant wxColour* const   wxCYAN;
%constant wxColour* const   wxLIGHT_GREY;
                                                                                
#// 'Null' objects
%constant wxBitmap const  wxNullBitmap;
%constant wxIcon const    wxNullIcon;
%constant wxCursor const  wxNullCursor;
%constant wxPen const     wxNullPen;
%constant wxBrush const   wxNullBrush;
%constant wxPalette const wxNullPalette;
%constant wxFont const    wxNullFont;
%constant wxColour const  wxNullColour;

%constant wxCursor const* wxSTANDARD_CURSOR;
%constant wxCursor const* wxHOURGLASS_CURSOR;
%constant wxCursor const*  wxCROSS_CURSOR;

