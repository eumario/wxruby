// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxDataObjectComposite
GC_MANAGE_AS_OBJECT(wxDataObjectComposite);

%include "../shared/data_object_common.i"

// SWIG gets confused and doesn't realise that various virtual methods
// from wxDataObject are implemented fully in this subclass, and so,
// believing it to be abstract doesn't provide an allocator for this
// class. This undocumented feature overrides this.
%feature("notabstract") wxDataObjectComposite;

%feature("nodirector") GetAllFormats;
%feature("nodirector") GetDataSize;
%feature("nodirector") GetDataHere;
%ignore GetDataHere;
%feature("nodirector") GetFormatCount;
%feature("nodirector") GetPreferredFormat;
%feature("nodirector") SetData;
%ignore SetData;

// Once a DataObject has been added, it belongs to the composite object,
// and will be freed by it on destruction.
%apply SWIGTYPE *DISOWN { wxDataObjectSimple* dataObject };

// Write our own get_data_here and set_data methods, easier than trying
// to do typemaps for these as it's a final class
%extend wxDataObjectComposite {
  VALUE get_data_here(VALUE rb_format)
  {
    VALUE result;
    // Convert the DataFormat object
    void* ptr;
    SWIG_ConvertPtr(rb_format, &ptr, SWIGTYPE_p_wxDataFormat, 0);
    wxDataFormat* format = reinterpret_cast< wxDataFormat * >(ptr);
    
    // Create and read in the buffer
    size_t data_size = $self->GetDataSize(*format);
    char *buf = new char [ data_size ];
    if ( $self->GetDataHere(*format, (void *)buf) )
      result = rb_str_new( (const char*)buf, data_size );
    else
      result = Qnil;

    // Tidy up and return
    delete [] buf;
    return result;
  }

  VALUE set_data(VALUE rb_format, VALUE data)
  {
    void* ptr;
    SWIG_ConvertPtr(rb_format, &ptr, SWIGTYPE_p_wxDataFormat, 0);
    wxDataFormat* format = reinterpret_cast< wxDataFormat * >(ptr);

    if ( $self->SetData(*format,
                        RSTRING_LEN(data),
                        (const void*)StringValuePtr(data) ) )
      return Qtrue;
    else
      return Qfalse;
  }
}

%import "include/wxDataObject.h"
%include "include/wxDataObjectComposite.h" 
