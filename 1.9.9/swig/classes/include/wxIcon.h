// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxIcon_h_)
#define _wxIcon_h_


class wxIcon : public wxBitmap
{
public:

    wxIcon();
    wxIcon( const wxIcon& icon);
#ifdef __WXGTK__
    wxIcon( const char **bits, int width=-1, int height=-1 );
    wxIcon( char **bits, int width=-1, int height=-1 );
#else
    wxIcon(const char **data);
    wxIcon(char **data);
#endif

    wxIcon( const wxString& filename,
#ifdef __WXGTK__
		wxBitmapType type = wxBITMAP_TYPE_XPM,
#else
		long type = wxBITMAP_TYPE_ICO_RESOURCE,
#endif
		int desiredWidth=-1, int desiredHeight=-1 );
    wxIcon(const wxIconLocation& loc);


    void CopyFromBitmap(const wxBitmap& bmp);
    int GetDepth() const;
    int GetHeight() const;
    int GetWidth() const;
// on GTK this method is inherited from Bitmap, not defined here
#ifndef __WXGTK__
	bool IsOk() const;
#endif
    bool LoadFile(const wxString& name, wxBitmapType type);
    void SetDepth(int depth);
    void SetHeight(int height);
    void SetWidth(int width);

};


#endif
