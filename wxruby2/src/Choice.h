/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.22
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

#ifndef SWIG_WxChoice_WRAP_H_
#define SWIG_WxChoice_WRAP_H_

class Swig::Director;


class SwigDirector_wxChoice : public wxChoice, public Swig::Director {

public:
    SwigDirector_wxChoice(VALUE self, bool disown = false);
    SwigDirector_wxChoice(VALUE self, wxWindow *parent, wxWindowID id, wxPoint const &pos, wxSize const &size, int n, wxString const choices[], long style = 0, wxValidator const &validator = wxDefaultValidator, wxString const &name = wxT("choice"), bool disown = false);
};


#endif
