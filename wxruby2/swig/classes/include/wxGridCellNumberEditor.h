// wxGridCellNumberEditor.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridCellNumberEditor_h_)
#define _wxGridCellNumberEditor_h_
class wxGridCellNumberEditor : public wxGridCellTextEditor
{
public:
   wxGridCellNumberEditor(int  min = -1, int  max = -1) ;
  wxString GetString() const;
  bool HasRange() const;
  void SetParameters(const wxString&  params ) ;
};


#endif
