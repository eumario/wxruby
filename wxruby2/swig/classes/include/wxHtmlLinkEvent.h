// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxHtmlLinkEvent_h_)
#define _wxHtmlLinkEvent_h_

class wxHtmlLinkEvent : public wxCommandEvent
{
public:
  wxHtmlLinkEvent();
  wxHtmlLinkEvent(int id, const wxHtmlLinkInfo &linkinfo);
  const wxHtmlLinkInfo &GetLinkInfo();
};

#endif
