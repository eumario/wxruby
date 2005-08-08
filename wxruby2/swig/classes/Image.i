#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxImage
%feature("nodirector") wxImage;

%{
//NO_DIRECTOR

#include <wx/wx.h>
#include <wx/image.h>
%}


%ignore wxImage(int  width , int  height , bool clear = true) ;
%ignore wxImage::Create();
%ignore wxImage::HasAlpha;
%ignore wxImage::AddHandler(const wxString&  filename );
%ignore wxImage::SetAlpha(unsigned char *);
%ignore wxImage::SetAlpha(int, int, unsigned char);
%ignore wxImage::GetImageExtWildcard();
%ignore wxImage::GetAlpha(int  x , int  y ) const;
%ignore wxImage::GetAlpha() const;


%include "include/wxImage.h"
