// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxRichTextEvent_h_)
#define _wxRichTextEvent_h_

class wxRichTextEvent : public wxNotifyEvent
{
 public:
  wxRichTextEvent(wxEventType commandType = wxEVT_NULL, int winid = 0);
  wxRichTextEvent(const wxRichTextEvent& event);
  long GetPosition() const;
  void SetPosition(long pos);

  int GetFlags() const;
  void SetFlags(int flags);

  wxRichTextStyleSheet* GetOldStyleSheet() const;
  void SetOldStyleSheet(wxRichTextStyleSheet* sheet);

  wxRichTextStyleSheet* GetNewStyleSheet() const;
  void SetNewStyleSheet(wxRichTextStyleSheet* sheet);

  const wxRichTextRange& GetRange() const;
  void SetRange(const wxRichTextRange& range);

  wxChar GetCharacter() const;
  void SetCharacter(wxChar ch);

  virtual wxEvent *Clone() const;
};

#endif
