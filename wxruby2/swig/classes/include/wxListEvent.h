// wxListEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxListEvent_h_)
#define _wxListEvent_h_
class wxListEvent : public wxNotifyEvent
{
public:
   wxListEvent(WXTYPE  commandType = 0, int  id = 0) ;
  long GetCacheFrom() const;
  long GetCacheTo() const;
  int GetKeyCode() const;
  long GetIndex() const;
  int GetColumn() const;
  wxPoint GetPoint() const;
  const wxString& GetLabel() const;
  const wxString& GetText() const;
  int GetImage() const;
  long GetData() const;
  long GetMask() const;
  const wxListItem& GetItem() const;
};


#endif
