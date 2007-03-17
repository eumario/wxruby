// wxGridCellNumberEditor.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridCellNumberEditor_h_)
#define _wxGridCellNumberEditor_h_
class wxGridCellNumberEditor : public wxGridCellTextEditor
{
public:
	/**
	 * \brief Allows to specify the range for acceptable data;
if min == max == -1, no range checking is done 
	 * \param int   
	 * \param int   
	*/

   wxGridCellNumberEditor(int  min = -1, int  max = -1) ;
	/**
	 * \brief String representation of the value. 
	*/

  wxString GetString() const;
	/**
	 * \brief If the return value is true, the editor uses a wxSpinCtrl to get user input,
otherwise it uses a wxTextCtrl. 
	*/

  bool HasRange() const;
	/**
	 * \brief Parameters string format is &quot;min,max&quot;. 
	 * \param const wxString&   
	*/

  void SetParameters(const wxString&  params ) ;
};


#endif
