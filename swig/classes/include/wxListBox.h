// wxListBox.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxListBox_h_)
#define _wxListBox_h_
class wxListBox : public wxControlWithItems
{
public:
   wxListBox() ;
  wxListBox(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, int  n = 0 , const wxString  choices[] = NULL, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "listBox");
  virtual  ~wxListBox() ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxPoint& pos , const wxSize& size , int  n , const wxString  choices[] = NULL, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "listBox");
  void Deselect(int  n ) ;
  int GetSelections(wxArrayInt&  selections ) const;
  void InsertItems(int  n, const wxString  choices []= NULL, int  pos = 0);
  bool Selected(int  n ) const;
  void Set(int  n , const wxString*  choices , void **clientData = NULL) ;
  void Set(const wxArrayString&  choices , void **clientData = NULL) ;
  void SetFirstItem(int  n ) ;
  void SetFirstItem(const wxString&  string ) ;
  // the following were missing from the xml
  void SetSelection(int n, const bool select = TRUE);
  void SetStringSelection(const wxString& string, const bool select = TRUE);
  void Append(const wxString& item);
  void Delete(int n);
  int FindString(wxString & string);
  int GetCount();
  int GetSelection();
  wxString GetString(int n);
  wxString GetStringSelection();
  void SetString(int n, wxString& string);
  void Select(int n);
};


#endif
