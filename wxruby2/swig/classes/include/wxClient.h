// wxClient.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxClient_h_)
#define _wxClient_h_
class wxClient : public wxObject
{
public:
   wxClient() ;
  wxConnectionBase * MakeConnection(const wxString&  host , const wxString&  service , const wxString&  topic ) ;
  virtual wxConnectionBase * OnMakeConnection() ;
  bool ValidHost(const wxString&  host ) ;
};


#endif
