#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

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
