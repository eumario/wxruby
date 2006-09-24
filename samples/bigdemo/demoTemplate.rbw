require 'wx'

class
    def initialize()

    end
end

module Demo
    def Demo.run(frame, nb, log)

    end

    def Demo.overview
        return ""
    end
end
    

if __FILE__ == $0
  run_solo_lib = File.join( File.dirname(__FILE__), 'run.rb')
  load run_solo_lib
  run File.basename($0)
end
