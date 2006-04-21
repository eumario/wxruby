#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxArtProvider

# The following are not yet compatible with SWIG 1.3.29
%ignore GetBitmap;
%ignore GetIcon;

%rename(ArtProvider) wxRubyArtProvider;

%import "include/wxObject.h"

%header %{
	#include <wx/artprov.h>
%}


%{

extern swig_class cWxSize;
extern swig_class cWxObject;

class wxRubyArtProvider : public wxArtProvider
{
  public:
  VALUE self;

  wxBitmap CreateBitmap(const wxArtID& id, const wxArtClient& client, const wxSize& size)
  {
    VALUE v_id,v_client,v_size,v_ret;
    wxBitmap result;

    v_id = rb_str_new2((const char *)id.c_str());
    v_client = rb_str_new2((const char *)client.c_str());
    v_size = SWIG_NewClassInstance(cWxSize.klass,SWIGTYPE_p_wxSize);
    wxSize *size_ptr = new wxSize(size);
    DATA_PTR(v_size) = size_ptr;

    v_ret = rb_funcall(self,rb_intern("create_bitmap"),3,v_id,v_client,v_size);
    
    if (v_ret != Qnil) 
      result = *((wxBitmap *)DATA_PTR(v_ret));
    else
      return wxNullBitmap;
    return result;
  }
};


%}

%ignore wxArtProvider;

%include "include/wxArtProvider.h"

class wxRubyArtProvider : public wxArtProvider
{
public:
    wxBitmap CreateBitmap(const wxArtID& id, const wxArtClient& client, const wxSize& size);
  static wxBitmap GetBitmap(const wxArtID&  id , const wxArtClient&  client = wxART_OTHER, const wxSize&  size = wxDefaultSize) ;
  static wxIcon GetIcon(const wxArtID&  id , const wxArtClient&  client = wxART_OTHER, const wxSize&  size = wxDefaultSize) ;
  static bool PopProvider() ;
  static void PushProvider(wxArtProvider*  provider ) ;
  static bool RemoveProvider(wxArtProvider*  provider ) ;
};
