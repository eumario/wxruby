// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxPropertySheetDialog_h_)
#define _wxPropertySheetDialog_h_

class wxPropertySheetDialog : public wxDialog
{
 public:
  wxPropertySheetDialog();

  wxPropertySheetDialog(wxWindow* parent, wxWindowID id,
                        const wxString& title,
                        const wxPoint& pos = wxDefaultPosition,
                        const wxSize& sz = wxDefaultSize,
                        long style = wxDEFAULT_DIALOG_STYLE,
                        const wxString& name = wxDialogNameStr);

  bool Create(wxWindow* parent, wxWindowID id,
              const wxString& title,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& sz = wxDefaultSize,
              long style = wxDEFAULT_DIALOG_STYLE,
              const wxString& name = wxDialogNameStr);

  // Set and get the notebook
  void SetBookCtrl(wxBookCtrlBase* book);
  wxBookCtrlBase* GetBookCtrl() const;

  // Set and get the inner sizer
  void SetInnerSize(wxSizer* sizer);
  wxSizer* GetInnerSizer() const;

  // Set and get the book style
  void SetSheetStyle(long sheetStyle);
  long GetSheetStyle() const;

  // Set and get the border around the whole dialog
  void SetSheetOuterBorder(int border);
  int GetSheetOuterBorder() const;

  // Set and get the border around the book control only
  void SetSheetInnerBorder(int border);
  int GetSheetInnerBorder() const;

  // Creates the buttons (none on PocketPC)
  virtual void CreateButtons(int flags = wxOK|wxCANCEL);

  // Lay out the dialog, to be called after pages have been created
  virtual void LayoutDialog(int centreFlags = wxBOTH);


  virtual wxBookCtrlBase* CreateBookCtrl();

  // Adds the book control to the inner sizer.
  virtual void AddBookCtrl(wxSizer* sizer);

  // Set the focus
  void OnActivate(wxActivateEvent& event);

  // Resize dialog if necessary
  void OnIdle(wxIdleEvent& event);
};

#endif
