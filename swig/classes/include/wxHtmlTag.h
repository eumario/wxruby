// wxHtmlTag.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlTag_h_)
#define _wxHtmlTag_h_
class wxHtmlTag : public wxObject
{
public:
   wxHtmlTag(const wxString&  source , int  pos , int  end_pos , wxHtmlTagsCache*  cache ) ;
  const wxString& GetAllParams() const;
  int GetBeginPos() const;
  int GetEndPos1() const;
  int GetEndPos2() const;
  wxString GetName() const;
  wxString GetParam(const wxString&  par , bool  with_commas = false) const;
  bool GetParamAsColour(const wxString&  par , wxColour * clr ) const;
  bool GetParamAsInt(const wxString&  par , int * value ) const;
  bool HasEnding() const;
  bool HasParam(const wxString&  par ) const;
  bool IsEnding() const;
  wxString ScanParam(const wxString&  par , const wxChar * format , void * value ) const;
};


#endif
