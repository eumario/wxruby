// wxFileDropTarget.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFileDropTarget_h_)
#define _wxFileDropTarget_h_
class wxFileDropTarget : public wxDropTarget
{
public:
   wxFileDropTarget() ;
  virtual bool OnDrop(long  x , long  y , const void  *data , size_t  size ) ;
  virtual bool OnDropFiles(wxCoord  x , wxCoord  y , const wxArrayString&  filenames ) ;
};


#endif
