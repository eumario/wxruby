// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxClipboard_h_)
#define _wxClipboard_h_
class wxClipboard : public wxObject
{
public:
   wxClipboard() ;
  virtual  ~wxClipboard();
  bool AddData(wxDataObject* data);
  void Clear();
  void Close();
  bool Flush();
  bool GetData(wxDataObject&  data);
  bool IsOpened() const;
  bool IsSupported(const wxDataFormat& format);
  bool Open();
  bool SetData(wxDataObject* data);
  void UsePrimarySelection(bool primary = true) ;
};


#endif
