// wxDynamicLibrary.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDynamicLibrary_h_)
#define _wxDynamicLibrary_h_
class wxDynamicLibrary
{
public:
   wxDynamicLibrary() ;
   wxDynamicLibrary(const wxString&  name ) ;
  wxDllType Detach() ;
  bool IsLoaded() const;
  bool Load(const wxString&  name ) ;
  void Unload() ;
  void* GetSymbol(const wxString&  name ) const;
};


#endif
