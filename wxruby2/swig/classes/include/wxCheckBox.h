// wxCheckBox.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCheckBox_h_)
#define _wxCheckBox_h_
class wxCheckBox : public wxControl
{
public:
   wxCheckBox() ;
  wxCheckBox(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  val = wxDefaultValidator, const wxString&  name = wxT("checkBox"));
  virtual  ~wxCheckBox() ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  val = wxDefaultValidator, const wxString&  name = wxT("checkBox"));
  bool GetValue() const;
  bool IsChecked() const;
  void SetValue(const bool  state ) ;

  // GetItemHeight is defined for GTK and MSW but not Mac
  // We should probably #if it, but for now we'll just take it out
  //size_t GetItemHeight() const { return m_nItemHeight; }  
};


#endif
