// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxContextHelpButton_h_)
#define _wxContextHelpButton_h_
class wxContextHelpButton : public wxBitmapButton
{
public:
   wxContextHelpButton(wxWindow* parent, 
                       wxWindowID id = wxID_CONTEXT_HELP, 
                       const wxPoint& pos = wxDefaultPosition, 
                       const wxSize& size = wxDefaultSize, 
                       long style = wxBU_AUTODRAW) ;
   void OnContextHelp(wxCommandEvent& event);
};


#endif
