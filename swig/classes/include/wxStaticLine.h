// wxStaticLine.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxStaticLine_h_)
#define _wxStaticLine_h_
class wxStaticLine : public wxControl
{
public:
   wxStaticLine() ;
   wxStaticLine(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxLI_HORIZONTAL, const wxString&  name = "staticLine") ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxString&  name = "staticLine") ;
  bool IsVertical() const;
  int GetDefaultSize() ;
};


#endif
