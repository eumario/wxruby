# Copyright 2004-2006 by Kevin Smith
# Released under the MIT-style wxruby2 license

// shared code for ControlWithItems - Wx::Choice, Wx::ComboBox etcxf


// First hide the old Wx definitions of these methods - which segfault
%ignore *::GetClientData(int n) const;
%ignore *::GetClientObject(int n) const;
%ignore *::SetClientObject(int  n, wxClientData * data);

%{
  extern swig_class cWxControlWithItems;
  extern void mark_wxControlWithItems(void* ptr);

  // Returns a ruby object stored as client data
  static VALUE wxControlWithItems_get_client_data(wxControlWithItems *ptr, int n) {
	VALUE returnVal = (VALUE) ptr->GetClientData(n);
	if ( returnVal )
	  return Qnil;
	return returnVal;
  }
%}
