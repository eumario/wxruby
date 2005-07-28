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
  virtual void Delete(int n);
  virtual void Clear();

  virtual int GetCount() const;
  virtual int GetSelection() const;
  virtual void SetSelection(int n);

  virtual int FindString(const wxString& s) const;
  virtual wxString GetString(int n) const;
  virtual void SetString(int n, const wxString& s);

  int GetColumns() const;
  void SetColumns(int n = 1) ;

  //void SetStringSelection(wxString &);
};


#endif
