# Copyright 2004-2006 by Kevin Smith
# Released under the MIT-style wxruby2 license

// shared code for ControlWithItems - Wx::Choice, Wx::ComboBox etcxf


// First hide the old Wx definitions of these methods - which segfault
%ignore *::GetClientData(int n) const;
%ignore *::SetClientData(int n, void *data);
%ignore *::GetClientObject(int n) const;
%ignore *::SetClientObject(int  n, wxClientData * data);

%{
  extern swig_class cWxControlWithItems;
  extern void mark_wxControlWithItems(void* ptr);
%}

%define CLIENT_DATA_FEATURES(kls)
%extend kls {
  VALUE get_client_data(int n) {
	// Avoid an assert failure if no data previously set
	if ( ! self->HasClientUntypedData() )
	  return Qnil;

	VALUE returnVal = (VALUE) self->GetClientData(n);
	if ( ! returnVal )
	  return Qnil;
	return returnVal;
  }

  VALUE set_client_data(int n, VALUE item_data) {
	self->SetClientData(n, (void *)item_data);
	return item_data;
  }
}
%enddef
