// wxTextCtrl.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTextCtrl_h_)
#define _wxTextCtrl_h_
class wxTextCtrl : public wxControl
{
public:
   wxTextCtrl() ;
   wxTextCtrl(wxWindow*  parent , wxWindowID  id , const wxString&  value = "", const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxTextCtrlNameStr) ;
  virtual  ~wxTextCtrl() ;
  void AppendText(const wxString&   text ) ;
  virtual bool CanCopy() ;
  virtual bool CanCut() ;
  virtual bool CanPaste() ;
  virtual bool CanRedo() ;
  virtual bool CanUndo() ;
  virtual void Clear() ;
  virtual void Copy() ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  value = "", const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxTextCtrlNameStr) ;
  virtual void Cut() ;
  void DiscardEdits() ;
  bool EmulateKeyPress(const wxKeyEvent&  event ) ;
  const wxTextAttr&  GetDefaultStyle() const;
  virtual long GetInsertionPoint() const;
  virtual long GetLastPosition() const;
  int GetLineLength(long  lineNo ) const;
  wxString GetLineText(long  lineNo ) const;
  int GetNumberOfLines() const;
  virtual wxString GetRange(long  from , long  to ) const;
  virtual void GetSelection(long*  from , long*  to ) const;
  virtual wxString GetStringSelection() ;
  bool GetStyle(long  position , wxTextAttr&  style ) ;
  wxString GetValue() const;
  bool IsEditable() const;
  bool IsModified() const;
  bool IsMultiLine() const;
  bool IsSingleLine() const;
  bool LoadFile(const wxString&   filename ) ;
  virtual void OnDropFiles(wxDropFilesEvent&  event ) ;
  virtual void Paste() ;
  bool PositionToXY(long  pos , long * x , long * y ) const;
  virtual void Redo() ;
  virtual void Remove(long  from , long  to ) ;
  virtual void Replace(long  from , long  to , const wxString&  value ) ;
  bool SaveFile(const wxString&   filename ) ;
  bool SetDefaultStyle(const wxTextAttr&  style ) ;
  virtual void SetEditable(const bool  editable ) ;
  virtual void SetInsertionPoint(long  pos ) ;
  virtual void SetInsertionPointEnd() ;
  virtual void SetMaxLength(unsigned long  len ) ;
  virtual void SetSelection(long  from , long  to ) ;
  bool SetStyle(long  start , long  end , const wxTextAttr&  style ) ;
  virtual void SetValue(const wxString&   value ) ;
  void ShowPosition(long  pos ) ;
  virtual void Undo() ;
  void WriteText(const wxString&   text ) ;
  long XYToPosition(long  x , long  y ) ;
};


#endif
