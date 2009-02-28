// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxGridCellBoolEditor_h_)
#define _wxGridCellBoolEditor_h_

class wxGridCellBoolEditor : public wxGridCellEditor
{
public:
  wxGridCellBoolEditor();

  virtual void Create(wxWindow* parent,
                      wxWindowID id,
                      wxEvtHandler* evtHandler);

  virtual void SetSize(const wxRect& rect);
  virtual void Show(bool show, wxGridCellAttr *attr = NULL);

  virtual bool IsAcceptedKey(wxKeyEvent& event);
  virtual void BeginEdit(int row, int col, wxGrid* grid);
  virtual bool EndEdit(int row, int col, wxGrid* grid);

  virtual void Reset();
  virtual void StartingClick();
  virtual void StartingKey(wxKeyEvent& event);

  virtual wxGridCellEditor *Clone();

  // added GetValue so we can get the value which is in the control, see
  // also UseStringValues()
  virtual wxString GetValue() const;

  // set the string values returned by GetValue() for the true and false
  // states, respectively
  static void UseStringValues(const wxString& valueTrue = _T("1"),
                              const wxString& valueFalse = wxEmptyString);

  // return true if the given string is equal to the string representation of
  // true value which we currently use
  static bool IsTrueValue(const wxString& value);

};

#endif
