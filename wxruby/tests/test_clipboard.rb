require 'test/unit'

# Manual running of tests differs between 1.8 and 1.9
if RUBY_VERSION < "1.9"
  require 'test/unit/ui/console/testrunner'
end

require 'wx'

class TestTextData < Test::Unit::TestCase
  # Using an in-built class
  def test_text_data
    td = Wx::TextDataObject.new('WXRUBY')
    assert_equal("WXRUBY", td.text)

    Wx::Clipboard.open do | clip |
      clip.clear
      assert ! clip.supported?(Wx::DF_TEXT)
      clip.place td
      assert clip.supported?(Wx::DF_TEXT)
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
  def test_bitmap_data
    # FIXME - this doesn't appear to load correctly on MingW-Ruby 1.9
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
      assert clip.supported? Wx::DF_BITMAP
    end

    d_obj_2 = Wx::BitmapDataObject.new
    Wx::Clipboard.open do | clip |
      assert clip.supported? Wx::DF_BITMAP
      clip.fetch d_obj_2
    end

    out_bmp = d_obj_2.bitmap
    assert out_bmp.ok?, "Fetched out bitmap"
    assert_equal height, out_bmp.height
    assert_equal width, out_bmp.width
  end
end

class TestDataObjectSimple < Test::Unit::TestCase
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
  def test_data_object_composite
    d_obj = Wx::DataObjectComposite.new
    d_obj.add( Wx::TextDataObject.new("THE TEXT") )
    # FIXME - this doesn't appear to load correctly on MingW-Ruby 1.9
    bmp = Wx::Bitmap.new('samples/minimal/mondrian.png')

    d_obj.add( Wx::BitmapDataObject.new(bmp) )
    assert_equal( 2, d_obj.format_count(0) )


    Wx::Clipboard.open do | clip |
      clip.clear
      clip.place d_obj
    end

    d_obj_2 = Wx::DataObjectComposite.new
    text_out = Wx::TextDataObject.new
    d_obj_2.add text_out

    bmp_out = Wx::BitmapDataObject.new
    d_obj_2.add bmp_out

    assert_equal 2, d_obj_2.format_count(0) 

    Wx::Clipboard.open do | clip |
      assert clip.supported?( Wx::DF_TEXT )
      assert clip.supported?( Wx::DF_BITMAP )

      clip.fetch d_obj_2
    end
    assert_equal "THE TEXT", text_out.text

    # FIXME - only the first format is read from the clipboard
    bmp_out = bmp_out.bitmap
    assert bmp_out.ok?, "Read out bitmap OK"
    assert_equal bmp.width, bmp_out.width
    assert_equal bmp.height, bmp_out.height

  end
end

class TestDataObject < Test::Unit::TestCase
  MY_CUSTOM_FORMAT = Wx::DataFormat.new('custom.text.format')

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
      [ MY_CUSTOM_FORMAT, Wx::DF_TEXT  ]
    end

    # Do setting the data
    def set_data(format, the_data)
      case format
      when MY_CUSTOM_FORMAT
        @html = the_data
      when Wx::DF_TEXT
        @my_data = the_data
      else
        false
      end
    end

    # Do getting the data
    def get_data_here(format)
      case format
      when Wx::DF_TEXT
        @my_data
      when MY_CUSTOM_FORMAT
        @html
      else
        nil
      end
    end
  end

  def test_data_obj
    d_obj = MyBasicDataObject.new('HELLO')
    assert_equal( 2, d_obj.format_count(0) )
    assert_equal('HELLO', d_obj.get_data_here(Wx::DF_TEXT) )
    assert_equal('<b>HELLO</b>', d_obj.get_data_here(MY_CUSTOM_FORMAT) )

    Wx::Clipboard.open do | clip |
      clip.place d_obj
    end
    
    d_obj_2 = MyBasicDataObject.new
    Wx::Clipboard.open do | clip |
      assert clip.supported?( Wx::DF_TEXT )
      assert clip.supported?( MY_CUSTOM_FORMAT )
      clip.fetch d_obj_2
    end
    assert_equal('<b>HELLO</b>', d_obj_2.get_data_here(MY_CUSTOM_FORMAT) )

    # FIXME - the non-preferred data object isn't set
    assert_equal('HELLO', d_obj_2.get_data_here(Wx::DF_TEXT) )
  end
end


# FIXME - test is run twice
Wx::App.run do
  # Must run whilst App is alive
  if RUBY_VERSION >= "1.9"
    MiniTest::Unit.new.run
  else
    Test::Unit::UI::Console::TestRunner.run(TestTextData)
    Test::Unit::UI::Console::TestRunner.run(TestBitmapData)
    Test::Unit::UI::Console::TestRunner.run(TestDataObject)
    Test::Unit::UI::Console::TestRunner.run(TestDataObjectComposite)
    Test::Unit::UI::Console::TestRunner.run(TestDataObjectSimple)
  end
  false
end

