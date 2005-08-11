// wxIcon.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxIcon_h_)
#define _wxIcon_h_


class wxIcon : public wxBitmap
{
public:

    wxIcon();
    wxIcon( const wxIcon& icon);
    wxIcon( const char **bits, int width=-1, int height=-1 );

    wxIcon( const wxString& filename,
#ifdef __WXGTK__
		wxBitmapType type = wxBITMAP_TYPE_XPM,
#else
		long type = wxBITMAP_TYPE_ICO_RESOURCE,
#endif
		int desiredWidth=-1, int desiredHeight=-1 );

	wxIcon( char **bits, int width=-1, int height=-1 );

    wxIcon(const wxIconLocation& loc);

#if 0 // Not appropriate for swig wrapping
    wxIcon& operator=(const wxIcon& icon);
    bool operator==(const wxIcon& icon) const { return m_refData == icon.m_refData; }
    bool operator!=(const wxIcon& icon) const { return !(*this == icon); }
#endif

    // create from bitmap (which should have a mask unless it's monochrome):
    // there shouldn't be any implicit bitmap -> icon conversion (i.e. no
    // ctors, assignment operators...), but it's ok to have such function
    void CopyFromBitmap(const wxBitmap& bmp);

};


#endif
