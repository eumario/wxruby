
class wxTreebookEvent : public wxBookCtrlBaseEvent
{
public:
    wxTreebookEvent(wxEventType commandType = wxEVT_NULL, 
                    int id = 0,
                    int nSel = wxNOT_FOUND, 
                    int nOldSel = wxNOT_FOUND);
    wxTreebookEvent(const wxTreebookEvent& event);
    virtual wxEvent *Clone() const;
};
