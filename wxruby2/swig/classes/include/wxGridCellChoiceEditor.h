// wxGridCellChoiceEditor.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridCellChoiceEditor_h_)
#define _wxGridCellChoiceEditor_h_
class wxGridCellChoiceEditor : public wxGridCellEditor
{
public:
	/**
	 * \brief  
	 * \param size_t   
	 * \param const wxString   
	 * \param bool   
	*/

   wxGridCellChoiceEditor(size_t  count = 0, const wxString  choices[] = NULL, bool  allowOthers = false) ;
	/**
	 * \brief Parameters string format is &quot;item1&#91;,item2&#91;...,itemN]]&quot; 
	 * \param const wxString&   
	*/

  void SetParameters(const wxString&  params ) ;
};


#endif
