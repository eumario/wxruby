// Copyright 2004-2005 by Kevin Smith
// released under the MIT-style wxruby2 license

#if !defined(_wxGridEditorCreatedEvent_h_)
#define _wxGridEditorCreatedEvent_h_
class wxGridEditorCreatedEvent : public wxCommandEvent
{
public:
    wxGridEditorCreatedEvent();

    wxGridEditorCreatedEvent(int id, wxEventType type, wxObject* obj,
                             int row, int col, wxControl* ctrl);

    int GetRow();
    int GetCol();
    wxControl* GetControl();
    void SetRow(int row);
    void SetCol(int col);
    void SetControl(wxControl* ctrl);

		virtual wxEvent *Clone() const;

};


#endif
