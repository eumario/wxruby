// wxCommandProcessor.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCommandProcessor_h_)
#define _wxCommandProcessor_h_
class wxCommandProcessor : public wxObject
{
public:
   wxCommandProcessor(int maxCommands = -1) ;
  virtual  ~wxCommandProcessor() ;
  virtual bool CanUndo() ;
  virtual void ClearCommands() ;
  virtual bool Redo() ;
  wxList& GetCommands() const;
  int GetMaxCommands() const;
  wxMenu* GetEditMenu() const;
  const wxString& GetRedoAccelerator() const;
  wxString GetRedoMenuLabel() const;
  const wxString& GetUndoAccelerator() const;
  wxString GetUndoMenuLabel() const;
  virtual void Initialize() ;
  void SetEditMenu(wxMenu*  menu ) ;
  void SetMenuStrings() ;
  void SetRedoAccelerator(const wxString& accel ) ;
  void SetUndoAccelerator(const wxString& accel ) ;
  virtual bool Submit(wxCommand * command , bool storeIt = true) ;
  virtual bool Undo() ;
};


#endif
