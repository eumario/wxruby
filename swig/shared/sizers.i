// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license


// Any nested sizers passed to Add() in are owned by C++, not GC'd by Ruby
%apply SWIGTYPE *DISOWN { wxSizer* sizer };

