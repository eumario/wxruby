/**********************************************************************

  textdataobject.t -

  $Author$
  $Date$

**********************************************************************/

//$$ CLASS TextDataObject : DataObjectSimple
//$$ NO_CLIENT_DATA

//$$ METHODS_BEGIN
wxTextDataObject(const wxString& text = wxEmptyString);
virtual size_t GetTextLength() const;
virtual wxString GetText() const;
virtual void SetText(const wxString& strText);

//$$ METHODS_END

//$$ BEGIN_H_FILE
#include <wx/dataobj.h>
//$$ RB_DECLARE_CLASS
//$$ END_H_FILE


//$$ BEGIN_CPP_FILE

//##############################################################################
//$$ RB_IMPLEMENT_CLASS

//$$ END_CPP_FILE
