// wxDataObjectSimple.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDataObjectSimple_h_)
#define _wxDataObjectSimple_h_
class wxDataObjectSimple : public wxDataObject
{
public:
	/**
	 * \brief Constructor accepts the supported format (none by default) which may also be
set later with  . 
	 * \param const wxDataFormat&  
	*/

   wxDataObjectSimple(const wxDataFormat& format = wxFormatInvalid) ;
	/**
	 * \brief Returns the (one and only one) format supported by this object. It is supposed
that the format is supported in both directions. 
	*/

  const wxDataFormat& GetFormat() const;
	/**
	 * \brief Sets the supported format. 
	 * \param const wxDataFormat&  
	*/

  void SetFormat(const wxDataFormat&  format ) ;
	/**
	 * \brief Gets the size of our data. Must be implemented in the derived class if the
object supports rendering its data. 
	*/

  virtual size_t GetDataSize() const;
	/**
	 * \brief Copy the data to the buffer, return true on success. Must be implemented in the
derived class if the object supports rendering its data.

\pythonnote{When implementing this method in wxPython, no additional
parameters are required and the data should be returned from the
method as a string.} 
	 * \param void   
	*/

  virtual bool GetDataHere(void  *buf ) const;
	/**
	 * \brief Copy the data from the buffer, return true on success. Must be implemented in
the derived class if the object supports setting its data.

\pythonnote{When implementing this method in wxPython, the data comes
as a single string parameter rather than the two shown here.} 
	 * \param size_t   
	 * \param const void   
	*/

  virtual bool SetData(size_t  len , const void  *buf ) ;
};


#endif
