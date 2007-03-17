// wxHtmlListBox.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlListBox_h_)
#define _wxHtmlListBox_h_
class wxHtmlListBox : public wxVListBox
{
public:
	/**
	 * \brief Normal constructor which calls  
internally. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param size_t   
	 * \param long   
	 * \param const wxString&   
	*/

   wxHtmlListBox(wxWindow*  parent , wxWindowID  id = wxID_ANY, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, size_t  countItems = 0, long  style = 0, const wxString&  name = wxVListBoxNameStr) ;
	/**
	 * \brief Default constructor, you must call  
later. 
	*/

   wxHtmlListBox() ;
	/**
	 * \brief Destructor cleans up whatever resources we use. 
	*/

  virtual  ~wxHtmlListBox() ;
	/**
	 * \brief Creates the control and optionally sets the initial number of items in it
(it may also be set or changed later with 
 ).

There are no special styles defined for wxHtmlListBox, in particular the
wxListBox styles can not be used here.

Returns   on success or   if the control couldn't be created 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long   
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id = wxID_ANY, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = 0, const wxString&  name = wxVListBoxNameStr) ;
	/**
	 * \brief This virtual function may be overridden to change the appearance of the
background of the selected cells in the same way as 
 .

It should be rarely, if ever, used because 
  allows to
change the selection background for all cells at once and doing anything more
fancy is probably going to look strangely. 
	 * \param const wxColour&   
	*/

  wxColour GetSelectedTextBgColour(const wxColour&  colBg ) const;
	/**
	 * \brief This virtual function may be overridden to customize the appearance of the
selected cells. It is used to determine how the colour   is going to
look inside selection. By default all original colours are completely ignored
and the standard, system-dependent, selection colour is used but the program
may wish to override this to achieve some custom appearance. 
	 * \param const wxColour&   
	*/

  wxColour GetSelectedTextColour(const wxColour&  colFg ) const;
	/**
	 * \brief This method must be implemented in the derived class and should return
the body (i.e. without   nor   tags) of the HTML fragment
for the given item. 
	 * \param size_t   
	*/

  virtual wxString OnGetItem(size_t  n ) const;
	/**
	 * \brief This function may be overridden to decorate HTML returned by
 . 
	 * \param size_t   
	*/

  virtual wxString OnGetItemMarkup(size_t  n ) const;
};


#endif
