/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.22
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

#ifndef SWIG_WxIcon_WRAP_H_
#define SWIG_WxIcon_WRAP_H_

class Swig::Director;


class SwigDirector_wxIcon : public wxIcon, public Swig::Director {

public:
    SwigDirector_wxIcon(VALUE self, bool disown = false);
    SwigDirector_wxIcon(VALUE self, wxIcon const &icon, bool disown = false);
    SwigDirector_wxIcon(VALUE self, char const **data, bool disown = false);
    SwigDirector_wxIcon(VALUE self, char **data, bool disown = false);
    SwigDirector_wxIcon(VALUE self, wxString const &name, wxBitmapType type = wxBITMAP_TYPE_ICO_RESOURCE, int desiredWidth = -1, int desiredHeight = -1, bool disown = false);
    SwigDirector_wxIcon(VALUE self, wxIconLocation const &loc, bool disown = false);
};


#endif
