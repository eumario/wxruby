// wxHtmlFilter.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlFilter_h_)
#define _wxHtmlFilter_h_
class wxHtmlFilter : public wxObject
{
public:
   wxHtmlFilter() ;
  bool CanRead(const wxFSFile&  file ) ;
  wxString ReadFile(const wxFSFile&  file ) ;
};


#endif
