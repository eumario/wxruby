// wxLayoutAlgorithm.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxLayoutAlgorithm_h_)
#define _wxLayoutAlgorithm_h_
class wxLayoutAlgorithm : public wxObject
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxLayoutAlgorithm() ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxLayoutAlgorithm() ;
	/**
	 * \brief Lays out the children of a normal frame.   is set to occupy the remaining space.

This function simply calls  . 
	 * \param wxFrame*   
	 * \param wxWindow*  
	*/

  bool LayoutFrame(wxFrame*  frame , wxWindow* mainWindow = NULL) const;
	/**
	 * \brief Lays out the children of an MDI parent frame. If   is non-NULL, the
given rectangle will be used as a starting point instead of the frame's client area.

The MDI client window is set to occupy the remaining space. 
	 * \param wxMDIParentFrame*   
	 * \param wxRect*  
	*/

  bool LayoutMDIFrame(wxMDIParentFrame*  frame , wxRect* rect = NULL) const;
	/**
	 * \brief Lays out the children of a normal frame or other window.

  is set to occupy the remaining space. If this is not specified, then
the last window that responds to a calculate layout event in query mode will get the remaining space
(that is, a non-query OnCalculateLayout event will not be sent to this window and the window will be set
to the remaining size). 
	 * \param wxWindow*   
	 * \param wxWindow*  
	*/

  bool LayoutWindow(wxWindow*  parent , wxWindow* mainWindow = NULL) const;
};


#endif
