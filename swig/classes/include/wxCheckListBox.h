// wxCheckListBox.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCheckListBox_h_)
#define _wxCheckListBox_h_
class wxCheckListBox : public wxListBox
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxCheckListBox() ;
	/**
	 * \brief Constructor, creating and showing a list box.





















\pythonnote{The wxCheckListBox constructor in wxPython reduces the  
and   arguments are to a single argument, which is
a list of strings.}

\perlnote{In wxPerl there is just an array reference in place of  
and  .} 
	 * \param wxWindow*  
	 * \param wxWindowID  
	 * \param const wxPoint&  
	 * \param const wxSize&  
	 * \param int  
	 * \param const wxString   
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

  wxCheckListBox(wxWindow*  parent , wxWindowID  id , const wxPoint& pos , const wxSize& size, int  n =0 , const wxString  choices[] = NULL, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("listBox"));
	/**
	 * \brief Destructor, destroying the list box. 
	*/

  virtual  ~wxCheckListBox() ;
	/**
	 * \brief Checks the given item. Note that calling this method doesn't result in
wxEVT_COMMAND_CHECKLISTBOX_TOGGLE being emitted. 
	 * \param int   
	 * \param bool  
	*/

  void Check(int  item , bool check = true) ;
	/**
	 * \brief Returns true if the given item is checked, false otherwise. 
	 * \param int  
	*/

  bool IsChecked(int  item ) const;
};


#endif
