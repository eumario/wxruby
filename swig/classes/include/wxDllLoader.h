// wxDllLoader.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDllLoader_h_)
#define _wxDllLoader_h_
class wxDllLoader
{
public:
  static wxString GetDllExt() ;
  wxDllType GetProgramHandle() ;
  void * GetSymbol(wxDllType  dllHandle , const wxString&  name ) ;
  wxDllType LoadLibrary(const wxString &  libname , bool*  success = NULL) ;
  void UnloadLibrary(wxDllType  dllhandle ) ;
};


#endif
