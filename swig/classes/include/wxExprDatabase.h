// wxExprDatabase.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxExprDatabase_h_)
#define _wxExprDatabase_h_
class wxExprDatabase : public wxList
{
public:
   wxExprDatabase(proioErrorHandler handler = 0) ;
   wxExprDatabase(wxExprType  type , const wxString& attribute , int size = 500, proioErrorHandler handler = 0) ;
  virtual  ~wxExprDatabase() ;
  void Append(wxExpr*  clause ) ;
  void BeginFind() ;
  void ClearDatabase() ;
  wxExpr*  FindClause(long  id ) ;
  wxExpr*  FindClause(const wxString&  attribute , const wxString&  value ) ;
  wxExpr* FindClause(const wxString&  attribute , long  value ) ;
  wxExpr* FindClause(const wxString&  attribute , float  value ) ;
  wxExpr* FindClauseByFunctor(const wxString&  functor ) ;
  int GetErrorCount() const;
  wxExpr* HashFind(const wxString&  functor , long  value ) const;
  wxExpr* HashFind(const wxString&  functor , const wxString&  value ) ;
  bool Read(const wxString&  filename ) ;
  bool ReadFromString(const wxString&  buffer ) ;
  bool Write(FILE * stream ) ;
  bool Write(const wxString&  filename ) ;
};


#endif
