// wxComboBox.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxComboBox_h_)
#define _wxComboBox_h_
class wxComboBox : public wxControlWithItems
{
public:
   wxComboBox() ;
  wxComboBox(wxWindow*  parent , wxWindowID  id , const wxString&  value, const wxPoint& pos , const wxSize& size , int  n , const wxString  choices[] , long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "comboBox");
  virtual  ~wxComboBox() ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  value, const wxPoint& pos , const wxSize& size , int  n , const wxString  choices[] , long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "comboBox");
  void Copy() ;
  void Cut() ;
  long GetInsertionPoint() const;
  long GetLastPosition() const;
  wxString GetValue() const;
  void Paste() ;
  void Replace(long  from , long  to , const wxString&  text ) ;
  void Remove(long  from , long  to ) ;
  void SetInsertionPoint(long  pos ) ;
  void SetInsertionPointEnd() ;
  void SetSelection(long  from , long  to ) ;
  void SetValue(const wxString&  text ) ;
  // the following were missing from the xml
  void Append(const wxString& item);
  void SetSelection(int n);
};


#endif
