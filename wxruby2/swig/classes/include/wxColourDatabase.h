// wxColourDatabase.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxColourDatabase_h_)
#define _wxColourDatabase_h_
class wxColourDatabase : public wxList
{
public:
   wxColourDatabase() ;
  wxColour* FindColour(const wxString&  colourName ) ;
  wxString FindName(const wxColour&  colour ) const;
  void Initialize() ;
};


#endif
