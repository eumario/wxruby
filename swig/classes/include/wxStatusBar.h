// wxStatusBar.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxStatusBar_h_)
#define _wxStatusBar_h_
class wxStatusBar : public wxWindow
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxStatusBar() ;
	/**
	 * \brief Constructor, creating the window. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param long  
	 * \param const wxString&   
	*/

   wxStatusBar(wxWindow*  parent , wxWindowID  id , long style = wxST_SIZEGRIP, const wxString&  name = wxT("statusBar")) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxStatusBar() ;
	/**
	 * \brief Creates the window, for two-step construction.

See   for details. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param long  
	 * \param const wxString&   
	*/


  bool Create(wxWindow *parent, wxWindowID id, long style, const wxString& name = wxPanelNameStr);

 # bool Create(wxWindow*  parent , wxWindowID  id , long style = wxST_SIZEGRIP, const wxString&  name = wxT("statusBar")) ;
	/**
	 * \brief  
	 * \param int  
	 * \param wxRect&  
	*/

  virtual bool GetFieldRect(int  i , wxRect&  rect ) const;
	/**
	 * \brief Returns the number of fields in the status bar. 
	*/

  int GetFieldsCount() const;
	/**
	 * \brief Returns the string associated with a status bar field. 
	 * \param int  
	*/

  virtual wxString GetStatusText(int ir = 0) const;
	/**
	 * \brief Sets the field text to the top of the stack, and pops the stack of saved
strings. 
	 * \param int  
	*/

  void PopStatusText(int field = 0) ;
	/**
	 * \brief Saves the current field text in a per field stack, and sets the field text
to the string passed as argument. 
	 * \param const wxString&  
	 * \param int  
	*/

  void PushStatusText(const wxString&  string , int field = 0) ;
	/**
	 * \brief Sets the number of fields, and optionally the field widths.

\pythonnote{Only the first parameter is accepted.  Use SetStatusWidths
to set the widths of the fields.}

\perlnote{In wxPerl this function accepts only the   parameter.
Use SetStatusWidths to set the field widths.} 
	 * \param int  
	 * \param int*   
	*/

  virtual void SetFieldsCount(int number = 1, int*  widths = NULL) ;
	/**
	 * \brief Sets the minimal possible hight for the status bar. The real height may be
bigger than the height specified here depending on the size of the font used by
the status bar. 
	 * \param int  
	*/

  void SetMinHeight(int  height ) ;
	/**
	 * \brief  
	 * \param const wxString&   
	 * \param int  
	*/

  virtual void SetStatusText(const wxString&  text , int i = 0) ;
	/**
	 * \brief  
	 * \param int  
	 * \param int *  
	*/

  virtual void SetStatusWidths(int  n , int * widths ) ;
};


#endif
