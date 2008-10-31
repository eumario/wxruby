// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

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
