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
	/**
	 * \brief This method is used to adjust pagebreak position. The parameter is
variable that contains y-coordinate of page break (= horizontal line that
should not be crossed by words, images etc.). If this cell cannot be divided
into two pieces (each one on another page) then it moves the pagebreak
few pixels up.

Returns true if pagebreak was modified, false otherwise

Usage: 
	 * \param int *   
	*/

  virtual bool AdjustPagebreak(int *  pagebreak ) ;
	/**
	 * \brief Renders the cell. 
	 * \param wxDC&   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param int   
	*/

  virtual void Draw(wxDC&  dc , int  x , int  y , int  view_y1 , int  view_y2 ) ;
	/**
	 * \brief This method is called instead of   when the
cell is certainly out of the screen (and thus invisible). This is not
nonsense - some tags (like  
or font setter) must be drawn even if they are invisible! 
	 * \param wxDC&   
	 * \param int   
	 * \param int   
	*/

  virtual void DrawInvisible(wxDC&  dc , int  x , int  y ) ;
	/**
	 * \brief Returns pointer to itself if this cell matches condition (or if any of the cells
following in the list matches), NULL otherwise.
(In other words if you call top-level container's Find it will
return pointer to the first cell that matches the condition)

It is recommended way how to obtain pointer to particular cell or
to cell of some type (e.g. wxHtmlAnchorCell reacts on
wxHTML_COND_ISANCHOR condition)







\wxheading{Defined conditions} 
	 * \param int   
	 * \param const void*   
	*/

  virtual const wxHtmlCell* Find(int  condition , const void*  param ) ;
	/**
	 * \brief Returns descent value of the cell (m_Descent member). 
\helponly{See explanation:

\image{}{descent.bmp}
} 
	*/

  int GetDescent() const;
	/**
	 * \brief Returns height of the cell (m_Height member). 
	*/

  int GetHeight() const;
	/**
	 * \brief Returns unique cell identifier if there is any, empty string otherwise. 
	*/

  virtual wxString GetId() const;
	/**
	 * \brief Returns hypertext link if associated with this cell or NULL otherwise.
See  .
(Note: this makes sense only for visible tags). 
	 * \param int   
	 * \param int   
	*/

  virtual wxHtmlLinkInfo* GetLink(int  x = 0, int  y = 0) const;
	/**
	 * \brief Returns pointer to the next cell in list (see htmlcell.h if you're
interested in details). 
	*/

  wxHtmlCell* GetNext() const;
	/**
	 * \brief Returns pointer to parent container. 
	*/

  wxHtmlContainerCell* GetParent() const;
	/**
	 * \brief Returns X position within parent (the value is relative to parent's
upper left corner). The returned value is meaningful only if
parent's   was called before! 
	*/

  int GetPosX() const;
	/**
	 * \brief Returns Y position within parent (the value is relative to parent's
upper left corner). The returned value is meaningful only if
parent's   was called before! 
	*/

  int GetPosY() const;
	/**
	 * \brief Returns width of the cell (m_Width member). 
	*/

  int GetWidth() const;
	/**
	 * \brief This method performs two actions:

\begin{enumerate}\itemsep=0pt
\item adjusts the cell's width according to the fact that maximal possible width is  .
(this has sense when working with horizontal lines, tables etc.)
\item prepares layout (=fill-in m_PosX, m_PosY (and sometimes m_Height) members)
based on actual width  
\end{enumerate}

It must be called before displaying cells structure because
m_PosX and m_PosY are undefined (or invalid)
before calling Layout. 
	 * \param int   
	*/

  virtual void Layout(int  w ) ;
	/**
	 * \brief This function is simple event handler. Each time the user clicks mouse button over a cell
within   this method of that cell is called. Default behavior is
that it calls  . 
	 * \param wxWindow*   
	 * \param int  
	 * \param int   
	 * \param const wxMouseEvent&   
	*/

  virtual void OnMouseClick(wxWindow*  parent , int x , int  y , const wxMouseEvent&  event ) ;
	/**
	 * \brief Sets unique cell identifier. Default value is no identifier, i.e. empty string. 
	 * \param const wxString&   
	*/

  void SetId(const wxString&  id ) ;
	/**
	 * \brief Sets the hypertext link associated with this cell. (Default value
is  (&quot;&quot;, &quot;&quot;) (no link)) 
	 * \param const wxHtmlLinkInfo&   
	*/

  void SetLink(const wxHtmlLinkInfo&  link ) ;
	/**
	 * \brief Sets the next cell in the list. This shouldn't be called by user - it is
to be used only by  . 
	 * \param wxHtmlCell   
	*/

  void SetNext(wxHtmlCell  *cell ) ;
	/**
	 * \brief Sets parent container of this cell. This is called from
 . 
	 * \param wxHtmlContainerCell   
	*/

  void SetParent(wxHtmlContainerCell  *p ) ;
	/**
	 * \brief Sets the cell's position within parent container. 
	 * \param int   
	 * \param int   
	*/

  void SetPos(int  x , int  y ) ;
};


#endif
