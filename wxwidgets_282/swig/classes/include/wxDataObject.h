// wxDataObject.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDataObject_h_)
#define _wxDataObject_h_
class wxDataObject
{
public:
	/**
	 * \brief Constructor. 
	*/

   wxDataObject() ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxDataObject() ;
	/**
	 * \brief Copy all supported formats in the given direction to the array pointed to by 
 . There is enough space for GetFormatCount(dir) formats in it.

\perlnote{In wxPerl this method only takes the   parameter. 
In scalar context it returns the first format,
in list context it returns a list containing all the supported formats.} 
	 * \param wxDataFormat *  
	 * \param Direction  
	*/

  virtual void GetAllFormats(wxDataFormat * formats , wxDataObject::Direction dir = Get) const= 0;
	/**
	 * \brief The method will write the data of the format   in the buffer   and return true on success, false on failure. 
	 * \param const wxDataFormat&  
	 * \param void   
	*/

  virtual bool GetDataHere(const wxDataFormat&  format , void  *buf ) const;
	/**
	 * \brief Returns the data size of the given format  . 
	 * \param const wxDataFormat&  
	*/

  virtual size_t GetDataSize(const wxDataFormat&  format ) const;
	/**
	 * \brief Returns the number of available formats for rendering or setting the data. 
	 * \param Direction  
	*/

  virtual size_t GetFormatCount(wxDataObject::Direction dir = Get) const=0;
	/**
	 * \brief Returns the preferred format for either rendering the data (if   is  ,
its default value) or for setting it. Usually this will be the
native format of the wxDataObject. 
	 * \param Direction  
	*/

  virtual wxDataFormat GetPreferredFormat(wxDataObject::Direction dir = Get) const=0;
	/**
	 * \brief Set the data in the format   of the length   provided in the
buffer  .

Returns true on success, false on failure. 
	 * \param const wxDataFormat&  
	 * \param size_t  
	 * \param const void   
	*/

  virtual bool SetData(const wxDataFormat&  format , size_t  len , const void  *buf ) ;
  // the following were missing from the xml
  enum Direction { Get=0x01, Set=0x02};;
};


#endif
