// Copyright 2004-2006 by Kevin Smith
// released under the MIT-style wxruby2 license

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
