// wxLogStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxLogStream_h_)
#define _wxLogStream_h_
class wxLogStream : public wxLog
{
public:
	/**
	 * \brief Constructs a log target which sends all the log messages to the given
output stream. If it is  , the messages are sent to  . 
	 * \param std::ostream   
	*/

   wxLogStream(std::ostream  *ostr = NULL) ;
};


#endif
