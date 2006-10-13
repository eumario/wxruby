# wxRuby2 Sample Code. Copyright (c) 2004-2006 Kevin B. Smith
# Freely reusable code: see SAMPLES-LICENSE.TXT for details

require 'wx'

class Log
  def write_text(txt)
    Wx::log_message(txt.chomp)
  end
  alias write write_text
end

# Wx::App is the container class for any wxruby app - only a single
# instance is required
class MinimalApp < Wx::App
  def initialize(sample)
    @sample = sample
    super()
  end

  def on_init
    frame = Wx::Frame.new(nil, -1, "wxRuby Demo: #{@sample}",
                             Wx::Point.new(50, 50), 
                             Wx::Size.new(450, 340))

    frame.create_status_bar
    
    menu_file = Wx::Menu.new()
    menu_file.append(Wx::ID_EXIT, "E&xit\tAlt-X", "Quit this program")
    menu_bar = Wx::MenuBar.new()
    menu_bar.append(menu_file, "&File")
    evt_menu(Wx::ID_EXIT) { frame.close }

    frame.set_menu_bar(menu_bar)
    frame.show

    # TODO:  Some samples may need clean-up calls?
    frame.evt_close {|evt| evt.skip }

    win = Demo.run(frame, frame, Log.new)
    # a window will be returned if the demo does not create
    # its own top-level window
    if win
      frame.set_size(640, 480)
      win.set_focus
    else
      return true
    end

    set_top_window(frame)
    true
  end
  
  def on_assert(file, line, condition, message)
    puts("ASSERT: #{file} #{line}: #{condition}; #{message}")
    raise
  end
end

def run(sample)
  app = MinimalApp.new(sample)
  app.main_loop()
end

if __FILE__ == $0
  if ARGV[0]
    begin
      load ARGV[0]
      run(ARGV[0])
    rescue(LoadError)
      puts "Unable to load '#{ARGV[0]}'"
    end
  else
    puts "You must specify the filename of the sample you want to run."
  end
end
