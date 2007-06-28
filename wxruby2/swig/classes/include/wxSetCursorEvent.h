//   Copyright 2007 by Kevin Smith
//   released under the MIT-style wxruby2 license

#if !defined(_wxSetCursorEvent_h_)
#define _wxSetCursorEvent_h_

class wxSetCursorEvent : public wxEvent
{
public:
  wxSetCursorEvent(wxCoord x = 0, wxCoord y = 0);
  wxSetCursorEvent(const wxSetCursorEvent & event);

  wxCoord GetX() const;
  wxCoord GetY() const;

  void SetCursor(const wxCursor& cursor);
  const wxCursor& GetCursor() const;
  bool HasCursor() const;

  virtual wxEvent *Clone() const;
};

#endif
