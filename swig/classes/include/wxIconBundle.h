// wxIconBundle.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxIconBundle_h_)
#define _wxIconBundle_h_
class wxIconBundle
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxIconBundle() ;
	/**
	 * \brief Initializes the bundle with the icon(s) found in the file. 
	 * \param const wxString&   
	 * \param long   
	*/

   wxIconBundle(const wxString&  file , long  type ) ;
	/**
	 * \brief Initializes the bundle with a single icon. 
	 * \param const wxIcon&   
	*/

   wxIconBundle(const wxIcon&  icon ) ;
	/**
	 * \brief Copy constructor. 
	 * \param const wxIconBundle&   
	*/

   wxIconBundle(const wxIconBundle&  ic ) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxIconBundle() ;
	/**
	 * \brief Adds all the icons contained in the file to the bundle;
if the collection already contains icons with the same
width and height, they are replaced by the new ones. 
	 * \param const wxString&   
	 * \param long   
	*/

  void AddIcon(const wxString&  file , long  type ) ;
	/**
	 * \brief Adds the icon to the collection; if the collection already
contains an icon with the same width and height, it is
replaced by the new one. 
	 * \param const wxIcon&   
	*/

  void AddIcon(const wxIcon&  icon ) ;
	/**
	 * \brief Returns the icon with the given size; if no such icon exists,
returns the icon with size wxSYS_ICON_X/wxSYS_ICON_Y;
if no such icon exists,
returns the first icon in the bundle. If size = wxSize( -1, -1 ),
returns the icon with size wxSYS_ICON_X/wxSYS_ICON_Y. 
	 * \param const wxSize&   
	*/

  const wxIcon& GetIcon(const wxSize&  size ) const;
	/**
	 * \brief Same as GetIcon( wxSize( size, size ) ). 
	 * \param wxCoord   
	*/

  const wxIcon& GetIcon(wxCoord  size = -1) const;
};


#endif
