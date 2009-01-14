require 'test/unit'
require 'wx'

class TestTextData < Test::Unit::TestCase
  FMT_TEXT = Wx::DataFormat.new(Wx::DF_TEXT)
  # Using an in-built class
  def test_text_data
    td = Wx::TextDataObject.new('WXRUBY')
    assert_equal("WXRUBY", td.text)

    Wx::Clipboard.open do | clip |
      clip.clear
      assert ! clip.supported?(FMT_TEXT)
      clip.place td
      assert clip.supported?(FMT_TEXT)
    end

    td_2 = Wx::TextDataObject.new
    Wx::Clipboard.open do | clip |
      clip.fetch td_2
    end
    assert_equal("WXRUBY", td_2.text)

    Wx::Clipboard.open do | clip |
      clip.clear
    end

    td_3 = Wx::TextDataObject.new
    Wx::Clipboard.open do | clip |
      clip.fetch td_3
    end
    assert_equal("", td_3.text)
  end
end


class TestBitmapData < Test::Unit::TestCase
  FMT_BMP = Wx::DataFormat.new(Wx::DF_BITMAP)
  # Using image data - this needs
  def test_bitmap_data
    bmp = Wx::Bitmap.new('samples/minimal/mondrian.png')
    height = bmp.height
    width  = bmp.width
    assert bmp.ok?, "Bitmap is OK"

    d_obj = Wx::BitmapDataObject.new(bmp)
    d_obj.bitmap = bmp

    assert d_obj.bitmap.ok?, "DataObject's bitmap is OK"
    Wx::Clipboard.open do | clip |
      clip.clear
      clip.place d_obj
      assert clip.supported? FMT_BMP
    end

    d_obj_2 = Wx::BitmapDataObject.new
    Wx::Clipboard.open do | clip |
      assert clip.supported? FMT_BMP
      clip.fetch d_obj
    end
    out_bmp = d_obj_2.bitmap
    assert out_bmp.ok?, "Fetched out bitmap"
    assert_equal height, out_bmp.height
    assert_equal width, out_bmp.width
  end
end

class TestDataObjSimple < Test::Unit::TestCase
  # A simple class supporting one format only - text
  class MyDataObjectSimple < Wx::DataObjectSimple
    attr_accessor :contents
    MY_FORMAT = Wx::DataFormat.new('this.is.special')

    def initialize(contents = nil)
      super MY_FORMAT
      if contents
        @contents = contents
      end
    end

    # These two must be overridden; get_data_size may be overridden
    def set_data(format, the_data)
      @contents = the_data
    end

    def get_data_here(format)
      @contents
    end
  end

  def test_data_obj_simple
    dobj = MyDataObjectSimple.new('TUESDAY')
    assert_equal('TUESDAY', dobj.contents)
    Wx::Clipboard.open do | clip |
      clip.set_data(dobj)
    end

    dobj_2 = MyDataObjectSimple.new
    Wx::Clipboard.open do | clip |
      clip.get_data(dobj_2)
    end
    assert_equal('TUESDAY', dobj_2.contents)
  end
end

class TestDataObjectComposite < Test::Unit::TestCase
  FMT_TXT = Wx::DataFormat.new(Wx::DF_TEXT)
  FMT_BMP = Wx::DataFormat.new(Wx::DF_BITMAP)

  # FIXME generally
  def test_data_object_composite
    d_obj = Wx::DataObjectComposite.new
    d_obj.add( Wx::TextDataObject.new("THE TEXT") )
    bmp = Wx::Bitmap.new('samples/minimal/mondrian.png')

    d_obj.add( Wx::BitmapDataObject.new(bmp) )

    assert_nothing_raised {
      assert_equal( 2, d_obj.format_count(0) )
    }

    Wx::Clipboard.open do | clip |
      clip.place d_obj
    end

    d_obj_2 = Wx::DataObjectComposite.new
    d_obj_2.add Wx::TextDataObject.new
    d_obj_2.add Wx::BitmapDataObject.new
    Wx::Clipboard.open do | clip |
      assert clip.supported?( FMT_TXT )
      assert clip.supported?( FMT_BMP )
    end
  end
end

class TestDataObject < Test::Unit::TestCase
  # A more complex class supporting multiple types
  FMT_TEXT = Wx::DataFormat.new(Wx::DF_TEXT)
  FMT_HTML = Wx::DataFormat.new('text.html')

  class MyBasicDataObject < Wx::DataObject
    attr_accessor :my_data
    def initialize(the_text = '')
      super()
      @my_data = the_text
      if the_text.empty?
        @html = ''
      else
        @html = "<b>#{the_text}</b>"
      end
    end

    # List all the formats that we support. By default, the first is
    # treated as the 'preferred' format; this can be overridden by
    # providing a get_preferred format.
    def get_all_formats(direction)
      [ FMT_HTML, FMT_TEXT  ]
    end

    # Do setting the data
    def set_data(format, the_data)
      case format
      when FMT_HTML
        @html = the_data
      when FMT_TEXT
        @my_data = the_data
      else
        false
      end
    end

    # Do getting the data
    def get_data_here(format)
      case format
      when FMT_TEXT
        @my_data
      when FMT_HTML
        @html
      else
        nil
      end
    end
  end

  def test_data_obj
    d_obj = MyBasicDataObject.new('HELLO')
    assert_equal( 2, d_obj.format_count(0) )
    assert_equal('HELLO', d_obj.get_data_here(FMT_TEXT) )
    assert_equal('<b>HELLO</b>', d_obj.get_data_here(FMT_HTML) )

    Wx::Clipboard.open do | clip |
      clip.place d_obj
    end
    
    d_obj_2 = MyBasicDataObject.new
    Wx::Clipboard.open do | clip |
      assert clip.supported?( FMT_TEXT )
      assert clip.supported?( FMT_HTML )
      clip.fetch d_obj_2
    end
    assert_equal('<b>HELLO</b>', d_obj_2.get_data_here(FMT_HTML) )
    # FIXME - the non-preferred data object isn't set
    assert_equal('HELLO', d_obj_2.get_data_here(FMT_TEXT) )
  end
end


# FIXME - test is run twice
Wx::App.run do
  # Must run whilst App is alive
  MiniTest::Unit.new.run

  false
end
