// wxCriticalSectionLocker.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCriticalSectionLocker_h_)
#define _wxCriticalSectionLocker_h_
class wxCriticalSectionLocker
{
public:
	/**
	 * \brief Constructs a wxCriticalSectionLocker object associated with given
  and enters it. 
	 * \param wxCriticalSection&   
	*/

   wxCriticalSectionLocker(wxCriticalSection&  criticalsection ) ;
	/**
	 * \brief Destructor leaves the critical section. 
	*/

  virtual  ~wxCriticalSectionLocker() ;
};


#endif
