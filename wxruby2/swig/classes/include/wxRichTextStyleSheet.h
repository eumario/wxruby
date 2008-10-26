// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxRichTextStyleSheet_h_)
#define _wxRichTextStyleSheet_h_

class wxRichTextStyleSheet : public wxObject
{
public:
  wxRichTextStyleSheet();
  ~wxRichTextStyleSheet();
  bool AddCharacterStyle(wxRichTextCharacterStyleDefinition* def);
  bool AddListStyle(wxRichTextListStyleDefinition* def);
  bool AddParagraphStyle(wxRichTextParagraphStyleDefinition* def);
  bool AddStyle(wxRichTextStyleDefinition* def);
  void DeleteStyles();
  wxRichTextCharacterStyleDefinition* FindCharacterStyle(const wxString& name) const;
  wxRichTextListStyleDefinition* FindListStyle(const wxString& name) const;
  wxRichTextParagraphStyleDefinition* FindParagraphStyle(const wxString& name) const;
  wxRichTextStyleDefinition* FindStyle(const wxString& name) const;
  wxRichTextCharacterStyleDefinition* GetCharacterStyle(size_t n) const;
  size_t GetCharacterStyleCount() const;
  const wxString GetDescription() const;
  wxRichTextListStyleDefinition* GetListStyle(size_t n) const;
  size_t GetListStyleCount() const;
  const wxString GetName() const;
  wxRichTextParagraphStyleDefinition* GetParagraphStyle(size_t n) const;
  size_t GetParagraphStyleCount() const;
  bool RemoveCharacterStyle(wxRichTextStyleDefinition* def,
                            bool deleteStyle = false);
  bool RemoveListStyle(wxRichTextStyleDefinition* def,
                         bool deleteStyle = false);
  bool RemoveParagraphStyle(wxRichTextStyleDefinition* def,
                            bool deleteStyle = false);
  bool RemoveStyle(wxRichTextStyleDefinition* def,
                   bool deleteStyle = false);
  void SetDescription(const wxString& descr);
  void SetName(const wxString& name);
};


#endif
