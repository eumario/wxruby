/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.21
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

#ifndef SWIG_WxButton_WRAP_H_
#define SWIG_WxButton_WRAP_H_

class Swig::Director;


class SwigDirector_wxButton : public wxButton, public Swig::Director {

public:
    SwigDirector_wxButton(VALUE self, bool disown = 0);
    SwigDirector_wxButton(VALUE self, wxWindow *parent, wxWindowID id, wxString const &label, wxPoint const &pos, wxSize const &size = wxDefaultSize, long style = 0, wxValidator const &validator = wxDefaultValidator, wxString const &name = "button", bool disown = 0);
};


#endif
