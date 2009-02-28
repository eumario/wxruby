// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxTextCtrl_h_)
#define _wxTextCtrl_h_
class wxTextCtrl : public wxControl
{
public:
    wxTextCtrl();
    wxTextCtrl(wxWindow *parent, 
			   wxWindowID id, 
			   wxString const &value = wxT(""), 
			   wxPoint const &pos = wxDefaultPosition, 
			   wxSize const &size = wxDefaultSize, 
			   long style = 0, 
			   wxValidator const &validator = wxDefaultValidator, 
			   wxString const &name = wxTextCtrlNameStr);

    bool Create(wxWindow *parent,
                wxWindowID id,
                const wxString &value = wxEmptyString,
                const wxPoint &pos = wxDefaultPosition,
                const wxSize &size = wxDefaultSize,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString &name = wxTextCtrlNameStr);

    wxString GetValue() const;
    virtual void SetValue(const wxString& value); // deprecated since 2.8
	virtual void ChangeValue(const wxString& value);


    int GetLineLength(long lineNo) const;
    wxString GetLineText(long lineNo) const;
    int GetNumberOfLines() const;
    bool IsModified() const;
    bool IsEditable() const;
	bool IsEmpty() const;

    void GetSelection(long* from, long* to) const;
    void Clear();
    void Replace(long from, long to, const wxString& value);
    void Remove(long from, long to);
    void MarkDirty();
    void DiscardEdits();
    void SetMaxLength(unsigned long len);
    void WriteText(const wxString& text);
    void AppendText(const wxString& text);
    bool SetStyle(long start, long end, const wxTextAttr& style);
    long XYToPosition(long x, long y) const;
    bool PositionToXY(long pos, long *x, long *y) const;
    void ShowPosition(long pos);

    wxTextCtrlHitTestResult HitTest(const wxPoint& pt,
                                            wxTextCoord *col,
                                            wxTextCoord *row) const;
    void Copy();
    void Cut();
    void Paste();
    void Undo();
    void Redo();

    bool CanCopy() const;
    bool CanCut() const;
    bool CanPaste() const;
    bool CanUndo() const;
    bool CanRedo() const;

    void SetInsertionPoint(long pos);
    void SetInsertionPointEnd();
    long GetInsertionPoint() const;
    wxTextPos GetLastPosition() const;
    void SetSelection(long from, long to);
    void SetEditable(bool editable);

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


    void SetModified(bool modified);

    virtual wxString GetRange(long from, long to) const;

    //virtual int GetLineLength(long lineNo) const = 0;
    //virtual wxString GetLineText(long lineNo) const = 0;
    //virtual int GetNumberOfLines() const = 0;

    bool IsSingleLine() const;
    bool IsMultiLine() const;

    //virtual void GetSelection(long* from, long* to) const = 0;

    virtual wxString GetStringSelection() const;

    //virtual void Clear() = 0;
    //virtual void Replace(long from, long to, const wxString& value) = 0;
    //virtual void Remove(long from, long to) = 0;

    virtual bool LoadFile(const wxString& file);
    virtual bool SaveFile(const wxString& file = wxEmptyString);

    bool EmulateKeyPress(const wxKeyEvent& event);
    bool GetStyle(long position, wxTextAttr& style);
    bool SetDefaultStyle(const wxTextAttr& style);
    const wxTextAttr& GetDefaultStyle() const;
    
	virtual void SelectAll();
    

   // int overflow(int i);
    wxTextCtrl& operator<<(const wxString& s);
    wxTextCtrl& operator<<(int i);
    wxTextCtrl& operator<<(long i);
    wxTextCtrl& operator<<(float f);
    wxTextCtrl& operator<<(double d);
    wxTextCtrl& operator<<(const wxChar c);

    virtual void DoUpdateWindowUI(wxUpdateUIEvent& event);

    virtual bool ShouldInheritColours() const;

		//Use this to turn off and on 'Check Spelling as You Type' on OS X 10.4.x and above
		//renamed in the .i file to check_spelling
#ifdef __WXMAC__
	#if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_4
		void MacCheckSpelling(bool check);
	#endif
#endif
};


#endif
