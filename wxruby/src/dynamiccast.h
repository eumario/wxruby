/**********************************************************************

  Dynamiccast.cpp

  $Author$
  $Date$

  Copyright (C) 2003  Kevin Smith,NSK

**********************************************************************/


#include "ruby.h"

#include <wx/wx.h>
#include <wx/hash.h>

#ifndef _RB_DYNAMIC_CAST_
#define _RB_DYNAMIC_CAST_

class WxTypeConverter : public wxObject
{
private:
	wxString name;

public:
	WxTypeConverter(wxString n):name(n){};
	wxString GetName()
	{
		return name;
	}
	virtual VALUE ToValue(wxObject *)=0;
};

template <class T> class WxRbTypeConverter : public WxTypeConverter
{
private:
	wxString name;

public:
	WxRbTypeConverter(const wxString &n):WxTypeConverter(n){};
	VALUE ToValue(wxObject *cppObject) 
	{
		if(!cppObject) 
            return Qnil;
		VALUE self = Data_Wrap_Struct(T::rubyClass, 0, 0, 0);
		DATA_PTR(self) = cppObject;
		return self;
	}
};



class WxRbTypeTable
{
	static wxHashTable table;
public:
	static void AddTypeConverter(WxTypeConverter *);
	static VALUE ConvertCppObject(wxObject *);
	static void Init();
};

#define WXRB_ADD_TYPE_CONV( cpp_class, ruby_class_name) \
    WxRbTypeTable::AddTypeConverter(new WxRbTypeConverter<cpp_class>((ruby_class_name)))


#endif
