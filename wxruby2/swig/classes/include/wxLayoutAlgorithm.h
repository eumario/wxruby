// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxLayoutAlgorithm_h_)
#define _wxLayoutAlgorithm_h_
class wxLayoutAlgorithm : public wxObject
{
public:
   wxLayoutAlgorithm() ;
  virtual  ~wxLayoutAlgorithm() ;
  bool LayoutFrame(wxFrame*  frame , wxWindow* mainWindow = NULL);
  bool LayoutMDIFrame(wxMDIParentFrame*  frame , wxRect* rect = NULL);
  bool LayoutWindow(wxWindow*  parent , wxWindow* mainWindow = NULL);
};


#endif
