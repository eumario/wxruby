// wxCheckListBox.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCheckListBox_h_)
#define _wxCheckListBox_h_
class wxCheckListBox : public wxListBox
{
public:
   wxCheckListBox() ;
  wxCheckListBox(wxWindow*  parent , wxWindowID  id , const wxPoint& pos , const wxSize& size, int  n =0 , const wxString  choices[] = NULL, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "listBox");
  virtual  ~wxCheckListBox() ;
  void Check(int  item , bool check = true) ;
  bool IsChecked(int  item ) const;
};


#endif
