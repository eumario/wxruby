// wxCustomDataObject.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCustomDataObject_h_)
#define _wxCustomDataObject_h_
class wxCustomDataObject : public wxDataObjectSimple
{
public:
	/**
	 * \brief The constructor accepts a   argument which specifies the (single)
format supported by this object. If it isn't set here, 
  should be used. 
	 * \param const wxDataFormat&   
	*/

   wxCustomDataObject(const wxDataFormat&  format = wxFormatInvalid) ;
	/**
	 * \brief The destructor will free the data hold by the object. Notice that although it
calls a virtual   function, the base
class version will always be called (C++ doesn't allow calling virtual
functions from constructors or destructors), so if you override  , you
should override the destructor in your class as well (which would probably
just call the derived class' version of  ). 
	*/

  virtual  ~wxCustomDataObject() ;
	/**
	 * \brief This function is called to allocate   bytes of memory from SetData().
The default version just uses the operator new. 
	 * \param size_t   
	*/

  virtual void * Alloc(size_t  size ) ;
	/**
	 * \brief This function is called when the data is freed, you may override it to anything
you want (or may be nothing at all). The default version calls operator
delete$&#91;]$ on the data. 
	*/

  virtual void Free() ;
	/**
	 * \brief Returns the data size in bytes. 
	*/

  virtual size_t GetSize() const;
	/**
	 * \brief Returns a pointer to the data. 
	*/

  virtual void * GetData() const;
	/**
	 * \brief Set the data. The data object will make an internal copy. 
	 * \param size_t   
	 * \param const void   
	*/

  virtual void SetData(size_t  size , const void  *data ) ;
	/**
	 * \brief Like  , but doesn't copy the data -
instead the object takes ownership of the pointer. 
	 * \param size_t   
	 * \param const void   
	*/

  virtual void TakeData(size_t  size , const void  *data ) ;
};


#endif
