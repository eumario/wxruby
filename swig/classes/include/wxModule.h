// wxModule.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxModule_h_)
#define _wxModule_h_
class wxModule : public wxObject
{
public:
   wxModule() ;
  virtual  ~wxModule() ;
  static void CleanupModules() ;
  void Exit() ;
  bool Init() ;
  static bool InitializeModules() ;
  virtual void OnExit() ;
  virtual bool OnInit() ;
  static void RegisterModule(wxModule*  module ) ;
  static bool RegisterModules() ;
};


#endif
