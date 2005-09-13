// wxGridCellEditor.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridCellEditor_h_)
#define _wxGridCellEditor_h_
class wxGridCellEditor
{
public:
	/**
	 * \brief  
	*/

   wxGridCellEditor() ;
	/**
	 * \brief  
	*/

  bool IsCreated() ;
	/**
	 * \brief Creates the actual edit control. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param wxEvtHandler*   
	*/

  virtual void Create(wxWindow*  parent , wxWindowID  id , wxEvtHandler*  evtHandler ) = 0;
	/**
	 * \brief Size and position the edit control. 
	 * \param const wxRect&   
	*/

  virtual void SetSize(const wxRect&  rect ) ;
	/**
	 * \brief Show or hide the edit control, use the specified attributes to set
colours/fonts for it. 
	 * \param bool   
	 * \param wxGridCellAttr*   
	*/

  virtual void Show(bool  show , wxGridCellAttr*  attr = NULL) ;
	/**
	 * \brief Draws the part of the cell not occupied by the control: the base class
version just fills it with background colour from the attribute. 
	 * \param const wxRect&   
	 * \param wxGridCellAttr*   
	*/

  virtual void PaintBackground(const wxRect&  rectCell , wxGridCellAttr*  attr ) ;
	/**
	 * \brief Fetch the value from the table and prepare the edit control
to begin editing. Set the focus to the edit control. 
	 * \param int   
	 * \param int   
	 * \param wxGrid*   
	*/

  virtual void BeginEdit(int  row , int  col , wxGrid*  grid ) = 0;
	/**
	 * \brief Complete the editing of the current cell. Returns true if the value has
changed. If necessary, the control may be destroyed. 
	 * \param int   
	 * \param int   
	 * \param wxGrid*   
	*/

  virtual bool EndEdit(int  row , int  col , wxGrid*  grid ) = 0;
	/**
	 * \brief Reset the value in the control back to its starting value. 
	*/

  virtual void Reset() = 0;
	/**
	 * \brief If the editor is enabled by pressing keys on the grid,
this will be called to let the editor do something about
that first key if desired. 
	 * \param wxKeyEvent&   
	*/

  virtual void StartingKey(wxKeyEvent&  event ) ;
	/**
	 * \brief If the editor is enabled by clicking on the cell, this method will be
called. 
	*/

  virtual void StartingClick() ;
	/**
	 * \brief Some types of controls on some platforms may need some help
with the Return key. 
	 * \param wxKeyEvent&   
	*/

  virtual void HandleReturn(wxKeyEvent&  event ) ;
	/**
	 * \brief Final cleanup. 
	*/

  virtual void Destroy() ;
	/**
	 * \brief Create a new object which is the copy of this one. 
	*/

  virtual wxGridCellEditor* Clone() const = 0;

	// DJC MAPTEK
	// added GetValue so we can get the value which is in the control
	virtual wxString GetValue() const = 0;	
};


#endif
