// wxQuantize.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxQuantize_h_)
#define _wxQuantize_h_
class wxQuantize : public wxObject
{
public:
   wxQuantize() ;
  bool Quantize(const wxImage&  src , wxImage&  dest , wxPalette**  pPalette , int  desiredNoColours = 236, unsigned char**  eightBitData = 0, int  flags = wxQUANTIZE_INCLUDE_WINDOWS_COLOURS|wxQUANTIZE_FILL_DESTINATION_IMAGE|wxQUANTIZE_RETURN_8BIT_DATA) ;
  bool Quantize(const wxImage&  src , wxImage&  dest , int  desiredNoColours = 236, unsigned char**  eightBitData = 0, int  flags = wxQUANTIZE_INCLUDE_WINDOWS_COLOURS|wxQUANTIZE_FILL_DESTINATION_IMAGE|wxQUANTIZE_RETURN_8BIT_DATA) ;
  void DoQuantize(unsigned  w , unsigned  h , unsigned char**  in_rows , unsigned char**  out_rows , unsigned char*  palette , int  desiredNoColours ) ;
};


#endif
