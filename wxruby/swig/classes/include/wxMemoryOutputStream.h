// wxMemoryOutputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMemoryOutputStream_h_)
#define _wxMemoryOutputStream_h_
class wxMemoryOutputStream : public wxOutputStream
{
public:
	/**
	 * \brief If   is NULL, then it will initialize a new empty buffer which will
grow if required.

\wxheading{Warning}

If the buffer is created, it will be destroyed at the destruction of the
stream. 
	 * \param char *  
	 * \param size_t  
	*/

   wxMemoryOutputStream(char * data = NULL, size_t length = 0) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxMemoryOutputStream() ;
	/**
	 * \brief CopyTo allowed you to transfer data from the internal buffer of
wxMemoryOutputStream to an external buffer.   specifies the size of
the buffer.

\wxheading{Returned value}

CopyTo returns the number of bytes copied to the buffer. Generally it is either
len or the size of the stream buffer. 
	 * \param char *  
	 * \param size_t   
	*/

  size_t CopyTo(char * buffer , size_t  len ) const;
};


#endif
