// wxLogChain.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxLogChain_h_)
#define _wxLogChain_h_
class wxLogChain : public wxLog
{
public:
   wxLogChain(wxLog * logger ) ;
  virtual  ~wxLogChain() ;
  wxLog * GetOldLog() const;
  bool IsPassingMessages() const;
  void PassMessages(bool  passMessages ) ;
  void SetLog(wxLog * logger ) ;
};


#endif
