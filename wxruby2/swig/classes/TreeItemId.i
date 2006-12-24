#   Copyright 2004-2006 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxTreeItemId

%{
#include <wx/treectrl.h>
%}

// returns the underlying opaque identifier as a ruby fixnum
%extend wxTreeItemId {
  VALUE to_i()
  {
	return INT2NUM( (int)self->m_pItem );
  }
}

%include "include/wxTreeItemId.h"
