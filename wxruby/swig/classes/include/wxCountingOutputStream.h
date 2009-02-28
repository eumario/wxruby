// wxCountingOutputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCountingOutputStream_h_)
#define _wxCountingOutputStream_h_
class wxCountingOutputStream : public wxOutputStream
{
public:
	/**
	 * \brief Creates a wxCountingOutputStream object. 
	*/

   wxCountingOutputStream() ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxCountingOutputStream() ;
	/**
	 * \brief Returns the current size of the stream. 
	*/

  size_t GetSize() const;
};


#endif
