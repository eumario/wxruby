// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxNotebookEvent_h_)
#define _wxNotebookEvent_h_

class wxNotebookEvent : public wxBookCtrlBaseEvent
{
public:
   wxNotebookEvent(wxEventType eventType = wxEVT_NULL, 
                   int id = 0, 
                   int sel = -1, 
                   int oldSel = -1);

  wxNotebookEvent(const wxNotebookEvent& event);
};


#endif
