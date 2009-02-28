// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxRichTextStyleListCtrl_h_)
#define _wxRichTextStyleListCtrl_h_


class wxRichTextStyleListCtrl: public wxControl
{
public:

  wxRichTextStyleListCtrl();
  
  wxRichTextStyleListCtrl(wxWindow* parent, wxWindowID id = wxID_ANY, 
                          const wxPoint& pos = wxDefaultPosition,
                          const wxSize& size = wxDefaultSize, 
                          long style = 0);

    virtual ~wxRichTextStyleListCtrl();

    void Init();

    bool Create(wxWindow* parent, 
                wxWindowID id = wxID_ANY, 
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize, 
                long style = 0);

    void UpdateStyles();
    void SetStyleSheet(wxRichTextStyleSheet* styleSheet);
    wxRichTextStyleSheet* GetStyleSheet() const;
    void SetRichTextCtrl(wxRichTextCtrl* ctrl);
    wxRichTextCtrl* GetRichTextCtrl() const;
    void SetStyleType(wxRichTextStyleListBox::wxRichTextStyleType styleType);
    wxRichTextStyleListBox::wxRichTextStyleType GetStyleType() const;
    wxRichTextStyleListBox* GetStyleListBox() const;

    wxChoice* GetStyleChoice() const;
};

#endif
