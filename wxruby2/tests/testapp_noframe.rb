require 'test/unit'
require 'wx'

class AppReturnsFalseFromInit < Wx::App
    attr_reader(:did_call_on_init)
    
    def on_init
        @did_call_on_init = true
        return false
    end
    
end

class TestApp < Test::Unit::TestCase
  def test_return_false_from_init
    o = AppReturnsFalseFromInit.new
    o.main_loop
    assert(o.did_call_on_init, "didn't call on_init?")
    assert_equal("wxruby", o.get_app_name)
  end
  
end

if $0 == __FILE__
  require 'test/unit/ui/console/testrunner'
  Test::Unit::UI::Console::TestRunner.run(TestApp)
end
