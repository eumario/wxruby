/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.25
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

#ifndef SWIG_WxEvent_WRAP_H_
#define SWIG_WxEvent_WRAP_H_

class Swig::Director;


class SwigDirector_wxEvent : public wxEvent, public Swig::Director {

public:
    SwigDirector_wxEvent(VALUE self, int id = 0, wxEventType eventType = wxEVT_NULL);
    virtual wxEvent *Clone() const;
};


#endif
