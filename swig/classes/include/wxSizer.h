// wxSizer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSizer_h_)
#define _wxSizer_h_
class wxSizer : public wxObject
{
public:
	/**
	 * \brief The constructor. Note that wxSizer is an abstract base class and may not
be instantiated. 
	*/

   wxSizer() ;
	/**
	 * \brief The destructor. 
	*/

  virtual  ~wxSizer() ;
	/**
	 * \brief  
	 * \param wxWindow*   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param wxObject*   
	*/

  void Add(wxWindow*  window , int  proportion = 0, int  flag = 0, int  border = 0, wxObject*  userData = NULL) ;
	/**
	 * \brief  
	 * \param wxSizer*   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param wxObject*   
	*/

  void Add(wxSizer*  sizer , int  proportion = 0, int  flag = 0, int  border = 0, wxObject*  userData = NULL) ;
	/**
	 * \brief Appends a child to the sizer.  wxSizer itself is an abstract class, but the parameters are
equivalent in the derived classes that you will instantiate to use it so they are described
here: 
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param wxObject*   
	*/

  void Add(int  width , int  height , int  proportion = 0, int  flag = 0, int  border = 0, wxObject*  userData = NULL) ;
	/**
	 * \brief This method is abstract and has to be overwritten by any derived class.
Here, the sizer will do the actual calculation of its children minimal sizes. 
	*/

  wxSize CalcMin()  = 0;
	/**
	 * \brief  
	 * \param wxWindow*   
	*/

  bool Detach(wxWindow*  window ) ;
	/**
	 * \brief  
	 * \param wxSizer*   
	*/

  bool Detach(wxSizer*  sizer ) ;
	/**
	 * \brief Detach a child from the sizer without destroying it.   is the window to be
detached,   is the equivalent sizer and   is the position of
the child in the sizer, typically 0 for the first item. This method does not
cause any layout or resizing to take place, call  
to update the layout &quot;on screen&quot; after detaching a child from the sizer.

Returns true if the child item was found and detached, false otherwise. 
	 * \param size_t   
	*/

  bool Detach(size_t  index ) ;
	/**
	 * \brief Tell the sizer to resize the   to match the sizer's minimal size. This
is commonly done in the constructor of the window itself, see sample in the description
of  . Returns the new size. 
	 * \param wxWindow*   
	*/

  wxSize Fit(wxWindow*  window ) ;
	/**
	 * \brief Tell the sizer to resize the virtual size of the   to match the sizer's
minimal size.  This will not alter the on screen size of the window, but may cause
the addition/removal/alteration of scrollbars required to view the virtual area in
windows which manage it. 
	 * \param wxWindow*   
	*/

  void FitInside(wxWindow*  window ) ;
	/**
	 * \brief Returns the current size of the sizer. 
	*/

  wxSize GetSize() ;
	/**
	 * \brief Returns the current position of the sizer. 
	*/

  wxPoint GetPosition() ;
	/**
	 * \brief Returns the minimal size of the sizer. This is either the combined minimal
size of all the children and their borders or the minimal size set by 
 , depending on which is bigger. 
	*/

  wxSize GetMinSize() ;
	/**
	 * \brief  
	 * \param size_t   
	 * \param wxWindow*   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param wxObject*   
	*/

  void Insert(size_t  index , wxWindow*  window , int  proportion = 0, int  flag = 0, int  border = 0, wxObject*  userData = NULL) ;
	/**
	 * \brief  
	 * \param size_t   
	 * \param wxSizer*   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param wxObject*   
	*/

  void Insert(size_t  index , wxSizer*  sizer , int  proportion = 0, int  flag = 0, int  border = 0, wxObject*  userData = NULL) ;
	/**
	 * \brief Insert a child into the sizer before any existing item at  .



See   for the meaning of the other parameters. 
	 * \param size_t   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param wxObject*   
	*/

  void Insert(size_t  index , int  width , int  height , int  proportion = 0, int  flag = 0, int  border = 0, wxObject*  userData = NULL) ;
	/**
	 * \brief Call this to force layout of the children anew, e.g. after having added a child
to or removed a child (window, other sizer or space) from the sizer while keeping
the current dimension. 
	*/

  void Layout() ;
	/**
	 * \brief  
	 * \param wxWindow*   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param wxObject*   
	*/

