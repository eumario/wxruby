/**********************************************************************

  validator.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_VALIDATOR_H
#define WXRUBY_VALIDATOR_H

class wxRbValidator : public wxValidator
{
public:
  wxRbValidator(VALUE klass) { self = klass;}
  virtual wxObject* Clone();
  virtual bool TransferFromWindow();
  virtual bool TransferToWindow();
  virtual bool Validate(wxWindow* parent);
private:
  VALUE self;
};

class WxValidator {
public:
    static VALUE alloc(VALUE self);
	static VALUE wrapNew(int argc, VALUE *argv, VALUE self);
    static VALUE init(VALUE self);
    static VALUE init0(wxValidator *validator);
    static VALUE GetWindow(VALUE self);
    static void SetBellOnError(int argc, VALUE *argv, VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
