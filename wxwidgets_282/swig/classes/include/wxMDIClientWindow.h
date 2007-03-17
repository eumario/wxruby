// wxMDIClientWindow.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMDIClientWindow_h_)
#define _wxMDIClientWindow_h_
class wxMDIClientWindow : public wxWindow
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxMDIClientWindow() ;
	/**
	 * \brief Constructor, creating the window. 
	 * \param wxMDIParentFrame*   
	 * \param long  
	*/

   wxMDIClientWindow(wxMDIParentFrame*  parent , long style = 0) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxMDIClientWindow() ;
	/**
	 * \brief Used in two-step frame construction. See  
for further details. 
	 * \param wxMDIParentFrame*   
	 * \param long  
	*/

  bool CreateClient(wxMDIParentFrame*  parent , long style = 0) ;
};


#endif
