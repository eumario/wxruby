// wxHashMap.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHashMap_h_)
#define _wxHashMap_h_
class wxHashMap
{
public:
   wxHashMap(size_type size = 10) ;
   wxHashMap(const wxHashMap&  map ) ;
  const_iterator begin() const;
  iterator begin() ;
  void clear() ;
  size_type count(const key_type&  key ) const;
  bool empty() const;
  const_iterator end() const;
  iterator end() ;
  size_type erase(const key_type&  key ) ;
  void erase(iterator  it ) ;
  void erase(const_iterator  it ) ;
  iterator find(const key_type&  key ) ;
  const_iterator find(const key_type&  key ) const;
  void insert(const value_type&  v ) ;
  size_type size() const;
};


#endif
