// wxGridCellTextEditor.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridCellTextEditor_h_)
#define _wxGridCellTextEditor_h_
class wxGridCellTextEditor : public wxGridCellEditor
{
public:
    wxGridCellTextEditor();

    virtual void Create(wxWindow* parent,
                        wxWindowID id,
                        wxEvtHandler* evtHandler);
    virtual void SetSize(const wxRect& rect);

    virtual void PaintBackground(const wxRect& rectCell, wxGridCellAttr *attr);

    virtual bool IsAcceptedKey(wxKeyEvent& event);
    virtual void BeginEdit(int row, int col, wxGrid* grid);
    virtual bool EndEdit(int row, int col, wxGrid* grid);

    virtual void Reset();
    virtual void StartingKey(wxKeyEvent& event);
    virtual void HandleReturn(wxKeyEvent& event);

    // parameters string format is "max_width"
    virtual void SetParameters(const wxString& params);

    virtual wxGridCellEditor *Clone() const;

    // DJC MAPTEK
    // added GetValue so we can get the value which is in the control
    virtual wxString GetValue() const;
};


#endif
