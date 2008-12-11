// wxComboBox.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxComboBox_h_)
#define _wxComboBox_h_
class wxComboBox : public wxControlWithItems
{
public:
  wxComboBox();

/* tweak this signature so it can be used for cases where only 
   a few parameters are passed */
  wxComboBox(wxWindow *parent, wxWindowID id,
          const wxString& value = wxEmptyString,
          const wxPoint& pos = wxDefaultPosition,
          const wxSize& size = wxDefaultSize,
          const wxArrayString& choices = wxArrayString(),
          long style = 0,
          const wxValidator& validator = wxDefaultValidator,
          const wxString& name = wxComboBoxNameStr);
					
	virtual ~wxComboBox();

  bool Create(wxWindow *parent,
              wxWindowID id,
              const wxString& value = wxEmptyString,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize,
              int n = 0,
              const wxString choices[] = NULL,
              long style = 0,
              const wxValidator& validator = wxDefaultValidator,
              const wxString& name = wxComboBoxNameStr);
              
  bool Create(wxWindow *parent,
              wxWindowID id,
              const wxString& value,
              const wxPoint& pos,
              const wxSize& size,
              const wxArrayString& choices,
              long style = 0,
              const wxValidator& validator = wxDefaultValidator,
              const wxString& name = wxComboBoxNameStr);
  void Copy() ;
  void Cut() ;
  int GetCurrentSelection() const;
  long GetInsertionPoint() const;
  long GetLastPosition() const;
#if defined(__WXMSW__) || defined (__WXGTK__)
  void GetSelection(long *from, long *to) const;
#endif
  wxString GetValue() const;
  void Paste() ;
  void Replace(long  from , long  to , const wxString&  text ) ;
  void Remove(long  from , long  to ) ;
  void SetInsertionPoint(long  pos ) ;
  void SetInsertionPointEnd() ;
  void SetSelection(long  from , long  to ) ;
  void SetValue(const wxString&  text ) ;

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
  virtual int Insert(const wxString&   item , int  pos , void * clientData );
  virtual void Insert(const wxString&   item , int  pos , wxClientData * clientData );
  virtual bool IsEmpty() const;
  virtual void SetClientData(int  n , void * data ) ;
  virtual void SetClientObject(int  n , wxClientData * data ) ;
  virtual void Select(int  n);
  virtual void SetSelection(int  n );
  virtual void SetString(int  n , const wxString&   string );
  virtual bool SetStringSelection(const wxString&   string );
};


#endif
