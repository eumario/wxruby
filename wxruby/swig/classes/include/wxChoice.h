// wxChoice.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxChoice_h_)
#define _wxChoice_h_
class wxChoice : public wxControlWithItems
{
public:
	/**
	 * \brief Default constructor. 
	*/
  wxChoice() { }
  virtual ~wxChoice();

  wxChoice(wxWindow *parent,
           wxWindowID id,
           const wxPoint& pos = wxDefaultPosition,
           const wxSize& size = wxDefaultSize,
           int n = 0, const wxString choices[] = NULL,
           long style = 0,
           const wxValidator& validator = wxDefaultValidator,
           const wxString& name = wxChoiceNameStr);
  
  wxChoice(wxWindow *parent,
           wxWindowID id,
           const wxPoint& pos,
           const wxSize& size,
           const wxArrayString& choices,
           long style = 0,
           const wxValidator& validator = wxDefaultValidator,
           const wxString& name = wxChoiceNameStr);

  bool Create(wxWindow *parent,
              wxWindowID id,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize,
              int n = 0, const wxString choices[] = NULL,
              long style = 0,
              const wxValidator& validator = wxDefaultValidator,
              const wxString& name = wxChoiceNameStr);
              
  bool Create(wxWindow *parent,
              wxWindowID id,
              const wxPoint& pos,
              const wxSize& size,
              const wxArrayString& choices,
              long style = 0,
              const wxValidator& validator = wxDefaultValidator,
              const wxString& name = wxChoiceNameStr);

  virtual int DoAppend(const wxString& item);
  virtual int DoInsert(const wxString& item, int pos);


  int GetColumns() const;
  void SetColumns(int n = 1) ;

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
  virtual void SetSelection(int  n );
  virtual void SetString(int  n , const wxString&   string );
  virtual bool SetStringSelection(const wxString&   string );
};


#endif
