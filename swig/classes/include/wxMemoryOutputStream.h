// wxMemoryOutputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMemoryOutputStream_h_)
#define _wxMemoryOutputStream_h_
class wxMemoryOutputStream : public wxOutputStream
{
public:
   wxMemoryOutputStream(char * data = NULL, size_t length = 0) ;
  virtual  ~wxMemoryOutputStream() ;
  size_t CopyTo(char * buffer , size_t  len ) const;
};


#endif
