// wxChoice.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxChoice_h_)
#define _wxChoice_h_
class wxChoice : public wxControlWithItems
{
public:
   wxChoice() ;
   wxChoice(wxWindow * parent , wxWindowID  id , const wxPoint&  pos , const wxSize&  size , int  n , const wxString  choices[] , long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "choice") ;
  virtual  ~wxChoice() ;
  bool Create(wxWindow * parent , wxWindowID  id , const wxPoint&  pos , const wxSize&  size , int  n , const wxString  choices[] , long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "choice");
  void Delete(int  n ) ;
  int GetColumns() const;
  void SetColumns(int n = 1) ;
  // the following were missing from the xml
  void SetSelection(int  n );
  void SetStringSelection(wxString &);
};


#endif
