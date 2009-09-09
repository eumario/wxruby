// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxImage
GC_MANAGE_AS_OBJECT(wxImage);

%{
#include <wx/image.h>
%}

// Typemaps and classes for dealing with Input/Output stream
%include "../shared/streams.i"

// Handled in Ruby: lib/wx/classes/image.rb
%ignore wxImage(wxInputStream& stream, 
                long type = wxBITMAP_TYPE_ANY, 
                int index = -1);
%ignore wxImage(wxInputStream& stream, 
                const wxString& mimetype, 
                int index = -1);
%ignore wxImage::GetImageCount(wxInputStream& stream, 
                               long type = wxBITMAP_TYPE_ANY);


%rename(LoadStream) wxImage::LoadFile(wxInputStream& stream, 
                                      long type, 
                                      int index = -1);
%rename(LoadStream) wxImage::LoadFile(wxInputStream& stream, 
                                      const wxString& mimetype, 
                                      int index = -1);
%rename(Write) wxImage::SaveFile(wxOutputStream& stream, 
                                 int type) const;
%rename(Write) wxImage::SaveFile(wxOutputStream& stream, 
                                 const wxString& mimetype) const;

// Renaming to avoid method overloading and thus conflicts at Ruby level
%rename(GetAlphaData) wxImage::GetAlpha() const;
%rename(SetAlphaData) wxImage::SetAlpha(unsigned char* alpha = NULL, bool static_data = false);

// Renaming for consistency with above methods and SetRGB method
%rename(GetRgbData) wxImage::GetData() const;
%rename(SetRgbData) wxImage::SetData(unsigned char* data);

// Handler methods are not supported in wxRuby; all standard handlers
// are loaded at startup, and we don't allow custom image handlers to be
// written in Ruby. Note if these methods are added, corrected freearg
// typemap for input wxString in static methods will be required.
%ignore wxImage::AddHandler;
%ignore wxImage::CleanUpHandlers;
%ignore wxImage::FindHandler;
%ignore wxImage::FindHandlerMime;
%ignore wxImage::GetHandlers;
%ignore wxImage::InitStandardHandlers;
%ignore wxImage::InsertHandler;
%ignore wxImage::RemoveHandler;

// The GetRgbData and GetAlphaData methods require special handling using %extend;
%ignore wxImage::GetRgbData;
%ignore wxImage::GetAlphaData;
// The SetRgbData and SetAlphaData are dealt with by typemaps (see below).


// For Image#set_rgb_data, Image#set_alpha_data and Image.new with raw data arg:
// copy raw string data from a Ruby string to a memory block that will be
// managed by wxWidgets (see static_data typemap below)
%typemap(in) unsigned char* data, unsigned char* alpha {
  if ( TYPE($input) == T_STRING )
    {
      int data_len = RSTRING_LEN($input);
      $1 = (unsigned char*)malloc(data_len);
      memcpy($1, StringValuePtr($input), data_len);
    }
  else if ( $input == Qnil ) // Needed for SetAlpha, an error for SetData
    $1 = NULL;
  else
    SWIG_exception_fail(SWIG_ERROR, 
                        "String required as raw Image data argument");
}

// Image.new(data...) and Image#set_alpha_data both accept a static_data
// argument to specify whether wxWidgets should delete the data
// pointer. Since in wxRuby we always copy from the Ruby string object
// to the Image, we always want wxWidgets to handle deletion of the copy
%typemap(in, numinputs=0) bool static_data "$1 = false;"

// For get_or_find_mask_colour, which should returns a triplet
// containing the mask colours, plus its normal Boolean return value.
%apply unsigned char *OUTPUT { unsigned char* r, 
                               unsigned char* g, 
                               unsigned char* b }

// GetRgbData and GetAlphaData methods return an unsigned char* pointer to the
// internal representation of the image's data. We can't simply use
// rb_str_new2 because the data is not NUL terminated, so strlen won't
// return the right length; we have to know the image's height and
// width to give the ruby string the right length.
// 
// Unlike the C++ version of these methods, these return copies of the
// data; the ruby string is NOT a pointer to that internal data and
// cannot be directly manipulated to change the image. This is tricky
// b/c of Ruby's GC; it might be possible, as in mmap (see
// http://blade.nagaokaut.ac.jp/cgi-bin/scat.rb/ruby/ruby-talk/296601)
// but is beyond my C skills
%extend wxImage {
  VALUE get_alpha_data() {
    unsigned char* alpha_data = $self->GetAlpha();
    int length = $self->GetWidth() * $self->GetHeight();
    return rb_str_new( (const char*)alpha_data, length);
  }

  VALUE get_rgb_data() {
    unsigned char* rgb_data = $self->GetData();
    int length = $self->GetWidth() * $self->GetHeight() * 3;
    return rb_str_new( (const char*)rgb_data, length);
  }
}

%import "include/wxObject.h"
%include "include/wxImage.h"
