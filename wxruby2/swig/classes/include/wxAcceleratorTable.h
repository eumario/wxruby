// wxAcceleratorTable.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxAcceleratorTable_h_)
#define _wxAcceleratorTable_h_
class wxAcceleratorTable : public wxObject
{
public:
   wxAcceleratorTable() ;
   wxAcceleratorTable(const wxAcceleratorTable&  bitmap ) ;
   wxAcceleratorTable(int  n , wxAcceleratorEntry  entries[] ) ;
   wxAcceleratorTable(const wxString&  resource ) ;
  virtual  ~wxAcceleratorTable() ;
  bool Ok() const;
};


#endif
