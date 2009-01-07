// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxRichTextCtrl_h_)
#define _wxRichTextCtrl_h_

class wxRichTextCtrl : public wxTextCtrl
{
public:
    wxRichTextCtrl();
    wxRichTextCtrl(wxWindow* parent, wxWindowID id = wxID_ANY,
                   const wxString& value = wxEmptyString,
                   const wxPoint& pos = wxDefaultPosition,
                   const wxSize& size = wxDefaultSize,
                   long style = wxRE_MULTILINE,
                   const wxValidator& validator = wxDefaultValidator,
                   const wxString& name = wxTextCtrlNameStr);
    ~wxRichTextCtrl();
    wxRichTextRange AddImage(const wxImage& image);

    wxRichTextRange AddParagraph(const wxString& text);
    void AppendText(const wxString& text);
    bool ApplyAlignmentToSelection(wxTextAttrAlignment alignment);
    bool ApplyBoldToSelection();
    bool ApplyItalicToSelection();
    bool ApplyStyle(wxRichTextStyleDefinition* def);
    bool ApplyStyleSheet(wxRichTextStyleSheet* sheet = NULL);
    bool ApplyUnderlineToSelection();
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
    bool BeginStyle(const wxTextAttrEx& style);
    bool BeginSuppressUndo();
    bool BeginSymbolBullet(wxChar symbol, int leftIndent,
                           int leftSubIndent,
                           int bulletStyle = wxTEXT_ATTR_BULLET_STYLE_SYMBOL);
    bool BeginTextColour(const wxColour& colour);
    bool BeginURL(const wxString& url,
                  const wxString& characterStyle = wxEmptyString);
    bool BeginUnderline();
    bool CanCopy() const;
    bool CanCut() const;
    bool CanDeleteSelection() const;
    bool CanPaste() const;
    bool CanRedo() const;
    bool CanUndo() const;
    void Clear();
    bool ClearListStyle(const wxRichTextRange& range,
                        int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO);
    void Command(wxCommandEvent& event);
    void Copy();
    bool Create(wxWindow* parent, wxWindowID id = wxID_ANY,
                const wxString& value = wxEmptyString,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxRE_MULTILINE,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxTextCtrlNameStr);
    void Cut();
    bool Delete(const wxRichTextRange& range);
    bool DeleteSelectedContent(long* newPos = NULL);
    void DeleteSelection();
    void DiscardEdits();
    //    wxSize DoGetBestSize() const;
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
    bool EndStyle();
    bool EndSuppressUndo();
    bool EndSymbolBullet();
    bool EndTextColour();
    bool EndURL();
    bool EndUnderline();
    bool ExtendSelection(long oldPosition, long newPosition,
                         int flags);
    long FindNextWordPosition(int direction = 1) const;
    void Freeze();
    const wxTextAttrEx GetBasicStyle() const;
    // These do the same thing in wxRuby - but prefer the other b/c it
    // will not pass ownership of the buffer to Ruby.
    // const wxRichTextBuffer GetBuffer();
    const wxRichTextBuffer& GetBuffer();
    long GetCaretPosition() const;
    bool GetCaretPositionForIndex(long position, wxRect& rect);
    wxCommandProcessor* GetCommandProcessor() const;
    const wxTextAttrEx GetDefaultStyle() const;
    long GetDelayedLayoutThreshold() const;
    wxString GetFilename() const;
    long GetFirstVisiblePosition() const;
    wxPoint GetFirstVisiblePoint() const;
    int GetHandlerFlags() const;
    long GetInsertionPoint() const;
    wxTextPos GetLastPosition() const;
    int GetLineLength(long lineNo) const;
    wxString GetLineText(long lineNo) const;
    wxPoint GetLogicalPoint(const wxPoint& ptPhysical) const;
    int GetNumberOfLines() const;
    wxPoint GetPhysicalPoint(const wxPoint& ptLogical) const;
    wxString GetRange(long from, long to) const;
    void GetSelection(long* from, long* to) const;
    const wxRichTextRange GetSelectionRange() const;
    wxString GetStringSelection() const;
    bool GetStyle(long position, wxRichTextAttr& style);
    bool GetStyle(long position, wxTextAttr& style);
    bool GetStyle(long position, wxTextAttrEx& style);
    bool GetStyleForRange(const wxRichTextRange& range,
                          wxRichTextAttr& style);
    bool GetStyleForRange(const wxRichTextRange& range,
                          wxTextAttr& style);
    bool GetStyleForRange(const wxRichTextRange& range,
                          wxTextAttrEx& style);
    wxRichTextStyleSheet* GetStyleSheet() const;
    bool GetUncombinedStyle(long position, wxRichTextAttr& style);
    bool GetUncombinedStyle(long position, wxTextAttrEx& style);
    bool GetUncombinedStyle(long position, wxTextAttr& style);
    wxString GetValue() const;
    wxRichTextLine* GetVisibleLineForCaretPosition(long caretPosition) const;
    bool HasCharacterAttributes(const wxRichTextRange& range,
                                const wxRichTextAttr& style) const;
    bool HasCharacterAttributes(const wxRichTextRange& range,
                                const wxTextAttrEx& style) const;
    bool HasParagraphAttributes(const wxRichTextRange& range,
                                const wxRichTextAttr& style) const;
    bool HasParagraphAttributes(const wxRichTextRange& range,
                                const wxTextAttrEx& style) const;
    bool HasSelection() const;
    wxTextCtrlHitTestResult HitTest(const wxPoint& pt, long* pos) const;
    const wxTextCtrlHitTestResult HitTest(const wxPoint& pt,
                                          wxTextCoord* col,
                                          wxTextCoord* row) const;
    void Init();
    //    void InitCommandEvent(wxCommandEvent& event) const;
    bool IsDefaultStyleShowing() const;
    bool IsEditable() const;
    bool IsFrozen() const;
    bool IsModified() const;
    bool IsMultiLine() const;
    bool IsPositionVisible(long pos) const;
    bool IsSelectionAligned(wxTextAttrAlignment alignment);
    bool IsSelectionBold();
    bool IsSelectionItalics();
    bool IsSelectionUnderlined();
    bool IsSingleLine() const;
    bool KeyboardNavigate(int keyCode, int flags);
    bool LayoutContent(bool onlyVisibleRect = false);
    bool LineBreak();
    bool LoadFile(const wxString& file,
                  int type = wxRICHTEXT_TYPE_ANY);
    void MarkDirty();
    bool MoveCaret(long pos, bool showAtLineStart = false);
    void MoveCaretBack(long oldPosition);
    void MoveCaretForward(long oldPosition);
    bool MoveDown(int noLines = 1, int flags = 0);
    bool MoveEnd(int flags = 0);
    bool MoveHome(int flags = 0);
    bool MoveLeft(int noPositions = 1, int flags = 0);
    bool MoveRight(int noPositions = 1, int flags = 0);
    bool MoveToLineEnd(int flags = 0);
    bool MoveToLineStart(int flags = 0);
    bool MoveToParagraphEnd(int flags = 0);
    bool MoveToParagraphStart(int flags = 0);
    bool MoveUp(int noLines = 1, int flags = 0);
    bool Newline();
    /* bool NumberList(const wxRichTextRange& range,
                    const wxRichTextListStyleDefinition* style,
                    int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO,
                    int startFrom = -1,
                    int listLevel = -1); */
    bool NumberList(const wxRichTextRange& range,
                    const wxString& styleName,
                    int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO,
                    int startFrom = -1,
                    int listLevel = -1);
    void OnClear(wxCommandEvent& event);
    void OnContextMenu(wxContextMenuEvent& event);
    void OnCopy(wxCommandEvent& event);
    void OnCut(wxCommandEvent& event);
    void OnDropFiles(wxDropFilesEvent& event);
    void OnPaste(wxCommandEvent& event);
    void OnRedo(wxCommandEvent& event);
    void OnSelectAll(wxCommandEvent& event);
    void OnUndo(wxCommandEvent& event);
    void OnUpdateClear(wxUpdateUIEvent& event);
    void OnUpdateCopy(wxUpdateUIEvent& event);
    void OnUpdateCut(wxUpdateUIEvent& event);
    void OnUpdatePaste(wxUpdateUIEvent& event);
    void OnUpdateRedo(wxUpdateUIEvent& event);
    void OnUpdateSelectAll(wxUpdateUIEvent& event);
    void OnUpdateUndo(wxUpdateUIEvent& event);
    bool PageDown(int noPages = 1, int flags = 0);
    bool PageUp(int noPages = 1, int flags = 0);
    void PaintBackground(wxDC& dc);
    void Paste();
    void PositionCaret();
    bool PositionToXY(long pos, long* x, long* y) const;
    /*    bool PromoteList(int promoteBy, const wxRichTextRange& range,
                     const wxRichTextListStyleDefinition* style,
                     int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO,
                     int listLevel = -1); */
    bool PromoteList(int promoteBy, const wxRichTextRange& range,
                     const wxString& styleName,
                     int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO,
                     int listLevel = -1);
    void Redo();
    void Remove(long from, long to);
    void Replace(long from, long to, const wxString& value);
    bool SaveFile(const wxString& file = wxEmptyString,
                  int type = wxRICHTEXT_TYPE_ANY);
    bool ScrollIntoView(long position, int keyCode);
    void SelectAll();
    void SelectNone();
    void SetAndShowDefaultStyle(const wxRichTextAttr& attr);
    void SetBasicStyle(const wxRichTextAttr& style);
    void SetBasicStyle(const wxTextAttrEx& style);
    void SetCaretPosition(long position,
                          bool showAtLineStart = false);
    bool SetDefaultStyle(const wxTextAttrEx& style);
    bool SetDefaultStyleToCursorStyle();
    void SetDelayedLayoutThreshold(long threshold);
    void SetEditable(bool editable);
    void SetFilename(const wxString& filename);
    bool SetFont(const wxFont& font);
    void SetHandlerFlags(int flags);
    void SetInsertionPoint(long pos);
    void SetInsertionPointEnd();
    /*    bool SetListStyle(const wxRichTextRange& range,
                      const wxRichTextListStyleDefinition* style,
                      int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO,
                      int startFrom = -1,
                      int listLevel = -1); */
    bool SetListStyle(const wxRichTextRange& range,
                      const wxString& styleName,
                      int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO,
                      int startFrom = -1,
                      int listLevel = -1);
    void SetSelection(long from, long to);
    void SetSelectionRange(const wxRichTextRange& range);
    bool SetStyle(const wxRichTextRange& range, const wxRichTextAttr& style);
    bool SetStyle(long start, long end, const wxTextAttrEx& style);
    bool SetStyle(long start, long end, const wxTextAttr& style);
    bool SetStyleEx(const wxRichTextRange& range,
                    const wxRichTextAttr& style,
                    int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO);
    bool SetStyleEx(long start, long end,
                    const wxTextAttrEx& style,
                    int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO);
    void SetStyleSheet(wxRichTextStyleSheet* styleSheet);
    void SetValue(const wxString& value);
    void SetupScrollbars(bool atTop = false);
    void ShowPosition(long pos);
    bool SuppressingUndo() const;
    void Thaw();
    void Undo();
    bool WordLeft(int noWords = 1, int flags = 0);
    bool WordRight(int noWords = 1, int flags = 0);
    bool WriteImage(const wxString& filename, int bitmapType);
    bool WriteImage(const wxRichTextImageBlock& imageBlock);
    bool WriteImage(const wxBitmap& bitmap,
                    int bitmapType = wxBITMAP_TYPE_PNG);
    bool WriteImage(const wxImage& image,
                    int bitmapType = wxBITMAP_TYPE_PNG);
    void WriteText(const wxString& text);
    long XYToPosition(long x, long y) const;

    // These methods are not strictly part of wxRichTextCtrl, but
    // inherited from the mix-in ScrollHelper

    virtual void GetViewStart(int *x, int *y) const;
    virtual void GetScrollPixelsPerUnit( int *pixelsPerUnitX,
                                         int *pixelsPerUnitY ) const;
    virtual void Scroll(int x, int y);
};




#endif
