// wxGridCellAttr.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridCellAttr_h_)
#define _wxGridCellAttr_h_
class wxGridCellAttr
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxGridCellAttr() ;
	/**
	 * \brief VZ: considering the number of members wxGridCellAttr has now, this ctor
seems to be pretty useless... may be we should just remove it? 
	 * \param const wxColour&   
	 * \param const wxColour&   
	 * \param const wxFont&   
	 * \param int   
	 * \param int   
	*/

   wxGridCellAttr(const wxColour&  colText , const wxColour&  colBack , const wxFont&  font , int  hAlign , int  vAlign ) ;
	/**
	 * \brief Creates a new copy of this object. 
	*/

  wxGridCellAttr* Clone() const;
	/**
	 * \brief This class is ref counted: it is created with ref count of 1, so
calling DecRef() once will delete it. Calling IncRef() allows to lock
it until the matching DecRef() is called 
	*/

  void IncRef() ;
	/**
	 * \brief  
	*/

  void DecRef() ;
	/**
	 * \brief Sets the text colour. 
	 * \param const wxColour&   
	*/

  void SetTextColour(const wxColour&  colText ) ;
	/**
	 * \brief Sets the background colour. 
	 * \param const wxColour&   
	*/

  void SetBackgroundColour(const wxColour&  colBack ) ;
	/**
	 * \brief Sets the font. 
	 * \param const wxFont&   
	*/

  void SetFont(const wxFont&  font ) ;
	/**
	 * \brief Sets the alignment. 
	 * \param int   
	 * \param int   
	*/

  void SetAlignment(int  hAlign , int  vAlign ) ;
	/**
	 * \brief  
	 * \param bool   
	*/

  void SetReadOnly(bool  isReadOnly = true) ;
	/**
	 * \brief takes ownership of the pointer 
	 * \param wxGridCellRenderer*   
	*/

  void SetRenderer(wxGridCellRenderer*  renderer ) ;
	/**
	 * \brief  
	 * \param wxGridCellEditor*   
	*/

  void SetEditor(wxGridCellEditor*  editor ) ;
	/**
	 * \brief accessors 
	*/

  bool HasTextColour() const;
	/**
	 * \brief  
	*/

  bool HasBackgroundColour() const;
	/**
	 * \brief  
	*/

  bool HasFont() const;
	/**
	 * \brief  
	*/

  bool HasAlignment() const;
	/**
	 * \brief  
	*/

  bool HasRenderer() const;
	/**
	 * \brief  
	*/

  bool HasEditor() const;
	/**
	 * \brief  
	*/

  const wxColour& GetTextColour() const;
	/**
	 * \brief  
	*/

  const wxColour& GetBackgroundColour() const;
	/**
	 * \brief  
	*/

  const wxFont& GetFont() const;
	/**
	 * \brief \perlnote{This method takes no parameters and
returns a 2-element list  .} 
	 * \param int*   
	 * \param int*   
	*/

  void GetAlignment(int*  hAlign , int*  vAlign ) const;
	/**
	 * \brief  
	 * \param wxGrid*   
	 * \param int   
	 * \param int   
	*/

  wxGridCellRenderer* GetRenderer(wxGrid*  grid , int  row , int  col ) const;
	/**
	 * \brief  
	 * \param wxGrid*   
	 * \param int   
	 * \param int   
	*/

  wxGridCellEditor* GetEditor(wxGrid*  grid , int  row , int  col ) const;
	/**
	 * \brief  
	*/

  bool IsReadOnly() const;
	/**
	 * \brief  
	 * \param wxGridCellAttr*   
	*/

  void SetDefAttr(wxGridCellAttr*  defAttr ) ;
};


#endif
