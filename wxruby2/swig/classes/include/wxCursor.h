// wxCursor.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCursor_h_)
#define _wxCursor_h_
class wxCursor : public wxBitmap
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxCursor() ;
	/**
	 * \brief Constructs a cursor by passing an array of bits (Motif and Xt only).   is used only under Motif.

If either   or   is -1, the hotspot will be the centre of the cursor image (Motif only). 
	 * \param const char  
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param const char   
	*/

  //wxCursor(const char  bits[] , int  width , int   height , int  hotSpotX = -1, int  hotSpotY = -1, const char  maskBits[] = NULL);
	/**
	 * \brief Constructs a cursor by passing a string resource name or filename.

On MacOS when specifying a string resource name, first the color cursors 'crsr' and then the black/white cursors 'CURS' in the resource chain are scanned through.

  and   are currently only used under Windows when loading from an
icon file, to specify the cursor hotspot relative to the top left of the image. 
	 * \param const wxString&   
	 * \param long   
	 * \param int   
	 * \param int   
	*/

  //wxCursor(const wxString&  cursorName , long  type , int  hotSpotX = 0, int  hotSpotY = 0);
	/**
	 * \brief Constructs a cursor using a cursor identifier. 
	 * \param int  
	*/

   wxCursor(int  cursorId ) ;
	/**
	 * \brief Constructs a cursor from a wxImage. The cursor is monochrome, colors with the RGB elements all greater
than 127 will be foreground, colors less than this background. The mask (if any) will be used as transparent.

In MSW the foreground will be white and the background black. The cursor is resized to 32x32
In GTK, the two most frequent colors will be used for foreground and background. The cursor will be displayed
at the size of the image.
On MacOS the cursor is resized to 16x16 and currently only shown as black/white (mask respected). 
	 * \param const wxImage&  
	*/

   wxCursor(const wxImage&  image ) ;
	/**
	 * \brief Copy constructor. This uses reference counting so is a cheap operation.





















\pythonnote{Constructors supported by wxPython are:\par
\indented{2cm}{ }
}

\perlnote{Constructors supported by wxPerl are:\par
 
} 
	 * \param const wxCursor&  
	*/

   wxCursor(const wxCursor&  cursor ) ;
	/**
	 * \brief Destroys the cursor. A cursor can be reused for more
than one window, and does not get destroyed when the window is
destroyed. wxWindows destroys all cursors on application exit, although
it is best to clean them up explicitly. 
	*/

  virtual  ~wxCursor() ;
	/**
	 * \brief Returns true if cursor data is present. 
	*/

  bool Ok() const;
  // the following were missing from the xml
  virtual ~wxCursor();
};


#endif
