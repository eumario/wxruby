// wxColourDialog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxColourDialog_h_)
#define _wxColourDialog_h_
class wxColourDialog : public wxDialog
{
public:
   wxColourDialog(wxWindow*  parent , wxColourData*  data = NULL) ;
  virtual  ~wxColourDialog() ;
  bool Create(wxWindow*  parent , wxColourData*  data = NULL) ;
  wxColourData& GetColourData() ;
  int ShowModal() ;
};


#endif
