// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxGCDC_h_)
#define _wxGCDC_h_
class wxGCDC : public wxDC
{
public:
    wxGCDC(const wxWindowDC& dc);
#ifdef __WXMSW__
    wxGCDC( const wxMemoryDC& dc);
#endif    
    wxGCDC();
    virtual ~wxGCDC();
};

#endif
