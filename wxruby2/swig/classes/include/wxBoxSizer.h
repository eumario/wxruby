// wxBoxSizer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxBoxSizer_h_)
#define _wxBoxSizer_h_
class wxBoxSizer : public wxSizer
{
public:
   wxBoxSizer(int  orient ) ;
  void RecalcSizes() ;
  wxSize CalcMin() ;
  int GetOrientation() ;
  // the following were missing from the xml
  virtual ~wxBoxSizer();
};


#endif
