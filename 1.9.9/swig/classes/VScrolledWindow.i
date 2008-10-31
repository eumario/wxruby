// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxVScrolledWindow
GC_MANAGE_AS_WINDOW(wxVScrolledWindow);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxVScrolledWindow);

// Actual class is implemented in C++ below
%rename(wxVScrolledWindow) wxRubyVScrolledWindow;

%{
#include <wx/vscroll.h>
%}

// This is a pure-abstract class in wxWidgets. Therefore
// Wx::ScrolledWindow in wxRuby actually wraps a bridging C++ class,
// which should delegate its calls to on_get_line_height etc using
// SWIG's directors
%{
  class wxRubyVScrolledWindow : public wxVScrolledWindow
  {
  public:
    wxRubyVScrolledWindow(wxWindow* parent, 
                          wxWindowID  id = wxID_ANY, 
                          const wxPoint&  pos = wxDefaultPosition,
                          const wxSize&  size = wxDefaultSize,
                          long style = 0, 
                          const wxString&  name = wxPanelNameStr) :
      wxVScrolledWindow(parent, id, pos, size, style, name)
      { }

    wxRubyVScrolledWindow() : wxVScrolledWindow() { }
    // wxRuby classes must override this method...
    virtual wxCoord OnGetLineHeight(size_t n) const 
      { 
        rb_raise(rb_eNoMethodError, 
                 "on_get_line_height method must be defined for VScrolledWindow");
        return 0; 
      }
    // And may override these:
    virtual wxCoord EstimateTotalHeight() const
      { return wxVScrolledWindow::EstimateTotalHeight(); }
    virtual void OnGetLinesHint(size_t lineMin, size_t lineMax) const
      { wxVScrolledWindow::OnGetLinesHint(lineMin, lineMax); }
  };
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxPanel.h"

class wxRubyVScrolledWindow : public wxVScrolledWindow
{
public:
  wxRubyVScrolledWindow(wxWindow* parent, 
                        wxWindowID  id = wxID_ANY, 
                        const wxPoint&  pos = wxDefaultPosition,
                        const wxSize&  size = wxDefaultSize, 
                        long style = 0, 
                        const wxString&  name = wxPanelNameStr);
  wxRubyVScrolledWindow();
  virtual ~wxRubyVScrolledWindow();
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
  virtual void OnGetLinesHint(size_t lineMin, size_t lineMax) const;
  void RefreshLine(size_t  line ) ;
  void RefreshLines(size_t  from , size_t  to ) ;
  void RefreshAll() ;
  bool ScrollLines(int  lines ) ;
  bool ScrollPages(int  pages ) ;
  bool ScrollToLine(size_t  line ) ;
  void SetLineCount(size_t  count ) ;
};
