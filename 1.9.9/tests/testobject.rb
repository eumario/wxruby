require 'test/unit'
require 'wx'

class TestObject < Test::Unit::TestCase
  def test_basics
    o = Wx::Object.new
  end
end

if $0 == __FILE__
  require 'test/unit/ui/console/testrunner'
  Test::Unit::UI::Console::TestRunner.run(TestObject)
end
