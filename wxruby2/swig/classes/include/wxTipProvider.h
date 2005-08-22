//   Copyright 2004-2005 by Kevin Smith
//   released under the MIT-style wxruby2 license

#if !defined(_wxTipProvider_h_)
#define _wxTipProvider_h_
class wxTipProvider
{
public:
   wxTipProvider(size_t  currentTip ) ;
  virtual wxString GetTip() = 0;
  virtual wxString PreprocessTip(const wxString& tip ) ;
  size_t GetCurrentTip() const;
};


#endif
