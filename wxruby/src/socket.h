/**********************************************************************

  socket.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_SOCKET_H
#define WXRUBY_SOCKET_H

#include "wx/socket.h"
#include "wx/protocol/protocol.h"

class WxSocketBase {
public:
    static VALUE alloc(VALUE self);
    static void Close(VALUE self);
    static VALUE Destroy(VALUE self);
    static VALUE Discard(VALUE self);
    static VALUE Error(VALUE self);
//    static VALUE GetClientData(VALUE self);
    static VALUE GetFlags(VALUE self);
    static void InterruptWait(VALUE self);
    static VALUE IsConnected(VALUE self);
    static VALUE IsData(VALUE self);
    static VALUE IsDisconnected(VALUE self);
    static VALUE LastCount(VALUE self);
    static VALUE LastError(VALUE self);
    static void Notify(VALUE self,VALUE vnotify);
    static VALUE Ok(VALUE self);
    static VALUE Peek(VALUE self,VALUE vbuffer,VALUE vnbytes);
    static VALUE Read(VALUE self,VALUE vbuffer,VALUE vnbytes);
    static VALUE ReadMsg(VALUE self,VALUE vbuffer,VALUE vnbytes);
    static void RestoreState(VALUE self);
    static void SaveState(VALUE self);
//    static void SetClientData(VALUE self,VALUE vdata);
    static void SetEventHandler(int argc, VALUE *argv, VALUE self);
    static void SetFlags(VALUE self,VALUE vflags);
    static void SetNotify(VALUE self,VALUE vflags);
    static void SetTimeout(VALUE self,VALUE vseconds);
    static VALUE Unread(VALUE self,VALUE vbuffer,VALUE vnbytes);
    static VALUE Wait(int argc, VALUE *argv, VALUE self);
    static VALUE WaitForLost(int argc, VALUE *argv, VALUE self);
    static VALUE WaitForRead(int argc, VALUE *argv, VALUE self);
    static VALUE WaitForWrite(int argc, VALUE *argv, VALUE self);
    static VALUE Write(VALUE self,VALUE vbuffer,VALUE vnbytes);
    static VALUE WriteMsg(VALUE self,VALUE vbuffer,VALUE vnbytes);
    static VALUE GetPeer(VALUE self);
    static VALUE init0(wxSocketBase *socket);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxSocketClient {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE Connect(int argc, VALUE *argv, VALUE self);
    static VALUE WaitOnConnect(int argc, VALUE *argv, VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxProtocol {
public:
    static VALUE alloc(VALUE self);
    static VALUE init0(wxProtocol *protocol);
    static VALUE Abort(VALUE self);
    static VALUE GetContentType(VALUE self);
    static VALUE GetError(VALUE self);
    static VALUE GetInputStream(VALUE self,VALUE vpath);
    static VALUE Reconnect(VALUE self);
    static void SetPassword(VALUE self,VALUE vuser);
    static void SetUser(VALUE self,VALUE vuser);

    static void DefineClass();
	static VALUE rubyClass;
};


class WxSocketServer {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE Accept(int argc, VALUE *argv, VALUE self);
    static VALUE AcceptWith(int argc, VALUE *argv, VALUE self);
    static VALUE WaitForAccept(int argc, VALUE *argv, VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};


#endif
