/**********************************************************************

  textattr.t -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

//$$ CLASS TextAttr
//$$ NEEDS_WRAPPING_CONSTRUCTOR
//$$ NO_CLIENT_DATA

//$$ METHODS_BEGIN
wxTextAttr(const wxColour& colText, const wxColour& colBack = wxNullColour, const wxFont& font = wxNullFont)

const wxColour& GetBackgroundColour() const
const wxFont& GetFont() const
const wxColour& GetTextColour() const
bool HasBackgroundColour() const
bool HasFont() const
bool HasTextColour() const
bool IsDefault() const
//$$ METHODS_END


//$$ BEGIN_H_FILE
//$$ RB_DECLARE_CLASS
//$$ END_H_FILE


//$$ BEGIN_CPP_FILE
#include "colour.h"
#include "font.h"

//$$ RB_IMPLEMENT_CLASS
//$$ END_CPP_FILE
