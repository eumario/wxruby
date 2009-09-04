// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxAuiPaneInfo
GC_MANAGE(wxAuiPaneInfo);

%{
// Workaround for wx's auibar.h incompatibility 2.8.10 with OS X compiler
// Should be fixed by future wxWidgets 
#ifdef __WXMAC__
#define id toolid
#endif

#include <wx/aui/aui.h>
%}

// Inconsistent with the rest of the Wx API, the AUIPaneINfo 
// has attribute setters that are the name of the attribute eg XXX('...'), 
// rather than SetXXX('...'), and attribute getters that are C++ public 
// members. In Ruby these can't be distinguished, so we have to rename
// all the problem methods. We do the others too for consistency

// boolean flags
%rename(SetBottomDockable) wxAuiPaneInfo::BottomDockable(bool b = true);
%rename(SetCaptionVisible) wxAuiPaneInfo::CaptionVisible(bool b = true);
%rename(SetCloseButton) wxAuiPaneInfo::CloseButton(bool b = true);
%rename(SetDestroyOnClose) wxAuiPaneInfo::DestroyOnClose(bool b = true);
%rename(SetDockable) wxAuiPaneInfo::Dockable(bool b = true);
%rename(SetFloatable) wxAuiPaneInfo::Floatable(bool b = true);
%rename(SetGripper) wxAuiPaneInfo::Gripper(bool b = true);
%rename(SetGripperTop) wxAuiPaneInfo::GripperTop(bool b = true);
%rename(SetLeftDockable) wxAuiPaneInfo::LeftDockable(bool b = true);
%rename(SetMaximizeButton) wxAuiPaneInfo::MaximizeButton(bool b = true);
%rename(SetMinimizeButton) wxAuiPaneInfo::MinimizeButton(bool b = true);
%rename(SetPaneBorder) wxAuiPaneInfo::PaneBorder(bool b = true);
%rename(SetPinButton) wxAuiPaneInfo::PinButton(bool b = true);
%rename(SetMinimizeButton) wxAuiPaneInfo::MinimizeButton(bool b = true);
%rename(SetResizable) wxAuiPaneInfo::Resizable(bool b = true);
%rename(SetRightDockable) wxAuiPaneInfo::RightDockable(bool b = true);
%rename(SetTopDockable) wxAuiPaneInfo::TopDockable(bool b = true);

// attribute-like settings
%rename(SetLayer) wxAuiPaneInfo::Layer(int layer);
%rename(SetPosition) wxAuiPaneInfo::Position(int pos);
%rename(SetRow) wxAuiPaneInfo::Row(int row);

// members
%immutable wxAuiPaneInfo::best_size;
%rename(GetBestSize) wxAuiPaneInfo::best_size;
%rename(SetBestSize) wxAuiPaneInfo::BestSize(const wxSize& size);
%rename(SetBestSize) wxAuiPaneInfo::BestSize(int x, int y);

%immutable wxAuiPaneInfo::caption;
%rename(GetCaption) wxAuiPaneInfo::caption;
%rename(SetCaption) wxAuiPaneInfo::Caption(const wxString& c);

%immutable wxAuiPaneInfo::floating_pos;
%rename(GetFloatingPosition) wxAuiPaneInfo::floating_pos;
%rename(SetFloatingPosition) wxAuiPaneInfo::FloatingPosition(const wxPoint& pos);
%rename(SetFloatingPosition) wxAuiPaneInfo::FloatingPosition(int x, int y);

%immutable wxAuiPaneInfo::floating_size;
%rename(GetFloatingSize) wxAuiPaneInfo::floating_size;
%rename(SetFloatingSize) wxAuiPaneInfo::FloatingSize(const wxSize& size);
%rename(SetFloatingSize) wxAuiPaneInfo::FloatingSize(int x, int y);

%immutable wxAuiPaneInfo::max_size;
%rename(GetMaxSize) wxAuiPaneInfo::max_size;
%rename(SetMaxSize) wxAuiPaneInfo::MaxSize(const wxSize& size);
%rename(SetMaxSize) wxAuiPaneInfo::MaxSize(int x, int y);

%immutable wxAuiPaneInfo::min_size;
%rename(GetMinSize) wxAuiPaneInfo::min_size;
%rename(SetMinSize) wxAuiPaneInfo::MinSize(const wxSize& size);
%rename(SetMinSize) wxAuiPaneInfo::MinSize(int x, int y);

%immutable wxAuiPaneInfo::name;
%rename(GetName) wxAuiPaneInfo::name;
%rename(SetName) wxAuiPaneInfo::Name(const wxString& n);

%immutable wxAuiPaneInfo::window;
%rename(GetWindow) wxAuiPaneInfo::window;
%rename(SetWindow) wxAuiPaneInfo::Window(wxWindow* w);

%include "include/wxAuiPaneInfo.h"
