// wxDataFormat.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDataFormat_h_)
#define _wxDataFormat_h_
class wxDataFormat
{
public:
   wxDataFormat(NativeFormat format = wxDF_INVALID) ;
   wxDataFormat(const wxChar  *format ) ;
  wxString GetId() const;
  NativeFormat GetType() const;
  void SetId(const wxChar  *format ) ;
  void SetType(NativeFormat  format ) ;
};


#endif
