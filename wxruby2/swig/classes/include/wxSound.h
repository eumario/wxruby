// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxSound_h_)
#define _wxSound_h_

class wxSound : public wxObject
{
 public:
  wxSound();
  wxSound(const wxString& fileName, bool isResource = false);
  wxSound(int size, const wxByte* data);
  virtual ~wxSound();
  bool Create(const wxString& fileName, bool isResource = false);
//As of wxWidgets 2.8.5 this is not a method for wxMac it is also not 
//listed in the documentation.
#if !defined(__WXMAC__)
  bool Create(int size, const wxByte* data);
#endif
  bool IsOk();
#if !defined(__WXMSW__)
  static bool IsPlaying();
#endif
  bool Play(unsigned flags = wxSOUND_ASYNC) const;
  static bool Play(const wxString& filename, unsigned flags = wxSOUND_ASYNC);
  static void Stop();
};

#endif
