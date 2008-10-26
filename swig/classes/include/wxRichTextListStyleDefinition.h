// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxRichTextListStyleDefinition_h_)
#define _wxRichTextListStyleDefinition_h_

class wxRichTextListStyleDefinition : public wxRichTextParagraphStyleDefinition
{
public:
  wxRichTextListStyleDefinition(const wxString& name = wxEmptyString);
  ~wxRichTextListStyleDefinition();
  wxRichTextAttr CombineWithParagraphStyle(int indent,
                                           const wxRichTextAttr& paraStyle,
                                           wxRichTextStyleSheet* styleSheet = NULL);
  int FindLevelForIndent(int indent) const;
  wxRichTextAttr GetCombinedStyle(int indent,
                                  wxRichTextStyleSheet* styleSheet = NULL) const;
  wxRichTextAttr GetCombinedStyleForLevel(int level,
                                          wxRichTextStyleSheet* styleSheet = NULL) const;
  const wxRichTextAttr* GetLevelAttributes(int level) const;
  int GetLevelCount() const;
  int IsNumbered(int level) const;
  void SetLevelAttributes(int level, const wxRichTextAttr& attr);
  // Version below is documented but not supported?
  /* void SetLevelAttributes(int level, int leftIndent,
                          int leftSubIndent,
                          int bulletStyle,
                          const wxString& bulletSymbol = wxEmptyString); */
};

#endif
