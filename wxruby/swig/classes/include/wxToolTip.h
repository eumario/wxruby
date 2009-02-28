// wxToolTip.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxToolTip_h_)
#define _wxToolTip_h_
class wxToolTip : public wxObject
{
public:
    // ctor & dtor
    wxToolTip(const wxString &tip);
    virtual ~wxToolTip();

    // accessors
        // tip text
    void SetTip(const wxString& tip);
  wxString GetTip() const;

        // the window we're associated with
    void SetWindow(wxWindow *win);
    wxWindow *GetWindow() const;

    // controlling tooltip behaviour: globally change tooltip parameters
        // enable or disable the tooltips globally
    static void Enable(bool flag);
        // set the delay after which the tooltip appears
    static void SetDelay(long milliseconds);
};


#endif
