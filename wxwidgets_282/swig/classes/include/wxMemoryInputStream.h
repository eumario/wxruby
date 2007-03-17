// wxMemoryInputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMemoryInputStream_h_)
#define _wxMemoryInputStream_h_
class wxMemoryInputStream : public wxInputStream
{
public:
	/**
	 * \brief Initializes a new read-only memory stream which will use the specified buffer
  of length  . The stream does not take ownership of the 
buffer, i.e. that it will not delete in its destructor. 
	 * \param const char *  
	 * \param size_t  
	*/

   wxMemoryInputStream(const char *  data , size_t  len ) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxMemoryInputStream() ;
};


#endif
