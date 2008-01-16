#!/usr/bin/env ruby
# wxRuby2 Sample Code. Copyright (c) 2004-2006 Kevin B. Smith
# Freely reusable code: see SAMPLES-LICENSE.TXT for details

begin
  require 'wx'
rescue LoadError => no_wx_err
  begin
    require 'rubygems'
    require 'wx'
  rescue LoadError
    raise no_wx_err
  end
end

# This simple sample demonstrates how to use Ruby 1.8's lightweight
# (green) threads to execute non-GUI code in parallel with a wxRuby
# GUI. This strategy is useful in a number of situations:
# 
# * To keep the GUI responsive whilst computationally intensive
#   operations are carried out in the background
# * To keep the GUI responsive while waiting for networking operations
#   to complete 
# 
# The basic problem is that, as with other Ruby GUI toolkits, non-GUI
# threads will not, by default, get allocated time to run while Ruby is
# busy in Wx code - the main wxRuby event loop. Strategies to deal with
# this include using non-blocking IO, and, more generically, using
# wxRuby's Timer class to explicitly allocate time for non-GUI threads
# to run. The latter technique is shown here.

# This frame shows a set of progress bars which monitor progress of
# long-running tasks. In this example, this long-running task is
# emulated by simply sleep-ing for random periods, but could equally be
# downloading from a socket or parsing a file.
class ProgressFrame < Wx::Frame
  STEPS = 20
  def initialize
    super(nil, :title => 'Threading demo')
    @gauges = []
    panel = Wx::Panel.new(self)
    sizer = Wx::BoxSizer.new(Wx::VERTICAL)
    # show ten gauges
    10.times do 
      gauge = Wx::Gauge.new(panel, :range => STEPS)
      # For each gauge, start a new thread in which the task runs
      Thread.new do 
        # The long-running task
        STEPS.times do | i |
          sleep rand(100) / 50.0
          # Update the main GUI
          gauge.value = i + 1
        end
      end
      @gauges << gauge
      sizer.add(gauge, 0, Wx::GROW|Wx::ALL, 2)
    end
    panel.sizer = sizer
    sizer.fit(panel)
  end
end

# This app class creates a frame, and, importantly, a timer to allow
class GaugeApp < Wx::App
  # Get a guaranteed-unique id
  THREAD_TIMER_ID = Wx::ID_HIGHEST + 1
  def on_init
    # Create a global application timer that passes control to other
    # ruby threads. The timer will run every 1/40 second (25ms). Higher
    # values will make the other threads run more often, but will
    # eventually degrade the responsiveness of the GUI.
    Wx::Timer.every(25) { Thread.pass }
    prog = ProgressFrame.new
    prog.show
  end
end

GaugeApp.new.main_loop
