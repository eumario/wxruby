// wxTextDataObject.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTextDataObject_h_)
#define _wxTextDataObject_h_
class wxTextDataObject : public wxDataObjectSimple
{
public:
   wxTextDataObject(const wxString&  text = wxEmptyString) ;
  virtual size_t GetTextLength() const;
  virtual wxString GetText() const;
  virtual void SetText(const wxString&  strText ) ;
};


#endif
