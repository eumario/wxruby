// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxObject
GC_MANAGE_AS_OBJECT(wxObject);

// These methods are useless, and possibly dangerous if called from Ruby
%ignore wxObject(wxObject const &other);
%ignore wxObject::Dump;
%ignore wxObject::Ref;
%ignore wxObject::UnRef;
%ignore wxObject::GetRefData;

// not dangerous, but not useful?
%ignore wxObject::IsKindOf;
%ignore wxObject::GetClassInfo;

%extend wxObject {
  // Returns the string name of the C++ wx class which this object is wrapping.
  // The doubled wx name is to fool renamer.rb, which strips the wx prefix.
  // The actual final method is called wx_class
  VALUE wxwx_class() {
	wxString class_name( self->GetClassInfo()->GetClassName() );
	VALUE rb_class_name = WXSTR_TO_RSTR(class_name);
	return rb_class_name;
  }
}

%include "include/wxObject.h"
