// wxDataObjectComposite.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDataObjectComposite_h_)
#define _wxDataObjectComposite_h_
class wxDataObjectComposite : public wxDataObject
{
public:
	/**
	 * \brief The default constructor. 
	*/

   wxDataObjectComposite() ;
	/**
	 * \brief Adds the   to the list of supported objects and it becomes the
preferred object if   is true. 
	 * \param wxDataObjectSimple   
	 * \param bool   
	*/

  void Add(wxDataObjectSimple  *dataObject , bool  preferred = false) ;
};


#endif
