# Copyright 2004-2006 by Kevin Smith
# Released under the MIT-style wxruby2 license

// shared code for ControlWithItems - Wx::Choice, Wx::ComboBox etcxf


// First hide the old Wx definitions of these methods - which segfault
%ignore *::GetClientData(int n) const;
%ignore *::GetClientObject(int n) const;
%ignore *::SetClientObject(int  n, wxClientData * data);

%{
  extern swig_class cWxControlWithItems;

  // Returns a ruby object stored as client data
  static VALUE wxControlWithItems_get_client_data(wxControlWithItems *ptr, int n) {
	VALUE returnVal = (VALUE) ptr->GetClientData(n);
	if ( returnVal )
	  return Qnil;
	return returnVal;
  }

  // Prevents Ruby's GC sweeping up items that are stored as client data
  // Checks whether the C++ object is still around first...
  static void mark_wxControlWithItems(void* ptr) {
	VALUE rb_obj = SWIG_RubyInstanceFor(ptr);
	if ( rb_iv_get(rb_obj, "@__wx_destroyed__" ) == Qtrue )
	  return;

	// On Windows, sometimes the wrong object is associated with the
	// ptr, so we check whether it is the right one to avoid crashes
	if ( ! rb_obj_is_kind_of(rb_obj, cWxControlWithItems.klass) ) 
	  return;

	wxControlWithItems* wx_cwi = (wxControlWithItems*) ptr;
	int count = wx_cwi->GetCount();
	if ( count == 0 )
	  return;
    if(!wx_cwi->HasClientObjectData()&&!wx_cwi->HasClientUntypedData())
        return; // Control containing only strings

	for (int i = 0; i < count; ++i)
	  {
		VALUE object = (VALUE) wx_cwi->GetClientData(i);
		if ( object && object != Qnil ) 
		  {
			rb_gc_mark(object);
		  }
	  }
  }
%}
