/**********************************************************************

  socket.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "stream.h"
#include "socket.h"

void WxSocketBase::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"SocketBase", rb_cObject);
	rb_define_alloc_func(rubyClass,WxSocketBase::alloc);
	rb_define_method(rubyClass, "close", VALUEFUNC(WxSocketBase::Close), 0);
	rb_define_method(rubyClass, "destroy", VALUEFUNC(WxSocketBase::Destroy), 0);
	rb_define_method(rubyClass, "discard", VALUEFUNC(WxSocketBase::Discard), 0);
	rb_define_method(rubyClass, "error", VALUEFUNC(WxSocketBase::Error), 0);
	rb_define_method(rubyClass, "get_client_data", VALUEFUNC(WxSocketBase::GetClientData), 0);
	rb_define_method(rubyClass, "get_flags", VALUEFUNC(WxSocketBase::GetFlags), 0);
	rb_define_method(rubyClass, "interrupt_wait", VALUEFUNC(WxSocketBase::InterruptWait), 0);
	rb_define_method(rubyClass, "is_connected", VALUEFUNC(WxSocketBase::IsConnected), 0);
	rb_define_method(rubyClass, "is_data", VALUEFUNC(WxSocketBase::IsData), 0);
	rb_define_method(rubyClass, "is_disconnected", VALUEFUNC(WxSocketBase::IsDisconnected), 0);
	rb_define_method(rubyClass, "last_count", VALUEFUNC(WxSocketBase::LastCount), 0);
	rb_define_method(rubyClass, "last_error", VALUEFUNC(WxSocketBase::LastError), 0);
	rb_define_method(rubyClass, "notify", VALUEFUNC(WxSocketBase::Notify), 1);
	rb_define_method(rubyClass, "ok", VALUEFUNC(WxSocketBase::Ok), 0);
	rb_define_method(rubyClass, "peek", VALUEFUNC(WxSocketBase::Peek), 2);
	rb_define_method(rubyClass, "read", VALUEFUNC(WxSocketBase::Read), 2);
	rb_define_method(rubyClass, "read_msg", VALUEFUNC(WxSocketBase::ReadMsg), 2);
	rb_define_method(rubyClass, "restore_state", VALUEFUNC(WxSocketBase::RestoreState), 0);
	rb_define_method(rubyClass, "save_state", VALUEFUNC(WxSocketBase::SaveState), 0);
	rb_define_method(rubyClass, "set_client_data", VALUEFUNC(WxSocketBase::SetClientData), 1);
	rb_define_method(rubyClass, "set_event_handler", VALUEFUNC(WxSocketBase::SetEventHandler), -1);
	rb_define_method(rubyClass, "set_flags", VALUEFUNC(WxSocketBase::SetFlags), 1);
	rb_define_method(rubyClass, "set_notify", VALUEFUNC(WxSocketBase::SetNotify), 1);
	rb_define_method(rubyClass, "set_timeout", VALUEFUNC(WxSocketBase::SetTimeout), 1);
	rb_define_method(rubyClass, "unread", VALUEFUNC(WxSocketBase::Unread), 2);
	rb_define_method(rubyClass, "wait", VALUEFUNC(WxSocketBase::Wait), -1);
	rb_define_method(rubyClass, "wait_for_lost", VALUEFUNC(WxSocketBase::WaitForLost), -1);
	rb_define_method(rubyClass, "wait_for_read", VALUEFUNC(WxSocketBase::WaitForRead), -1);
	rb_define_method(rubyClass, "wait_for_write", VALUEFUNC(WxSocketBase::WaitForWrite), -1);
	rb_define_method(rubyClass, "write", VALUEFUNC(WxSocketBase::Write), 2);
	rb_define_method(rubyClass, "write_msg", VALUEFUNC(WxSocketBase::WriteMsg), 2);
	rb_define_method(rubyClass, "get_peer", VALUEFUNC(WxSocketBase::GetPeer), 0);
}

VALUE
WxSocketBase::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxSocketBase::init0(wxSocketBase *socket)
{
    static VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = socket;
    return self;
}

void
WxSocketBase::Close(VALUE self)
{
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    ptr->Close();
}

VALUE
WxSocketBase::Destroy(VALUE self)
{
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    return (ptr->Destroy() ? Qtrue : Qfalse);
}

VALUE
WxSocketBase::Discard(VALUE self)
{
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    return WxSocketBase::init0(&ptr->Discard());
}

VALUE
WxSocketBase::Error(VALUE self)
{
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    return (ptr->Error() ? Qtrue : Qfalse);
}

VALUE
WxSocketBase::GetClientData(VALUE self)
{
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    return (VALUE)(ptr->GetClientData());
}

VALUE
WxSocketBase::GetFlags(VALUE self)
{
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    return INT2NUM(ptr->GetFlags());
}

void
WxSocketBase::InterruptWait(VALUE self)
{
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    ptr->InterruptWait();
}

VALUE
WxSocketBase::IsConnected(VALUE self)
{
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    return (ptr->IsConnected() ? Qtrue : Qfalse);
}

VALUE
WxSocketBase::IsData(VALUE self)
{
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    return (ptr->IsData() ? Qtrue : Qfalse);
}

VALUE
WxSocketBase::IsDisconnected(VALUE self)
{
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    return (ptr->IsDisconnected() ? Qtrue : Qfalse);
}

VALUE
WxSocketBase::LastCount(VALUE self)
{
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    return INT2NUM(ptr->LastCount());
}

VALUE
WxSocketBase::LastError(VALUE self)
{
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    return INT2NUM(ptr->LastError());
}

void
WxSocketBase::Notify(VALUE self,VALUE vnotify)
{
    bool notify = (vnotify == Qtrue);
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    ptr->Notify(notify);
}

VALUE
WxSocketBase::Ok(VALUE self)
{
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    return (ptr->Ok() ? Qtrue : Qfalse);
}

void
WxSocketBase::RestoreState(VALUE self)
{
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    ptr->RestoreState();
}

void
WxSocketBase::SaveState(VALUE self)
{
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    ptr->SaveState();
}

void
WxSocketBase::SetClientData(VALUE self,VALUE vdata)
{
    void *data = (void*)vdata;
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    ptr->SetClientData(data);
}

void
WxSocketBase::SetEventHandler(int argc, VALUE *argv, VALUE self)
{
    wxEvtHandler *handler;
    Data_Get_Struct(argv[0], wxEvtHandler, handler);
    int id = -1;
    if(argc>1) id = NUM2INT(argv[1]);
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    ptr->SetEventHandler(*handler,id);
}

void
WxSocketBase::SetFlags(VALUE self,VALUE vflags)
{
    wxSocketFlags flags = (wxSocketFlags)NUM2INT(vflags);
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    ptr->SetFlags(flags);
}

void
WxSocketBase::SetNotify(VALUE self,VALUE vflags)
{
    wxSocketEventFlags flags = (wxSocketEventFlags)NUM2INT(vflags);
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    ptr->SetNotify(flags);
}

void
WxSocketBase::SetTimeout(VALUE self,VALUE vseconds)
{
    int seconds = NUM2INT(vseconds);
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    ptr->SetTimeout(seconds);
}

VALUE
WxSocketBase::Peek(VALUE self,VALUE vbuffer,VALUE vnbytes)
{
    void * buffer = (void*)StringValuePtr(vbuffer);
    wxUint32 nbytes = NUM2INT(vnbytes);
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    return WxSocketBase::init0(&ptr->Peek(buffer,nbytes));
}

VALUE
WxSocketBase::Read(VALUE self,VALUE vbuffer,VALUE vnbytes)
{
    void * buffer = (void*)StringValuePtr(vbuffer);
    wxUint32 nbytes = NUM2INT(vnbytes);
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    return WxSocketBase::init0(&ptr->Read(buffer,nbytes));
}

VALUE
WxSocketBase::ReadMsg(VALUE self,VALUE vbuffer,VALUE vnbytes)
{
    void * buffer = (void*)StringValuePtr(vbuffer);
    wxUint32 nbytes = NUM2INT(vnbytes);
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    return WxSocketBase::init0(&ptr->ReadMsg(buffer,nbytes));
}

VALUE
WxSocketBase::Unread(VALUE self,VALUE vbuffer,VALUE vnbytes)
{
    void * buffer = (void*)StringValuePtr(vbuffer);
    wxUint32 nbytes = NUM2INT(vnbytes);
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    return WxSocketBase::init0(&ptr->Unread(buffer,nbytes));
}

VALUE
WxSocketBase::Wait(int argc, VALUE *argv, VALUE self)
{
    long seconds = -1;
    if(argc>0) seconds = NUM2INT(argv[0]);
    long millisecond = 0;
    if(argc>1) millisecond = NUM2INT(argv[1]);
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    return (ptr->Wait(seconds,millisecond) ? Qtrue : Qfalse);
}

VALUE
WxSocketBase::WaitForLost(int argc, VALUE *argv, VALUE self)
{
    long seconds = -1;
    if(argc>0) seconds = NUM2INT(argv[0]);
    long millisecond = 0;
    if(argc>1) millisecond = NUM2INT(argv[1]);
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    return (ptr->WaitForLost(seconds,millisecond) ? Qtrue : Qfalse);
}

VALUE
WxSocketBase::WaitForRead(int argc, VALUE *argv, VALUE self)
{
    long seconds = -1;
    if(argc>0) seconds = NUM2INT(argv[0]);
    long millisecond = 0;
    if(argc>1) millisecond = NUM2INT(argv[1]);
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    return (ptr->WaitForRead(seconds,millisecond) ? Qtrue : Qfalse);
}

VALUE
WxSocketBase::WaitForWrite(int argc, VALUE *argv, VALUE self)
{
    long seconds = -1;
    if(argc>0) seconds = NUM2INT(argv[0]);
    long millisecond = 0;
    if(argc>1) millisecond = NUM2INT(argv[1]);
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    return (ptr->WaitForWrite(seconds,millisecond) ? Qtrue : Qfalse);
}

VALUE
WxSocketBase::Write(VALUE self,VALUE vbuffer,VALUE vnbytes)
{
    void * buffer = (void*)StringValuePtr(vbuffer);
    wxUint32 nbytes = NUM2INT(vnbytes);
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    return WxSocketBase::init0(&ptr->Write(buffer,nbytes));
}

VALUE
WxSocketBase::WriteMsg(VALUE self,VALUE vbuffer,VALUE vnbytes)
{
    void * buffer = (void*)StringValuePtr(vbuffer);
    wxUint32 nbytes = NUM2INT(vnbytes);
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    return WxSocketBase::init0(&ptr->WriteMsg(buffer,nbytes));
}

VALUE
WxSocketBase::GetPeer(VALUE self)
{
    wxIPV4address addr;
    wxSocketBase *ptr;
    Data_Get_Struct(self, wxSocketBase, ptr);
    if(ptr->GetPeer(addr))
        return rb_ary_new3(2,rb_str_new2(addr.Hostname()),INT2NUM(addr.Service()));
    else
        return rb_ary_new3(2,rb_str_new2(""),INT2NUM(0));
}

VALUE WxSocketBase::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxSocketBase::DefineClass();
    }
};
static ZAutoDefine x;

//----------------------------------------------------------------------------------------
void WxSocketServer::DefineClass()
{
	if(rubyClass)
		return;
	WxSocketBase::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"SocketServer", WxSocketBase::rubyClass);
	rb_define_alloc_func(rubyClass,WxSocketServer::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxSocketServer::init), -1);
	rb_define_method(rubyClass, "accept", VALUEFUNC(WxSocketServer::Accept), -1);
	rb_define_method(rubyClass, "accept_with", VALUEFUNC(WxSocketServer::AcceptWith), -1);
	rb_define_method(rubyClass, "wait_for_accept", VALUEFUNC(WxSocketServer::WaitForAccept), -1);
}

VALUE
WxSocketServer::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxSocketServer::init(int argc, VALUE *argv, VALUE self)
{
    wxIPV4address addr;
    wxSocketFlags flags = wxSOCKET_NONE;
    unsigned short service;
    if(argc==2) {
        wxString hostname = StringValuePtr(argv[0]);
        addr.Hostname(hostname);
        service = NUM2INT(argv[1]);
        addr.Service(service);
    } else {
        addr.AnyAddress();
        service = NUM2INT(argv[0]);
        addr.Service(service);
    }
    wxSocketServer *ptr;
    Data_Get_Struct(self, wxSocketServer, ptr);
    ptr = new wxSocketServer(addr,flags);
    DATA_PTR(self) = ptr;

    return self;
}


VALUE
WxSocketServer::Accept(int argc, VALUE *argv, VALUE self)
{
    bool wait = TRUE;
    if(argc>0 && argv[0]==Qfalse) wait = FALSE;
    wxSocketServer *ptr;
    Data_Get_Struct(self, wxSocketServer, ptr);
    return WxSocketBase::init0(ptr->Accept(wait));
}


VALUE
WxSocketServer::AcceptWith(int argc, VALUE *argv, VALUE self)
{
    wxSocketBase *socket;
    Data_Get_Struct(argv[0], wxSocketBase, socket);
    bool wait = TRUE;
    if(argc>1 && argv[1]==Qfalse) wait = FALSE;

    wxSocketServer *ptr;
    Data_Get_Struct(self, wxSocketServer, ptr);
    return (ptr->AcceptWith(*socket,wait) ? Qtrue : Qfalse);
}

VALUE
WxSocketServer::WaitForAccept(int argc, VALUE *argv, VALUE self)
{
    long seconds = -1;
    if(argc>0) seconds = NUM2INT(argv[0]);
    long millisecond = 0;
    if(argc>1) millisecond = NUM2INT(argv[1]);

    wxSocketServer *ptr;
    Data_Get_Struct(self, wxSocketServer, ptr);
    return (ptr->WaitForAccept(seconds,millisecond) ? Qtrue : Qfalse);
}

VALUE WxSocketServer::rubyClass;

class ZAutoDefineWxSocketServer
{
public:
   ZAutoDefineWxSocketServer()
    {
       WxSocketServer::DefineClass();
    }
};
static ZAutoDefineWxSocketServer x2;

//----------------------------------------------------------------------------------------
void WxSocketClient::DefineClass()
{
	if(rubyClass)
		return;
	WxSocketBase::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"SocketClient", WxSocketBase::rubyClass);
	rb_define_alloc_func(rubyClass,WxSocketClient::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxSocketClient::init), -1);
	rb_define_method(rubyClass, "connect", VALUEFUNC(WxSocketClient::Connect), -1);
	rb_define_method(rubyClass, "wait_on_connect", VALUEFUNC(WxSocketClient::WaitOnConnect), -1);
}

VALUE
WxSocketClient::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxSocketClient::init(int argc, VALUE *argv, VALUE self)
{
    wxSocketFlags flags = wxSOCKET_NONE;
    if(argc>0) flags = (wxSocketFlags)NUM2INT(argv[0]);

    wxSocketClient *ptr;
    Data_Get_Struct(self, wxSocketClient, ptr);
    ptr = new wxSocketClient(flags);
    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxSocketClient::Connect(int argc, VALUE *argv, VALUE self)
{
    wxIPV4address addr;
    unsigned short service;
    if(argc>1) {
        wxString hostname = StringValuePtr(argv[0]);
        addr.Hostname(hostname);
        service = NUM2INT(argv[1]);
        addr.Service(service);
    } else {
        addr.AnyAddress();
        service = NUM2INT(argv[0]);
        addr.Service(service);
    }
    bool wait = TRUE;
    if(argc>0 && argv[argc-1]==Qfalse) wait = FALSE;
    wxSocketClient *ptr;
    Data_Get_Struct(self, wxSocketClient, ptr);
    return (ptr->Connect(addr,wait) ? Qtrue : Qfalse);
}

VALUE
WxSocketClient::WaitOnConnect(int argc, VALUE *argv, VALUE self)
{
    long seconds = -1;
    if(argc>0) seconds = NUM2INT(argv[0]);
    long milliseconds = 0;
    if(argc>1) milliseconds = NUM2INT(argv[1]);
    wxSocketClient *ptr;
    Data_Get_Struct(self, wxSocketClient, ptr);
    return (ptr->WaitOnConnect(seconds,milliseconds) ? Qtrue : Qfalse);
}

VALUE WxSocketClient::rubyClass;

class ZAutoDefineWxSocketClient
{
public:
   ZAutoDefineWxSocketClient()
    {
       WxSocketClient::DefineClass();
    }
};
static ZAutoDefineWxSocketClient x3;

//-------------------------------------------------------------------------
void WxProtocol::DefineClass()
{
	if(rubyClass)
		return;
	WxSocketClient::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"Protocol", WxSocketClient::rubyClass);
	rb_define_alloc_func(rubyClass,WxProtocol::alloc);
	rb_define_method(rubyClass, "abort", VALUEFUNC(WxProtocol::Abort), 0);
	rb_define_method(rubyClass, "get_content_type", VALUEFUNC(WxProtocol::GetContentType), 0);
	rb_define_method(rubyClass, "get_error", VALUEFUNC(WxProtocol::GetError), 0);
	rb_define_method(rubyClass, "get_input_stream", VALUEFUNC(WxProtocol::GetInputStream), 0);
	rb_define_method(rubyClass, "reconnect", VALUEFUNC(WxProtocol::Reconnect), 0);
	rb_define_method(rubyClass, "set_password", VALUEFUNC(WxProtocol::SetPassword), 1);
	rb_define_method(rubyClass, "set_user", VALUEFUNC(WxProtocol::SetUser), 1);
}

VALUE
WxProtocol::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxProtocol::init0(wxProtocol *protocol)
{
    static VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = protocol;
    return self;
}

VALUE
WxProtocol::Reconnect(VALUE self)
{
    wxProtocol *ptr;
    Data_Get_Struct(self, wxProtocol, ptr);
    return (ptr->Reconnect() ? Qtrue : Qfalse);
}

VALUE
WxProtocol::GetInputStream(VALUE self,VALUE vpath)
{
    wxString path = StringValuePtr(vpath);
    wxProtocol *ptr;
    Data_Get_Struct(self, wxProtocol, ptr);
    return WxInputStream::init0(ptr->GetInputStream(path));
}

VALUE
WxProtocol::Abort(VALUE self)
{
    wxProtocol *ptr;
    Data_Get_Struct(self, wxProtocol, ptr);
    return (ptr->Abort() ? Qtrue : Qfalse);
}

VALUE
WxProtocol::GetError(VALUE self)
{
    wxProtocol *ptr;
    Data_Get_Struct(self, wxProtocol, ptr);
    return INT2NUM(ptr->GetError());
}

VALUE
WxProtocol::GetContentType(VALUE self)
{
    wxProtocol *ptr;
    Data_Get_Struct(self, wxProtocol, ptr);
    return rb_str_new2(ptr->GetContentType());
}

void
WxProtocol::SetUser(VALUE self,VALUE vuser)
{
    wxString user = StringValuePtr(vuser);
    wxProtocol *ptr;
    Data_Get_Struct(self, wxProtocol, ptr);
    ptr->SetUser(user);
}

void
WxProtocol::SetPassword(VALUE self,VALUE vuser)
{
    wxString user = StringValuePtr(vuser);
    wxProtocol *ptr;
    Data_Get_Struct(self, wxProtocol, ptr);
    ptr->SetPassword(user);
}

VALUE WxProtocol::rubyClass;

class ZAutoDefineWxProtocol
{
public:
   ZAutoDefineWxProtocol()
    {
       WxProtocol::DefineClass();
    }
};
static ZAutoDefineWxProtocol x4;
