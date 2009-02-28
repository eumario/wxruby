// wxVariantData.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxVariantData_h_)
#define _wxVariantData_h_
class wxVariantData : public wxObject
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxVariantData() ;
	/**
	 * \brief Copy the data from `this' object to  . 
	 * \param wxVariantData&  
	*/

  void Copy(wxVariantData&  data ) ;
	/**
	 * \brief Returns true if this object is equal to  . 
	 * \param wxVariantData&  
	*/

  bool Eq(wxVariantData&  data ) const;
	/**
	 * \brief Returns the string type of the data. 
	*/

  wxString GetType() const;
	/**
	 * \brief If the data is a wxObject returns a pointer to the objects wxClassInfo structure, if
the data isn't a wxObject the method returns NULL. 
	*/

  wxClassInfo* GetValueClassInfo() const;
	/**
	 * \brief  
	 * \param ostream&  
	*/

  bool Read(ostream&  stream ) ;
	/**
	 * \brief Reads the data from   or  . 
	 * \param wxString&  
	*/

  bool Read(wxString&  string ) ;
	/**
	 * \brief  
	 * \param ostream&  
	*/

  bool Write(ostream&  stream ) const;
	/**
	 * \brief Writes the data to   or  . 
	 * \param wxString&  
	*/

  bool Write(wxString&  string ) const;
};


#endif
