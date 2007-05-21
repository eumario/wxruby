// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

// This file, required by common.i defines a set of macros which are used
// to specify memory management strategies for individual Wx classes.

// Broadly speaking there are two different strategies:
//
// 1) For all classes which inherit from Wx::Window, including all Frames,
//    Dialogs and Controls: the C++ objects are managed by WxWidgets; when=
//    Frame is closed, it and all its contents are deleted. Therefore wxRuby
//    doesn't try to delete these objects as part of GC until they are known
//    to have been deleted. The instance of Wx::App watches for window
//    destruction, and in the GC-mark phase marks all Windows that are still
//    alive. [see App.i]
//    
// 2) Almost all other classes are memory managed by wxRuby - that is, when
//    they have fallen out of scope and GC is run, the underlying C++ object
//    will be deleted too by the standard %freefunc.


// This is implemented in swig/wx.i
%{
extern void GcNullFreeFunc(void *);
%}

// Macro definitions.

// Objects that are tracked but managed by WxWidgets - this is currently 
// all Windows, including Frames and Dialogs
%define GC_NEVER(kls)
%trackobjects;
%feature("freefunc") kls "GcNullFreeFunc";
%enddef

// Strategy for windows that aren't top-level windows.
// Here, the C++ objects are destroyed automatically by WxWidgets when the
// frame that contains them is closed and destroyed
%define GC_MANAGE_AS_WINDOW(kls)
GC_NEVER(kls);
%enddef

// Strategy for top-level frames - these are destroyed automatically.
%define GC_MANAGE_AS_FRAME(kls)
GC_NEVER(kls);
%enddef

// Strategy for dialogs - these are destroyed automatically
%define GC_MANAGE_AS_DIALOG(kls)
GC_NEVER(kls);
%enddef

// Events - cleaned up by WxWidgets when handling is complete, shouldn't 
// be stored so not tracked.
%define GC_MANAGE_AS_EVENT(kls)
%feature("freefunc") kls "GcNullFreeFunc";
%enddef

// Other descendants of Wx::Object - eg Colour, Pen, Bitmap - that Wx 
// manages by reference counting
%define GC_MANAGE_AS_OBJECT(kls)
%trackobjects;
%enddef

// All other classes - mainly helper classes (eg Sizer, GridCellxxx) and
// informational classes eg Point, Size, Rect. These are tracked but 
// sometimes later disowned once passed into a widget, and thenceforth 
// managed by WxWidgets
%define GC_MANAGE(kls)
%trackobjects;
%enddef

