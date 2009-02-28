// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxStyledTextEvent_h_)
#define _wxStyledTextEvent_h_

class wxStyledTextEvent : public wxCommandEvent {
public:
    wxStyledTextEvent(wxEventType commandType=0, int id=0);
    ~wxStyledTextEvent() {}

    void SetPosition(int pos)             { m_position = pos; }
    void SetKey(int k)                    { m_key = k; }
    void SetModifiers(int m)              { m_modifiers = m; }
    void SetModificationType(int t)       { m_modificationType = t; }
    void SetText(const wxString& t)       { m_text = t; }
    void SetLength(int len)               { m_length = len; }
    void SetLinesAdded(int num)           { m_linesAdded = num; }
    void SetLine(int val)                 { m_line = val; }
    void SetFoldLevelNow(int val)         { m_foldLevelNow = val; }
    void SetFoldLevelPrev(int val)        { m_foldLevelPrev = val; }
    void SetMargin(int val)               { m_margin = val; }
    void SetMessage(int val)              { m_message = val; }
    void SetWParam(int val)               { m_wParam = val; }
    void SetLParam(int val)               { m_lParam = val; }
    void SetListType(int val)             { m_listType = val; }
    void SetX(int val)                    { m_x = val; }
    void SetY(int val)                    { m_y = val; }
    void SetDragText(const wxString& val) { m_dragText = val; }
    void SetDragAllowMove(bool val)       { m_dragAllowMove = val; }
#ifdef  STC_USE_DND
    void SetDragResult(wxDragResult val)  { m_dragResult = val; }
#endif

    int  GetPosition() const         { return m_position; }
    int  GetKey()  const             { return m_key; }
    int  GetModifiers() const        { return m_modifiers; }
    int  GetModificationType() const { return m_modificationType; }
    wxString GetText() const         { return m_text; }
    int  GetLength() const           { return m_length; }
    int  GetLinesAdded() const       { return m_linesAdded; }
    int  GetLine() const             { return m_line; }
    int  GetFoldLevelNow() const     { return m_foldLevelNow; }
    int  GetFoldLevelPrev() const    { return m_foldLevelPrev; }
    int  GetMargin() const           { return m_margin; }
    int  GetMessage() const          { return m_message; }
    int  GetWParam() const           { return m_wParam; }
    int  GetLParam() const           { return m_lParam; }
    int  GetListType() const         { return m_listType; }
    int  GetX() const                { return m_x; }
    int  GetY() const                { return m_y; }
    wxString GetDragText()           { return m_dragText; }
    bool GetDragAllowMove()          { return m_dragAllowMove; }
#ifdef STC_USE_DND
    wxDragResult GetDragResult()     { return m_dragResult; }
#endif

    bool GetShift() const;
    bool GetControl() const;
    bool GetAlt() const;

    virtual wxEvent* Clone() const { return new wxStyledTextEvent(*this); }
};

#endif
