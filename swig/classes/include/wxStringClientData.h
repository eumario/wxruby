// wxStringClientData.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxStringClientData_h_)
#define _wxStringClientData_h_
class wxStringClientData : public wxClientData
{
public:
	/**
	 * \brief Empty constructor. 
	*/

   wxStringClientData() ;
	/**
	 * \brief Create client data with string. 
	 * \param const wxString&   
	*/

   wxStringClientData(const wxString&  data ) ;
	/**
	 * \brief Get string client data. 
	*/

  const wxString& GetData() const;
	/**
	 * \brief Set string client data. 
	 * \param const wxString&   
	*/

  void SetData(const wxString&  data ) ;
};


#endif
