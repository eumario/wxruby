// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxMenuEvent_h_)
#define _wxMenuEvent_h_
class wxMenuEvent : public wxEvent
{
public:
   wxMenuEvent(int id = 0, int menu_id = 0, wxMenu* menu = NULL);
   wxMenu* GetMenu() const;
   int GetMenuId() const;
   bool IsPopup() const;
};


#endif
