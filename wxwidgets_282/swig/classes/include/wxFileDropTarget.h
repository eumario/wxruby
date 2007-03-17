// wxFileDropTarget.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFileDropTarget_h_)
#define _wxFileDropTarget_h_
class wxFileDropTarget : public wxDropTarget
{
public:
	/**
	 * \brief Constructor. 
	*/

   wxFileDropTarget() ;
	/**
	 * \brief See  . This function is implemented
appropriately for files, and calls  . 
	 * \param long   
	 * \param long   
	 * \param const void   
	 * \param size_t   
	*/

  virtual bool OnDrop(long  x , long  y , const void  *data , size_t  size ) ;
	/**
	 * \brief Override this function to receive dropped files. 
	 * \param wxCoord   
	 * \param wxCoord   
	 * \param const wxArrayString&   
	*/

  virtual bool OnDropFiles(wxCoord  x , wxCoord  y , const wxArrayString&  filenames ) ;
};


#endif
