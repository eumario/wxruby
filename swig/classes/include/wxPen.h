// wxPen.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPen_h_)
#define _wxPen_h_
class wxPen : public wxGDIObject
{
public:
	/**
	 * \brief Default constructor. The pen will be uninitialised, and   will
return false. 
	*/

   wxPen() ;
	/**
	 * \brief Constructs a pen from a colour object, pen width and style. 
	 * \param const wxColour&  
	 * \param int  
	 * \param int  
	*/

   wxPen(const wxColour&  colour , int  width , int  style ) ;
	/**
	 * \brief Constructs a pen from a colour name, pen width and style. 
	 * \param const wxString&   
	 * \param int  
	 * \param int  
	*/

   wxPen(const wxString&  colourName , int  width , int  style ) ;
	/**
	 * \brief Constructs a stippled pen from a stipple bitmap and a width. 
	 * \param const wxBitmap&  
	 * \param int  
	*/

   wxPen(const wxBitmap&  stipple , int  width ) ;
	/**
	 * \brief  
	 * \param const wxPen&  
	*/

   wxPen(const wxPen&  pen ) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxPen() ;
	/**
	 * \brief Returns the pen cap style, which may be one of  ,   and
 . The default is  . 
	*/

  int GetCap() const;
	/**
	 * \brief Returns a reference to the pen colour. 
	*/

  wxColour& GetColour() const;
	/**
	 * \brief Gets an array of dashes (defined as char in X, DWORD under Windows).
  is a pointer to the internal array. Do not deallocate or store this pointer.
The function returns the number of dashes associated with this pen. 
	 * \param wxDash**  
	*/

  int GetDashes(wxDash**  dashes ) const;
	/**
	 * \brief Returns the pen join style, which may be one of  ,   and
 . The default is  . 
	*/

  int GetJoin() const;
	/**
	 * \brief Gets a pointer to the stipple bitmap. 
	*/

  wxBitmap*  GetStipple() const;
	/**
	 * \brief  
	*/

  int GetStyle() const;
	/**
	 * \brief Returns the pen width. 
	*/

  int GetWidth() const;
	/**
	 * \brief Returns true if the pen is initialised. 
	*/

  bool Ok() const;
	/**
	 * \brief Sets the pen cap style, which may be one of  ,   and
 . The default is  . 
	 * \param int  
	*/

  void SetCap(int  capStyle ) ;
	/**
	 * \brief  
	 * \param wxColour&  
	*/

  void SetColour(wxColour&  colour ) ;
	/**
	 * \brief  
	 * \param const wxString&   
	*/

  void SetColour(const wxString&  colourName ) ;
	/**
	 * \brief The pen's colour is changed to the given colour. 
	 * \param int  
	 * \param int  
	 * \param int  
	*/

  void SetColour(int  red , int  green , int  blue ) ;
	/**
	 * \brief Associates an array of pointers to dashes (defined as char in X, DWORD under Windows)
with the pen. The array is not deallocated by wxPen, but neither must it be
deallocated by the calling application until the pen is deleted or this
function is called with a NULL array. 
	 * \param int   
	 * \param wxDash*  
	*/

  void SetDashes(int  n , wxDash*  dashes ) ;
	/**
	 * \brief Sets the pen join style, which may be one of  ,   and
 . The default is  . 
	 * \param int  
	*/

  void SetJoin(int join_style ) ;
	/**
	 * \brief Sets the bitmap for stippling. 
	 * \param wxBitmap*   
	*/

  void SetStipple(wxBitmap*  stipple ) ;
	/**
	 * \brief Set the pen style. 
	 * \param int  
	*/

  void SetStyle(int  style ) ;
	/**
	 * \brief Sets the pen width. 
	 * \param int  
	*/

  void SetWidth(int  width ) ;
};


#endif
