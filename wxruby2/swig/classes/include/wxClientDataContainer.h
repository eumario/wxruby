// wxClientDataContainer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxClientDataContainer_h_)
#define _wxClientDataContainer_h_
class wxClientDataContainer
{
public:
   wxClientDataContainer() ;
  virtual  ~wxClientDataContainer() ;
  void* GetClientData() const;
  wxClientData* GetClientObject() const;
  void SetClientData(void*  data ) ;
  void SetClientObject(wxClientData*  data ) ;
};


#endif
