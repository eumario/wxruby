// wxNotebookSizer.h

// This class is now deprecated, so we no longer support it

#if 0
#if !defined(_wxNotebookSizer_h_)
#define _wxNotebookSizer_h_
class wxNotebookSizer : public wxSizer
{
public:
	/**
	 * \brief Constructor. It takes an associated notebook as its only parameter. 
	 * \param wxNotebook*   
	*/

   wxNotebookSizer(wxNotebook*  notebook ) ;
	/**
	 * \brief Returns the notebook associated with the sizer. 
	*/

  wxNotebook* GetNotebook() ;
};


#endif
#endif