  void Prepend(wxWindow*  window , int  proportion = 0, int  flag = 0, int  border = 0, wxObject*  userData = NULL) ;
	/**
	 * \brief  
	 * \param wxSizer*   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param wxObject*   
	*/

  void Prepend(wxSizer*  sizer , int  proportion = 0, int  flag = 0, int  border = 0, wxObject*  userData = NULL) ;
	/**
	 * \brief Same as  , but prepends the items to the beginning of the
list of items (windows, subsizers or spaces) owned by this sizer. 
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param wxObject*   
	*/

  void Prepend(int  width , int  height , int  proportion = 0, int  flag = 0, int  border = 0, wxObject*  userData = NULL) ;
	/**
	 * \brief This method is abstract and has to be overwritten by any derived class.
Here, the sizer will do the actual calculation of its children's positions
and sizes. 
	*/

  void RecalcSizes()  = 0;
	/**
	 * \brief  
	 * \param wxWindow*   
	*/

  bool Remove(wxWindow*  window ) ;
	/**
	 * \brief  
	 * \param wxSizer*   
	*/

  bool Remove(wxSizer*  sizer ) ;
	/**
	 * \brief Removes a child from the sizer and destroys it.    is the wxSizer to be removed,
  is the position of the child in the sizer, typically 0 for the first item.
This method does not cause any layout or resizing to take place, call
  to update the layout &quot;on screen&quot; after removing a
child from the sizer.

  The method taking a wxWindow&#42; parameter is deprecated.  For historical reasons
it does not destroy the window as would usually be expected from Remove.  You should use
  in new code instead.  There is currently no wxSizer
method that will both detach and destroy a wxWindow item.

Returns true if the child item was found and removed, false otherwise. 
	 * \param size_t   
	*/

  bool Remove(size_t  index ) ;
	/**
	 * \brief Call this to force the sizer to take the given dimension and thus force the items owned
by the sizer to resize themselves according to the rules defined by the parameter in the 
  and   methods. 
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param int   
	*/

  void SetDimension(int  x , int  y , int  width , int  height ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  void SetMinSize(int  width , int  height ) ;
	/**
	 * \brief Call this to give the sizer a minimal size. Normally, the sizer will calculate its
minimal size based purely on how much space its children need. After calling this
method   will return either the minimal size
as requested by its children or the minimal size set here, depending on which is
bigger. 
	 * \param wxSize   
	*/

  void SetMinSize(wxSize  size ) ;
	/**
	 * \brief  
	 * \param wxWindow*   
	 * \param int  
	 * \param int  
	*/

  void SetItemMinSize(wxWindow*  window , int  width , int  height ) ;
	/**
	 * \brief  
	 * \param wxSizer*   
	 * \param int  
	 * \param int  
	*/

  void SetItemMinSize(wxSizer*  sizer , int  width , int  height ) ;
	/**
	 * \brief Set an item's minimum size by window, sizer, or position. The item will be found recursively
in the sizer's descendants. This function enables an application to set the size of an item
after initial creation. 
	 * \param size_t   
	 * \param int  
	 * \param int  
	*/

  void SetItemMinSize(size_t  index , int  width , int  height ) ;
	/**
	 * \brief Tell the sizer to set (and  ) the minimal size of the   to
match the sizer's minimal size.  This is commonly done in the constructor of the window itself,
see sample in the description of   if the window is resizable
(as are many dialogs under Unix and frames on probably all platforms). 
	 * \param wxWindow*   
	*/

  void SetSizeHints(wxWindow*  window ) ;
	/**
	 * \brief Tell the sizer to set the minimal size of the   virtual area to match the sizer's
minimal size. For windows with managed scrollbars this will set them appropriately. 
	 * \param wxWindow*   
	*/

  void SetVirtualSizeHints(wxWindow*  window ) ;
	/**
	 * \brief  
	 * \param wxWindow*   
	 * \param bool   
	*/

  void Show(wxWindow*  window , bool  show = true) ;
	/**
	 * \brief  
	 * \param wxSizer*   
	 * \param bool   
	*/

  void Show(wxSizer*  sizer , bool  show = true) ;
	/**
	 * \brief Shows or hides the  ,  , or item at  .
To make a sizer item disappear or reappear, use Show() followed by Layout().

Note that this only works with wxBoxSizer and wxFlexGridSizer, since they
are the only two sizer classes that can size rows/columns independently. 
	 * \param size_t   
	 * \param bool   
	*/

  void Show(size_t  index , bool  show = true) ;
};


#endif
