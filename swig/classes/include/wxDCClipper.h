// wxDCClipper.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDCClipper_h_)
#define _wxDCClipper_h_
class wxDCClipper
{
public:
	/**
	 * \brief  
	 * \param wxDC&   
	 * \param wxCoord   
	 * \param wxCoord   
	 * \param wxCoord   
	 * \param wxCoord   
	*/

   wxDCClipper(wxDC&  dc , wxCoord  x , wxCoord  y , wxCoord  w , wxCoord  h ) ;
	/**
	 * \brief Constructor: sets the the clipping region for the given device context to the
specified rectangle. 
	 * \param wxDC&   
	 * \param const wxRect&  
	*/

   wxDCClipper(wxDC&  dc , const wxRect&  rect ) ;
	/**
	 * \brief Destructor: destroys the clipping region set in the constructor. 
	*/

  virtual  ~wxDCClipper() ;
};


#endif
