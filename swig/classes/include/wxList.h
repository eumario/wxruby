// wxList.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxList_h_)
#define _wxList_h_
class wxList : public wxObject
{
public:
   wxList() ;
   wxList(unsigned int  key_type ) ;
   wxList(int  n , T * objects[] ) ;
   wxList(T * object ) ;
  virtual  ~wxList() ;
  wxNode<T> * Append(T * object ) ;
  wxNode<T> * Append(long  key , T * object ) ;
  wxNode<T> * Append(const wxString&  key , T * object ) ;
  void Clear() ;
  void DeleteContents(bool  destroy ) ;
  bool DeleteNode(wxNode<T> * node ) ;
  bool DeleteObject(T * object ) ;
  wxNode<T> * Find(T *  object ) ;
  wxNode<T> * Find(long  key ) ;
  wxNode<T> * Find(const wxString&  key ) ;
  size_t GetCount() const;
  wxNode<T> * GetFirst() ;
  wxNode<T> * GetLast() ;
  int IndexOf(T*  obj  ) ;
  wxNode<T> * Insert(T * object ) ;
  wxNode<T> * Insert(size_t  position , T * object ) ;
  wxNode<T> * Insert(wxNode<T> * node , T * object ) ;
  bool IsEmpty() const;
  wxNode<T> * Item(size_t  index ) const;
  wxNode<T> * Member(T * object ) ;
  wxNode<T> * Nth(int  n ) ;
  int Number() ;
  void Sort(wxSortCompareFunction  compfunc ) ;
};


#endif
