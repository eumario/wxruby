/**********************************************************************

  dataobjectsimple.t -

  $Author$
  $Date$

**********************************************************************/

//$$ CLASS DataObjectSimple : DataObject
//$$ NO_CLIENT_DATA

//$$ METHODS_BEGIN
wxDataObjectSimple(const wxDataFormat& format = wxFormatInvalid);

const wxDataFormat& GetFormat() const;
void SetFormat(const wxDataFormat& format);
virtual size_t GetDataSize() const;
virtual bool GetDataHere(void *buf) const;
virtual bool SetData(size_t len, const void *buf);
//$$ METHODS_END

//$$ BEGIN_H_FILE
#include <wx/dataobj.h>
//$$ RB_DECLARE_CLASS
//$$ END_H_FILE

//$$ BEGIN_CPP_FILE
//$$ RB_IMPLEMENT_CLASS
//$$ END_CPP_FILE
