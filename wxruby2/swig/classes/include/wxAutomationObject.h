// wxAutomationObject.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxAutomationObject_h_)
#define _wxAutomationObject_h_
class wxAutomationObject : public wxObject
{
public:
   wxAutomationObject(WXIDISPATCH* dispatchPtr = NULL) ;
  virtual  ~wxAutomationObject() ;
  wxVariant CallMethod(const wxString&  method , int  noArgs , wxVariant  args[] ) const;
  wxVariant CallMethod(const wxString&  method , ...  ) const;
  bool CreateInstance(const wxString&  classId ) const;
  IDispatch* GetDispatchPtr() const;
  bool GetInstance(const wxString&  classId ) const;
  bool GetObject(wxAutomationObject& obj , const wxString&  property , int noArgs = 0, wxVariant  args[] = NULL) const;
  wxVariant GetProperty(const wxString&  property , int  noArgs , wxVariant  args[] ) const;
  wxVariant GetProperty(const wxString&  property , ...  ) const;
  bool Invoke(const wxString&  member , int  action , wxVariant&  retValue , int  noArgs , wxVariant  args[] , const wxVariant* ptrArgs[] = 0) const;
  bool PutProperty(const wxString&  property , int  noArgs , wxVariant  args[] ) const;
  bool PutProperty(const wxString&  property , ...  ) ;
  void SetDispatchPtr(WXIDISPATCH*  dispatchPtr ) ;
};


#endif
