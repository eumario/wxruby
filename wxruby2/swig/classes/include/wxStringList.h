// wxStringList.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxStringList_h_)
#define _wxStringList_h_
class wxStringList : public wxList
{
public:
   wxStringList() ;
   wxStringList(char*  first ) ;
  virtual  ~wxStringList() ;
  wxNode * Add(const wxString&  s ) ;
  void Clear() ;
  void Delete(const wxString&  s ) ;
  char* ListToArray(bool new_copies = false) ;
  bool Member(const wxString&  s ) ;
  void Sort() ;
};


#endif
