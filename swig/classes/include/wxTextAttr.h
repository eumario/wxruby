// wxTextAttr.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTextAttr_h_)
#define _wxTextAttr_h_
class wxTextAttr
{
public:
	/**
	 * \brief  
	*/

   wxTextAttr() ;
	/**
	 * \brief The constructors initialize one or more of the text foreground colour, background
colour, font, and alignment. The values not initialized in the constructor can be set
later, otherwise   will use
the default values for them. 
	 * \param const wxColour&   
	 * \param const wxColour&   
	 * \param const wxFont&   
	 * \param wxTextAttrAlignment   
	*/

   wxTextAttr(const wxColour&  colText , const wxColour&  colBack = wxNullColour, const wxFont&  font = wxNullFont, wxTextAttrAlignment  alignment = wxTEXT_ALIGNMENT_DEFAULT) ;
	/**
	 * \brief Returns the paragraph alignment. 
	*/

  wxTextAttrAlignment GetAlignment() const;
	/**
	 * \brief Return the background colour specified by this attribute. 
	*/

  const wxColour& GetBackgroundColour() const;
	/**
	 * \brief Return the text font specified by this attribute. 
	*/

  const wxFont& GetFont() const;
	/**
	 * \brief Returns the left indent in tenths of a millimetre. 
	*/

  int GetLeftIndent() const;
	/**
	 * \brief Returns the right indent in tenths of a millimetre. 
	*/

  int GetRightIndent() const;
	/**
	 * \brief Returns the array of integers representing the tab stops. Each
array element specifies the tab stop in tenths of a millimetre. 
	*/

  const wxArrayInt& GetTabs() const;
	/**
	 * \brief Return the text colour specified by this attribute. 
	*/

  const wxColour& GetTextColour() const;
	/**
	 * \brief Returns   if this style specifies the background colour to use. 
	*/

  bool HasBackgroundColour() const;
	/**
	 * \brief Returns   if this style specifies the font to use. 
	*/

  bool HasFont() const;
	/**
	 * \brief Returns   if this style specifies the foreground colour to use. 
	*/

  bool HasTextColour() const;
	/**
	 * \brief Returns a bitlist indicating which attributes will be set. 
	*/

  long GetFlags() ;
	/**
	 * \brief Returns   if this style specifies any non-default attributes. 
	*/

  bool IsDefault() const;
	/**
	 * \brief Sets the paragraph alignment. 
	 * \param wxTextAttrAlignment  
	*/

  void SetAlignment(wxTextAttrAlignment  alignment ) ;
	/**
	 * \brief Sets the background colour. 
	 * \param const wxColour&   
	*/

  void SetBackgroundColour(const wxColour&  colour ) ;
	/**
	 * \brief Pass a bitlist indicating which attributes will be set. 
	 * \param long  
	*/

  void SetFlags(long  flags ) ;
	/**
	 * \brief Sets the text font. 
	 * \param const wxFont&  
	*/

  void SetFont(const wxFont&  font ) ;
	/**
	 * \brief Sets the left indent in tenths of a millimetre. 
	 * \param int   
	*/

  void SetLeftIndent(int  indent ) ;
	/**
	 * \brief Sets the right indent in tenths of a millimetre. 
	 * \param int   
	*/

  void SetRightIndent(int  indent ) ;
	/**
	 * \brief Sets the array of integers representing the tab stops. Each
array element specifies the tab stop in tenths of a millimetre. 
	 * \param const wxArrayInt&  
	*/

  void SetTabs(const wxArrayInt&  tabs ) ;
	/**
	 * \brief Sets the text colour. 
	 * \param const wxColour&   
	*/

  void SetTextColour(const wxColour&  colour ) ;
};


#endif
