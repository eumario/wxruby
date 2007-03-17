// wxTextDataObject.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTextDataObject_h_)
#define _wxTextDataObject_h_
class wxTextDataObject : public wxDataObjectSimple
{
public:
	/**
	 * \brief Constructor, may be used to initialise the text (otherwise 
  should be used later). 
	 * \param const wxString&   
	*/

   wxTextDataObject(const wxString&  text = wxEmptyString) ;
	/**
	 * \brief Returns the data size. By default, returns the size of the text data
set in the constructor or using  .
This can be overridden to provide text size data on-demand. It is recommended
to return the text length plus 1 for a trailing zero, but this is not
strictly required. 
	*/

  virtual size_t GetTextLength() const;
	/**
	 * \brief Returns the text associated with the data object. You may wish to override
this method when offering data on-demand, but this is not required by
wxWindows' internals. Use this method to get data in text form from
the  . 
	*/

  virtual wxString GetText() const;
	/**
	 * \brief Sets the text associated with the data object. This method is called
when the data object receives the data and, by default, copies the text into
the member variable. If you want to process the text on the fly you may wish to
override this function. 
	 * \param const wxString&   
	*/

  virtual void SetText(const wxString&  strText ) ;
};


#endif
