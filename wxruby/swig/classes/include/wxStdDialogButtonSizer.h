#if !defined(_wxStdDialogButtonSizer_h_)
#define _wxStdDialogButtonSizer_h_

class wxStdDialogButtonSizer: public wxBoxSizer
{
public:
    // Constructor just creates a new wxBoxSizer, not much else.
    // Box sizer orientation is automatically determined here:
    // vertical for PDAs, horizontal for everything else?
    wxStdDialogButtonSizer();

    // Checks button ID against system IDs and sets one of the pointers below
    // to this button. Does not do any sizer-related things here.
    void AddButton(wxButton *button);

    // Use these if no standard ID can/should be used
    void SetAffirmativeButton( wxButton *button );
    void SetNegativeButton( wxButton *button );
    void SetCancelButton( wxButton *button );
    void Realize();

    wxButton *GetAffirmativeButton() const { return m_buttonAffirmative; }
    wxButton *GetApplyButton() const { return m_buttonApply; }
    wxButton *GetNegativeButton() const { return m_buttonNegative; }
    wxButton *GetCancelButton() const { return m_buttonCancel; }
    wxButton *GetHelpButton() const { return m_buttonHelp; }

protected:
    wxButton *m_buttonAffirmative;  // wxID_OK, wxID_YES, wxID_SAVE go here
    wxButton *m_buttonApply;
    wxButton *m_buttonNegative;     // wxID_NO
    wxButton *m_buttonCancel;
    wxButton *m_buttonHelp;

};

#endif
