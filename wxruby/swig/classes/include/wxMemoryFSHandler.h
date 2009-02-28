// wxMemoryFSHandler.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMemoryFSHandler_h_)
#define _wxMemoryFSHandler_h_
class wxMemoryFSHandler : public wxFileSystemHandler
{
public:
	/**
	 * \brief Constructor. 
	*/

   wxMemoryFSHandler() ;
	/**
	 * \brief  
	 * \param const wxString&   
	 * \param wxImage&   
	 * \param long   
	*/

  static void AddFile(const wxString&  filename , wxImage&  image , long  type ) ;
	/**
	 * \brief  
	 * \param const wxString&   
	 * \param const wxBitmap&   
	 * \param long   
	*/

  static void AddFile(const wxString&  filename , const wxBitmap&  bitmap , long  type ) ;
	/**
	 * \brief  
	 * \param const wxString&   
	 * \param const wxString&   
	*/

  static void AddFile(const wxString&  filename , const wxString&  textdata ) ;
	/**
	 * \brief Add file to list of files stored in memory. Stored 
data (bitmap, text or raw data)
will be copied into private memory stream and available under 
name &quot;memory:&quot; + filename.

Note that when storing image/bitmap, you must use image format that wxWindows
can write (e.g. JPG, PNG, see  )! 
	 * \param const wxString&   
	 * \param const void*   
	 * \param size_t   
	*/

  static void AddFile(const wxString&  filename , const void*  binarydata , size_t  size ) ;
	/**
	 * \brief Remove file from memory FS and free occupied memory. 
	 * \param const wxString&   
	*/

  static void RemoveFile(const wxString&  filename ) ;
};


#endif
