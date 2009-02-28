// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxRichTextStyleDefinition_h_)
#define _wxRichTextStyleDefinition_h_

class wxRichTextStyleDefinition : public wxObject
{
public:
  wxRichTextStyleDefinition(const wxString& name = wxEmptyString);
  ~wxRichTextStyleDefinition();
  const wxString GetBaseStyle() const;
  const wxString GetDescription() const;
  const wxString GetName() const;
  // wxRichTextAttr& GetStyle() const;   // ignore this duplicate
  const wxRichTextAttr& GetStyle() const;
  wxTextAttr GetStyleMergedWithBase(wxRichTextStyleSheet* sheet) const;
  void SetBaseStyle(const wxString& name);
  void SetDescription(const wxString& descr);
  void SetName(const wxString& name);
  void SetStyle(const wxRichTextAttr& style);
};

#endif
