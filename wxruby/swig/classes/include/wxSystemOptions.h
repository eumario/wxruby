// wxSystemOptions.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSystemOptions_h_)
#define _wxSystemOptions_h_
class wxSystemOptions : public wxObject
{
public:
	/**
	 * \brief Default constructor. You don't need to create an instance of wxSystemOptions
since all of its functions are static. 
	*/

   wxSystemOptions() ;
	/**
	 * \brief Gets an option. The function is case-insensitive to  . 
	 * \param const wxString&  
	*/

  wxString GetOption(const wxString&  name ) const;
	/**
	 * \brief Gets an option as an integer. The function is case-insensitive to  . 
	 * \param const wxString&  
	*/

  int GetOptionInt(const wxString&  name ) const;
	/**
	 * \brief Returns true if the given option is present. The function is case-insensitive to  . 
	 * \param const wxString&  
	*/

  bool HasOption(const wxString&  name ) const;
	/**
	 * \brief  
	 * \param const wxString&  
	 * \param const wxString&  
	*/

  void SetOption(const wxString&  name , const wxString&  value ) ;
	/**
	 * \brief Sets an option. The function is case-insensitive to  . 
	 * \param const wxString&  
	 * \param int  
	*/

  void SetOption(const wxString&  name , int  value ) ;
};


#endif
