// wxGridCellFloatRenderer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridCellFloatRenderer_h_)
#define _wxGridCellFloatRenderer_h_
class wxGridCellFloatRenderer : public wxGridCellStringRenderer
{
public:
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

   wxGridCellFloatRenderer(int  width = -1, int  precision = -1) ;
	/**
	 * \brief Returns the precision ( see   ). 
	*/

  int GetPrecision() const;
	/**
	 * \brief Returns the width ( see   ). 
	*/

  int GetWidth() const;
	/**
	 * \brief Parameters string format is &quot;width&#91;,precision]&quot;. 
	 * \param const wxString&   
	*/

  void SetParameters(const wxString&  params ) ;
	/**
	 * \brief Sets the precision ( see   ). 
	 * \param int   
	*/

  void SetPrecision(int  precision ) ;
	/**
	 * \brief Sets the width ( see   ) 
	 * \param int   
	*/

  void SetWidth(int  width ) ;
};


#endif
