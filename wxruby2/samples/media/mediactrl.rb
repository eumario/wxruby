#!/usr/bin/env ruby
# wxRuby2 Sample Code. Copyright (c) 2004-2008 wxRuby development team
# Freely reusable code: see SAMPLES-LICENSE.TXT for details
begin
  require 'rubygems' 
rescue LoadError
end
require 'wx'

# This sample demonstrates the use of Wx::MediaCtrl, which can be used
# to playback sounds or movies using a platform-native player.
class MediaPanel < Wx::Panel
  def initialize(parent)
    super(parent, :style => Wx::TAB_TRAVERSAL|Wx::CLIP_CHILDREN)

    # The actual media player control
    @mc = Wx::MediaCtrl.new(self)

    evt_media_loaded @mc,:on_media_loaded

    # Some buttons to control playback
    @btn_load = Wx::Button.new(self, :label => "Load File")
    evt_button @btn_load,:on_load_file

    @btn_play = Wx::Button.new(self, :label => "Play")
    evt_button @btn_play, :on_play
    @btn_play.disable

    @btn_pause = Wx::Button.new(self, :label => "Pause")
    evt_button @btn_pause, :on_pause
    @btn_pause.disable

    @btn_stop = Wx::Button.new(self, :label => "Stop")
    evt_button @btn_stop,:on_stop
    @btn_stop.disable

    @slider = Wx::Slider.new(self, :min_value => 0, :max_value => 1)
    @slider.min_size = [150, -1]
    evt_slider @slider, :on_seek
    
    @st_size = Wx::StaticText.new(self, :label => "", :size => [100, -1])
    @st_len  = Wx::StaticText.new(self, :label => "", :size => [100, -1])
    @st_pos  = Wx::StaticText.new(self, :label => "", :size => [100, -1])
    
    # layout the panel
    sizer = Wx::BoxSizer.new(Wx::VERTICAL)

    sizer.add(@mc, 1, Wx::EXPAND|Wx::ALL, 5)
    sizer.add(@slider, 0, Wx::EXPAND|Wx::ALL, 5)

    # For the playback text
    secs_sizer = Wx::BoxSizer.new(Wx::HORIZONTAL)
    secs_sizer.add(@st_pos, 0, Wx::ALL, 2)
    secs_sizer.add(@st_len, 0, Wx::ALL, 2)
    secs_sizer.add(@st_size, 0, Wx::ALL, 2)
    sizer.add(secs_sizer, 0, Wx::ALIGN_RIGHT|Wx::ALL, 0)

    btn_sizer = Wx::BoxSizer.new(Wx::HORIZONTAL)
    btn_sizer.add(@btn_load, 1, Wx::ALL, 2)
    btn_sizer.add(@btn_play, 1, Wx::ALL, 2)
    btn_sizer.add(@btn_pause, 1, Wx::ALL, 2)
    btn_sizer.add(@btn_stop, 1, Wx::ALL, 2)
    sizer.add(btn_sizer, 0, Wx::ALL, 5)

    self.sizer = sizer

    @timer = Wx::Timer.new(self,101)
    evt_timer(101,:on_timer)
    @timer.start(100)
  end

  # Update the position indicator in seconds
  def on_timer(evt)
    offset = @mc.tell
    # Will be -1 if nothing is loaded
    if offset >= 0
      @slider.value = offset
      offset_secs = offset / 1000 
      @st_pos.label = "%i:%02d" % [ offset_secs / 60, offset_secs % 60 ]
    else
      @st_pos.label = ""
    end
  end

  # Actually load a file into the mediactrl
  def do_load_file(path)
    @btn_play.disable
    unless @mc.load(path)
      Wx::message_box("Unable to load file", "ERROR",
                       Wx::ICON_ERROR|Wx::OK)
    else
      
    end
  end
  
  MEDIA_FILE_WILDCARD = "MP3 Files (*.mp3)|*.mp3|Avi Files (*.avi)|*.avi"
  # Load a media file from disk
  def on_load_file(evt)
    dlg = Wx::FileDialog.new( self, 
                              :message  => "Choose a media file",
                              :wildcard => MEDIA_FILE_WILDCARD, 
                              :style    => Wx::OPEN)
    if dlg.show_modal == Wx::ID_OK
      do_load_file(dlg.path)
    end
  end

  # Move the media to a position in the file, using the slider
  def on_seek(evt)
    offset = @slider.value
    @mc.seek(offset)
  end

  # Set up the initial size for the move
  def on_media_loaded(evt)
    # Readjust to the original size of the video
    @mc.set_initial_size

    # Enable the control buttons
    @btn_play.enable
    @btn_pause.enable
    @btn_stop.enable

    # Update the length and position text indicators with the media's
    # time length, shown as minutes and seconds
    len_secs = @mc.length / 1000
    @st_len.label = "%i:%02d" % [ len_secs / 60, len_secs % 60 ]

    # Set the seek slider
    @slider.set_range(0, @mc.length)

    # Refresh the layout
    sizer.layout
  end

  # Stop the playback
  def on_stop(evt)
    @mc.stop
  end

  # Pause the playback
  def on_pause(evt)
    @mc.pause
  end

  # Start the playback
  def on_play(evt)
    if not @mc.play
      Wx::MessageBox("unable to play media","ERROR",Wx::ICON_ERROR|Wx::OK)
    else
      @mc.set_initial_size
      sizer.layout
    end
  end
end

class MediaFrame<Wx::Frame
  def initialize()
    super(nil,:title=>"MediaCtrl test",:size=>[700,700])
    win = MediaPanel.new(self)
  end
end

# Actually run the app
Wx::App.run do 
  MediaFrame.new.show
end
