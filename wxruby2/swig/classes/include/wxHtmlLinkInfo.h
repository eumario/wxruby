// wxHtmlLinkInfo.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlLinkInfo_h_)
#define _wxHtmlLinkInfo_h_
class wxHtmlLinkInfo : public wxObject
{
public:
   wxHtmlLinkInfo() ;
   wxHtmlLinkInfo(const wxString&  href , const wxString&  target = wxEmptyString) ;
  const wxMouseEvent * GetEvent() ;
  const wxHtmlCell * GetHtmlCell() ;
  wxString GetHref() ;
  wxString GetTarget() ;
};


#endif
