#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxSize

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
