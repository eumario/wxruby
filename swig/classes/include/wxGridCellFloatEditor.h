// wxGridCellFloatEditor.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridCellFloatEditor_h_)
#define _wxGridCellFloatEditor_h_
class wxGridCellFloatEditor : public wxGridCellTextEditor
{
public:
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

   wxGridCellFloatEditor(int  width = -1, int  precision = -1) ;
	/**
	 * \brief Parameters string format is &quot;width,precision&quot; 
	 * \param const wxString&   
	*/

  void SetParameters(const wxString&  params ) ;
};


#endif
