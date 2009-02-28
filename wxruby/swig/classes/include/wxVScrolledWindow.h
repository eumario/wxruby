// wxVScrolledWindow.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxVScrolledWindow_h_)
#define _wxVScrolledWindow_h_
class wxVScrolledWindow : public wxPanel
{
public:
  wxVScrolledWindow(wxWindow* parent, 
                    wxWindowID  id = wxID_ANY, 
                    const wxPoint&  pos = wxDefaultPosition, 
                    const wxSize&  size = wxDefaultSize, 
                    long style = 0, 
                    const wxString&  name = wxPanelNameStr);
  wxVScrolledWindow();
  bool Create(wxWindow* parent, 
              wxWindowID id = wxID_ANY, 
              const wxPoint&  pos = wxDefaultPosition, 
              const wxSize&  size = wxDefaultSize, 
              long  style = 0, 
              const wxString& name = wxPanelNameStr);
  virtual wxCoord EstimateTotalHeight() const;
  size_t GetFirstVisibleLine() const;
  size_t GetLastVisibleLine() const;
  size_t GetLineCount() const;
  int HitTest(wxCoord  x , wxCoord  y ) const;
  int HitTest(const wxPoint&  pt ) const;
  bool IsVisible(size_t  line ) const;
  virtual wxCoord OnGetLineHeight(size_t  n ) const;
  virtual void OnGetLinesHint(size_t  lineMin , size_t  lineMax ) const;
  void RefreshLine(size_t  line ) ;
  void RefreshLines(size_t  from , size_t  to ) ;
  void RefreshAll() ;
  bool ScrollLines(int  lines ) ;
  bool ScrollPages(int  pages ) ;
  bool ScrollToLine(size_t  line ) ;
  void SetLineCount(size_t  count ) ;
};


#endif
