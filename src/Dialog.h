/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.22
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

#ifndef SWIG_WxDialog_WRAP_H_
#define SWIG_WxDialog_WRAP_H_

class Swig::Director;


class SwigDirector_wxDialog : public wxDialog, public Swig::Director {

public:
    SwigDirector_wxDialog(VALUE self, bool disown = false);
    SwigDirector_wxDialog(VALUE self, wxWindow *parent, wxWindowID id, wxString const &title, wxPoint const &pos = wxDefaultPosition, wxSize const &size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE, wxString const &name = wxT("dialogBox"), bool disown = false);
    virtual void OnApply(wxCommandEvent &event);
    virtual void OnCancel(wxCommandEvent &event);
    virtual void OnOK(wxCommandEvent &event);
    virtual void OnSysColourChanged(wxSysColourChangedEvent &event);
};


#endif
