// wxZlibOutputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxZlibOutputStream_h_)
#define _wxZlibOutputStream_h_
class wxZlibOutputStream : public wxFilterOutputStream
{
public:
	/**
	 * \brief Creates a new write-only compressed stream.   means level of 
compression. It is number between 0 and 9 (including these values) where
0 means no compression and 9 best but slowest compression. -1 is default
value (currently equivalent to 6). 
	 * \param wxOutputStream&  
	 * \param int  
	*/

   wxZlibOutputStream(wxOutputStream&  stream , int level = -1) ;
};


#endif
