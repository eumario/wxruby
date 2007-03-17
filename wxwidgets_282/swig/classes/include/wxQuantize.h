// wxQuantize.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxQuantize_h_)
#define _wxQuantize_h_
class wxQuantize : public wxObject
{
public:
	/**
	 * \brief Constructor. You do not need to construct a wxQuantize object since its functions are static. 
	*/

   wxQuantize() ;
	/**
	 * \brief Reduce the colours in the source image and put the result into the
destination image. Both images may be the same, to overwrite the source image.
Specify an optional palette pointer to receive the resulting palette.
This palette may be passed to ConvertImageToBitmap, for example.

If you pass a palette pointer, you must free the palette yourself. 
	 * \param const wxImage&   
	 * \param wxImage&   
	 * \param wxPalette**   
	 * \param int   
	 * \param unsigned char**   
	 * \param int   
	*/

  bool Quantize(const wxImage&  src , wxImage&  dest , wxPalette**  pPalette , int  desiredNoColours = 236, unsigned char**  eightBitData = 0, int  flags = wxQUANTIZE_INCLUDE_WINDOWS_COLOURS|wxQUANTIZE_FILL_DESTINATION_IMAGE|wxQUANTIZE_RETURN_8BIT_DATA) ;
	/**
	 * \brief This version sets a palette in the destination image so you don't
have to manage it yourself. 
	 * \param const wxImage&   
	 * \param wxImage&   
	 * \param int   
	 * \param unsigned char**   
	 * \param int   
	*/

  bool Quantize(const wxImage&  src , wxImage&  dest , int  desiredNoColours = 236, unsigned char**  eightBitData = 0, int  flags = wxQUANTIZE_INCLUDE_WINDOWS_COLOURS|wxQUANTIZE_FILL_DESTINATION_IMAGE|wxQUANTIZE_RETURN_8BIT_DATA) ;
	/**
	 * \brief Converts input bitmap(s) into 8bit representation with custom palette.

in_rows and out_rows are arrays &#91;0..h-1] of pointer to rows
(in_rows contains w &#42; 3 bytes per row, out_rows w bytes per row).

Fills out_rows with indexes into palette (which is also stored into palette variable). 
	 * \param unsigned   
	 * \param unsigned   
	 * \param unsigned char**   
	 * \param unsigned char**   
	 * \param unsigned char*   
	 * \param int   
	*/

  void DoQuantize(unsigned  w , unsigned  h , unsigned char**  in_rows , unsigned char**  out_rows , unsigned char*  palette , int  desiredNoColours ) ;
};


#endif
