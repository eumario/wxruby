// wxTextValidator.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTextValidator_h_)
#define _wxTextValidator_h_
class wxTextValidator : public wxValidator
{
public:
   wxTextValidator(const wxTextValidator&  validator ) ;
   wxTextValidator(long style = wxFILTER_NONE, wxString*  valPtr = NULL) ;
  virtual  ~wxTextValidator() ;
  virtual wxValidator* Clone() const;
  wxStringList& GetExcludeList() const;
  wxStringList& GetIncludeList() const;
  long GetStyle() const;
  virtual void OnChar(wxKeyEvent&  event ) ;
  void SetExcludeList(const wxStringList&  stringList ) ;
  void SetIncludeList(const wxStringList&  stringList ) ;
  void SetStyle(long  style ) ;
  virtual bool TransferFromWindow() ;
  virtual bool TransferToWindow() ;
  virtual bool Validate(wxWindow*  parent ) ;
};


#endif
