/**********************************************************************

  htmlprocessor.t -

  $Author$
  $Date$
  created at: 2004-08-04 12:08

  Copyright (C) 2004  Tobias Gruetzmacher

**********************************************************************/

//$$ CLASS HtmlProcessor
//$$ NO_CLIENT_DATA
//$$ ABSTRACT

//$$ METHODS_BEGIN
    wxHtmlProcessor();
    abstract virtual wxString Process(const wxString& text) const;
    virtual int GetPriority();
    virtual void Enable(bool enable = TRUE);
    bool IsEnabled();

//$$ METHODS_END

//$$ BEGIN_H_FILE
#include "wx/html/htmlproc.h"
//$$ RB_DECLARE_CLASS
//$$ END_H_FILE


//$$ BEGIN_CPP_FILE
//$$ RB_IMPLEMENT_CLASS

wxHtmlProcessorHelper::wxHtmlProcessorHelper() :
    wxHtmlProcessor()
{
}

void wxHtmlProcessorHelper::SetSelf(VALUE self)
{
	me = self;
}

wxString wxHtmlProcessorHelper::Process(const wxString& text) const
{
	ID method = rb_intern("process");
	
	VALUE ret = rb_funcall(me, method, 1, rb_str_new2(text));
	
	return wxString(StringValuePtr(ret));
}

//$$ END_CPP_FILE
