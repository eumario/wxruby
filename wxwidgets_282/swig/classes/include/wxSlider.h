// wxSlider.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSlider_h_)
#define _wxSlider_h_
class wxSlider : public wxControl
{
public:
	/**
	 * \brief Default slider. 
	*/

   wxSlider() ;
	/**
	 * \brief  
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param int   
	 * \param int  
	 * \param int  
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

   wxSlider(wxWindow*  parent , wxWindowID  id , int  value  , int  minValue , int  maxValue , const wxPoint&  point = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxSL_HORIZONTAL, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("slider")) ;
	/**
	 * \brief Destructor, destroying the slider. 
	*/

  virtual  ~wxSlider() ;
	/**
	 * \brief Clears the selection, for a slider with the   style. 
	*/

  void ClearSel() ;
	/**
	 * \brief Clears the ticks. 
	*/

  void ClearTicks() ;
	/**
	 * \brief Used for two-step slider construction. See  
for further details. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param int   
	 * \param int  
	 * \param int  
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , int  value  , int  minValue , int  maxValue , const wxPoint&  point = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxSL_HORIZONTAL, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("slider")) ;
	/**
	 * \brief Returns the line size. 
	*/

  int GetLineSize() const;
	/**
	 * \brief  
	*/

  int GetMax() const;
	/**
	 * \brief  
	*/

  int GetMin() const;
	/**
	 * \brief Returns the page size. 
	*/

  int GetPageSize() const;
	/**
	 * \brief  
	*/

  int GetSelEnd() const;
	/**
	 * \brief  
	*/

  int GetSelStart() const;
	/**
	 * \brief Returns the thumb length. 
	*/

  int GetThumbLength() const;
	/**
	 * \brief Returns the tick frequency. 
	*/

  int GetTickFreq() const;
	/**
	 * \brief  
	*/

  int GetValue() const;
	/**
	 * \brief  
	 * \param int  
	 * \param int  
	*/

  void SetRange(int  minValue , int  maxValue ) ;
	/**
	 * \brief Sets the tick mark frequency and position. 
	 * \param int   
	 * \param int   
	*/

  void SetTickFreq(int  n , int  pos ) ;
	/**
	 * \brief Sets the line size for the slider. 
	 * \param int   
	*/

  void SetLineSize(int  lineSize ) ;
	/**
	 * \brief Sets the page size for the slider. 
	 * \param int   
	*/

  void SetPageSize(int  pageSize ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  void SetSelection(int  startPos , int  endPos ) ;
	/**
	 * \brief Sets the slider thumb length. 
	 * \param int   
	*/

  void SetThumbLength(int  len ) ;
	/**
	 * \brief Sets a tick position. 
	 * \param int  
	*/

  void SetTick(int  tickPos ) ;
	/**
	 * \brief Sets the slider position. 
	 * \param int  
	*/

  void SetValue(int  value ) ;
};


#endif
