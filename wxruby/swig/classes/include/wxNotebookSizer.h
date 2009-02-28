// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

// This class is now deprecated, so we no longer support it

#if 0
#if !defined(_wxNotebookSizer_h_)
#define _wxNotebookSizer_h_
class wxNotebookSizer : public wxSizer
{
public:
   wxNotebookSizer(wxNotebook*  notebook ) ;
  wxNotebook* GetNotebook() ;

  // define pure virtual methods from base classes
  virtual void RecalcSizes();
  virtual wxSize CalcMin();
};


#endif
#endif
