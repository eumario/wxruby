// wxScrollBar.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxScrollBar_h_)
#define _wxScrollBar_h_
class wxScrollBar : public wxControl
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxScrollBar() ;
	/**
	 * \brief  
	 * \param wxWindow*  
	 * \param wxWindowID   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

   wxScrollBar(wxWindow*  parent , wxWindowID  id , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxSB_HORIZONTAL, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("scrollBar")) ;
	/**
	 * \brief Destructor, destroying the scrollbar. 
	*/

  virtual  ~wxScrollBar() ;
	/**
	 * \brief Scrollbar creation function called by the scrollbar constructor.
See   for details. 
	 * \param wxWindow*  
	 * \param wxWindowID   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxSB_HORIZONTAL, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("scrollBar")) ;
	/**
	 * \brief Returns the length of the scrollbar. 
	*/

  int GetRange() const;
	/**
	 * \brief Returns the page size of the scrollbar. This is the number of scroll units
that will be scrolled when the user pages up or down. Often it is the
same as the thumb size. 
	*/

  int GetPageSize() const;
	/**
	 * \brief Returns the current position of the scrollbar thumb. 
	*/

  int GetThumbPosition() const;
	/**
	 * \brief Returns the thumb or `view' size. 
	*/

  int GetThumbLength() const;
	/**
	 * \brief Sets the object length for the scrollbar. This is the total object size (virtual size). You must
call     calling SetObjectLength. 
	 * \param int  
	*/

  void SetObjectLength(int  objectLength ) ;
	/**
	 * \brief Sets the page size for the scrollbar. This is the number of scroll units which are scrolled when the
user pages down (clicks on the scrollbar outside the thumbtrack area). 
	 * \param int  
	*/

  void SetPageSize(int  pageSize ) ;
	/**
	 * \brief Sets the position of the scrollbar. 
	 * \param int  
	*/

  void SetThumbPosition(int  viewStart ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param const bool   
	*/

  virtual void SetScrollbar(int  position , int  thumbSize , int  range , int  pageSize , const bool  refresh = true) ;
	/**
	 * \brief Sets the view length for the scrollbar. 
	 * \param int  
	*/

  void SetViewLength(int  viewLength ) ;
};


#endif
