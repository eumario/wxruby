// wxFileDataObject.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFileDataObject_h_)
#define _wxFileDataObject_h_
class wxFileDataObject : public wxDataObjectSimple
{
public:
  virtual void AddFile(const wxString&  file ) ;
  const wxArrayString&  GetFilenames() const;
};


#endif
