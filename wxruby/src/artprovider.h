/**********************************************************************

  artprovider.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

#ifndef WXRUBY_ARTPROVIDER_H
#define WXRUBY_ARTPROVIDER_H

#include "wx/artprov.h"

class wxRbArtProvider : public wxArtProvider
{
  protected:
    virtual wxBitmap CreateBitmap(const wxArtID& id, 
                          const wxArtClient& client,
                          const wxSize &size);
                          
  public:
    wxRbArtProvider(VALUE v) { self = v; }	
    VALUE self;                          
};

class WxArtProvider {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self);
    static VALUE CreateBitmap(VALUE self,VALUE vid,VALUE vclient,VALUE vsize);
    static VALUE GetBitmap(int argc, VALUE *argv, VALUE self);
    static VALUE GetIcon(int argc, VALUE *argv, VALUE self);
    static VALUE PopProvider(VALUE self);
    static void PushProvider(VALUE self,VALUE vprovider);
    static VALUE RemoveProvider(VALUE self,VALUE vprovider);

    static void DefineClass();
	static VALUE rubyClass;
};


#endif
