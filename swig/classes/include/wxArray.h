// wxArray.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxArray_h_)
#define _wxArray_h_
class wxArray
{
public:
  virtual  ~wxArray() ;
  virtual  ~wxArray() ;
  virtual  ~wxArray() ;
  void Add(T  item , size_t copies = 1) ;
  void Add(T * item ) ;
  void Add(T & item , size_t copies = 1) ;
  void Alloc(size_t  count ) ;
  void Clear() ;
  size_t Count() const;
  T * Detach(size_t  index ) ;
  void Empty() ;
  size_t GetCount() const;
  int Index(T&  item , bool  searchFromEnd = false) ;
  int Index(T&  item ) ;
  void Insert(T  item , size_t  n , size_t  copies = 1) ;
  void Insert(T * item , size_t  n ) ;
  void Insert(T & item , size_t  n , size_t  copies = 1) ;
  bool IsEmpty() const;
  T& Item(size_t  index ) const;
  T& Last() const;
  void Remove(T  item ) ;
  void RemoveAt(size_t  index , size_t  count = 1) ;
  void SetCount(size_t  count , T  defval = T(0)) ;
  void Shrink() ;
  void Sort(CMPFUNC<T>  compareFunction ) ;
};


#endif
