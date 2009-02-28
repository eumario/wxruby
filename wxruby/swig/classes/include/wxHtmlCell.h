// wxHtmlCell.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlCell_h_)
#define _wxHtmlCell_h_
class wxHtmlCell : public wxObject
{
public:
	/**
	 * \brief Constructor. 
	*/

   wxHtmlCell() ;
  virtual bool AdjustPagebreak(int *  pagebreak,wxArrayInt& known_pagebreaks) const ;
  virtual void Draw(wxDC&  dc , int  x , int  y , int  view_y1 , int  view_y2, wxHtmlRenderingInfo info) ;
  virtual void DrawInvisible(wxDC&  dc , int  x , int  y, wxHtmlRenderingInfo info ) ;
  virtual const wxHtmlCell* Find(int  condition , const void*  param ) ;
  int GetDescent() const;
  int GetHeight() const;
  virtual wxString GetId() const;
  virtual wxHtmlLinkInfo* GetLink(int  x = 0, int  y = 0) const;
  wxHtmlCell* GetNext() const;
  wxHtmlContainerCell* GetParent() const;
  int GetPosX() const;
  int GetPosY() const;
  int GetWidth() const;
  virtual void Layout(int  w ) ;
  virtual void OnMouseClick(wxWindow*  parent , int x , int  y , const wxMouseEvent&  event ) ;
  void SetId(const wxString&  id ) ;
  void SetLink(const wxHtmlLinkInfo&  link ) ;
  void SetNext(wxHtmlCell  *cell ) ;
  void SetParent(wxHtmlContainerCell  *p ) ;
  void SetPos(int  x , int  y ) ;
};


#endif
