// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxRichTextStyleListBox_h_)
#define _wxRichTextStyleListBox_h_


class wxRichTextStyleListBox: public wxHtmlListBox
{
 public:


  enum wxRichTextStyleType
  {
    wxRICHTEXT_STYLE_ALL,
    wxRICHTEXT_STYLE_PARAGRAPH,
    wxRICHTEXT_STYLE_CHARACTER,
    wxRICHTEXT_STYLE_LIST
  };

  wxRichTextStyleListBox();
  wxRichTextStyleListBox(wxWindow* parent, 
                         wxWindowID id = wxID_ANY, 
                         const wxPoint& pos = wxDefaultPosition,
                         const wxSize& size = wxDefaultSize, long style = 0);
  virtual ~wxRichTextStyleListBox();

  void Init();
  bool Create(wxWindow* parent, 
              wxWindowID id = wxID_ANY, 
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize, long style = 0);
  wxString CreateHTML(wxRichTextStyleDefinition* def) const;
  void SetStyleSheet(wxRichTextStyleSheet* styleSheet);
  wxRichTextStyleSheet* GetStyleSheet() const;
  void SetRichTextCtrl(wxRichTextCtrl* ctrl);
  wxRichTextCtrl* GetRichTextCtrl() const;
  wxRichTextStyleDefinition* GetStyle(size_t i) const ;
  int GetIndexForStyle(const wxString& name) const ;
  int SetStyleSelection(const wxString& name);
  void UpdateStyles();
  void ApplyStyle(int i);
  int ConvertTenthsMMToPixels(wxDC& dc, int units) const;
  virtual bool CanAutoSetSelection();
  virtual void SetAutoSetSelection(bool autoSet);
  void SetApplyOnSelection(bool applyOnSel);
  bool GetApplyOnSelection() const;
  void SetStyleType(wxRichTextStyleType styleType);
  wxRichTextStyleType GetStyleType() const;
};


#endif
