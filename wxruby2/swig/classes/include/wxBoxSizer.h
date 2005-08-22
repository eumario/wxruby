//   Copyright 2004-2005 by Kevin Smith
//   released under the MIT-style wxruby2 license

#if !defined(_wxBoxSizer_h_)
#define _wxBoxSizer_h_
class wxBoxSizer : public wxSizer
{
public:
   wxBoxSizer(int  orient ) ;
  virtual ~wxBoxSizer();

  int GetOrientation() ;

  // define pure virtual methods from base classes
  virtual void RecalcSizes();
  virtual wxSize CalcMin();
};


#endif
