// wxScopedArray.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxScopedArray_h_)
#define _wxScopedArray_h_
class wxScopedArray
{
public:
   wxScopedArray(type T = NULL) ;
  void reset(T * = NULL) ;
  const T* get() ;
  void swap(wxScopedPtr  & ot ) ;
};


#endif
