// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxRichTextParagraphStyleDefinition_h_)
#define _wxRichTextStyleParagraphDefinition_h_

class wxRichTextParagraphStyleDefinition : public wxRichTextStyleDefinition
{
public:
    wxRichTextParagraphStyleDefinition(const wxString& name = wxEmptyString);
    ~wxRichTextParagraphStyleDefinition();
    const wxString GetNextStyle() const;
    void SetNextStyle(const wxString& name);
};

#endif
