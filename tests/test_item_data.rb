require 'test/unit'
require 'test/unit/ui/console/testrunner'
require 'wx'

class TestApp < Wx::App
  attr_accessor :test_class
  def on_init
    Test::Unit::UI::Console::TestRunner.run(self.test_class)
  end
end

class CtrlContainerFrame < Wx::Frame
  attr_accessor :control
  def initialize(ctrl_class, *args)
    super(nil, -1, 'Test ' + ctrl_class.name)
    self.control = ctrl_class.new(self, -1, *args)
  end
end

class TestItemData < Test::Unit::TestCase
  def assert_retrievable_data(ctrl, n, test_value)
    compare = Marshal.load( Marshal.dump(test_value) )
    ctrl.set_client_data(n, test_value)
    assert_equal(compare, ctrl.get_client_data(n) )
    GC.start
    assert_equal(compare, ctrl.get_client_data(n) )
  end

  def do_control_with_items_assertions(f)
    assert_retrievable_data(f.control, 0, { 'b' => 'B' })
    assert_retrievable_data(f.control, 1, 'string item data')
    assert_retrievable_data(f.control, 2, 42.3)
  end

  def test_treectrl_itemdata
    f = CtrlContainerFrame.new(Wx::TreeCtrl)
    root = f.control.add_root('foo')

    id = f.control.append_item(root, 'a hash', -1, -1, { :a => 7 })
    assert_equal({:a => 7 }, 
                  f.control.get_item_data(id) )

    id = f.control.prepend_item(root, 'a float', -1, -1, 7.8)
    assert_equal(7.8, 
                 f.control.get_item_data(id) )

    id = f.control.prepend_item(root, 'an array', -1, -1, %w|foo bar baz|)
    GC.start
    assert_equal(%w|foo bar baz|,
                 f.control.get_item_data(id) )

    f.close(true)
  end

  def test_choice_itemdata
    f = CtrlContainerFrame.new(Wx::Choice, Wx::DEFAULT_POSITION,
                                Wx::DEFAULT_SIZE, %w[hash string float])
    do_control_with_items_assertions(f)
    f.close(true)
  end

   def test_listbox_itemdata
     f = CtrlContainerFrame.new(Wx::ListBox, Wx::DEFAULT_POSITION,
                                 Wx::DEFAULT_SIZE, %w[hash string float])
     do_control_with_items_assertions(f)
     f.close(true)
   end
  
   def test_combobox_itemdata
     f = CtrlContainerFrame.new(Wx::ComboBox, '', Wx::DEFAULT_POSITION,
                               Wx::DEFAULT_SIZE, %w[hash string float])
     do_control_with_items_assertions(f)
     f.close(true)
   end
end

app = TestApp.new
app.test_class = TestItemData
app.main_loop
