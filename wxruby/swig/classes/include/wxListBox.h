// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxListBox_h_)
#define _wxListBox_h_
class wxListBox : public wxControlWithItems
{
public:
   wxListBox() ;
  wxListBox(wxWindow* parent, wxWindowID id, 
            const wxPoint& pos = wxDefaultPosition, 
            const wxSize& size = wxDefaultSize, 
            int  n = 0, 
            const wxString  choices[] = NULL, 
            long style = 0, 
            const wxValidator&  validator = wxDefaultValidator, 
            const wxString&  name = wxT("listBox"));
  virtual  ~wxListBox() ;
  bool Create(wxWindow* parent, 
              wxWindowID  id, 
              const wxPoint& pos, 
              const wxSize& size, 
              int  n, 
              const wxString  choices[] = NULL, 
              long style = 0, 
              const wxValidator& validator = wxDefaultValidator, 
              const wxString&  name = wxT("listBox"));
  void Deselect(int  n);
  int GetSelections(wxArrayInt& selections) const;
  int HitTest(const wxPoint& pt) const;
  void InsertItems(int nItems, const wxString *items, int pos);
  void InsertItems(const wxArrayString& items, int pos);
  bool IsSelected(int  n ) const;
  void Set(int  n , const wxString*  choices , void **clientData = NULL) ;
  void Set(const wxArrayString&  choices , void **clientData = NULL) ;
  void SetFirstItem(int  n );
  void SetFirstItem(const wxString& string);

  // the following were missing from the xml
  void Select(int n);

  // override pure virtuals in a base class
  virtual int Append(const wxString&   item );
  virtual int Append(const wxString&   item , void * clientData );
  virtual int Append(const wxString&   item , wxClientData * clientData );
  virtual void Append(const wxArrayString&  strings );
  virtual void Clear();
  virtual void Delete(int  n );
  virtual int FindString(const wxString&  string );
  virtual void * GetClientData(int  n ) const;
  virtual wxClientData * GetClientObject(int  n ) const;
  virtual unsigned int GetCount() const;
  virtual int GetSelection() const;
  virtual wxString GetString(int  n ) const;
  virtual wxString GetStringSelection() const;
  virtual void Insert(const wxString&   item , int  pos );
  virtual void Insert(const wxString&   item , int  pos , void * clientData );
  virtual void Insert(const wxString&   item , int  pos , wxClientData * clientData );
  virtual bool IsEmpty() const;
  virtual void SetClientData(int  n , void * data ) ;
  virtual void SetClientObject(int  n , wxClientData * data ) ;
  virtual void SetSelection(int  n );
  virtual void SetString(int  n , const wxString&   string );
  virtual bool SetStringSelection(const wxString&   string );
};


#endif
