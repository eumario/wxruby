// Copyright 2006 by Kevin Smith
// released under the MIT-style wxruby2 license

#if !defined(_wxTextCtrl_h_)
#define _wxTextCtrl_h_
class wxTextCtrl : public wxControl
{
public:
    wxTextCtrl();
    wxTextCtrl(wxWindow *parent, wxWindowID id, wxString const &value = wxT(""), 
		wxPoint const &pos = wxDefaultPosition, wxSize const &size = wxDefaultSize, 
		long style = 0, wxValidator const &validator = wxDefaultValidator, 
		wxString const &name = wxTextCtrlNameStr);
    bool Create(wxWindow *parent,
                wxWindowID id,
                const wxString &value = wxEmptyString,
                const wxPoint &pos = wxDefaultPosition,
                const wxSize &size = wxDefaultSize,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString &name = wxTextCtrlNameStr);

    virtual wxString GetValue() const;
    virtual void SetValue(const wxString& value);
    virtual int GetLineLength(long lineNo) const;
    virtual wxString GetLineText(long lineNo) const;
    virtual int GetNumberOfLines() const;
    virtual bool IsModified() const;
    virtual bool IsEditable() const;
    virtual void GetSelection(long* from, long* to) const;
    virtual void Clear();
    virtual void Replace(long from, long to, const wxString& value);
    virtual void Remove(long from, long to);
    virtual void MarkDirty();
    virtual void DiscardEdits();
    virtual void SetMaxLength(unsigned long len);
    virtual void WriteText(const wxString& text);
    virtual void AppendText(const wxString& text);
    virtual bool SetStyle(long start, long end, const wxTextAttr& style);
    virtual long XYToPosition(long x, long y) const;
    virtual bool PositionToXY(long pos, long *x, long *y) const;
    virtual void ShowPosition(long pos);
    virtual wxTextCtrlHitTestResult HitTest(const wxPoint& pt, long *pos) const;
    virtual wxTextCtrlHitTestResult HitTest(const wxPoint& pt,
                                            wxTextCoord *col,
                                            wxTextCoord *row) const;
    virtual void Copy();
    virtual void Cut();
    virtual void Paste();
    virtual void Undo();
    virtual void Redo();
    virtual bool CanUndo() const;
    virtual bool CanRedo() const;
    virtual void SetInsertionPoint(long pos);
    virtual void SetInsertionPointEnd();
    virtual long GetInsertionPoint() const;
    virtual wxTextPos GetLastPosition() const;
    virtual void SetSelection(long from, long to);
    virtual void SetEditable(bool editable);
    virtual bool Enable( bool enable = true );
    void OnDropFiles( wxDropFilesEvent &event );
    void OnChar( wxKeyEvent &event );
    void OnCut(wxCommandEvent& event);
    void OnCopy(wxCommandEvent& event);
    void OnPaste(wxCommandEvent& event);
    void OnUndo(wxCommandEvent& event);
    void OnRedo(wxCommandEvent& event);
    void OnUpdateCut(wxUpdateUIEvent& event);
    void OnUpdateCopy(wxUpdateUIEvent& event);
    void OnUpdatePaste(wxUpdateUIEvent& event);
    void OnUpdateUndo(wxUpdateUIEvent& event);
    void OnUpdateRedo(wxUpdateUIEvent& event);
    bool SetFont(const wxFont& font);
    bool SetForegroundColour(const wxColour& colour);
    bool SetBackgroundColour(const wxColour& colour);

	// Although the following were public in the .h file,
	// I believe they are not part of the public API
	//GtkWidget* GetConnectWidget();
    //bool IsOwnGtkWindow( GdkWindow *window );
    //void DoApplyWidgetStyle(GtkRcStyle *style);
    //void CalculateScrollbar();
    //void OnInternalIdle();
    //void SetUpdateFont(bool ) { }
    //void SetModified() { m_modified = true; }
    //virtual void Freeze();
    //virtual void Thaw();
    //virtual bool ScrollLines(int lines);
    //virtual bool ScrollPages(int pages);
    //virtual void OnParentEnable( bool enable ) ;
    //void IgnoreNextTextUpdate();
    //bool IgnoreTextUpdate();
    //static wxVisualAttributes
    //GetClassDefaultAttributes(wxWindowVariant variant = wxWINDOW_VARIANT_NORMAL);
	
	// From wxTextCtrlBase
    //virtual wxString GetValue() const = 0;
    //virtual void SetValue(const wxString& value) = 0;

    virtual wxString GetRange(long from, long to) const;

    //virtual int GetLineLength(long lineNo) const = 0;
    //virtual wxString GetLineText(long lineNo) const = 0;
    //virtual int GetNumberOfLines() const = 0;

    //virtual bool IsModified() const = 0;
    //virtual bool IsEditable() const = 0;

    bool IsSingleLine() const;
    bool IsMultiLine() const;

    //virtual void GetSelection(long* from, long* to) const = 0;

    virtual wxString GetStringSelection() const;

    //virtual void Clear() = 0;
    //virtual void Replace(long from, long to, const wxString& value) = 0;
    //virtual void Remove(long from, long to) = 0;

    virtual bool LoadFile(const wxString& file);
    virtual bool SaveFile(const wxString& file = wxEmptyString);

    //virtual void MarkDirty() = 0;
    //virtual void DiscardEdits() = 0;

    virtual void SetMaxLength(unsigned long ) { }

    //virtual void WriteText(const wxString& text) = 0;
    //virtual void AppendText(const wxString& text) = 0;

    virtual bool EmulateKeyPress(const wxKeyEvent& event);
    virtual bool SetStyle(long start, long end, const wxTextAttr& style);
    virtual bool GetStyle(long position, wxTextAttr& style);
    virtual bool SetDefaultStyle(const wxTextAttr& style);
    virtual const wxTextAttr& GetDefaultStyle() const;

    //virtual long XYToPosition(long x, long y) const = 0;
    //virtual bool PositionToXY(long pos, long *x, long *y) const = 0;
    //virtual void ShowPosition(long pos) = 0;

    virtual wxTextCtrlHitTestResult HitTest(const wxPoint& pt, long *pos) const;
    virtual wxTextCtrlHitTestResult HitTest(const wxPoint& pt,
                                            wxTextCoord *col,
                                            wxTextCoord *row) const;

    //virtual void Copy() = 0;
    //virtual void Cut() = 0;
    //virtual void Paste() = 0;

    virtual bool CanCopy() const;
    virtual bool CanCut() const;
    virtual bool CanPaste() const;


    //virtual void Undo() = 0;
    //virtual void Redo() = 0;
    //virtual bool CanUndo() const = 0;
    //virtual bool CanRedo() const = 0;
    //virtual void SetInsertionPoint(long pos) = 0;
    //virtual void SetInsertionPointEnd() = 0;
    //virtual long GetInsertionPoint() const = 0;
    //virtual wxTextPos GetLastPosition() const = 0;
    //virtual void SetSelection(long from, long to) = 0;
    
	virtual void SelectAll();
    
	//virtual void SetEditable(bool editable) = 0;

   // int overflow(int i);
    wxTextCtrl& operator<<(const wxString& s);
    wxTextCtrl& operator<<(int i);
    wxTextCtrl& operator<<(long i);
    wxTextCtrl& operator<<(float f);
    wxTextCtrl& operator<<(double d);
    wxTextCtrl& operator<<(const wxChar c);

    virtual void DoUpdateWindowUI(wxUpdateUIEvent& event);

    virtual bool ShouldInheritColours() const;
};


#endif
