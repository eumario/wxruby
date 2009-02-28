// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license


#if !defined(_wxDateEvent_h_)
#define _wxDateEvent_h_
class wxDateEvent : public wxCommandEvent
{
public:
  const wxDateTime& GetDate() const;
  void SetDate(const wxDateTime& date);
};


#endif
