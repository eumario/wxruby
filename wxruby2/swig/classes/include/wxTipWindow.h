// wxTipWindow.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTipWindow_h_)
#define _wxTipWindow_h_
class wxTipWindow : public wxWindow
{
public:
   wxTipWindow(wxWindow*  parent , const wxString&  text , wxCoord  maxLength = 100, wxTipWindow**  windowPtr ) ;
  void SetTipWindowPtr(wxTipWindow**  windowPtr ) ;
  void SetBoundingRect(const wxRect&  rectBound ) ;
};


#endif
