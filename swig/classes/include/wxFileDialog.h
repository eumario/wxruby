// wxFileDialog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFileDialog_h_)
#define _wxFileDialog_h_
class wxFileDialog : public wxDialog
{
public:
   wxFileDialog(wxWindow*  parent , const wxString&  message = "Choose", const wxString&  defaultDir = "", const wxString&  defaultFile = "", const wxString&  wildcard = "*.*", long  style = 0, const wxPoint&  pos = wxDefaultPosition) ;
  virtual  ~wxFileDialog() ;
  wxString GetDirectory() const;
  wxString GetFilename() const;
  void GetFilenames(wxArrayString&  filenames ) const;
  int GetFilterIndex() const;
  wxString GetMessage() const;
  wxString GetPath() const;
  void GetPaths(wxArrayString&  paths ) const;
  long GetStyle() const;
  wxString GetWildcard() const;
  void SetDirectory(const wxString&  directory ) ;
  void SetFilename(const wxString&  setfilename ) ;
  void SetFilterIndex(int  filterIndex ) ;
  void SetMessage(const wxString&  message ) ;
  void SetPath(const wxString&  path ) ;
  void SetStyle(long  style ) ;
  void SetWildcard(const wxString&  wildCard ) ;
  int ShowModal() ;
};


#endif
