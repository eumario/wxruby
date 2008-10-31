// wxSingleInstanceChecker.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSingleInstanceChecker_h_)
#define _wxSingleInstanceChecker_h_
class wxSingleInstanceChecker
{
public:
	/**
	 * \brief Default ctor, use   after it. 
	*/

   wxSingleInstanceChecker() ;
	/**
	 * \brief Like   but without
error checking. 
	 * \param const wxString&   
	 * \param const wxString&   
	*/

   wxSingleInstanceChecker(const wxString&  name , const wxString&  path = wxEmptyString) ;
	/**
	 * \brief Initialize the object if it had been created using the default constructor.
Note that you can't call Create() more than once, so calling it if the 
  
had been used is an error. 
	 * \param const wxString&   
	 * \param const wxString&   
	*/

  bool Create(const wxString&  name , const wxString&  path = wxEmptyString) ;
	/**
	 * \brief Returns   if another copy of this program is already running,   otherwise. 
	*/

  bool IsAnotherRunning() const;
	/**
	 * \brief Destructor frees the associated resources.

Note that it is not virtual, this class is not meant to be used polymorphically 
	*/

  virtual  ~wxSingleInstanceChecker() ;
};


#endif
