// Copyright 2006 by Kevin Smith
// released under the MIT-style wxruby2 license

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
