#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxCursor

/*
 * The following is too close to another constructor
 */
%feature("nodirector") wxCursor::wxCursor(const char  bits[] , int  width , int   height , int  hotSpotX = -1, int  hotSpotY = -1, const char  maskBits[] = NULL) ;
%ignore  wxCursor::wxCursor(const char  bits[] , int  width , int   height , int  hotSpotX = -1, int  hotSpotY = -1, const char  maskBits[] = NULL) ;

// I'm not sure why, but this gives a compile error with directors enabled
%feature("nodirector") wxCursor::Create(int, int, int) ;
%ignore  wxCursor::Create(int, int, int);

%import "include/wxObject.h"
%import "include/wxGDIObject.h"
%import "include/wxBitmap.h"

%include "include/wxCursor.h"
