// wxTextFile.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTextFile_h_)
#define _wxTextFile_h_
class wxTextFile
{
public:
   wxTextFile() const;
   wxTextFile(const wxString&  strFile ) const;
  virtual  ~wxTextFile() const;
  void AddLine(const wxString&  str , wxTextFileType  type = typeDefault) const;
  bool Close() const;
  bool Create() const;
  bool Create(const wxString&  strFile ) const;
  bool Exists() const;
  bool IsOpened() const;
  size_t GetLineCount() const;
  wxString& GetLine(size_t  n ) const;
  size_t GetCurrentLine() const;
  void GoToLine(size_t  n ) const;
  bool Eof() const;
  static const char* GetEOL(wxTextFileType  type = typeDefault) const;
  wxString& GetFirstLine() const;
  wxString& GetNextLine() ;
  wxString& GetPrevLine() ;
  wxString& GetLastLine() ;
  wxTextFileType GetLineType(size_t  n ) const;
  wxTextFileType GuessType() const;
  const char* GetName() const;
  void InsertLine(const wxString&  str , size_t  n , wxTextFileType  type = typeDefault) const;
  bool Open(wxMBConv& conv = wxConvUTF8) const;
  bool Open(const wxString&  strFile , wxMBConv& conv = wxConvUTF8) const;
  void RemoveLine(size_t  n ) const;
  void Clear() const;
  bool Write(wxTextFileType  typeNew = wxTextFileType_None, wxMBConv& conv = wxConvUTF8) const;
};


#endif
