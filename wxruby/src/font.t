/**********************************************************************

  font.t -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

//$$ CLASS Font
//$$ NEEDS_WRAPPING_CONSTRUCTOR
//$$ NO_CLIENT_DATA

//$$ METHODS_BEGIN
    wxFont()
    wxFont(int pointSize, int family, int style, int weight, const bool underline = FALSE, const wxString& faceName = "", wxFontEncoding encoding = wxFONTENCODING_DEFAULT)

    bool IsFixedWidth() const
    wxString GetFaceName() const
    int GetFamily() const
    wxString GetNativeFontInfoDesc() const
    int GetPointSize() const
    int GetStyle() const
    bool GetUnderlined() const
    int GetWeight() const
    bool Ok() const
    void SetFaceName(const wxString& faceName)
    void SetFamily(int family)
#(1)    void SetNativeFontInfo(const wxNativeFontInfo& info)
    void SetPointSize(int pointSize)
    void SetStyle(int style)
    void SetUnderlined(const bool underlined)
    void SetWeight(int weight)
    
    static wxFontEncoding GetDefaultEncoding()
    static void SetDefaultEncoding(wxFontEncoding encoding)
//$$ METHODS_END

//(1) Under GTK, expects wxNativeFontInfo instead of wxString
#(1)    void SetNativeFontInfo(const wxNativeFontInfo& info)



//$$ BEGIN_H_FILE
class WxFont
{
public:
    //$$ RB_DECLARE
    static VALUE init0(const wxFont& font);
};
//$$ END_H_FILE


//$$ BEGIN_CPP_FILE
#include "wx/font.h"

//$$ RB_IMPLEMENT_CLASS

VALUE WxFont::init0(const wxFont &font)
{
    wxFont *ptr;
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    // TODO: The following line will leak memory!
    ptr = new wxFont();
    *ptr = font;
    DATA_PTR(self) = ptr;
    return self;
}

//$$ END_CPP_FILE
