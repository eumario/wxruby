// wxBitmapDataObject.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxBitmapDataObject_h_)
#define _wxBitmapDataObject_h_
class wxBitmapDataObject : public wxDataObjectSimple
{
public:
	/**
	 * \brief Returns the bitmap associated with the data object. You may wish to override
this method when offering data on-demand, but this is not required by
wxWindows' internals. Use this method to get data in bitmap form from
the  . 
	*/

  virtual wxBitmap GetBitmap() const;
	/**
	 * \brief Sets the bitmap associated with the data object. This method is called when the
data object receives data. Usually there will be no reason to override this
function. 
	 * \param const wxBitmap&   
	*/

  virtual void SetBitmap(const wxBitmap&  bitmap ) ;
};


#endif
