// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxGLContext_h_)
#define _wxGLContext_h_

class wxGLContext : public wxObject
{
public:
    wxGLContext(wxGLCanvas *win, const wxGLContext* other=NULL );
    virtual ~wxGLContext();
    void SetCurrent(const wxGLCanvas& win) const;
};

#endif
