// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxValidator
GC_MANAGE_AS_OBJECT(wxValidator);

// This must be implemented in Ruby; a default implementation is
// provided in lib/wx/classes/validator.rb
%ignore wxValidator::Clone();

// These are no-ops since wxRuby doesn't do C++-style data transfer
%ignore wxValidator::TransferFromWindow();
%ignore wxValidator::TransferToWindow();

// Stub implementations that do nothing but return true to avoid
// warnings when called from WxWidgets
%extend wxValidator {
  bool transfer_from_window() { return true; }
  bool transfer_to_window() { return true; }
}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"

%include "include/wxValidator.h"
