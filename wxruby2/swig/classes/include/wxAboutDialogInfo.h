// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxAboutDialogInfo_h_)
#define _wxAboutDialogInfo_h_

class wxAboutDialogInfo
{
 public:
  wxAboutDialogInfo();

  void SetName(const wxString& name);
  wxString GetName() const;
  void SetVersion(const wxString& version);
  bool HasVersion() const;
  wxString GetVersion() const;

  void SetDescription(const wxString& desc);
  bool HasDescription() const;
  wxString GetDescription() const;

  void SetCopyright(const wxString& copyright);
  bool HasCopyright() const;
  wxString GetCopyright() const;

  // long, multiline string containing the text of the program licence
  void SetLicence(const wxString& licence);
  void SetLicense(const wxString& licence);
  bool HasLicence() const;
  wxString GetLicence() const;

  // icon to be shown in the dialog, defaults to the main frame icon
  void SetIcon(const wxIcon& icon);
  bool HasIcon() const;
  wxIcon GetIcon() const;

  // web site for the program and its description (defaults to URL itself if
  // empty)
  void SetWebSite(const wxString& url, 
                  const wxString& desc = wxEmptyString);
  bool HasWebSite() const;

  wxString GetWebSiteURL() const;
  wxString GetWebSiteDescription() const;

  void SetDevelopers(const wxArrayString& developers);
  void AddDeveloper(const wxString& developer);
  bool HasDevelopers() const;
  const wxArrayString& GetDevelopers() const;

  void SetDocWriters(const wxArrayString& docwriters);
  void AddDocWriter(const wxString& docwriter);
  bool HasDocWriters() const;
  const wxArrayString& GetDocWriters() const;

  // the list of artists for the program art
  void SetArtists(const wxArrayString& artists);
  void AddArtist(const wxString& artist);
  bool HasArtists() const;
  const wxArrayString& GetArtists();

  // the list of translators
  void SetTranslators(const wxArrayString& translators);
  void AddTranslator(const wxString& translator);
  bool HasTranslators() const;
  const wxArrayString& GetTranslators() const;
};

#endif
