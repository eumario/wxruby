// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxRendererNative_h_)
#define _wxRendererNative_h_

class wxRendererNative
{
public:
  // pseudo-constructors
  static wxRendererNative& Get();
  static wxRendererNative& GetGeneric();
  static wxRendererNative& GetDefault();

  int DrawHeaderButton(wxWindow *win,
					   wxDC& dc,
					   const wxRect& rect,
					   int flags = 0,
					   wxHeaderSortIconType sortArrow = wxHDR_SORT_ICON_NONE,
					   wxHeaderButtonParams* params=NULL);

  // Normally only called by DrawHeaderButton.
  int  DrawHeaderButtonContents(wxWindow *win,
								wxDC& dc,
								const wxRect& rect,
								int flags = 0,
								wxHeaderSortIconType sortArrow = wxHDR_SORT_ICON_NONE,
								wxHeaderButtonParams* params=NULL);

  int GetHeaderButtonHeight(wxWindow *win);
  void DrawTreeItemButton(wxWindow *win,
						  wxDC& dc,
						  const wxRect& rect,
						  int flags = 0);

  // draw the border for sash window: this border must be such that the sash
  // drawn by DrawSash() blends into it well
  void DrawSplitterBorder(wxWindow *win,
						  wxDC& dc,
						  const wxRect& rect,
						  int flags = 0);

  void DrawSplitterSash(wxWindow *win,
						wxDC& dc,
						const wxSize& size,
						wxCoord position,
						wxOrientation orient,
						int flags = 0);

  void DrawComboBoxDropButton(wxWindow *win,
							  wxDC& dc,
							  const wxRect& rect,
							  int flags = 0);

  void DrawDropArrow(wxWindow *win,
					 wxDC& dc,
					 const wxRect& rect,
					 int flags = 0);

  void DrawCheckBox(wxWindow *win,
					wxDC& dc,
					const wxRect& rect,
					int flags = 0);
  void DrawPushButton(wxWindow *win,
					  wxDC& dc,
					  const wxRect& rect,
					  int flags = 0);
  void DrawItemSelectionRect(wxWindow *win,
							 wxDC& dc,
							 const wxRect& rect,
							 int flags = 0);


  wxSplitterRenderParams GetSplitterParams(const wxWindow *win);



#if wxUSE_DYNLIB_CLASS
    static wxRendererNative *Load(const wxString& name);
#endif // wxUSE_DYNLIB_CLASS
    static wxRendererNative *Set(wxRendererNative *renderer);
    wxRendererVersion GetVersion() const = 0;

    virtual ~wxRendererNative();
};

#endif
