// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxXmlResource_h_)
#define _wxXmlResource_h_
class wxXmlResource : public wxObject
{
 public:
  wxXmlResource(int flags = wxXRC_USE_LOCALE);
  wxXmlResource(const wxString& filemask, int flags = wxXRC_USE_LOCALE);
  ~wxXmlResource();
  bool Load(const wxString& filemask);
  void InitAllHandlers();
  void AddHandler(wxXmlResourceHandler *handler);
  void InsertHandler(wxXmlResourceHandler *handler);
  void ClearHandlers();
  static void AddSubclassFactory(wxXmlSubclassFactory *factory);
  wxMenu *LoadMenu(const wxString& name);
  wxMenuBar *LoadMenuBar(wxWindow *parent, const wxString& name);
  wxMenuBar *LoadMenuBar(const wxString& name);
  wxToolBar *LoadToolBar(wxWindow *parent, const wxString& name);
  wxDialog *LoadDialog(wxWindow *parent, const wxString& name);
  bool LoadDialog(wxDialog *dlg, wxWindow *parent, const wxString& name);
  wxPanel *LoadPanel(wxWindow *parent, const wxString& name);
  bool LoadPanel(wxPanel *panel, wxWindow *parent, const wxString& name);
  wxFrame *LoadFrame(wxWindow* parent, const wxString& name);
  bool LoadFrame(wxFrame* frame, wxWindow *parent, const wxString& name);
  wxObject *LoadObject(wxWindow *parent, const wxString& name,
                       const wxString& classname);
  bool LoadObject(wxObject *instance, wxWindow *parent, const wxString& name,
                  const wxString& classname);
  wxBitmap LoadBitmap(const wxString& name);
  wxIcon LoadIcon(const wxString& name);
  bool AttachUnknownControl(const wxString& name, wxWindow *control,
                            wxWindow *parent = NULL);
  static int GetXRCID(const wxChar *str_id);
  long GetVersion() const;
  int CompareVersion(int major, int minor, int release, int revision) const;
  static wxXmlResource *Get();
  static wxXmlResource *Set(wxXmlResource *res);
  int GetFlags() const;
  void SetFlags(int flags);
};


#endif
