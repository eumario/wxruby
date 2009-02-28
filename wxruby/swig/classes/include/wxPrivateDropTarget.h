// wxPrivateDropTarget.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPrivateDropTarget_h_)
#define _wxPrivateDropTarget_h_
class wxPrivateDropTarget : public wxDropTarget
{
public:
	/**
	 * \brief  
	*/

   wxPrivateDropTarget() ;
	/**
	 * \brief You have to override OnDrop to get at the data.
The string ID identifies the format of clipboard or DnD data. A word
processor would e.g. add a wxTextDataObject and a wxPrivateDataObject
to the clipboard - the latter with the Id &quot;WXWORD_FORMAT&quot;. 
	 * \param const wxString&   
	*/

  void SetId(const wxString&  id ) ;
	/**
	 * \brief  
	*/

  virtual wxString GetId() const;
};


#endif
