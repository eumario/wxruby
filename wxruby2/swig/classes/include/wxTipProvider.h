// wxTipProvider.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTipProvider_h_)
#define _wxTipProvider_h_
class wxTipProvider
{
public:
   wxTipProvider(size_t  currentTip ) ;
  virtual wxString GetTip()=0;
  virtual wxString PreprocessTip(const wxString& tip ) ;
  size_t GetCurrentTip() const;
};


#endif
