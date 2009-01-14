require 'test/unit'
require 'wx'

class TestTextData < Test::Unit::TestCase
  # Using an in-built class
  def _test_text_data
    td = Wx::TextDataObject.new('WXRUBY')
    assert_equal("WXRUBY", td.text)
    Wx::Clipboard.open do | clip |
      clip.place td
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

  def _test_data_obj_simple
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
      [ FMT_TEXT, FMT_HTML ]
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
    assert_equal('HELLO', d_obj_2.get_data_here(FMT_TEXT) )
    assert_equal('<b>HELLO</b>', d_obj_2.get_data_here(FMT_HTML) )
  end
end
