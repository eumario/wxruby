// wxAcceleratorEntry.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

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
  void Set(int  flags , int  keyCode , int  cmd ) ;
};


#endif
