// wxValidator.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxValidator_h_)
#define _wxValidator_h_
class wxValidator : public wxEvtHandler
{
public:
   wxValidator() ;
  virtual  ~wxValidator() ;
  virtual wxObject* Clone() const;
  wxWindow* GetWindow() const;
  void SetBellOnError(bool doIt = true) ;
  void SetWindow(wxWindow*  window ) ;
  virtual bool TransferFromWindow() ;
  virtual bool TransferToWindow() ;
  virtual bool Validate(wxWindow*  parent ) ;
};


#endif
