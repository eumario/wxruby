// wxStaticBoxSizer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxStaticBoxSizer_h_)
#define _wxStaticBoxSizer_h_
class wxStaticBoxSizer : public wxBoxSizer
{
public:
	/**
	 * \brief Constructor. It takes an associated static box and the orientation   
as parameters - orient can be either of wxVERTICAL or wxHORIZONTAL. 
	 * \param wxStaticBox*   
	 * \param int   
	*/

   wxStaticBoxSizer(wxStaticBox*  box , int  orient ) ;
	/**
	 * \brief Returns the static box associated with the sizer. 
	*/

  wxStaticBox* GetStaticBox() ;
};


#endif
