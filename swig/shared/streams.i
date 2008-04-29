// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

// Several methods (eg in wxImage) allow data to be read from an input
// stream rather than a file. This simple C++ class delegates calls to
// wxInputStream methods to any IO-like ruby object that responds to the
// specified methods. This can be used, for example, to read Image data
// from a socket to another program.

%{
  class wxRubyInputStream : public wxInputStream
  {
  public:
	wxRubyInputStream(VALUE rb_io) { m_rbio = rb_io; }

	bool CanRead() {
	  return ( ! RTEST( rb_funcall(m_rbio, rb_intern("closed?"), 0) ) );
	}
	char GetC() { 
	  return (char)NUM2INT( rb_funcall(m_rbio, rb_intern("getc"), 0) );
	}
	bool Eof() {
	  return RTEST( rb_funcall(m_rbio, rb_intern("eof"), 0) );
	}
	size_t OnSysRead(void *buffer, size_t bufsize) {
	  VALUE read_data = rb_funcall(m_rbio, rb_intern("read"), 
								   1, INT2NUM(bufsize));
	  memcpy(buffer, RSTRING_PTR(read_data), RSTRING_LEN(read_data));
	  return RSTRING_LEN(read_data);
	}
	wxRubyInputStream& Read(void *buffer, size_t size) {
	  VALUE read_data = rb_funcall(m_rbio, rb_intern("read"), 
								   1, INT2NUM(size));
	  memcpy(buffer, RSTRING_PTR(read_data), RSTRING_LEN(read_data));
	  return *this;
	}
	off_t SeekI(off_t pos, wxSeekMode mode = wxFromStart) {
	  // Seek mode integers happily coincide in Wx and Ruby
	  rb_funcall( m_rbio, rb_intern("seek"), 2, 
				  INT2NUM(pos), INT2NUM(mode) );
	  return this->TellI();
	}
	off_t TellI() {
	  return NUM2INT( rb_funcall( m_rbio, rb_intern("tell"), 0) );
	}
  protected:
	VALUE m_rbio;
  };

%}

%typemap(in) wxInputStream& "$1 = new wxRubyInputStream($input);"
%typemap(typecheck) wxInputStream& {
  RTEST(rb_respond_to($input, rb_intern("read")));
}
%typemap(freearg) wxInputStream& "delete $1;"
