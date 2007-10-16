// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxTipProvider_h_)
#define _wxTipProvider_h_
class wxTipProvider
{
public:
   wxTipProvider(size_t  currentTip ) ;
	virtual ~wxTipProvider();
  virtual wxString GetTip() = 0;
  virtual wxString PreprocessTip(const wxString& tip ) ;
  size_t GetCurrentTip() const;
};


#endif
