// wxFindReplaceDialog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFindReplaceDialog_h_)
#define _wxFindReplaceDialog_h_
class wxFindReplaceDialog : public wxDialog
{
public:
   wxFindReplaceDialog() ;
   wxFindReplaceDialog(wxWindow *  parent , wxFindReplaceData*  data , const wxString&  title , int  style = 0) ;
  virtual  ~wxFindReplaceDialog() ;
  bool Create(wxWindow *  parent , wxFindReplaceData*  data , const wxString&  title , int  style = 0) ;
  const wxFindReplaceData* GetData() const;
};


#endif
