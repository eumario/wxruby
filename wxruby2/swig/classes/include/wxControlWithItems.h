// wxControlWithItems.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxControlWithItems_h_)
#define _wxControlWithItems_h_
class wxControlWithItems : public wxControl
{
public:
  int Append(const wxString&   item )  = 0;
  int Append(const wxString&   item , void * clientData )  = 0;
  int Append(const wxString&   item , wxClientData * clientData )  = 0;
  void Append(const wxArrayString&  strings )  = 0;
  void Clear()  = 0;
  void Delete(int  n )  = 0;
  int FindString(const wxString&  string )  = 0;
  void * GetClientData(int  n ) const;
  wxClientData * GetClientObject(int  n ) const;
  int GetCount() const = 0;
  int GetSelection() const = 0;
  wxString GetString(int  n ) const = 0;
  wxString GetStringSelection() const;
  int Insert(const wxString&   item , int  pos ) ;
  int Insert(const wxString&   item , int  pos , void * clientData ) ;
  int Insert(const wxString&   item , int  pos , wxClientData * clientData ) ;
  bool IsEmpty() const;
  int Number() const;
  void SetClientData(int  n , void * data ) ;
  void SetClientObject(int  n , wxClientData * data ) ;
  void SetSelection(int  n ) ;
  void SetString(int  n , const wxString&   string )  = 0;
  void SetStringSelection(const wxString&   string ) ;
};


#endif
