// wxContextHelp.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxContextHelp_h_)
#define _wxContextHelp_h_
class wxContextHelp : public wxObject
{
public:
   wxContextHelp(wxWindow* window = NULL, bool doNow = true) ;
  virtual  ~wxContextHelp() ;
  bool BeginContextHelp(wxWindow* window = NULL) ;
  bool EndContextHelp() ;
};


#endif
