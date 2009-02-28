// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxRichTextFileHandler_h_)
#define _wxRichTextFileHandler_h_

class wxRichTextFileHandler : public wxObject
{
public:
    wxRichTextFileHandler(const wxString& name = wxEmptyString,
                          const wxString& ext = wxEmptyString,
                          int type = 0);
    bool CanHandle(const wxString& filename) const;
    bool CanLoad() const;
    bool CanSave() const;
    const wxString GetEncoding() const;
    wxString GetExtension() const;
    int GetFlags() const;
    wxString GetName() const;
    int GetType() const;
    bool IsVisible() const;
    bool LoadFile(wxRichTextBuffer* buffer, wxInputStream& stream);
    bool LoadFile(wxRichTextBuffer* buffer,
                  const wxString& filename);
    bool SaveFile(wxRichTextBuffer* buffer, wxOutputStream& stream);
    bool SaveFile(wxRichTextBuffer* buffer,
                  const wxString& filename);
    void SetEncoding(const wxString& encoding);
    void SetExtension(const wxString& ext);
    void SetFlags(int flags);
    void SetName(const wxString& name);
    void SetType(int type);
    void SetVisible(bool visible);

};

#endif
