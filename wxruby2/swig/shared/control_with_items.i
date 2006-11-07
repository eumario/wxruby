# Copyright 2004-2006 by Kevin Smith
# Released under the MIT-style wxruby2 license

// Prevents Ruby's GC sweeping up items that are stored as client data
// Checks whether the C++ object is still around first...

%{
  static void mark_wxControlWithItems(void* ptr) {
	VALUE rb_obj = SWIG_RubyInstanceFor(ptr);
	if ( rb_ivar_get(rb_obj, rb_intern("@__swig_dead__") ) == Qtrue )
	  return;

	wxControlWithItems* wx_cwi = (wxControlWithItems*) ptr;
	int count = wx_cwi->GetCount();
	if ( count == 0 )
	  return;
	for (int i = 0; i < count; ++i)
	  {
		VALUE object = (VALUE) wx_cwi->GetClientData(i);
		if ( object != NULL && object != Qnil ) 
		  {
			rb_gc_mark(object);
		  }
	  }
  }
%}
