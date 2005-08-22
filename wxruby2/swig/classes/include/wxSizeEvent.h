//   Copyright 2004-2005 by Kevin Smith
//   released under the MIT-style wxruby2 license

#if !defined(_wxSizeEvent_h_)
#define _wxSizeEvent_h_
class wxSizeEvent : public wxEvent
{
public:
   wxSizeEvent(const wxSize&  sz , int  id = 0) ;
  wxSize GetSize() const;

  // override pure virtual methods from base classes
  virtual wxEvent* Clone() const;
};


#endif
