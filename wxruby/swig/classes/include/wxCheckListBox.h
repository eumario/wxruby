// wxCheckListBox.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCheckListBox_h_)
#define _wxCheckListBox_h_
class wxCheckListBox : public wxListBox
{
public:
  wxCheckListBox();
  wxCheckListBox(wxWindow *parent, wxWindowID id,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 int nStrings = 0,
                 const wxString choices[] = NULL,
                 long style = 0,
                 const wxValidator& validator = wxDefaultValidator,
                 const wxString& name = wxListBoxNameStr);
  wxCheckListBox(wxWindow *parent, wxWindowID id,
                 const wxPoint& pos,
                 const wxSize& size,
                 const wxArrayString& choices,
                 long style = 0,
                 const wxValidator& validator = wxDefaultValidator,
                 const wxString& name = wxListBoxNameStr);

  bool Create(wxWindow *parent, wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                int n = 0, const wxString choices[] = NULL,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxListBoxNameStr);
  bool Create(wxWindow *parent, wxWindowID id,
                const wxPoint& pos,
                const wxSize& size,
                const wxArrayString& choices,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxListBoxNameStr);

  // override base class virtuals
  virtual void Delete(int n);
  // items may be checked
  virtual bool IsChecked(size_t uiIndex) const;
  virtual void Check(size_t uiIndex, bool bCheck = true);

};


#endif
