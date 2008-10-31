// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

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
   bool IsOk() const;
};


#endif
