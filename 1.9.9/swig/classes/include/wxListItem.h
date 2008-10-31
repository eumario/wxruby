// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxListItem_h_)
#define _wxListItem_h_
class wxListItem : public wxObject
{
public:
  wxListItem();
  void Clear();
  wxListColumnFormat GetAlign() const;
  wxColour GetBackgroundColour() const;
  int GetColumn() const;
  long GetData() const;
  wxFont GetFont() const;
  long GetId() const;
  int GetImage() const;
  long GetMask() const;
  long GetState() const;
  const wxString& GetText() const;
  wxColour GetTextColour() const;
  int GetWidth() const;
  void SetAlign(wxListColumnFormat  align);
  void SetBackgroundColour(const wxColour&  colBack);
  void SetColumn(int  col);
  void SetData(long data);
  void SetData(void*  data);
  void SetFont(const wxFont&  font);
  void SetId(long  id);
  void SetImage(int  image);
  void SetMask(long  mask);
  void SetState(long  state);
  void SetStateMask(long  stateMask);
  void SetText(const wxString&  text);
  void SetTextColour(const wxColour&  colText);
  void SetWidth(int  width);
};


#endif
