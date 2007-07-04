

// Any nested sizers passed to Add() in are owned by C++, not GC'd by Ruby
%apply SWIGTYPE *DISOWN { wxSizer* sizer };

