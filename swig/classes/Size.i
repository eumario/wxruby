// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxSize
GC_MANAGE(wxSize);

%include "include/wxSize.h"

%extend wxSize {
    VALUE x()
    {
        wxSize *me = self;

        if (me != NULL) return INT2NUM(me->x);
        else return Qnil;
    }

    VALUE y()
    {
        wxSize *me=self;

        if (me != NULL) return INT2NUM(me->y);
        else return Qnil;
    }
}
