// wxHashTable.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHashTable_h_)
#define _wxHashTable_h_
class wxHashTable : public wxObject
{
public:
   wxHashTable(unsigned int  key_type , int size = 1000) ;
  virtual  ~wxHashTable() ;
  void BeginFind() ;
  void Clear() ;
  wxObject * Delete(long  key ) ;
  wxObject * Delete(const wxString&   key ) ;
  void DeleteContents(bool  flag ) ;
  wxObject * Get(long  key ) ;
  wxObject * Get(const char*  key ) ;
  long MakeKey(const wxString&  string ) ;
  wxNode * Next() ;
  void Put(long  key , wxObject * object ) ;
  void Put(const char*  key , wxObject * object ) ;
  size_t GetCount() const;
};


#endif
