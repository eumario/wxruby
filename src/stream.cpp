/**********************************************************************

  stream.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "stream.h"

//-----------------------------------------------------------------------
void WxStreamBase::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"StreamBase", rb_cObject);
	rb_define_alloc_func(rubyClass,WxStreamBase::alloc);
	rb_define_method(rubyClass, "get_last_error", VALUEFUNC(WxStreamBase::GetLastError), 0);
	rb_define_method(rubyClass, "is_ok", VALUEFUNC(WxStreamBase::IsOk), 0);
	rb_define_method(rubyClass, "reset", VALUEFUNC(WxStreamBase::Reset), 0);
	rb_define_method(rubyClass, "free", VALUEFUNC(WxStreamBase::free), 0);
}

VALUE
WxStreamBase::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxStreamBase::GetLastError(VALUE self)
{
    wxStreamBase *ptr;
    Data_Get_Struct(self, wxStreamBase, ptr);
    return INT2NUM(ptr->GetLastError());
}

VALUE
WxStreamBase::IsOk(VALUE self)
{
    wxStreamBase *ptr;
    Data_Get_Struct(self, wxStreamBase, ptr);
    return (ptr->IsOk() ? Qtrue : Qfalse);
}

void
WxStreamBase::Reset(VALUE self)
{
    wxStreamBase *ptr;
    Data_Get_Struct(self, wxStreamBase, ptr);
    ptr->Reset();
}

void
WxStreamBase::free(VALUE self)
{
    wxStreamBase *ptr;
    Data_Get_Struct(self, wxStreamBase, ptr);
    delete ptr;
}

VALUE WxStreamBase::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxStreamBase::DefineClass();
    }
};
static ZAutoDefine x;

//-----------------------------------------------------------------------
void WxInputStream::DefineClass()
{
	if(rubyClass)
		return;
	WxStreamBase::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"InputStream", WxStreamBase::rubyClass);
	rb_define_alloc_func(rubyClass,WxInputStream::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new0), 0);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxInputStream::init), 0);
	rb_define_method(rubyClass, "eof", VALUEFUNC(WxInputStream::Eof), 0);
	rb_define_method(rubyClass, "get_c", VALUEFUNC(WxInputStream::GetC), 0);
	rb_define_method(rubyClass, "last_read", VALUEFUNC(WxInputStream::LastRead), 0);
	rb_define_method(rubyClass, "peek", VALUEFUNC(WxInputStream::Peek), 0);
	rb_define_method(rubyClass, "read", VALUEFUNC(WxInputStream::Read), -1);
	rb_define_method(rubyClass, "seek_i", VALUEFUNC(WxInputStream::SeekI), -1);
	rb_define_method(rubyClass, "tell_i", VALUEFUNC(WxInputStream::TellI), 0);
	rb_define_method(rubyClass, "ungetch", VALUEFUNC(WxInputStream::Ungetch), -1);
}

VALUE
WxInputStream::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxInputStream::init(VALUE self)
{
    wxInputStream *ptr;
    Data_Get_Struct(self, wxInputStream, ptr);
//    ptr = new wxInputStream();
    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxInputStream::init0(wxInputStream *stream)
{
    if(stream==NULL) return Qnil;
    static VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = stream;
    return self;
}

VALUE
WxInputStream::GetC(VALUE self)
{
    wxInputStream *ptr;
    Data_Get_Struct(self, wxInputStream, ptr);
    return INT2NUM(ptr->GetC());
}

VALUE
WxInputStream::Eof(VALUE self)
{
    wxInputStream *ptr;
    Data_Get_Struct(self, wxInputStream, ptr);
    return (ptr->Eof() ? Qtrue : Qfalse);
}

VALUE
WxInputStream::LastRead(VALUE self)
{
    wxInputStream *ptr;
    Data_Get_Struct(self, wxInputStream, ptr);
    return INT2NUM(ptr->LastRead());
}

VALUE
WxInputStream::Peek(VALUE self)
{
    wxInputStream *ptr;
    Data_Get_Struct(self, wxInputStream, ptr);
    return INT2NUM(ptr->Peek());
}

VALUE
WxInputStream::Read(int argc, VALUE *argv, VALUE self)
{
    wxInputStream *ptr;
    Data_Get_Struct(self, wxInputStream, ptr);
    if(argc==2) {
        void *buffer = (void*)StringValuePtr(argv[0]);
        size_t size = NUM2INT(argv[1]);
        return WxInputStream::init0(&ptr->Read(buffer,size));
    } else {
        wxOutputStream *stream_out;
        Data_Get_Struct(argv[0], wxOutputStream, stream_out);
        return WxInputStream::init0(&ptr->Read(*stream_out));
    }
}


VALUE
WxInputStream::SeekI(int argc, VALUE *argv, VALUE self)
{
    off_t pos = NUM2INT(argv[0]);
    wxSeekMode mode = wxFromStart;
    if(argc>1) mode = (wxSeekMode)NUM2INT(argv[1]);

    wxInputStream *ptr;
    Data_Get_Struct(self, wxInputStream, ptr);
    return INT2NUM(ptr->SeekI(pos,mode));
}

VALUE
WxInputStream::TellI(VALUE self)
{
    wxInputStream *ptr;
    Data_Get_Struct(self, wxInputStream, ptr);
    return INT2NUM(ptr->TellI());
}

VALUE
WxInputStream::Ungetch(int argc, VALUE *argv, VALUE self)
{
    wxInputStream *ptr;
    Data_Get_Struct(self, wxInputStream, ptr);
    if(TYPE(argv[0])==T_FIXNUM) {
        char c = NUM2INT(argv[0]);
        return (ptr->Ungetch(c) ? Qtrue : Qfalse);
    } else {
        void *buffer = (void*)StringValuePtr(argv[0]);
        size_t size = NUM2INT(argv[1]);
        return INT2NUM(ptr->Ungetch(buffer,size));
    }
}

VALUE WxInputStream::rubyClass;

class ZAutoDefineWxInputStream
{
public:
   ZAutoDefineWxInputStream()
    {
       WxInputStream::DefineClass();
    }
};
static ZAutoDefineWxInputStream x2;

//-----------------------------------------------------------------------
void WxOutputStream::DefineClass()
{
	if(rubyClass)
		return;
	WxStreamBase::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"OutputStream", WxStreamBase::rubyClass);
	rb_define_alloc_func(rubyClass,WxOutputStream::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new0), 0);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxOutputStream::init), 0);
	rb_define_method(rubyClass, "last_write", VALUEFUNC(WxOutputStream::LastWrite), 0);
	rb_define_method(rubyClass, "put_c", VALUEFUNC(WxOutputStream::PutC), 1);
	rb_define_method(rubyClass, "seek_o", VALUEFUNC(WxOutputStream::SeekO), -1);
	rb_define_method(rubyClass, "tell_o", VALUEFUNC(WxOutputStream::TellO), 0);
	rb_define_method(rubyClass, "write", VALUEFUNC(WxOutputStream::Write), -1);
}

VALUE
WxOutputStream::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxOutputStream::init(VALUE self)
{
    wxOutputStream *ptr;
    Data_Get_Struct(self, wxOutputStream, ptr);
//    ptr = new wxOutputStream();
    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxOutputStream::init0(wxOutputStream *stream)
{
    if(stream==NULL) return Qnil;
    static VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = stream;
    return self;
}

VALUE
WxOutputStream::LastWrite(VALUE self)
{
    wxOutputStream *ptr;
    Data_Get_Struct(self, wxOutputStream, ptr);
    return INT2NUM(ptr->LastWrite());
}

void
WxOutputStream::PutC(VALUE self,VALUE vc)
{
    char c = NUM2INT(vc);
    wxOutputStream *ptr;
    Data_Get_Struct(self, wxOutputStream, ptr);
    ptr->PutC(c);
}

VALUE
WxOutputStream::SeekO(int argc, VALUE *argv, VALUE self)
{
    off_t pos = NUM2INT(argv[0]);
    wxSeekMode mode = wxFromStart;
    if(argc>1) mode = (wxSeekMode)NUM2INT(argv[1]);

    wxOutputStream *ptr;
    Data_Get_Struct(self, wxOutputStream, ptr);
    return INT2NUM(ptr->SeekO(pos,mode));
}

VALUE
WxOutputStream::TellO(VALUE self)
{
    wxOutputStream *ptr;
    Data_Get_Struct(self, wxOutputStream, ptr);
    return INT2NUM(ptr->TellO());
}


VALUE
WxOutputStream::Write(int argc, VALUE *argv, VALUE self)
{
    wxOutputStream *ptr;
    Data_Get_Struct(self, wxOutputStream, ptr);
    if(argc==2) {
        void *buffer = (void*)StringValuePtr(argv[0]);
        size_t size = NUM2INT(argv[1]);
        return WxOutputStream::init0(&ptr->Write(buffer,size));
    } else {
        wxInputStream *stream_in;
        Data_Get_Struct(argv[0], wxInputStream, stream_in);
        return WxOutputStream::init0(&ptr->Write(*stream_in));
    }
}

VALUE WxOutputStream::rubyClass;

class ZAutoDefineWxOutputStream
{
public:
   ZAutoDefineWxOutputStream()
    {
       WxOutputStream::DefineClass();
    }
};
static ZAutoDefineWxOutputStream x3;

//-----------------------------------------------------------------------
void WxFileOutputStream::DefineClass()
{
	if(rubyClass)
		return;
	WxOutputStream::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"FileOutputStream", WxOutputStream::rubyClass);
	rb_define_alloc_func(rubyClass,WxFileOutputStream::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new1), 1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxFileOutputStream::init), 1);
	rb_define_method(rubyClass, "ok", VALUEFUNC(WxFileOutputStream::Ok), 0);
}

VALUE
WxFileOutputStream::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxFileOutputStream::init(VALUE self,VALUE vfile)
{
    wxFileOutputStream *ptr;
    Data_Get_Struct(self, wxFileOutputStream, ptr);
    if(TYPE(vfile)==T_STRING) {
        wxString ofileName = StringValuePtr(vfile);
        ptr = new wxFileOutputStream(ofileName);
    } else if(TYPE(vfile)==T_FIXNUM) {
        int fd = NUM2INT(vfile);
        ptr = new wxFileOutputStream(fd);
    } else {
        wxFile *file;
        Data_Get_Struct(vfile, wxFile, file);
        ptr = new wxFileOutputStream(*file);
    }
    DATA_PTR(self) = ptr;

    return self;
}


VALUE
WxFileOutputStream::Ok(VALUE self)
{
    wxFileOutputStream *ptr;
    Data_Get_Struct(self, wxFileOutputStream, ptr);
    return (ptr->Ok() ? Qtrue : Qfalse);
}

VALUE WxFileOutputStream::rubyClass;

class ZAutoDefineWxFileOutputStream
{
public:
   ZAutoDefineWxFileOutputStream()
    {
       WxFileOutputStream::DefineClass();
    }
};
static ZAutoDefineWxFileOutputStream x4;
