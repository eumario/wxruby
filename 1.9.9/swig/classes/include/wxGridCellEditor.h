// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxGridCellEditor_h_)
#define _wxGridCellEditor_h_
class wxGridCellEditor : public wxGridCellWorker
{
public:
    wxGridCellEditor();

    bool IsCreated();
    wxControl* GetControl();
    void SetControl(wxControl* control);

    wxGridCellAttr* GetCellAttr();
    void SetCellAttr(wxGridCellAttr* attr);

    // Creates the actual edit control
    virtual void Create(wxWindow* parent,
                        wxWindowID id,
                        wxEvtHandler* evtHandler) = 0;

    // Size and position the edit control
    virtual void SetSize(const wxRect& rect);

    // Show or hide the edit control, use the specified attributes to set
    // colours/fonts for it
    virtual void Show(bool show, wxGridCellAttr *attr = (wxGridCellAttr *)NULL);

    // Draws the part of the cell not occupied by the control: the base class
    // version just fills it with background colour from the attribute
    virtual void PaintBackground(const wxRect& rectCell, wxGridCellAttr *attr);

    // Fetch the value from the table and prepare the edit control
    // to begin editing.  Set the focus to the edit control.
    virtual void BeginEdit(int row, int col, wxGrid* grid) = 0;

    // Complete the editing of the current cell. Returns true if the value has
    // changed.  If necessary, the control may be destroyed.
    virtual bool EndEdit(int row, int col, wxGrid* grid) = 0;

    // Reset the value in the control back to its starting value
  virtual void Reset() = 0;

    // return true to allow the given key to start editing: the base class
    // version only checks that the event has no modifiers. The derived
    // classes are supposed to do "if ( base::IsAcceptedKey() && ... )" in
    // their IsAcceptedKey() implementation, although, of course, it is not a
    // mandatory requirment.
    //
    // NB: if the key is F2 (special), editing will always start and this
    //     method will not be called at all (but StartingKey() will)
    virtual bool IsAcceptedKey(wxKeyEvent& event);

    // If the editor is enabled by pressing keys on the grid, this will be
    // called to let the editor do something about that first key if desired
    virtual void StartingKey(wxKeyEvent& event);

    // if the editor is enabled by clicking on the cell, this method will be
    // called
    virtual void StartingClick();

    // Some types of controls on some platforms may need some help
    // with the Return key.
    virtual void HandleReturn(wxKeyEvent& event);

    // Final cleanup
    virtual void Destroy();

    // create a new object which is the copy of this one
    virtual wxGridCellEditor *Clone() const = 0;

	// DJC MAPTEK
	// added GetValue so we can get the value which is in the control
	virtual wxString GetValue() const = 0;	
};


#endif
