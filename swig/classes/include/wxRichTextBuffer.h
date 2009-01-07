// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxRichTextBuffer_h_)
#define _wxRichTextBuffer_h_

class wxRichTextBuffer
{
public:
    wxRichTextBuffer(const wxRichTextBuffer& obj);
    wxRichTextBuffer();
    ~wxRichTextBuffer();
    bool AddEventHandler(wxEvtHandler* handler);
    void AddHandler(wxRichTextFileHandler* handler);
    wxRichTextRange AddParagraph(const wxString& text);
    bool BatchingUndo() const;
    bool BeginAlignment(wxTextAttrAlignment alignment);
    bool BeginBatchUndo(const wxString& cmdName);
    bool BeginBold();
    bool BeginCharacterStyle(const wxString& characterStyle);
    bool BeginFont(const wxFont& font);
    bool BeginFontSize(int pointSize);
    bool BeginItalic();
    bool BeginLeftIndent(int leftIndent, int leftSubIndent = 0);
    bool BeginLineSpacing(int lineSpacing);
    bool BeginListStyle(const wxString& listStyle, int level = 1,
                        int number = 1);
    bool BeginNumberedBullet(int bulletNumber, int leftIndent,
                             int leftSubIndent,
                             int bulletStyle = wxTEXT_ATTR_BULLET_STYLE_ARABIC|wxTEXT_ATTR_BULLET_STYLE_PERIOD);
    bool BeginParagraphSpacing(int before, int after);
    bool BeginParagraphStyle(const wxString& paragraphStyle);
    bool BeginRightIndent(int rightIndent);
    bool BeginStandardBullet(const wxString& bulletName,
                             int leftIndent,
                             int leftSubIndent,
                             int bulletStyle = wxTEXT_ATTR_BULLET_STYLE_STANDARD);
    bool BeginStyle(const wxTextAttrEx& style);
    bool BeginSuppressUndo();
    bool BeginSymbolBullet(wxChar symbol, int leftIndent,
                           int leftSubIndent,
                           int bulletStyle = wxTEXT_ATTR_BULLET_STYLE_SYMBOL);
    bool BeginTextColour(const wxColour& colour);
    bool BeginURL(const wxString& url,
                  const wxString& characterStyle = wxEmptyString);
    bool BeginUnderline();
    bool CanPasteFromClipboard() const;
    void CleanUpHandlers();
    void Clear();
    bool ClearListStyle(const wxRichTextRange& range,
                        int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO);
    void ClearStyleStack();
    wxRichTextObject* Clone() const;
    void Copy(const wxRichTextBuffer& obj);
    bool CopyToClipboard(const wxRichTextRange& range);
    bool DeleteRangeWithUndo(const wxRichTextRange& range,
                             wxRichTextCtrl* ctrl);
    void Dump();
    void Dump(wxTextOutputStream& stream);
    bool EndAlignment();
    bool EndAllStyles();
    bool EndBatchUndo();
    bool EndBold();
    bool EndCharacterStyle();
    bool EndFont();
    bool EndFontSize();
    bool EndItalic();
    bool EndLeftIndent();
    bool EndLineSpacing();
    bool EndListStyle();
    bool EndNumberedBullet();
    bool EndParagraphSpacing();
    bool EndParagraphStyle();
    bool EndRightIndent();
    bool EndStandardBullet();
    bool EndStyle();
    bool EndSuppressUndo();
    bool EndSymbolBullet();
    bool EndTextColour();
    bool EndURL();
    bool EndUnderline();
    wxRichTextFileHandler* FindHandler(int imageType);
    wxRichTextFileHandler* FindHandler(const wxString& extension,
                                       int imageType);
    wxRichTextFileHandler* FindHandler(const wxString& name);
    wxRichTextFileHandler* FindHandlerFilenameOrType(const wxString& filename,
            int imageType);

    const wxTextAttrEx GetBasicStyle() const;
    wxRichTextCommand* GetBatchedCommand() const;
    wxCommandProcessor* GetCommandProcessor() const;
    const wxTextAttrEx GetDefaultStyle() const;
    wxString GetExtWildcard(bool combine = false, bool save = false,
                            wxArrayInt* types = NULL);
    wxList GetHandlers();
    static wxRichTextRenderer* GetRenderer();
    bool GetStyle(long position, wxRichTextAttr& style);
    bool GetStyleForRange(const wxRichTextRange& range,
                          wxTextAttrEx& style);
    wxRichTextStyleSheet* GetStyleSheet() const;
    size_t GetStyleStackSize() const;
    bool GetUncombinedStyle(long position, wxRichTextAttr& style);
    int HitTest(wxDC& dc, const wxPoint& pt, long& textPosition);
    void Init();
    void InitStandardHandlers();
    void InsertHandler(wxRichTextFileHandler* handler);
    bool InsertImageWithUndo(long pos,
                             const wxRichTextImageBlock& imageBlock,
                             wxRichTextCtrl* ctrl);
    bool InsertNewlineWithUndo(long pos, wxRichTextCtrl* ctrl);
    bool InsertTextWithUndo(long pos, const wxString& text,
                            wxRichTextCtrl* ctrl);
    bool IsModified() const;
    bool LoadFile(wxInputStream& stream,
                  int type = wxRICHTEXT_TYPE_ANY);
    bool LoadFile(const wxString& filename,
                  int type = wxRICHTEXT_TYPE_ANY);
    void Modify(bool modify = true);
    /*    bool NumberList(const wxRichTextRange& range,
                    const wxRichTextListStyleDefinition* style,
                    int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO,
                    int startFrom = -1,
                    int listLevel = -1); */
    bool NumberList(const wxRichTextRange& range,
                    const wxString& styleName,
                    int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO,
                    int startFrom = -1,
                    int listLevel = -1);
    bool PasteFromClipboard(long position);
    /* bool PromoteList(int promoteBy, const wxRichTextRange& range,
                     const wxRichTextListStyleDefinition* style,
                     int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO,
                     int listLevel = -1); */
    bool PromoteList(int promoteBy, const wxRichTextRange& range,
                     const wxString& styleName,
                     int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO,
                     int listLevel = -1); 
    bool RemoveEventHandler(wxEvtHandler* handler,
                            bool deleteHandler = false);
    bool RemoveHandler(const wxString& name);
    void ResetAndClearCommands();
    bool SaveFile(wxOutputStream& stream,
                  int type = wxRICHTEXT_TYPE_ANY);
    bool SaveFile(const wxString& filename,
                  int type = wxRICHTEXT_TYPE_ANY);
    void SetBasicStyle(const wxTextAttrEx& style);
    void SetDefaultStyle(const wxTextAttrEx& style);
    /* bool SetListStyle(const wxRichTextRange& range,
                      const wxRichTextListStyleDefinition* style,
                      int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO,
                      int startFrom = -1,
                      int listLevel = -1); */
    bool SetListStyle(const wxRichTextRange& range,
                      const wxString& styleName,
                      int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO,
                      int startFrom = -1,
                      int listLevel = -1);
    static void SetRenderer(wxRichTextRenderer* renderer);
    bool SetStyle(const wxRichTextRange& range,
                  const wxTextAttrEx& style,
                  int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO);
    bool SetStyle(const wxRichTextRange& range, 
                  const wxRichTextAttr& style, 
                  int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO);
    void SetStyleSheet(wxRichTextStyleSheet* styleSheet);
    bool SubmitAction(wxRichTextAction* action);
    bool SuppressingUndo() const;
};

#endif

