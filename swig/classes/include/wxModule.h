// wxModule.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxModule_h_)
#define _wxModule_h_
class wxModule : public wxObject
{
public:
	/**
	 * \brief Constructs a wxModule object. 
	*/

   wxModule() ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxModule() ;
	/**
	 * \brief Calls Exit for each module instance. Called by wxWindows on exit, so there is no
need for an application to call it. 
	*/

  static void CleanupModules() ;
	/**
	 * \brief Calls OnExit. This function is called by wxWindows and should not need to be called
by an application. 
	*/

  void Exit() ;
	/**
	 * \brief Calls OnInit. This function is called by wxWindows and should not need to be called
by an application. 
	*/

  bool Init() ;
	/**
	 * \brief Calls Init for each module instance. Called by wxWindows on startup, so there is no
need for an application to call it. 
	*/

  static bool InitializeModules() ;
	/**
	 * \brief Provide this function with appropriate cleanup for your module. 
	*/

  virtual void OnExit() ;
	/**
	 * \brief Provide this function with appropriate initialization for your module. If the function
returns false, wxWindows will exit immediately. 
	*/

  virtual bool OnInit() ;
	/**
	 * \brief Registers this module with wxWindows. Called by wxWindows on startup, so there is no
need for an application to call it. 
	 * \param wxModule*  
	*/

  static void RegisterModule(wxModule*  module ) ;
	/**
	 * \brief Creates instances of and registers all modules. Called by wxWindows on startup, so there is no
need for an application to call it. 
	*/

  static bool RegisterModules() ;
};


#endif
