// wxStringTokenizer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxStringTokenizer_h_)
#define _wxStringTokenizer_h_
class wxStringTokenizer : public wxObject
{
public:
   wxStringTokenizer() ;
   wxStringTokenizer(const wxString&  str , const wxString&  delims = "", wxStringTokenizerMode  mode = wxTOKEN_DEFAULT) ;
  int CountTokens() const;
  bool HasMoreTokens() const;
  wxString GetNextToken() ;
  size_t GetPosition() const;
  wxString GetString() const;
  void SetString(const wxString&  to_tokenize , const wxString&  delims = "", wxStringTokenizerMode  mode = wxTOKEN_DEFAULT) ;
};


#endif
