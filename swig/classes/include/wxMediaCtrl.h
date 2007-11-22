
enum wxMediaState
{
    wxMEDIASTATE_STOPPED,
    wxMEDIASTATE_PAUSED,
    wxMEDIASTATE_PLAYING
};

enum wxMediaCtrlPlayerControls
{
    wxMEDIACTRLPLAYERCONTROLS_NONE           =   0,
    //Step controls like fastfoward, step one frame etc.
    wxMEDIACTRLPLAYERCONTROLS_STEP           =   1 << 0,
    //Volume controls like the speaker icon, volume slider, etc.
    wxMEDIACTRLPLAYERCONTROLS_VOLUME         =   1 << 1,
    wxMEDIACTRLPLAYERCONTROLS_DEFAULT        =
                    wxMEDIACTRLPLAYERCONTROLS_STEP |
                    wxMEDIACTRLPLAYERCONTROLS_VOLUME
};


typedef int wxFileOffset;

// ----------------------------------------------------------------------------
//
// wxMediaCtrl
//
// ----------------------------------------------------------------------------

class wxMediaCtrl : public wxControl
{
public:
    wxMediaCtrl();

    wxMediaCtrl(wxWindow* parent, wxWindowID winid,
                const wxString& fileName = wxEmptyString,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxString& szBackend = wxEmptyString,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxT("mediaCtrl"));

    wxMediaCtrl(wxWindow* parent, wxWindowID winid,
                const wxURI& location,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxString& szBackend = wxEmptyString,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxT("mediaCtrl"));

    virtual ~wxMediaCtrl();

    bool Create(wxWindow* parent, wxWindowID winid,
                const wxString& fileName = wxEmptyString,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxString& szBackend = wxEmptyString,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxT("mediaCtrl"));

    bool Create(wxWindow* parent, wxWindowID winid,
                const wxURI& location,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxString& szBackend = wxEmptyString,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxT("mediaCtrl"));

    bool DoCreate(wxClassInfo* instance,
                wxWindow* parent, wxWindowID winid,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxT("mediaCtrl"));

    bool Play();
    bool Pause();
    bool Stop();

    bool Load(const wxString& fileName);

    wxMediaState GetState();

    wxFileOffset Seek(wxFileOffset where, wxSeekMode mode = wxFromStart);
    wxFileOffset Tell(); //FIXME: This should be const
    wxFileOffset Length(); //FIXME: This should be const


    double GetPlaybackRate();           //All but MCI & GStreamer
    bool SetPlaybackRate(double dRate); //All but MCI & GStreamer
    bool Load(const wxURI& location);
    bool Load(const wxURI& location, const wxURI& proxy);

    wxFileOffset GetDownloadProgress(); // DirectShow only
    wxFileOffset GetDownloadTotal();    // DirectShow only

    double GetVolume();
    bool   SetVolume(double dVolume);

    bool    ShowPlayerControls(
        wxMediaCtrlPlayerControls flags = wxMEDIACTRLPLAYERCONTROLS_DEFAULT);

    //helpers for the wxPython people
    bool LoadURI(const wxString& fileName)
    {   return Load(wxURI(fileName));       }
    bool LoadURIWithProxy(const wxString& fileName, const wxString& proxy)
    {   return Load(wxURI(fileName), wxURI(proxy));       }


};



