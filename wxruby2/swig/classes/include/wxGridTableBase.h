// wxGridTableBase.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridTableBase_h_)
#define _wxGridTableBase_h_
class wxGridTableBase : public wxObject
{
public:
	/**
	 * \brief  
	*/

   wxGridTableBase() ;
	/**
	 * \brief  
	*/

  virtual  ~wxGridTableBase() ;
	/**
	 * \brief You must override these functions in a derived table class. 
	*/

  int GetNumberRows() ;
	/**
	 * \brief  
	*/

  int GetNumberCols() ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  bool IsEmptyCell(int  row , int  col ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  wxString GetValue(int  row , int  col ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	 * \param const wxString&   
	*/

  void SetValue(int  row , int  col , const wxString&  value ) ;
	/**
	 * \brief Data type determination and value access. 
	 * \param int   
	 * \param int   
	*/

  wxString GetTypeName(int  row , int  col ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	 * \param const wxString&   
	*/

  bool CanGetValueAs(int  row , int  col , const wxString&  typeName ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	 * \param const wxString&   
	*/

  bool CanSetValueAs(int  row , int  col , const wxString&  typeName ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  long GetValueAsLong(int  row , int  col ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  double GetValueAsDouble(int  row , int  col ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  bool GetValueAsBool(int  row , int  col ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	 * \param long   
	*/

  void SetValueAsLong(int  row , int  col , long  value ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	 * \param double   
	*/

  void SetValueAsDouble(int  row , int  col , double  value ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	 * \param bool   
	*/

  void SetValueAsBool(int  row , int  col , bool  value ) ;
	/**
	 * \brief For user defined types 
	 * \param int   
	 * \param int   
	 * \param const wxString&   
	*/

  void* GetValueAsCustom(int  row , int  col , const wxString&  typeName ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	 * \param const wxString&   
	 * \param void*   
	*/

  void SetValueAsCustom(int  row , int  col , const wxString&  typeName , void*  value ) ;
	/**
	 * \brief Overriding these is optional 
	 * \param wxGrid*   
	*/

  void SetView(wxGrid*  grid ) ;
	/**
	 * \brief  
	*/

  wxGrid * GetView() const;
	/**
	 * \brief  
	*/

  void Clear() ;
	/**
	 * \brief  
	 * \param size_t   
	 * \param size_t   
	*/

  bool InsertRows(size_t  pos = 0, size_t  numRows = 1) ;
	/**
	 * \brief  
	 * \param size_t   
	*/

  bool AppendRows(size_t  numRows = 1) ;
	/**
	 * \brief  
	 * \param size_t   
	 * \param size_t   
	*/

  bool DeleteRows(size_t  pos = 0, size_t  numRows = 1) ;
	/**
	 * \brief  
	 * \param size_t   
	 * \param size_t   
	*/

  bool InsertCols(size_t  pos = 0, size_t  numCols = 1) ;
	/**
	 * \brief  
	 * \param size_t   
	*/

  bool AppendCols(size_t  numCols = 1) ;
	/**
	 * \brief  
	 * \param size_t   
	 * \param size_t   
	*/

  bool DeleteCols(size_t  pos = 0, size_t  numCols = 1) ;
	/**
	 * \brief  
	 * \param int   
	*/

  wxString GetRowLabelValue(int  row ) ;
	/**
	 * \brief  
	 * \param int   
	*/

  wxString GetColLabelValue(int  col ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param const   
	*/

  void SetRowLabelValue(int  WXUNUSED(row) , const  wxString& ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param const   
	*/

  void SetColLabelValue(int  WXUNUSED(col) , const  wxString& ) ;
	/**
	 * \brief Attribute handling
give us the attr provider to use - we take ownership of the pointer 
	 * \param wxGridCellAttrProvider*   
	*/

  void SetAttrProvider(wxGridCellAttrProvider*  attrProvider ) ;
	/**
	 * \brief get the currently used attr provider (may be NULL) 
	*/

  wxGridCellAttrProvider* GetAttrProvider() const;
	/**
	 * \brief Does this table allow attributes?  Default implementation creates
a wxGridCellAttrProvider if necessary. 
	*/

  bool CanHaveAttributes() ;
	/**
	 * \brief change row/col number in attribute if needed 
	 * \param size_t   
	 * \param int   
	*/

  void UpdateAttrRows(size_t  pos , int  numRows ) ;
	/**
	 * \brief  
	 * \param size_t   
	 * \param int   
	*/

  void UpdateAttrCols(size_t  pos , int  numCols ) ;
	/**
	 * \brief by default forwarded to wxGridCellAttrProvider if any. May be
overridden to handle attributes directly in the table. 
	 * \param int   
	 * \param int   
	*/

  wxGridCellAttr* GetAttr(int  row , int  col ) ;
	/**
	 * \brief these functions take ownership of the pointer 
	 * \param wxGridCellAttr*   
	 * \param int   
	 * \param int   
	*/

  void SetAttr(wxGridCellAttr*  attr , int  row , int  col ) ;
	/**
	 * \brief  
	 * \param wxGridCellAttr*   
	 * \param int   
	*/

  void SetRowAttr(wxGridCellAttr*  attr , int  row ) ;
	/**
	 * \brief  
	 * \param wxGridCellAttr*   
	 * \param int   
	*/

  void SetColAttr(wxGridCellAttr*  attr , int  col ) ;
};


#endif
