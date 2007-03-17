// Copyright 2004-2005 by Kevin Smith
// released under the MIT-style wxruby2 license


#if !defined(_wxCursor_h_)
#define _wxCursor_h_
class wxCursor : public wxBitmap
{
public:
   wxCursor() ;
  //wxCursor(const char  bits[] , int  width , int   height , int  hotSpotX = -1, int  hotSpotY = -1, const char  maskBits[] = NULL);
  //wxCursor(const wxString&  cursorName , long  type , int  hotSpotX = 0, int  hotSpotY = 0);
   wxCursor(int  cursorId ) ;
   wxCursor(const wxImage&  image ) ;
   wxCursor(const wxCursor&  cursor ) ;
  virtual  ~wxCursor() ;
  bool Ok() const;
};


#endif
