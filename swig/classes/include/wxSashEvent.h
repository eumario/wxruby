// wxSashEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSashEvent_h_)
#define _wxSashEvent_h_
class wxSashEvent : public wxCommandEvent
{
public:
   wxSashEvent(int  id = 0, wxSashEdgePosition edge = wxSASH_NONE) ;
  wxSashEdgePosition GetEdge() const;
  wxRect GetDragRect() const;
  wxSashDragStatus GetDragStatus() const;
};


#endif
