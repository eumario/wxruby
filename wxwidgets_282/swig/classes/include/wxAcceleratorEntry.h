// Copyright 2004-2006 by Kevin Smith
// released under the MIT-style wxruby2 license

#if !defined(_wxAcceleratorEntry_h_)
#define _wxAcceleratorEntry_h_
class wxAcceleratorEntry
{
public:
   wxAcceleratorEntry() ;
   wxAcceleratorEntry(int  flags , int  keyCode , int  cmd ) ;
  int GetCommand() const;
  int GetFlags() const;
  int GetKeyCode() const;
  wxMenuItem *GetMenuItem() const;
  void Set(int  flags , int  keyCode , int  cmd ) ;
  void SetMenuItem(wxMenuItem *item);

};


#endif
