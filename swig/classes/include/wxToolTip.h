// wxToolTip.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxToolTip_h_)
#define _wxToolTip_h_
class wxToolTip : public wxObject
{
public:
  static void Enable(bool  flag ) ;
  static void SetDelay(long  msecs ) ;
   wxToolTip(const wxString&  tip ) ;
  void SetTip(const wxString&  tip ) ;
  wxString GetTip() const;
  wxWindow* GetWindow() const;
};


#endif
