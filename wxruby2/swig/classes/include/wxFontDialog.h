// wxFontDialog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFontDialog_h_)
#define _wxFontDialog_h_
class wxFontDialog : public wxDialog
{
public:
	/**
	 * \brief  
	*/

   wxFontDialog() ;
	/**
	 * \brief  
	 * \param wxWindow*   
	*/

   wxFontDialog(wxWindow*  parent ) ;
	/**
	 * \brief Constructor. Pass a parent window, and optionally the 
  object to be used to initialize the dialog
controls. If the default constructor is used, 
  must be called before the dialog can be
shown. 
	 * \param wxWindow*   
	 * \param const wxFontData&   
	*/

   wxFontDialog(wxWindow*  parent , const wxFontData&  data ) ;
	/**
	 * \brief  
	*/

  bool Create() ;
	/**
	 * \brief  
	 * \param wxWindow*   
	*/

  bool Create(wxWindow*  parent ) ;
	/**
	 * \brief Creates the dialog if it the wxFontDialog object had been initialized using the
default constructor. Returns   on success and   if an error
occured. 
	 * \param wxWindow*   
	 * \param const wxFontData&   
	*/

  bool Create(wxWindow*  parent , const wxFontData&  data ) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxFontDialog() ;
	/**
	 * \brief  
	*/

  const wxFontData& GetFontData() const;
	/**
	 * \brief Returns the   associated with the font dialog. 
	*/

  wxFontData& GetFontData() ;
	/**
	 * \brief Shows the dialog, returning   if the user pressed Ok, and 
  otherwise.

If the user cancels the dialog (ShowModal returns  ), no font
will be created. If the user presses OK, a new wxFont will be created and
stored in the font dialog's wxFontData structure. 
	*/

  int ShowModal() ;
};


#endif
