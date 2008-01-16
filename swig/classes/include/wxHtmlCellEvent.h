// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxHtmlCellEvent_h_)
#define _wxHtmlCellEvent_h_

class wxHtmlCellEvent : public wxCommandEvent
{
public:
  wxHtmlCellEvent();
  wxHtmlCellEvent(wxEventType commandType, int id,
                  wxHtmlCell *cell, const wxPoint &pt,
                  const wxMouseEvent &ev);
  wxHtmlCell* GetCell() const;
  wxPoint GetPoint() const;
  wxMouseEvent GetMouseEvent() const;
  
  void SetLinkClicked(bool linkclicked);
  bool GetLinkClicked() const;
};

#endif
