//   Copyright 2004-2005 by Kevin Smith
//   released under the MIT-style wxruby2 license

#if !defined(_wxStaticBoxSizer_h_)
#define _wxStaticBoxSizer_h_
class wxStaticBoxSizer : public wxBoxSizer
{
public:
   wxStaticBoxSizer(wxStaticBox*  box , int  orient ) ;
  wxStaticBox* GetStaticBox() ;
};


#endif
