// wxTextDropTarget.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTextDropTarget_h_)
#define _wxTextDropTarget_h_
class wxTextDropTarget : public wxDropTarget
{
public:
   wxTextDropTarget() ;
  virtual bool OnDrop(long  x , long  y , const void  *data , size_t  size ) ;
  virtual bool OnDropText(long  x , long  y , const char  *data ) ;
};


#endif
