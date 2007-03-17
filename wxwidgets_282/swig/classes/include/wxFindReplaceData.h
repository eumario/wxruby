// wxFindReplaceData.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFindReplaceData_h_)
#define _wxFindReplaceData_h_
class wxFindReplaceData : public wxObject
{
public:
	/**
	 * \brief Constuctor initializes the flags to default value (0). 
	 * \param wxUint32   
	*/

   wxFindReplaceData(wxUint32  flags = 0) ;
	/**
	 * \brief Get the string to find. 
	*/

  wxString GetFindString();
	/**
	 * \brief Get the replacement string. 
	*/

  wxString GetReplaceString();
	/**
	 * \brief Get the combination of   values. 
	*/

  int GetFlags() const;
	/**
	 * \brief Set the flags to use to initialize the controls of the dialog. 
	 * \param wxUint32   
	*/

  void SetFlags(wxUint32  flags ) ;
	/**
	 * \brief Set the string to find (used as initial value by the dialog). 
	 * \param const wxString&   
	*/

  void SetFindString(const wxString&  str ) ;
	/**
	 * \brief Set the replacement string (used as initial value by the dialog). 
	 * \param const wxString&   
	*/

  void SetReplaceString(const wxString&  str ) ;
};


#endif
