// wxArrayString.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxArrayString_h_)
#define _wxArrayString_h_
class wxArrayString
{
public:
   wxArrayString() ;
   wxArrayString(const wxArrayString&  array ) ;
  virtual  ~wxArrayString() ;
  size_t Add(const wxString&  str , size_t copies = 1) ;
  void Alloc(size_t  nCount ) ;
  void Clear() ;
  size_t Count() const;
  void Empty() ;
  size_t GetCount() const;
  int Index(const char *  sz , bool bCase = true, bool bFromEnd = false) ;
  void Insert(const wxString&  str , size_t  nIndex , size_t  copies = 1) ;
   IsEmpty() ;
  wxString& Item(size_t  nIndex ) const;
   Last() ;
  void Remove(const char *  sz ) ;
  void Remove(size_t  nIndex , size_t  count = 1) ;
  void Shrink() ;
  void Sort(bool reverseOrder = false) ;
  void Sort(CompareFunction  compareFunction ) ;
};


#endif
