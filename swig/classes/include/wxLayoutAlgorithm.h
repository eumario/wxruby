// wxLayoutAlgorithm.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxLayoutAlgorithm_h_)
#define _wxLayoutAlgorithm_h_
class wxLayoutAlgorithm : public wxObject
{
public:
   wxLayoutAlgorithm() ;
  virtual  ~wxLayoutAlgorithm() ;
  bool LayoutFrame(wxFrame*  frame , wxWindow* mainWindow = NULL) const;
  bool LayoutMDIFrame(wxMDIParentFrame*  frame , wxRect* rect = NULL) const;
  bool LayoutWindow(wxWindow*  parent , wxWindow* mainWindow = NULL) const;
};


#endif
