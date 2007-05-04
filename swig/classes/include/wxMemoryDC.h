// wxMemoryDC.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMemoryDC_h_)
#define _wxMemoryDC_h_
class wxMemoryDC : public wxDC
{
public:
	/**
	 * \brief Constructs a new memory device context.

Use the   member to test whether the constructor was successful
in creating a usable device context. Don't forget to select a bitmap
into the DC before drawing on it. 
	*/

   wxMemoryDC() ;
	/**
	 * \brief Selects the given bitmap into the device context, to use as the memory
bitmap. Selecting the bitmap into a memory DC allows you to draw into
the DC (and therefore the bitmap) and also to use   to copy
the bitmap to a window. For this purpose, you may find  
easier to use instead.

If the argument is wxNullBitmap (or some other uninitialised wxBitmap) the current bitmap is selected out of the device
context, and the original bitmap restored, allowing the current bitmap to
be destroyed safely. 
	 * \param const wxBitmap&   
	*/

  void SelectObject(wxBitmap&  bitmap );
  virtual void SelectObjectAsSource(const wxBitmap& bmp);
};


#endif
