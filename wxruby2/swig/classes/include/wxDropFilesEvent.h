// wxDropFilesEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDropFilesEvent_h_)
#define _wxDropFilesEvent_h_
class wxDropFilesEvent : public wxEvent
{
public:
	/**
	 * \brief Constructor. 
	 * \param WXTYPE   
	 * \param int   
	 * \param wxString*   
	*/

   wxDropFilesEvent(WXTYPE  id = 0, int  noFiles = 0, wxString*  files = NULL) ;
	/**
	 * \brief Returns an array of filenames. 
	*/

  wxString* GetFiles() const;
	/**
	 * \brief Returns the number of files dropped. 
	*/

  int GetNumberOfFiles() const;
	/**
	 * \brief Returns the position at which the files were dropped.

Returns an array of filenames. 
	*/

  wxPoint GetPosition() const;
};


#endif
