// wxScopedPtr.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxScopedPtr_h_)
#define _wxScopedPtr_h_
class wxScopedPtr
{
public:
   wxScopedPtr(type T = NULL) ;
  void reset(T * = NULL) ;
  const T* get() ;
  void swap(wxScopedPtr  & ot ) ;
};


#endif
