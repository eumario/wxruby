// wxClassInfo.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxClassInfo_h_)
#define _wxClassInfo_h_
class wxClassInfo
{
public:
   wxClassInfo(char*  className , char*  baseClass1 , char*  baseClass2 , int  size , wxObjectConstructorFn  fn ) ;
  wxObject* CreateObject() ;
  static wxClassInfo * FindClass(char*  name ) ;
  char* GetBaseClassName1() const;
  char* GetBaseClassName2() const;
  char * GetClassName() const;
  int GetSize() const;
  static void InitializeClasses() ;
  bool IsKindOf(wxClassInfo*  info ) ;
};


#endif
