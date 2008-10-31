// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxRichTextHeaderFooterData_h_)
#define _wxRichTextHeaderFooterData_h_

class wxRichTextHeaderFooterData: public wxObject
{
 public:
  wxRichTextHeaderFooterData();
  wxRichTextHeaderFooterData(const wxRichTextHeaderFooterData& data);

  void Init();
  void Copy(const wxRichTextHeaderFooterData& data);

  void SetHeaderText(const wxString& text, 
                     wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_ALL, 
                     wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE);
  wxString GetHeaderText(wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_EVEN, 
                         wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE) const;

  void SetFooterText(const wxString& text, 
                     wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_ALL, 
                     wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE);
  wxString GetFooterText(wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_EVEN, 
                         wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE) const;

  void SetText(const wxString& text, 
               int headerFooter, 
               wxRichTextOddEvenPage page, 
               wxRichTextPageLocation location);
  wxString GetText(int headerFooter, 
                   wxRichTextOddEvenPage page, 
                   wxRichTextPageLocation location) const;

  void SetMargins(int headerMargin, int footerMargin);
  int GetHeaderMargin() const;
  int GetFooterMargin() const;

  void SetShowOnFirstPage(bool showOnFirstPage);
  bool GetShowOnFirstPage() const;

  void Clear();

  void SetFont(const wxFont& font);
  const wxFont& GetFont() const;

  void SetTextColour(const wxColour& col);
  const wxColour& GetTextColour() const;
};

#endif
