// wxFSFile.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFSFile_h_)
#define _wxFSFile_h_
class wxFSFile : public wxObject
{
public:
   wxFSFile(wxInputStream  *stream , const wxString&  loc , const wxString&  mimetype , const wxString&  anchor ) ;
  const wxString& GetAnchor() const;
  const wxString& GetLocation() const;
  const wxString& GetMimeType() const;
  wxDateTime GetModificationTime() const;
  wxInputStream* GetStream() const;
};


#endif
