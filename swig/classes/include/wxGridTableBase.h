// wxGridTableBase.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridTableBase_h_)
#define _wxGridTableBase_h_
class wxGridTableBase : public wxObject
{
public:
   wxGridTableBase() ;
  virtual  ~wxGridTableBase() ;
  int GetNumberRows() ;
  int GetNumberCols() ;
  bool IsEmptyCell(int  row , int  col ) ;
  wxString GetValue(int  row , int  col ) ;
  void SetValue(int  row , int  col , const wxString&  value ) ;
  wxString GetTypeName(int  row , int  col ) ;
  bool CanGetValueAs(int  row , int  col , const wxString&  typeName ) ;
  bool CanSetValueAs(int  row , int  col , const wxString&  typeName ) ;
  long GetValueAsLong(int  row , int  col ) ;
  double GetValueAsDouble(int  row , int  col ) ;
  bool GetValueAsBool(int  row , int  col ) ;
  void SetValueAsLong(int  row , int  col , long  value ) ;
  void SetValueAsDouble(int  row , int  col , double  value ) ;
  void SetValueAsBool(int  row , int  col , bool  value ) ;
  void* GetValueAsCustom(int  row , int  col , const wxString&  typeName ) ;
  void SetValueAsCustom(int  row , int  col , const wxString&  typeName , void*  value ) ;
  void SetView(wxGrid*  grid ) ;
  wxGrid * GetView() const;
  void Clear() ;
  bool InsertRows(size_t  pos = 0, size_t  numRows = 1) ;
  bool AppendRows(size_t  numRows = 1) ;
  bool DeleteRows(size_t  pos = 0, size_t  numRows = 1) ;
  bool InsertCols(size_t  pos = 0, size_t  numCols = 1) ;
  bool AppendCols(size_t  numCols = 1) ;
  bool DeleteCols(size_t  pos = 0, size_t  numCols = 1) ;
  wxString GetRowLabelValue(int  row ) ;
  wxString GetColLabelValue(int  col ) ;
  void SetRowLabelValue(int  WXUNUSED(row) , const  wxString& ) ;
  void SetColLabelValue(int  WXUNUSED(col) , const  wxString& ) ;
  void SetAttrProvider(wxGridCellAttrProvider*  attrProvider ) ;
  wxGridCellAttrProvider* GetAttrProvider() const;
  bool CanHaveAttributes() ;
  void UpdateAttrRows(size_t  pos , int  numRows ) ;
  void UpdateAttrCols(size_t  pos , int  numCols ) ;
  wxGridCellAttr* GetAttr(int  row , int  col ) ;
  void SetAttr(wxGridCellAttr*  attr , int  row , int  col ) ;
  void SetRowAttr(wxGridCellAttr*  attr , int  row ) ;
  void SetColAttr(wxGridCellAttr*  attr , int  col ) ;
};


#endif
