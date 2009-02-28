// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxArtProvider
GC_MANAGE_AS_OBJECT(wxArtProvider);

%rename(ArtProvider) wxRubyArtProvider;

%header %{
#include <wx/artprov.h>
%}

// ArtId and ArtClient are basically just strings ...
typedef wxString wxArtID;
typedef wxString wxArtClient;
// ... but because they are used only in static methods, which have one
// fewer argument (no "self") than instance methods, we need to do
// deletion differently from the standard technique in typemap.i
%typemap(freearg) wxString& "if ( argc > $argnum - 1 ) delete $1;";

%apply SWIGTYPE *DISOWN {wxArtProvider* provider};

%{

extern swig_class cWxSize;
extern swig_class cWxObject;

class wxRubyArtProvider : public wxArtProvider
{
  public:

  wxBitmap CreateBitmap(const wxArtID& id, const wxArtClient& client, const wxSize& size)
  {
    VALUE v_id,v_client,v_size,v_ret;
    wxBitmap result;

	VALUE self = SWIG_RubyInstanceFor(this);

    v_id     = WXSTR_TO_RSTR(id);
    v_client = WXSTR_TO_RSTR(client);
    v_size   = SWIG_NewClassInstance(cWxSize.klass, SWIGTYPE_p_wxSize);
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
%ignore wxArtProvider::CreateBitmap; // must be supplied in ruby

%import "include/wxObject.h"
%include "include/wxArtProvider.h"

class wxRubyArtProvider : public wxArtProvider
{
public:
  wxBitmap CreateBitmap(const wxArtID& id, 
						const wxArtClient& client, 
						const wxSize& size);
  static wxBitmap GetBitmap(const wxArtID& id, 
							const wxArtClient&  client = wxART_OTHER, 
							const wxSize&  size = wxDefaultSize);
  static wxIcon GetIcon(const wxArtID&  id, 
						const wxArtClient& client = wxART_OTHER, 
						const wxSize&  size = wxDefaultSize);
  static void Insert(wxArtProvider*  provider);
  static bool Pop() ;
  static void Push(wxArtProvider*  provider);
  static bool Remove(wxArtProvider*  provider);
};
