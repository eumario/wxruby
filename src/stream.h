/**********************************************************************

  stream.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_STREAM_H
#define WXRUBY_STREAM_H

#include "wx/stream.h"
#include "wx/wfstream.h"

class WxStreamBase {
public:
    static VALUE alloc(VALUE self);
    static VALUE GetLastError(VALUE self);
    static VALUE IsOk(VALUE self);
    static void Reset(VALUE self);
    static void free(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};


class WxInputStream {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self);
    static VALUE init0(wxInputStream *stream);
    static VALUE Eof(VALUE self);
    static VALUE GetC(VALUE self);
    static VALUE LastRead(VALUE self);
    static VALUE Peek(VALUE self);
    static VALUE Read(int argc, VALUE *argv, VALUE self);
    static VALUE SeekI(int argc, VALUE *argv, VALUE self);
    static VALUE TellI(VALUE self);
    static VALUE Ungetch(int argc, VALUE *argv, VALUE self);

    static void DefineClass();
	static VALUE rubyClass;

};


class WxOutputStream {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self);
    static VALUE init0(wxOutputStream *stream);
    static VALUE LastWrite(VALUE self);
    static void PutC(VALUE self,VALUE vc);
    static VALUE SeekO(int argc, VALUE *argv, VALUE self);
    static VALUE TellO(VALUE self);
    static VALUE Write(int argc, VALUE *argv, VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxFileOutputStream {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self,VALUE vfile);
    static VALUE Ok(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
