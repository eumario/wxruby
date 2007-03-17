// wxListItem.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxListItem_h_)
#define _wxListItem_h_
class wxListItem : public wxObject
{
public:
	/**
	 * \brief Constructor. 
	*/

   wxListItem() ;
	/**
	 * \brief Resets the item state to the default. 
	*/

  void Clear() ;
	/**
	 * \brief Returns the alignment for this item. Can be one of
wxLIST_FORMAT_LEFT, wxLIST_FORMAT_RIGHT or wxLIST_FORMAT_CENTRE. 
	*/

  wxListColumnFormat GetAlign() const;
	/**
	 * \brief Returns the background colour for this item. 
	*/

  wxColour GetBackgroundColour() const;
	/**
	 * \brief Returns the zero-based column; meaningful only in report mode. 
	*/

  int GetColumn() const;
	/**
	 * \brief Returns client data associated with the control. 
	*/

  long GetData() const;
	/**
	 * \brief Returns the font used to display the item. 
	*/

  wxFont GetFont() const;
	/**
	 * \brief Returns the zero-based item position. 
	*/

  long GetId() const;
	/**
	 * \brief Returns the zero-based index of the image
associated with the item into the image list. 
	*/

  int GetImage() const;
	/**
	 * \brief Returns a bit mask indicating which fields of the structure are valid;
can be any combination of the following values:

\twocolwidtha{5cm} 
	*/

  long GetMask() const;
	/**
	 * \brief Returns a bit field representing the state of the item. Can be any
combination of:

\twocolwidtha{5cm} 
	*/

  long GetState() const;
	/**
	 * \brief Returns the label/header text. 
	*/

  const wxString& GetText() const;
	/**
	 * \brief Returns the text colour. 
	*/

  wxColour GetTextColour() const;
	/**
	 * \brief Meaningful only for column headers in report mode. Returns the column width. 
	*/

  int GetWidth() const;
	/**
	 * \brief Sets the alignment for the item. See also 
	 * \param wxListColumnFormat   
	*/

  void SetAlign(wxListColumnFormat  align ) ;
	/**
	 * \brief Sets the background colour for the item. 
	 * \param const wxColour&   
	*/

  void SetBackgroundColour(const wxColour&  colBack ) ;
	/**
	 * \brief Sets the zero-based column. Meaningful only in report mode. 
	 * \param int   
	*/

  void SetColumn(int  col ) ;
	/**
	 * \brief  
	 * \param long   
	*/

  void SetData(long  data ) ;
	/**
	 * \brief Sets client data for the item. 
	 * \param void*   
	*/

  void SetData(void*  data ) ;
	/**
	 * \brief Sets the font for the item. 
	 * \param const wxFont&   
	*/

  void SetFont(const wxFont&  font ) ;
	/**
	 * \brief Sets the zero-based item position. 
	 * \param long   
	*/

  void SetId(long  id ) ;
	/**
	 * \brief Returns the zero-based index of the image associated with the item
into the image list. 
	 * \param int   
	*/

  void SetImage(int  image ) ;
	/**
	 * \brief Sets the mask of valid fields. See  . 
	 * \param long   
	*/

  void SetMask(long  mask ) ;
	/**
	 * \brief Sets the item state flags (note that the valid state flags are influenced
by the value of the state mask, see
 ).
See   for valid flag
values. 
	 * \param long   
	*/

  void SetState(long  state ) ;
	/**
	 * \brief Sets the bitmask that is used to determine which of the state flags
are to be set. See also  . 
	 * \param long   
	*/

  void SetStateMask(long  stateMask ) ;
	/**
	 * \brief Sets the text label for the item. 
	 * \param const wxString&   
	*/

  void SetText(const wxString&  text ) ;
	/**
	 * \brief Sets the text colour for the item. 
	 * \param const wxColour&   
	*/

  void SetTextColour(const wxColour&  colText ) ;
	/**
	 * \brief Meaningful only for column headers in report mode. Sets the column width. 
	 * \param int   
	*/

  void SetWidth(int  width ) ;
};


#endif
