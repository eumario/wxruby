// wxXmlResource.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxXmlResource_h_)
#define _wxXmlResource_h_
class wxXmlResource : public wxObject
{
public:
    // Constructor.
    // Flags: wxXRC_USE_LOCALE
    //              translatable strings will be translated via _()
    //        wxXRC_NO_SUBCLASSING
    //              subclass property of object nodes will be ignored
    //              (useful for previews in XRC editors)
    wxXmlResource(int flags = wxXRC_USE_LOCALE);

    // Constructor.
    // Flags: wxXRC_USE_LOCALE
    //              translatable strings will be translated via _()
    //        wxXRC_NO_SUBCLASSING
    //              subclass property of object nodes will be ignored
    //              (useful for previews in XRC editors)
    wxXmlResource(const wxString& filemask, int flags = wxXRC_USE_LOCALE);

    // Destructor.
    ~wxXmlResource();

    // Loads resources from XML files that match given filemask.
    // This method understands VFS (see filesys.h).
    bool Load(const wxString& filemask);

    // Initialize handlers for all supported controls/windows. This will
    // make the executable quite big because it forces linking against
    // most of the wxWidgets library.
    void InitAllHandlers();

    // Initialize only a specific handler (or custom handler). Convention says
    // that handler name is equal to the control's name plus 'XmlHandler', for
    // example wxTextCtrlXmlHandler, wxHtmlWindowXmlHandler. The XML resource
    // compiler (xmlres) can create include file that contains initialization
    // code for all controls used within the resource.
    void AddHandler(wxXmlResourceHandler *handler);

    // Add a new handler at the begining of the handler list
    void InsertHandler(wxXmlResourceHandler *handler);

    // Removes all handlers
    void ClearHandlers();

    // Registers subclasses factory for use in XRC. This function is not meant
    // for public use, please see the comment above wxXmlSubclassFactory
    // definition.
    static void AddSubclassFactory(wxXmlSubclassFactory *factory);

    // Loads menu from resource. Returns NULL on failure.
    wxMenu *LoadMenu(const wxString& name);

    // Loads menubar from resource. Returns NULL on failure.
    wxMenuBar *LoadMenuBar(wxWindow *parent, const wxString& name);

    // Loads menubar from resource. Returns NULL on failure.
    wxMenuBar *LoadMenuBar(const wxString& name) { return LoadMenuBar(NULL, name); }

#if wxUSE_TOOLBAR
    // Loads a toolbar.
    wxToolBar *LoadToolBar(wxWindow *parent, const wxString& name);
#endif

    // Loads a dialog. dlg points to parent window (if any).
    wxDialog *LoadDialog(wxWindow *parent, const wxString& name);

    // Loads a dialog. dlg points to parent window (if any). This form
    // is used to finish creation of already existing instance (main reason
    // for this is that you may want to use derived class with new event table)
    // Example (typical usage):
    //      MyDialog dlg;
    //      wxTheXmlResource->LoadDialog(&dlg, mainFrame, "my_dialog");
    //      dlg->ShowModal();
    bool LoadDialog(wxDialog *dlg, wxWindow *parent, const wxString& name);

    // Loads a panel. panel points to parent window (if any).
    wxPanel *LoadPanel(wxWindow *parent, const wxString& name);

    // Loads a panel. panel points to parent window (if any). This form
    // is used to finish creation of already existing instance.
    bool LoadPanel(wxPanel *panel, wxWindow *parent, const wxString& name);

    // Loads a frame.
    wxFrame *LoadFrame(wxWindow* parent, const wxString& name);
    bool LoadFrame(wxFrame* frame, wxWindow *parent, const wxString& name);

    // Load an object from the resource specifying both the resource name and
    // the classname.  This lets you load nonstandard container windows.
    wxObject *LoadObject(wxWindow *parent, const wxString& name,
                         const wxString& classname);

    // Load an object from the resource specifying both the resource name and
    // the classname.  This form lets you finish the creation of an existing
    // instance.
    bool LoadObject(wxObject *instance, wxWindow *parent, const wxString& name,
                    const wxString& classname);

    // Loads a bitmap resource from a file.
    wxBitmap LoadBitmap(const wxString& name);

    // Loads an icon resource from a file.
    wxIcon LoadIcon(const wxString& name);

    // Attaches an unknown control to the given panel/window/dialog.
    // Unknown controls are used in conjunction with <object class="unknown">.
    bool AttachUnknownControl(const wxString& name, wxWindow *control,
                              wxWindow *parent = NULL);

    // Returns a numeric ID that is equivalent to the string id used in an XML
    // resource. To be used in event tables.
    // Macro XRCID is provided for convenience
    static int GetXRCID(const wxChar *str_id);

    // Returns version information (a.b.c.d = d+ 256*c + 256^2*b + 256^3*a).
  long GetVersion() const;

    // Compares resources version to argument. Returns -1 if resources version
    // is less than the argument, +1 if greater and 0 if they equal.
    int CompareVersion(int major, int minor, int release, int revision) const;
//// Singleton accessors.

    // Gets the global resources object or creates one if none exists.
    static wxXmlResource *Get();

    // Sets the global resources object and returns a pointer to the previous one (may be NULL).
    static wxXmlResource *Set(wxXmlResource *res);

    // Returns flags, which may be a bitlist of wxXRC_USE_LOCALE and wxXRC_NO_SUBCLASSING.
    int GetFlags() const;
    // Set flags after construction.
    void SetFlags(int flags);
};


#endif
