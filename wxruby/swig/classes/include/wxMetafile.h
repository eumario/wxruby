// wxMetafile.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMetafile_h_)
#define _wxMetafile_h_
class wxMetafile : public wxObject
{
public:
	/**
	 * \brief Constructor. If a filename is given, the Windows disk metafile is
read in. Check whether this was performed successfully by
using the   member. 
	 * \param const wxString&   
	*/

   wxMetafile(const wxString&  filename = wxT("")) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxMetafile() ;
	/**
	 * \brief Returns true if the metafile is valid. 
	*/

  bool Ok() ;
	/**
	 * \brief Plays the metafile into the given device context, returning
true if successful. 
	 * \param wxDC *  
	*/

  bool Play(wxDC * dc ) ;
	/**
	 * \brief Passes the metafile data to the clipboard. The metafile can no longer be
used for anything, but the wxMetafile object must still be destroyed by
the application.

Below is a example of metafile, metafile device context and clipboard use
from the   example. Note the way the metafile dimensions
are passed to the clipboard, making use of the device context's ability
to keep track of the maximum extent of drawing commands. 
	 * \param int  
	 * \param int  
	*/

  bool SetClipboard(int width = 0, int height = 0) ;
};


#endif
