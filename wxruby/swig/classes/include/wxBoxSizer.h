// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxBoxSizer_h_)
#define _wxBoxSizer_h_
class wxBoxSizer : public wxSizer
{
public:
   wxBoxSizer(int  orient ) ;
  virtual ~wxBoxSizer();

  int GetOrientation() ;
  void SetOrientation(int orient);

  // define pure virtual methods from base classes
  virtual void RecalcSizes();
  virtual wxSize CalcMin();
};


#endif
