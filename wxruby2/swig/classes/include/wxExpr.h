// wxExpr.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxExpr_h_)
#define _wxExpr_h_
class wxExpr
{
public:
   wxExpr(const wxString& functor ) ;
   wxExpr(wxExprType  type , const wxString& wordOrString = "") ;
   wxExpr(long  value ) ;
   wxExpr(float  value ) ;
   wxExpr(wxList*  value ) ;
  virtual  ~wxExpr() ;
  void AddAttributeValue(const wxString&  attribute , float  value ) ;
  void AddAttributeValue(const wxString&  attribute , long  value ) ;
  void AddAttributeValue(const wxString&  attribute , wxList*  value ) ;
  void AddAttributeValue(const wxString&  attribute , wxExpr*  value ) ;
  void AddAttributeValueString(const wxString&  attribute , const wxString&  value ) ;
  void AddAttributeValueStringList(const wxString&  attribute , wxList*  value ) ;
  void AddAttributeValueWord(const wxString&  attribute , const wxString&  value ) ;
  void Append(wxExpr*  value ) ;
  wxExpr*  Arg(wxExprType  type , int  n ) const;
  void Insert(wxExpr*  value ) ;
  bool GetAttributeValue(const wxString&  attribute , wxString&  value ) const;
  bool GetAttributeValue(const wxString&  attribute , float&  value ) const;
  bool GetAttributeValue(const wxString&  attribute , int&  value ) const;
  bool GetAttributeValue(const wxString&  attribute , long&  value ) const;
  bool GetAttributeValue(const wxString&  attribute , wxExpr**  value ) const;
  void GetAttributeValueStringList(const wxString& attribute , wxList*  value ) const;
  wxExpr* AttributeValue(const wxString&  word ) const;
  wxExpr* Copy() const;
  void DeleteAttributeValue(const wxString&  attribute ) ;
  wxString Functor() const;
  wxObject* GetClientData() const;
  wxExpr* GetFirst() const;
  wxExpr* GetLast() const;
  wxExpr* GetNext() const;
  long IntegerValue() const;
  wxExpr* Nth(int  n ) const;
  float RealValue() const;
  void SetClientData(wxObject * data ) ;
  wxString StringValue() const;
  wxExprType Type() const;
  wxString WordValue() const;
  void WriteClause(FILE *  stream ) ;
  void WriteExpr(FILE *  stream ) ;
};


#endif
