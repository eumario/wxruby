// wxArtProvider.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxArtProvider_h_)
#define _wxArtProvider_h_
class wxArtProvider : public wxObject
{
public:
	/**
	 * \brief Derived art provider classes must override this method to create requested 
art resource. Note that returned bitmaps are cached by wxArtProvider and it is therefore
not neccessary to optimize CreateBitmap for speed (e.g. you may create wxBitmap objects
from XPMs here). 
	 * \param const wxArtID&   
	 * \param const wxArtClient&   
	 * \param const wxSize&   
	*/

  virtual wxBitmap CreateBitmap(const wxArtID&  id , const wxArtClient&  client , const wxSize&  size ) = 0;
	/**
	 * \brief Query registered providers for bitmap with given ID. 
	 * \param const wxArtID&   
	 * \param const wxArtClient&   
	 * \param const wxSize&   
	*/

  static wxBitmap GetBitmap(const wxArtID&  id , const wxArtClient&  client = wxART_OTHER, const wxSize&  size = wxDefaultSize) ;
	/**
	 * \brief Same as  , but
return a wxIcon object (or wxNullIcon on failure). 
	 * \param const wxArtID&   
	 * \param const wxArtClient&   
	 * \param const wxSize&   
	*/

  static wxIcon GetIcon(const wxArtID&  id , const wxArtClient&  client = wxART_OTHER, const wxSize&  size = wxDefaultSize) ;
	/**
	 * \brief Remove latest added provider and delete it. 
	*/

  static bool PopProvider() ;
	/**
	 * \brief Register new art provider (add it to the top of providers stack). 
	 * \param wxArtProvider*   
	*/

  static void PushProvider(wxArtProvider*  provider ) ;
	/**
	 * \brief Remove a provider from the stack. The provider must have been added previously
and is   deleted. 
	 * \param wxArtProvider*   
	*/

  static bool RemoveProvider(wxArtProvider*  provider ) ;
};


#endif
