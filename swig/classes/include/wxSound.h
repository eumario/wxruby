// Copyright 2006 - 2007 by Kevin Smith
// released under the MIT-style wxruby2 license

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
  bool Create(int size, const wxByte* data);
  bool IsOk();
#if !defined(__WXMSW__)
  static bool IsPlaying();
#endif
  bool Play(unsigned flags = wxSOUND_ASYNC) const;
  static bool Play(const wxString& filename, unsigned flags = wxSOUND_ASYNC);
  static void Stop();
};

#endif
