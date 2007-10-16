// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxAuiNotebookEvent_h_)
#define _wxAuiNotebookEvent_h_


// aui notebook event class

class wxAuiNotebookEvent : public wxNotifyEvent
{
public:
    wxAuiNotebookEvent(wxEventType command_type = wxEVT_NULL,
                       int win_id = 0)
          : wxNotifyEvent(command_type, win_id)
    {
        old_selection = -1;
        selection = -1;
        drag_source = NULL;
    }

    wxEvent *Clone() const { return new wxAuiNotebookEvent(*this); }

    void SetSelection(int s) { selection = s; m_commandInt = s; }
    int GetSelection() const { return selection; }
    
    void SetOldSelection(int s) { old_selection = s; }
    int GetOldSelection() const { return old_selection; }
    
    void SetDragSource(wxAuiNotebook* s) { drag_source = s; }
    wxAuiNotebook* GetDragSource() const { return drag_source; }
};

#endif
