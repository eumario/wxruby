// wxTextDropTarget.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTextDropTarget_h_)
#define _wxTextDropTarget_h_
class wxTextDropTarget : public wxDropTarget
{
public:
	/**
	 * \brief Constructor. 
	*/

   wxTextDropTarget() ;
	/**
	 * \brief See  . This function is implemented
appropriately for text, and calls  . 
	 * \param long   
	 * \param long   
	 * \param const void   
	 * \param size_t   
	*/

  virtual bool OnDrop(long  x , long  y , const void  *data , size_t  size ) ;
	/**
	 * \brief Override this function to receive dropped text. 
	 * \param long   
	 * \param long   
	 * \param const char   
	*/

  virtual bool OnDropText(long  x , long  y , const char  *data ) ;
};


#endif
