// wxGenericValidator.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGenericValidator_h_)
#define _wxGenericValidator_h_
class wxGenericValidator : public wxValidator
{
public:
   wxGenericValidator(const wxGenericValidator&  validator ) ;
   wxGenericValidator(bool*  valPtr ) ;
   wxGenericValidator(wxString*  valPtr ) ;
   wxGenericValidator(int*  valPtr ) ;
   wxGenericValidator(wxArrayInt*  valPtr ) ;
  virtual  ~wxGenericValidator() ;
  virtual wxValidator* Clone() const;
  virtual bool TransferFromWindow() ;
  virtual bool TransferToWindow() ;
};


#endif
