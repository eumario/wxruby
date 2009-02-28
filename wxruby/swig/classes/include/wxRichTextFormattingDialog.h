// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxRichTextFormattingDialog_h_)
#define _wxRichTextFormattingDialog_h_

class wxRichTextFormattingDialog: public wxPropertySheetDialog
{
public:
  wxRichTextFormattingDialog();

    wxRichTextFormattingDialog(long flags, 
                               wxWindow* parent, 
                               const wxString& title = wxGetTranslation(wxT("Formatting")), 
                               wxWindowID id = wxID_ANY,
                               const wxPoint& pos = wxDefaultPosition, 
                               const wxSize& sz = wxDefaultSize,
                               long style = wxDEFAULT_DIALOG_STYLE);
    ~wxRichTextFormattingDialog();

    void Init();

    bool Create(long flags, 
                wxWindow* parent, 
                const wxString& title = wxGetTranslation(wxT("Formatting")), 
                wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition, 
                const wxSize& sz = wxDefaultSize,
                long style = wxDEFAULT_DIALOG_STYLE);

    /// Get attributes from the given range
    virtual bool GetStyle(wxRichTextCtrl* ctrl, const wxRichTextRange& range);

    /// Set the attributes and optionally update the display
    virtual bool SetStyle(const wxTextAttrEx& style, bool update = true);

    /// Set the style definition and optionally update the display
    virtual bool SetStyleDefinition(const wxRichTextStyleDefinition& styleDef, 
                                    wxRichTextStyleSheet* sheet, 
                                    bool update = true);

    /// Get the style definition, if any
    virtual wxRichTextStyleDefinition* GetStyleDefinition() const;

    /// Get the style sheet, if any
    virtual wxRichTextStyleSheet* GetStyleSheet() const;

    /// Update the display
    virtual bool UpdateDisplay();

    /// Apply attributes to the given range
    virtual bool ApplyStyle(wxRichTextCtrl* ctrl, 
                            const wxRichTextRange& range, 
                            int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO|wxRICHTEXT_SETSTYLE_OPTIMIZE);

    /// Gets and sets the attributes
    const wxTextAttrEx& GetAttributes() const;
    wxTextAttrEx& GetAttributes();
    void SetAttributes(const wxTextAttrEx& attr);

    /// Transfers the data and from to the window
    virtual bool TransferDataToWindow();
    virtual bool TransferDataFromWindow();

    /// Apply the styles when a different tab is selected, so the previews are
    /// up to date
    void OnTabChanged(wxBookCtrlEvent& event);

    /// Respond to help command
    void OnHelp(wxCommandEvent& event);

    /// Set/get image list
    void SetImageList(wxImageList* imageList);
    wxImageList* GetImageList() const;

    /// Get/set formatting factory object
    static void SetFormattingDialogFactory(wxRichTextFormattingDialogFactory* factory);
    static wxRichTextFormattingDialogFactory* GetFormattingDialogFactory();

    /// Helper for pages to get the top-level dialog
    static wxRichTextFormattingDialog* GetDialog(wxWindow* win);

    /// Helper for pages to get the attributes
    static wxTextAttrEx* GetDialogAttributes(wxWindow* win);

    /// Helper for pages to get the style
    static wxRichTextStyleDefinition* GetDialogStyleDefinition(wxWindow* win);

    /// Should we show tooltips?
    static bool ShowToolTips();

    /// Determines whether tooltips will be shown
    static void SetShowToolTips(bool show);

    /// Map book control page index to our page id
    void AddPageId(int id);
};

#endif
