// wxString.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxString_h_)
#define _wxString_h_
class wxString
{
public:
   wxString() ;
   wxString(const wxString&  x ) ;
   wxString(char  ch , size_t n = 1) ;
   wxString(const char*  psz , size_t nLength = wxSTRING_MAXLEN) ;
   wxString(const unsigned char*  psz , size_t nLength = wxSTRING_MAXLEN) ;
   wxString(const wchar_t*  psz ) ;
  virtual  ~wxString() ;
  void Alloc(size_t  nLen ) ;
  wxString& Append(const char*  psz ) ;
  wxString& Append(char  ch , int count = 1) ;
  wxString AfterFirst(char  ch ) const;
  wxString AfterLast(char  ch ) const;
  wxString BeforeFirst(char  ch ) const;
  wxString BeforeLast(char  ch ) const;
  const char * c_str() const;
  void Clear() ;
  int Cmp(const char*  psz ) const;
  int CmpNoCase(const char*  psz ) const;
  int CompareTo(const char*  psz , caseCompare cmp = exact) const;
  bool Contains(const wxString&  str ) const;
  void Empty() ;
  int Find(char  ch , bool fromEnd = false) const;
  int Find(const char*  sz ) const;
  int First(char  c ) ;
  int First(const char*  psz ) const;
  int First(const wxString&  str ) const;
  static wxString Format(const wxChar  *format ,  ... ) ;
  static wxString FormatV(const wxChar  *format , va_list  argptr ) ;
  int Freq(char  ch ) const;
  char GetChar(size_t  n ) const;
  const char* GetData() const;
  char& GetWritableChar(size_t  n ) ;
  wxChar* GetWriteBuf(size_t  len ) ;
  size_t Index(char  ch ) const;
  size_t Index(const char*  sz ) const;
  size_t Index(const char*  sz , bool caseSensitive = true, bool fromEnd = false) const;
  bool IsAscii() const;
  bool IsEmpty() const;
  bool IsNull() const;
  bool IsNumber() const;
  bool IsSameAs(const char*  psz , bool caseSensitive = true) const;
  bool IsSameAs(char  c , bool caseSensitive = true) const;
  bool IsWord() const;
  char Last() const;
  char& Last() ;
  wxString Left(size_t  count ) const;
  size_t Len() const;
  size_t Length() const;
  wxString Lower() const;
  void LowerCase() ;
  wxString& MakeLower() ;
  wxString& MakeUpper() ;
  bool Matches(const char*  szMask ) const;
  wxString Mid(size_t  first , size_t count = wxSTRING_MAXLEN) const;
  wxString& Pad(size_t  count , char pad = ', bool fromRight = true) ;
  wxString& Prepend(const wxString&  str ) ;
  int Printf(const char*  pszFormat ,  ... ) ;
  int PrintfV(const char*  pszFormat , va_list  argPtr ) ;
  wxString& Remove(size_t  pos ) ;
  wxString& Remove(size_t  pos , size_t  len ) ;
  wxString& RemoveLast() ;
  size_t Replace(const char*  szOld , const char*  szNew , bool replaceAll = true) ;
  wxString Right(size_t  count ) const;
  void SetChar(size_t  n , char ch ) ;
  void Shrink() ;
  void sprintf(const char*   fmt ) ;
  bool StartsWith(const wxChar  *prefix , wxString  *rest = NULL) const;
  wxString Strip(stripType s = trailing) const;
  wxString SubString(size_t  from , size_t  to ) const;
  bool ToDouble(double  *val ) const;
  bool ToLong(long  *val , int  base = 10) const;
  bool ToULong(unsigned long  *val , int  base = 10) const;
  wxString& Trim(bool fromRight = true) ;
  wxString& Truncate(size_t  len ) ;
  void UngetWriteBuf() ;
  void UngetWriteBuf(size_t  len ) ;
  wxString Upper() const;
  void UpperCase() ;
};


#endif
