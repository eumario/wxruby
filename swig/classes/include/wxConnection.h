// wxConnection.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxConnection_h_)
#define _wxConnection_h_
class wxConnection : public wxObject
{
public:
   wxConnection() ;
   wxConnection(char*  buffer , int  size ) ;
  bool Advise(const wxString&  item , char*  data , int size = -1, wxIPCFormat format = wxCF_TEXT) ;
  bool Execute(char*  data , int size = -1, wxIPCFormat format = wxCF_TEXT) ;
  bool Disconnect() ;
  virtual bool OnAdvise(const wxString&  topic , const wxString&  item , char*  data , int  size , wxIPCFormat  format ) ;
  virtual bool OnDisconnect() ;
  virtual bool OnExecute(const wxString&  topic , char*  data , int  size , wxIPCFormat  format ) ;
  virtual bool OnPoke(const wxString&  topic , const wxString&  item , char*  data , int  size , wxIPCFormat  format ) ;
  virtual char* OnRequest(const wxString&  topic , const wxString&  item , int * size , wxIPCFormat  format ) ;
  virtual bool OnStartAdvise(const wxString&  topic , const wxString&  item ) ;
  virtual bool OnStopAdvise(const wxString&  topic , const wxString&  item ) ;
  bool Poke(const wxString&  item , char*  data , int size = -1, wxIPCFormat format = wxCF_TEXT) ;
  char* Request(const wxString&  item , int * size , wxIPCFormat format = wxIPC_TEXT) ;
  bool StartAdvise(const wxString&  item ) ;
  bool StopAdvise(const wxString&  item ) ;
};


#endif
