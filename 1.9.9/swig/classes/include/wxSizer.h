// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxSizer_h_)
#define _wxSizer_h_
class wxSizer : public wxObject
{
public:
    wxSizer();
    ~wxSizer();

    inline wxSizerItem* Add( wxWindow *window,
                             int proportion = 0,
                             int flag = 0,
                             int border = 0,
                             wxObject* userData = NULL );
    inline wxSizerItem* Add( wxSizer *sizer,
                             int proportion = 0,
                             int flag = 0,
                             int border = 0,
                             wxObject* userData = NULL );
    inline wxSizerItem* Add( int width,
                             int height,
                             int proportion = 0,
                             int flag = 0,
                             int border = 0,
                             wxObject* userData = NULL );
    inline wxSizerItem* Add( wxWindow *window, const wxSizerFlags& flags );
    inline wxSizerItem* Add( wxSizer *sizer, const wxSizerFlags& flags );
    inline wxSizerItem* Add( wxSizerItem *item );

    inline wxSizerItem* AddSpacer(int size);
    inline wxSizerItem* AddStretchSpacer(int prop = 1);

    inline wxSizerItem* Insert( size_t index,
                                wxWindow *window,
                                int proportion = 0,
                                int flag = 0,
                                int border = 0,
                                wxObject* userData = NULL );
    inline wxSizerItem* Insert( size_t index,
                                wxSizer *sizer,
                                int proportion = 0,
                                int flag = 0,
                                int border = 0,
                                wxObject* userData = NULL );
    inline wxSizerItem* Insert( size_t index,
                                int width,
                                int height,
                                int proportion = 0,
                                int flag = 0,
                                int border = 0,
                                wxObject* userData = NULL );
    inline wxSizerItem* Insert( size_t index,
                                wxWindow *window,
                                const wxSizerFlags& flags );
    inline wxSizerItem* Insert( size_t index,
                                wxSizer *sizer,
                                const wxSizerFlags& flags );
    virtual wxSizerItem* Insert( size_t index, wxSizerItem *item );

    inline wxSizerItem* InsertSpacer(size_t index, int size);
    inline wxSizerItem* InsertStretchSpacer(size_t index, int prop = 1);

    inline wxSizerItem* Prepend( wxWindow *window,
                                 int proportion = 0,
                                 int flag = 0,
                                 int border = 0,
                                 wxObject* userData = NULL );
    inline wxSizerItem* Prepend( wxSizer *sizer,
                                 int proportion = 0,
                                 int flag = 0,
                                 int border = 0,
                                 wxObject* userData = NULL );
    inline wxSizerItem* Prepend( int width,
                                 int height,
                                 int proportion = 0,
                                 int flag = 0,
                                 int border = 0,
                                 wxObject* userData = NULL );
    inline wxSizerItem* Prepend( wxWindow *window, const wxSizerFlags& flags );
    inline wxSizerItem* Prepend( wxSizer *sizer, const wxSizerFlags& flags );
    inline wxSizerItem* Prepend( wxSizerItem *item );

    inline wxSizerItem* PrependSpacer(int size);
    inline wxSizerItem* PrependStretchSpacer(int prop = 1);


    // Deprecated in 2.6 since historically it does not delete the window,
    // use Detach instead.
    //virtual bool Remove( wxWindow *window );
    virtual bool Remove( wxSizer *sizer );
    virtual bool Remove( int index );

	virtual bool Replace(wxWindow* oldwin, wxWindow* newwin, 
						 bool recursive = false);
	virtual bool Replace(wxSizer* oldsz, wxSizer* newsz, 
						 bool recursive = false);

    virtual bool Detach( wxWindow *window );
    virtual bool Detach( wxSizer *sizer );
    virtual bool Detach( size_t index );

    virtual void Clear( bool delete_windows = false );
    virtual void DeleteWindows();

    void SetMinSize( int width, int height );
    void SetMinSize( wxSize size );

    // Searches recursively
    bool SetItemMinSize( wxWindow *window, int width, int height );
    bool SetItemMinSize( wxWindow *window, wxSize size );

    // Searches recursively
    bool SetItemMinSize( wxSizer *sizer, int width, int height );
    bool SetItemMinSize( wxSizer *sizer, wxSize size );

    bool SetItemMinSize( size_t index, int width, int height );
    bool SetItemMinSize( size_t index, wxSize size );

    wxSize GetSize() const;
    wxPoint GetPosition() const;

    // Calculate the minimal size or return m_minSize if bigger.
    wxSize GetMinSize();

    virtual void RecalcSizes()  = 0;
    virtual wxSize CalcMin() = 0;

    virtual void Layout();

    wxSize Fit( wxWindow *window );
    void FitInside( wxWindow *window );
    void SetSizeHints( wxWindow *window );
    void SetVirtualSizeHints( wxWindow *window );

    wxSizerItemList& GetChildren();

    void SetDimension( int x, int y, int width, int height );

    wxSizerItem* GetItem( wxWindow *window, bool recursive = false );
    wxSizerItem* GetItem( wxSizer *sizer, bool recursive = false );
    wxSizerItem* GetItem( size_t index );

    // Manage whether individual scene items are considered
    // in the layout calculations or not.
    bool Show( wxWindow *window, bool show = true, bool recursive = false );
    bool Show( wxSizer *sizer, bool show = true, bool recursive = false );
    bool Show( size_t index, bool show = true );

    bool Hide( wxSizer *sizer, bool recursive = false );
    bool Hide( wxWindow *window, bool recursive = false );
    bool Hide( size_t index );

    bool IsShown( wxWindow *window ) const;
    bool IsShown( wxSizer *sizer ) const;
    bool IsShown( size_t index ) const;

    // Recursively call wxWindow::Show () on all sizer items.
    virtual void ShowItems (bool show);

    void Show(bool show);
    bool IsShown() const;
};


#endif
