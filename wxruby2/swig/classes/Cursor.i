#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxCursor
%feature("nodirector") wxCursor;

%{
//NO_DIRECTOR
%}

/*
 * The following is too close to another constructor
 */

%feature("nodirector") wxCursor::wxCursor(const char  bits[] , int  width , int   height , int  hotSpotX = -1, int  hotSpotY = -1, const char  maskBits[] = NULL) ;
%ignore  wxCursor::wxCursor(const char  bits[] , int  width , int   height , int  hotSpotX = -1, int  hotSpotY = -1, const char  maskBits[] = NULL) ;

%include "include/wxCursor.h"
