// wxCommand.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCommand_h_)
#define _wxCommand_h_
class wxCommand : public wxObject
{
public:
   wxCommand(bool canUndo = false, const wxString&  name = NULL) ;
  virtual  ~wxCommand() ;
  bool CanUndo() ;
  bool Do() ;
  wxString GetName() ;
  bool Undo() ;
};


#endif
