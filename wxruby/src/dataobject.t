/**********************************************************************

  dataobject.t -

  $Author$
  $Date$

**********************************************************************/

//$$ CLASS DataObject
//$$ ABSTRACT
//$$ NO_CLIENT_DATA

//$$ METHODS_BEGIN
wxDataObject();

abstract void GetAllFormats(wxDataFormat *formats, wxDataObject::Direction dir = wxDataObject::Get) const;
abstract bool GetDataHere(const wxDataFormat& format, void *buf) const;
abstract size_t GetDataSize(const wxDataFormat& format) const;
abstract size_t GetFormatCount(wxDataObject::Direction dir = wxDataObject::Get) const;
abstract wxDataFormat GetPreferredFormat(wxDataObject::Direction dir = wxDataObject::Get) const;
virtual bool SetData(const wxDataFormat& format, size_t len, const void *buf);
//$$ METHODS_END

//$$ BEGIN_H_FILE
#include<wx/dataobj.h>
#include "dataformat.h"
//$$ RB_DECLARE_CLASS
//$$ END_H_FILE

//$$ BEGIN_CPP_FILE
//$$ RB_IMPLEMENT_CLASS
//$$ END_CPP_FILE
