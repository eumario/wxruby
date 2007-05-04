#if !defined(_wxDialogBase_h_)
#define _wxDialogBase_h_
class wxDialogBase : public wxTopLevelWindow
{
public:
    wxDialogBase() ;
    virtual  ~wxDialogBase() ;
    void Centre(int direction = wxBOTH) ;
    /**
    * \brief Used for two-step dialog box construction. See  
        for details. 
    * \param wxWindow*   
    * \param wxWindowID   
    * \param const wxString&   
    * \param const wxPoint&   
    * \param const wxSize&   
    * \param long  
    * \param const wxString&   
    */

    bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  title , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE, const wxString&  name = wxT("dialogBox")) ;
    wxString GetTitle() const;
    void Iconize(const bool  iconize ) ;
    bool IsIconized() const;
    void SetIcon(const wxIcon&  icon ) ;
    void SetIcons(const wxIconBundle&  icons ) ;
    void SetTitle(const wxString&   title ) ;
    virtual bool Show(bool show = true ) ;

    virtual int ShowModal()=0;
    virtual void EndModal(int  retCode )=0;
    virtual bool IsModal()const=0;
    void SetReturnCode(int  retCode ) ;
    int GetReturnCode() const;
    void SetAffirmativeId(int affirmativeId);
    int GetAffirmativeId() const;
    void SetEscapeId(int escapeId);
    int GetEscapeId() const;
private:
    void OnSysColourChanged(wxSysColourChangedEvent& event);

};


#endif
