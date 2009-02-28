// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxSizerItem_h_)
#define _wxSizerItem_h_

class wxSizerItem : public wxObject
{
public:
    // window
    wxSizerItem( wxWindow *window,
                 int proportion,
                 int flag,
                 int border,
                 wxObject* userData );

    // window with flags
    wxSizerItem(wxWindow *window, const wxSizerFlags& flags);

    // subsizer
    wxSizerItem( wxSizer *sizer,
                 int proportion,
                 int flag,
                 int border,
                 wxObject* userData );

    // sizer with flags
    wxSizerItem(wxSizer *sizer, const wxSizerFlags& flags);
    // spacer
    wxSizerItem( int width,
                 int height,
                 int proportion,
                 int flag,
                 int border,
                 wxObject* userData);

    // spacer with flags
    wxSizerItem(int width, int height, const wxSizerFlags& flags);

    wxSizerItem();
    virtual ~wxSizerItem();

    void DeleteWindows();
    void DetachSizer();

    wxSize GetSize() const;
    wxSize CalcMin();
    void SetDimension( const wxPoint& pos, const wxSize& size );

    wxSize GetMinSize() const;
    wxSize GetMinSizeWithBorder() const;

    void SetMinSize(const wxSize& size);
    void SetMinSize( int x, int y );
    void SetInitSize( int x, int y );

    void SetRatio(int width, int height);
    void SetRatio(const wxSize& size);
    void SetRatio(float ratio);
    float GetRatio() const;
    wxRect GetRect();

    bool IsWindow() const;
    bool IsSizer() const;
    bool IsSpacer() const;

    void SetProportion( int proportion );
    int GetProportion() const;
    void SetFlag( int flag );
    int GetFlag() const;
    void SetBorder( int border );
    int GetBorder() const;


    wxWindow *GetWindow() const;
    wxSizer *GetSizer() const;
    wxSize GetSpacer() const;

    bool IsShown() const;
    void Show(bool show);

    void SetUserData(wxObject* userData);
    wxObject* GetUserData() const;
    wxPoint GetPosition() const;



    void SetWindow(wxWindow *window);
    void SetSizer(wxSizer *sizer);
    void SetSpacer(const wxSize& size);
    void SetSpacer(int width, int height);
};

#endif
