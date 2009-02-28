// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

// NB - this is copied, not referenced in classes/HelpProvider.i
#if !defined(_wxHelpProvider_h_)
#define _wxHelpProvider_h_
class wxHelpProvider
{
public:
  virtual ~wxHelpProvider();
  static wxHelpProvider* Set(wxHelpProvider* helpProvider);
  static wxHelpProvider* Get();
  virtual void AddHelp(wxWindowBase* window, const wxString&  text);
  virtual void AddHelp(wxWindowID id, const wxString& text);
  virtual wxString GetHelp(const wxWindowBase* window);
  virtual void RemoveHelp(wxWindowBase* window);
  virtual bool ShowHelp(wxWindowBase* window);
  virtual bool ShowHelpAtPoint(wxWindowBase* window, const wxPoint point, 
                               wxHelpEvent::Origin origin);
};

#endif
