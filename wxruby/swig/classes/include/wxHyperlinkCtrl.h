// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxHyperlinkCtrl_h_)
#define _wxHyperlinkCtrl_h_


class wxHyperlinkCtrl : public wxControl
{
public:
    // Default constructor (for two-step construction).
    wxHyperlinkCtrl() { }

    // Constructor.
    wxHyperlinkCtrl(wxWindow *parent,
                    wxWindowID id,
                    const wxString& label, const wxString& url,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    long style = wxHL_DEFAULT_STYLE,
                    const wxString& name = wxHyperlinkCtrlNameStr)
    {
        (void)Create(parent, id, label, url, pos, size, style, name);
    }

    // Creation function (for two-step construction).
    bool Create(wxWindow *parent,
                wxWindowID id,
                const wxString& label, const wxString& url,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxHL_DEFAULT_STYLE,
                const wxString& name = wxHyperlinkCtrlNameStr);


    // get/set
    wxColour GetHoverColour() const { return m_hoverColour; }
    void SetHoverColour(const wxColour &colour) { m_hoverColour = colour; }

    wxColour GetNormalColour() const { return m_normalColour; }
    void SetNormalColour(const wxColour &colour);

    wxColour GetVisitedColour() const { return m_visitedColour; }
    void SetVisitedColour(const wxColour &colour);

    wxString GetURL() const { return m_url; }
    void SetURL (const wxString &url) { m_url=url; }

    void SetVisited(bool visited = true) { m_visited=visited; }
    bool GetVisited() const { return m_visited; }
};

#endif
