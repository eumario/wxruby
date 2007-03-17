// wxEvtHandler.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxEvtHandler_h_)
#define _wxEvtHandler_h_
class wxEvtHandler : public wxObject
{
public:
	/**
	 * \brief Constructor. 
	*/

   wxEvtHandler() ;
	/**
	 * \brief Destructor. If the handler is part of a chain, the destructor will
unlink itself and restore the previous and next handlers so that they point to
each other. 
	*/

  virtual  ~wxEvtHandler() ;
	/**
	 * \brief This function posts an event to be processed later. 
	 * \param wxEvent&   
	*/

  virtual void AddPendingEvent(wxEvent&  event ) ;
	/**
	 * \brief  
	 * \param int  
	 * \param wxEventType   
	 * \param wxObjectEventFunction  
	 * \param wxObject*  
	*/

  void Connect(int  id , wxEventType  eventType , wxObjectEventFunction  function , wxObject* userData = NULL) ;
	/**
	 * \brief Connects the given function dynamically with the event handler, id and event type. This
is an alternative to the use of static event tables. See the 'dynamic' sample for usage. 
	 * \param int  
	 * \param int  
	 * \param wxEventType   
	 * \param wxObjectEventFunction  
	 * \param wxObject*  
	*/

  void Connect(int  id , int  lastId , wxEventType  eventType , wxObjectEventFunction  function , wxObject* userData = NULL) ;
	/**
	 * \brief  
	 * \param int  
	 * \param wxEventType   
	 * \param wxObjectEventFunction  
	 * \param wxObject*  
	*/

  bool Disconnect(int  id , wxEventType  eventType = wxEVT_NULL, wxObjectEventFunction function = NULL, wxObject* userData = NULL) ;
	/**
	 * \brief Disconnects the given function dynamically from the event handler, using the specified
parameters as search criteria and returning true if a matching function has been
found and removed. This method can only disconnect functions which have been added
using the   method. There is no way
to disconnect functions connected using the (static) event tables. 
	 * \param int  
	 * \param int  
	 * \param wxEventType   
	 * \param wxObjectEventFunction  
	 * \param wxObject*  
	*/

  bool Disconnect(int  id , int lastId = -1, wxEventType  eventType = wxEVT_NULL, wxObjectEventFunction function = NULL, wxObject* userData = NULL) ;
	/**
	 * \brief Gets user-supplied client data. 
	*/

  void*  GetClientData() ;
	/**
	 * \brief Get a pointer to the user-supplied client data object. 
	*/

  wxClientData* GetClientObject() const;
	/**
	 * \brief Returns true if the event handler is enabled, false otherwise. 
	*/

  bool GetEvtHandlerEnabled() ;
	/**
	 * \brief Gets the pointer to the next handler in the chain. 
	*/

  wxEvtHandler* GetNextHandler() ;
	/**
	 * \brief Gets the pointer to the previous handler in the chain. 
	*/

  wxEvtHandler* GetPreviousHandler() ;
	/**
	 * \brief Processes an event, searching event tables and calling zero or more suitable event handler function(s). 
	 * \param wxEvent&   
	*/

  virtual bool ProcessEvent(wxEvent&  event ) ;
	/**
	 * \brief Searches the event table, executing an event handler function if an appropriate one
is found. 
	 * \param wxEventTable&   
	 * \param wxEvent&   
	*/

  bool SearchEventTable(wxEventTable&  table , wxEvent&  event ) ;
	/**
	 * \brief Sets user-supplied client data. 
	 * \param void*   
	*/

  void SetClientData(void*  data ) ;
	/**
	 * \brief Set the client data object. Any previous object will be deleted. 
	 * \param wxClientData*   
	*/

  void SetClientObject(wxClientData*  data ) ;
	/**
	 * \brief Enables or disables the event handler. 
	 * \param bool   
	*/

  void SetEvtHandlerEnabled(bool  enabled ) ;
	/**
	 * \brief Sets the pointer to the next handler. 
	 * \param wxEvtHandler*   
	*/

  void SetNextHandler(wxEvtHandler*  handler ) ;
	/**
	 * \brief Sets the pointer to the previous handler. 
	 * \param wxEvtHandler*   
	*/

  void SetPreviousHandler(wxEvtHandler*  handler ) ;
};


#endif
