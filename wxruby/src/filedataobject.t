/**********************************************************************

  textdataobject.t -

  $Author$
  $Date$

**********************************************************************/

//$$ CLASS FileDataObject : DataObjectSimple
//$$ NO_CLIENT_DATA

//$$ METHODS_BEGIN
wxFileDataObject();

virtual void AddFile(const wxString& file); // MSW only!!!
#(1)const wxArrayString& GetFilenames() const;
//$$ METHODS_END

#(1) should be implemented manually to return a ruby string array

//$$ BEGIN_H_FILE
#include <wx/dataobj.h>
//$$ RB_DECLARE_CLASS
//$$ END_H_FILE


//$$ BEGIN_CPP_FILE

//##############################################################################
//$$ RB_IMPLEMENT_CLASS

//$$ END_CPP_FILE
