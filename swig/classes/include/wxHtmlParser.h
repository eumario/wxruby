// wxHtmlParser.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlParser_h_)
#define _wxHtmlParser_h_
class wxHtmlParser : public wxObject
{
public:
   wxHtmlParser() ;
  void AddTag(const wxHtmlTag&  tag ) ;
  virtual void AddTagHandler(wxHtmlTagHandler  *handler ) ;
  virtual void AddText(const char*  txt ) ;
  void DoParsing(int  begin_pos , int  end_pos ) ;
  void DoParsing() ;
  virtual void DoneParser() ;
  wxFileSystem* GetFS() const;
  virtual wxObject* GetProduct() ;
  wxString* GetSource() ;
  virtual void InitParser(const wxString&  source ) ;
  virtual wxFSFile* OpenURL(wxHtmlURLType  type , const wxString&  url ) ;
  wxObject* Parse(const wxString&  source ) ;
  void PushTagHandler(wxHtmlTagHandler*  handler , wxString  tags ) ;
  void PopTagHandler() ;
  void SetFS(wxFileSystem  *fs ) ;
  void StopParsing() ;
};


#endif
