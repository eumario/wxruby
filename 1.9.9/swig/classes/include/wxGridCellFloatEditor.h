// wxGridCellFloatEditor.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridCellFloatEditor_h_)
#define _wxGridCellFloatEditor_h_
class wxGridCellFloatEditor : public wxGridCellTextEditor
{
public:

   wxGridCellFloatEditor(int  width = -1, int  precision = -1) ;

    virtual void Create(wxWindow* parent,
                        wxWindowID id,
                        wxEvtHandler* evtHandler);

    virtual bool IsAcceptedKey(wxKeyEvent& event);
    virtual void BeginEdit(int row, int col, wxGrid* grid);
    virtual bool EndEdit(int row, int col, wxGrid* grid);

    virtual void Reset();
    virtual void StartingKey(wxKeyEvent& event);

    virtual wxGridCellEditor *Clone() const;

    // parameters string format is "width,precision"
    virtual void SetParameters(const wxString& params); 
};


#endif
