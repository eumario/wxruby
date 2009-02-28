// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxDC
GC_MANAGE_AS_OBJECT(wxDC);

// Used by draw_lines, draw_polygon etc
%include "../shared/points_list.i"

// Won't compile without this b/c abstract class
%ignore wxDC();

// raises 'void value is not ignored as it should be' compile error
%ignore wxDC::StartPage;

// dealt with below - needs some argument -> output mangling
%ignore wxDC::GetPartialTextExtents;

// These versions are not needed as we use shared typemaps (in
// swig/typemaps.i) to convert the other method signatures into a ruby
// method that simply accepts an Array of points
%ignore DrawLines(const wxList* points, 
                  wxCoord xoffset = 0, 
                  wxCoord yoffset = 0);
%ignore DrawPolygon(const wxList* points, 
                    wxCoord xoffset = 0, 
                    wxCoord yoffset = 0, 
                    int fill_style = wxODDEVEN_RULE);

// Separate versions that return a pair of integers as against standard
// version returning a Size object
%rename(GetDimensions) wxDC::GetSize(wxCoord * width , wxCoord * height);
%rename(GetDimensionsMM) wxDC::GetSizeMM(wxCoord *width , wxCoord *height) const;
%rename(GetTextSize) wxDC::GetTextExtent(const wxString& string) const;
%rename(GetMultiLineTextSize) wxDC::GetMultiLineTextExtent(const wxString& string) const;



%extend wxDC {
  // Needs to return input parameter with list of lengths
  VALUE get_partial_text_extents(VALUE text) {
    wxString str = wxString(StringValuePtr(text), wxConvUTF8);
    wxArrayInt result = wxArrayInt();
    $self->GetPartialTextExtents(str, result);
    VALUE rb_result = rb_ary_new();
    for (size_t i = 0; i < result.GetCount(); i++) 
      {
        rb_ary_push(rb_result, INT2NUM( result.Item(i) ) );
      }
    return rb_result;
  }

};


%import "include/wxObject.h"

%include "include/wxDC.h"
