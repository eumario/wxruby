// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxStandardPaths_h_)
#define _wxStandardPaths_h_

class wxStandardPaths
{
public:

    enum ResourceCat
    {
        ResourceCat_None,
        ResourceCat_Messages,
        ResourceCat_Max
    };

    static wxStandardPathsBase& Get();
    wxString GetExecutablePath() const;
    wxString GetConfigDir() const;
    wxString GetUserConfigDir() const;
    wxString GetDataDir() const;
    wxString GetLocalDataDir() const;
    wxString GetUserDataDir() const;
    wxString GetUserLocalDataDir() const;
    wxString GetPluginsDir() const;
    wxString GetResourcesDir() const;
    wxString GetLocalizedResourcesDir(const wxChar *lang, 
                                      ResourceCat category = ResourceCat_None) const;
    wxString GetDocumentsDir() const;
    wxString GetTempDir() const;

    // virtual dtor for the base class
    virtual ~wxStandardPathsBase();

protected:
    // append "/appname" suffix if the app name is set (doesn't append the
    // slash if dir already ends with a slash or dot)
    static wxString AppendAppName(const wxString& dir);
};

#endif
