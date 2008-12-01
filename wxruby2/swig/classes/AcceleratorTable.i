// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxAcceleratorTable
GC_MANAGE_AS_OBJECT(wxAcceleratorTable);

%{
#include <wx/accel.h>
%}

%feature("nodirector") wxAcceleratorTable;

// This form is supported on windows only
%ignore wxAcceleratorTable::wxAcceleratorTable(const wxString& resource);
// This ctor is probably not needed
%ignore wxAcceleratorTable::wxAcceleratorTable(const wxAcceleratorTable& bitmap);

// this is useless method, just here to inform SWIG about the existence
// of the wxAcceleratorEntry class, so that it creates the typed pointer
// definition _p_wxAcceleratorEntry
%extend wxAcceleratorTable { VALUE bogus__(wxAcceleratorEntry) { return (VALUE)0; } }


// For constructor, accepts an array of Wx::AcceleratorEntry objects
%typemap(in,numinputs=1) (int n, wxAcceleratorEntry entries[]) (wxAcceleratorEntry *arr)
{
  if (($input == Qnil) || (TYPE($input) != T_ARRAY))
  {
    $1 = 0;
    $2 = NULL;
  }
  else
  {
    wxAcceleratorEntry *wx_acc_ent;
    arr = new wxAcceleratorEntry[ RARRAY_LEN($input) ];
    for (int i = 0; i < RARRAY_LEN($input); i++)
    {
	  SWIG_ConvertPtr(rb_ary_entry($input,i), (void **) &wx_acc_ent, 
                      SWIGTYPE_p_wxAcceleratorEntry, 1);
	  if (wx_acc_ent == NULL) 
		rb_raise(rb_eTypeError, "Reference to null wxAcceleratorEntry");
	  arr[i] = *wx_acc_ent;
    }
    $1 = RARRAY_LEN($input);
    $2 = arr;
  }
}
%typemap(default,numinputs=1) (int n, wxAcceleratorEntry entries[]) 
{
    $1 = 0;
    $2 = NULL;
}

%typemap(freearg) (int n, wxAcceleratorEntry entries[])
{
    if ($2 != NULL) delete [] $2;
}

%typemap(typecheck) (int n , wxAcceleratorEntry entries[])
{
   $1 = (TYPE($input) == T_ARRAY);
}

%import "include/wxObject.h"

%include "include/wxAcceleratorTable.h"
