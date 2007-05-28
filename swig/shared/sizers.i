

// Any nested sizers passed to Add() in are owned by C++, not GC'd by Ruby
%apply SWIGTYPE *DISOWN { wxSizer* sizer };


// Whilst sizers that are directly managing Windows will be marked,
// those that are contained within other sizers need to be explicitly
// handled:
%{
static void mark_wxSizer(void *ptr) 
{
  wxSizer* wx_sizer = (wxSizer*)ptr;
  wxSizerItemList& children = wx_sizer->GetChildren();
  
  // Mark each menu in the menubar in turn
  for ( wxwxSizerItemListNode *node = children.GetFirst(); 
		node;
		node = node->GetNext() )
	{
	  wxSizerItem* item = node->GetData();
	  wxSizer* child_sizer  = item->GetSizer();
	  if ( child_sizer )
		{
		  VALUE rb_child_sizer = SWIG_RubyInstanceFor(child_sizer);
		  rb_gc_mark(rb_child_sizer);
		}
	}
}  
%}

