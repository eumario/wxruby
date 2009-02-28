// wxMetafileDC.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMetafileDC_h_)
#define _wxMetafileDC_h_
class wxMetafileDC : public wxDC
{
public:
	/**
	 * \brief Constructor. If no filename is passed, the metafile is created
in memory. 
	 * \param const wxString&   
	*/

   wxMetafileDC(const wxString&  filename = wxT("")) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxMetafileDC() ;
	/**
	 * \brief This must be called after the device context is finished with. A
metafile is returned, and ownership of it passes to the calling
application (so it should be destroyed explicitly). 
	*/

  wxMetafile * Close() ;
};


#endif
