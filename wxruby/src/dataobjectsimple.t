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
#if 0
wxDataObjectSimpleHelper::wxDataObjectSimpleHelper(){};

void wxDataObjectSimpleHelper::SetSelf(VALUE self) const
{
	me = self;
}

bool wxDataObjectSimpleHelper::SetData(const wxDataFormat& format, size_t len, void *buf) 
{
	// TODO: Fill this in!
	return false;
}

bool wxDataObjectSimpleHelper::GetDataHere(const wxDataFormat& format, void *buf) const
{
	// TODO: Fill this in!
	return false;
}

size_t wxDataObjectSimpleHelper::GetDataSize(const wxDataFormat& format) const
{
	// TODO: Fill this in!
	return 0;
}
#endif
//$$ END_CPP_FILE
