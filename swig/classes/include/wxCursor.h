// wxCursor.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCursor_h_)
#define _wxCursor_h_
class wxCursor : public wxBitmap
{
public:
   wxCursor() ;
  //wxCursor(const char  bits[] , int  width , int   height , int  hotSpotX = -1, int  hotSpotY = -1, const char  maskBits[] = NULL);
   wxCursor(const wxString&  cursorName , long  type , int  hotSpotX = 0, int  hotSpotY = 0) ;
   wxCursor(int  cursorId ) ;
   wxCursor(const wxImage&  image ) ;
   wxCursor(const wxCursor&  cursor ) ;
  virtual  ~wxCursor() ;
  bool Ok() const;
  // the following were missing from the xml
  virtual ~wxCursor();
};


#endif
