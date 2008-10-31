// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxStaticBoxSizer_h_)
#define _wxStaticBoxSizer_h_
class wxStaticBoxSizer : public wxBoxSizer
{
public:
  wxStaticBoxSizer(wxStaticBox* box, int orient);
  wxStaticBoxSizer(int orient, wxWindow *win, const wxString& label = wxEmptyString);

  virtual void RecalcSizes();
  virtual wxSize CalcMin();
  wxStaticBox* GetStaticBox() const;
  virtual void ShowItems(bool show);

};


#endif
