class wxGBSpan
{
public:
    wxGBSpan() : m_rowspan(1), m_colspan(1) {}
    wxGBSpan(int rowspan, int colspan) : m_rowspan(rowspan), m_colspan(colspan) {}

    // default copy ctor and assignment operator are okay.

    int GetRowspan() const { return m_rowspan; }
    int GetColspan() const { return m_colspan; }
    void SetRowspan(int rowspan) { m_rowspan = rowspan; }
    void SetColspan(int colspan) { m_colspan = colspan; }

    bool operator==(const wxGBSpan& o) const { return m_rowspan == o.m_rowspan && m_colspan == o.m_colspan; }
    bool operator!=(const wxGBSpan& o) const { return !(*this == o); }

private:
    int m_rowspan;
    int m_colspan;
};
