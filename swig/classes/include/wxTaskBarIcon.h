// wxTaskBarIcon.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTaskBarIcon_h_)
#define _wxTaskBarIcon_h_
class wxTaskBarIcon : public wxEvtHandler
{
public:
   wxTaskBarIcon() ;
  virtual  ~wxTaskBarIcon() ;
  bool IsIconInstalled() ;
  bool IsOk() ;
  bool PopupMenu(wxMenu*  menu ) ;
  bool RemoveIcon() ;
  bool SetIcon(const wxIcon&  icon , const wxString&  tooltip ) ;
};


#endif
