// wxBoxSizer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxBoxSizer_h_)
#define _wxBoxSizer_h_
class wxBoxSizer : public wxSizer
{
public:
	/**
	 * \brief Constructor for a wxBoxSizer.   may be either of wxVERTICAL
or wxHORIZONTAL for creating either a column sizer or a row sizer. 
	 * \param int   
	*/

   wxBoxSizer(int  orient ) ;
	/**
	 * \brief Implements the calculation of a box sizer's dimensions and then sets
the size of its its children (calling   
if the child is a window). It is used internally only and must not be called
by the user. Documented for information. 
	*/

  void RecalcSizes() ;
	/**
	 * \brief Implements the calculation of a box sizer's minimal. It is used internally
only and must not be called by the user. Documented for information. 
	*/

  wxSize CalcMin() ;
	/**
	 * \brief Returns the orientation of the box sizer, either wxVERTICAL
or wxHORIZONTAL. 
	*/

  int GetOrientation() ;
  // the following were missing from the xml
  virtual ~wxBoxSizer();
};


#endif
