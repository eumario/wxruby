// wxFindReplaceDialog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFindReplaceDialog_h_)
#define _wxFindReplaceDialog_h_
class wxFindReplaceDialog : public wxDialog
{
public:
	/**
	 * \brief  
	*/

   wxFindReplaceDialog() ;
	/**
	 * \brief After using default constructor   
must be called.

The   and   parameters must be non- . 
	 * \param wxWindow *   
	 * \param wxFindReplaceData*   
	 * \param const wxString&   
	 * \param int   
	*/

   wxFindReplaceDialog(wxWindow *  parent , wxFindReplaceData*  data , const wxString&  title , int  style = 0) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxFindReplaceDialog() ;
	/**
	 * \brief Creates the dialog; use   to show it on screen.

The   and   parameters must be non- . 
	 * \param wxWindow *   
	 * \param wxFindReplaceData*   
	 * \param const wxString&   
	 * \param int   
	*/

  bool Create(wxWindow *  parent , wxFindReplaceData*  data , const wxString&  title , int  style = 0) ;
	/**
	 * \brief Get the   object used by this
dialog. 
	*/

  const wxFindReplaceData* GetData() const;

#if defined(__WXMSW__)
    virtual bool Show(bool show = true);
    virtual void SetTitle( const wxString& title);
    virtual wxString GetTitle() const;
#endif
};


#endif
