// wxDropFilesEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDropFilesEvent_h_)
#define _wxDropFilesEvent_h_
class wxDropFilesEvent : public wxEvent
{
public:
   wxDropFilesEvent(WXTYPE  id = 0, int  noFiles = 0, wxString*  files = NULL) ;
  wxString* GetFiles() const;
  int GetNumberOfFiles() const;
  wxPoint GetPosition() const;
};


#endif
