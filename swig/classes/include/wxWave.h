// wxWave.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxWave_h_)
#define _wxWave_h_
class wxWave : public wxObject
{
public:
   wxWave() ;
   wxWave(const wxString&  fileName , bool isResource = false) ;
  virtual  ~wxWave() ;
  bool Create(const wxString&  fileName , bool isResource = false) ;
  bool IsOk() const;
  bool Play(bool async = true, bool looped = false) const;
};


#endif
