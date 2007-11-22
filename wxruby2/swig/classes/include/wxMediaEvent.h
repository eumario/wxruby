
class  wxMediaEvent : public wxNotifyEvent
{
public:
    // ------------------------------------------------------------------------
    // wxMediaEvent Constructor
    //
    // Normal constructor, much the same as wxNotifyEvent
    // ------------------------------------------------------------------------
    wxMediaEvent(wxEventType commandType = wxEVT_NULL, int winid = 0)
        : wxNotifyEvent(commandType, winid)
    {                                       }

    // ------------------------------------------------------------------------
    // wxMediaEvent Copy Constructor
    //
    // Normal copy constructor, much the same as wxNotifyEvent
    // ------------------------------------------------------------------------
    wxMediaEvent(const wxMediaEvent &clone)
            : wxNotifyEvent(clone)
    {                                       }

    // ------------------------------------------------------------------------
    // wxMediaEvent::Clone
    //
    // Allocates a copy of this object.
    // Required for wxEvtHandler::AddPendingEvent
    // ------------------------------------------------------------------------
    virtual wxEvent *Clone() const
    {   return new wxMediaEvent(*this);     }

};