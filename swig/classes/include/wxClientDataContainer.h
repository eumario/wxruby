// wxClientDataContainer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxClientDataContainer_h_)
#define _wxClientDataContainer_h_
class wxClientDataContainer
{
public:
	/**
	 * \brief  
	*/

   wxClientDataContainer() ;
	/**
	 * \brief  
	*/

  virtual  ~wxClientDataContainer() ;
	/**
	 * \brief Get the untyped client data. 
	*/

  void* GetClientData() const;
	/**
	 * \brief Get a pointer to the client data object. 
	*/

  wxClientData* GetClientObject() const;
	/**
	 * \brief Set the untyped client data. 
	 * \param void*   
	*/

  void SetClientData(void*  data ) ;
	/**
	 * \brief Set the client data object. Any previous object will be deleted. 
	 * \param wxClientData*   
	*/

  void SetClientObject(wxClientData*  data ) ;
};


#endif
