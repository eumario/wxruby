// Copyright 2004-2005 by Kevin Smith
// released under the MIT-style wxruby2 license

#if !defined(_wxGridCellCoords_h_)
#define _wxGridCellCoords_h_
class wxGridCellCoords
{
public:
    wxGridCellCoords();
    wxGridCellCoords( int r, int c );

    // default copy ctor is ok

    int GetRow() const;
    void SetRow( int n );
    int GetCol() const;
    void SetCol( int n );
    void Set( int row, int col );

    wxGridCellCoords& operator=( const wxGridCellCoords& other );

    bool operator==( const wxGridCellCoords& other ) const;

    bool operator!=( const wxGridCellCoords& other ) const;

    bool operator!() const;
};


#endif
