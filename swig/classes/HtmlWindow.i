// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxHtmlWindow
GC_MANAGE_AS_WINDOW(wxHtmlWindow);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxHtmlWindow);

// This class has to be implemented internally with a hand-written C++
// class, in order that the virtual OnOpeningURL method can work
// properly. Unfortunately there's no way to make this work using SWIG
// typemaps.
%rename(HtmlWindow) wxRubyHtmlWindow;

%{
#include <wx/html/htmlwin.h>
%}

// wxHtmlWindow flags:
#define wxHW_SCROLLBAR_NEVER    0x0002
#define wxHW_SCROLLBAR_AUTO     0x0004
#define wxHW_NO_SELECTION       0x0008
#define wxHW_DEFAULT_STYLE      wxHW_SCROLLBAR_AUTO


// implement in ruby
%ignore wxHtmlWindow::LoadFile;

// dealt with below
%ignore wxHtmlWindow::OnOpeningURL;

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxPanel.h"
%import "include/wxScrolledWindow.h"
// %import "include/wxHtmlWindow.h"

// Deal with sizes argument to SetFonts
%typemap(in) const int* sizes {
  if ( TYPE($input) != T_ARRAY || RARRAY_LEN($input) != 7 )
    rb_raise(rb_eTypeError, 
             "The 'font sizes' argument must be an array with 7 integers");
  $1 = new int[7];
  for ( size_t i = 0; i < 7; i++ )
    ($1)[i] = NUM2INT(rb_ary_entry($input, i));
}

%typemap(freearg) const int* sizes "if ($1) delete($1);"

%ignore wxHtmlWindow;

%{
  class wxRubyHtmlWindow : public wxHtmlWindow
  {
  public:
    wxRubyHtmlWindow(wxWindow *parent, 
                     wxWindowID  id = -1, 
                     const wxPoint&  pos = wxDefaultPosition, 
                     const wxSize&  size = wxDefaultSize, 
                     long style = wxHW_SCROLLBAR_AUTO, 
                     const wxString&  name = wxT("htmlWindow")) :      
      wxHtmlWindow(parent, id, pos, size, style, name)
    {  }
    // This is the actual method called from C++ when a URL is clicked
    // etc. The Ruby interface accepts a single argument, the URL, and
    // can return True = allow, False = block or a String = redirect.
    // The standard version in the base class (in
    // lib/wx/classes/htmlwin.rb) always allows
    virtual wxHtmlOpeningStatus OnOpeningURL(wxHtmlURLType type, 
                                             const wxString&  url, 
                                             wxString* redirect) const
    {
      VALUE self   = SWIG_RubyInstanceFor((void *)this);
      VALUE rb_url = WXSTR_TO_RSTR(url);
      VALUE ret = rb_funcall(self, rb_intern("on_opening_url"), 1, rb_url);
      if ( ret == Qtrue )
        return wxHTML_OPEN;
      else if ( ret == Qfalse || ret == Qnil )
        return wxHTML_BLOCK;
      else if ( TYPE(ret) == T_STRING ) 
        {
          // FIXME - this leaks memory

          wxString* temp = new wxString( StringValuePtr(ret), wxConvUTF8 );
          *redirect = *temp;
          return wxHTML_REDIRECT;
        }
      else 
        {
          rb_raise(rb_eTypeError, 
                   "Wrong return value for on_opening_url, should be true, false, or String redirect");
        }
    }
  };
%}

class wxRubyHtmlWindow : public wxHtmlWindow
{
public:
  wxRubyHtmlWindow(wxWindow *parent, 
                   wxWindowID  id = -1, 
                   const wxPoint&  pos = wxDefaultPosition, 
                   const wxSize&  size = wxDefaultSize, 
                   long style = wxHW_SCROLLBAR_AUTO, 
                   const wxString&  name = wxT("htmlWindow"));
  static void AddFilter(wxHtmlFilter  *filter ) ;
  bool AppendToPage(const wxString&  source ) ;
  wxHtmlContainerCell* GetInternalRepresentation() const;
  wxString GetOpenedAnchor() ;
  wxString GetOpenedPage() ;
  wxString GetOpenedPageTitle() ;
  wxFrame* GetRelatedFrame() const;
  bool HistoryBack() ;
  bool HistoryCanBack() ;
  bool HistoryCanForward() ;
  void HistoryClear() ;
  bool HistoryForward() ;
  virtual bool LoadFile(const wxFileName&  filename ) ;
  virtual bool LoadPage(const wxString&  location ) ;
  wxHtmlOpeningStatus OnOpeningURL(wxHtmlURLType  type , const wxString&  url , wxString * redirect ) const;
  virtual void OnSetTitle(const wxString&  title ) ;
  virtual void ReadCustomization(wxConfigBase  *cfg , wxString  path = wxEmptyString) ;
  void SelectAll();
  wxString SelectionToText();
  void SelectLine(const wxPoint& pos);
  void SelectWord(const wxPoint& pos);
  void SetBorders(int  b ) ;
  void SetFonts(wxString& normal_face, wxString& fixed_face, const int *sizes = NULL) ;
  bool SetPage(const wxString&  source ) ;
  void SetRelatedFrame(wxFrame*  frame , const wxString&  format ) ;
  void SetRelatedStatusBar(int  bar ) ;
  virtual void WriteCustomization(wxConfigBase  *cfg , wxString  path = wxEmptyString) ;

};
