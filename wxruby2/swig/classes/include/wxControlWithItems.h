// wxControlWithItems.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxControlWithItems_h_)
#define _wxControlWithItems_h_
class wxControlWithItems : public wxControl
{
public:

  virtual int Append(const wxString&   item )  = 0;
  virtual int Append(const wxString&   item , void * clientData )  = 0;
  virtual int Append(const wxString&   item , wxClientData * clientData )  = 0;
  virtual void Append(const wxArrayString&  strings )  = 0;
  virtual void Clear()  = 0;
  virtual void Delete(int  n )  = 0;
  virtual int FindString(const wxString&  string )  = 0;
  virtual void * GetClientData(int  n ) const = 0;
  virtual wxClientData * GetClientObject(int  n ) const = 0;
  virtual unsigned int GetCount() const = 0;
  virtual int GetSelection() const = 0;
  virtual wxString GetString(int  n ) const = 0;
  wxArrayString GetStrings() const;
  virtual wxString GetStringSelection() const = 0;
  virtual int Insert(const wxString&   item , int  pos ) = 0;
  virtual int Insert(const wxString&   item , int  pos , void * clientData ) = 0;
  virtual int Insert(const wxString&   item , int  pos , wxClientData * clientData ) = 0;
  virtual bool IsEmpty() const = 0;
  virtual void Select(int n) = 0;
  void SetClientData(int  n , void * data ) = 0;
  void SetClientObject(int  n , wxClientData * data ) = 0;
  virtual void SetSelection(int  n ) = 0;
  virtual void SetString(int  n , const wxString&   string )  = 0;
  virtual void SetStringSelection(const wxString&   string ) = 0;
};


#endif
