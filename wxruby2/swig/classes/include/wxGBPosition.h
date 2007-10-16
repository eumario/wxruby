// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

class wxGBPosition
{
public:
    wxGBPosition() : m_row(0), m_col(0) {}
    wxGBPosition(int row, int col) : m_row(row), m_col(col) {}

    // default copy ctor and assignment operator are okay.

    int GetRow() const { return m_row; }
    int GetCol() const { return m_col; }
    void SetRow(int row) { m_row = row; }
    void SetCol(int col) { m_col = col; }

    bool operator==(const wxGBPosition& p) const { return m_row == p.m_row && m_col == p.m_col; }
    bool operator!=(const wxGBPosition& p) const { return !(*this == p); }

private:
    int m_row;
    int m_col;
};
