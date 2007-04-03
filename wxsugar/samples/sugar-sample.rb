require 'wx'
require 'wx_sugar/all'

class MyButton < Wx::Button
  def on_button()
    p "clicked my button"
  end
end

class SugaryFrame < Wx::Frame
  def initialize(*args)
    super
    # binds evt_close automatically to self#on_close
    listen(:close)

    arrange_vertically(:padding => 5)
    # This panel and contents should expand to fit
    add( Wx::Panel, :proportion => 1 ) do | panel |
      # a text control
      panel.background_colour = Wx::Colour.new(200, 150, 100) 
      tx = panel.add( Wx::TextCtrl[ :value => 'initial value', 
                               :style => Wx::TE_MULTILINE,
                               :size  => [200, 300]  ] )
      # test if a style is applied to a control
      tx.has_style?(Wx::TE_MULTILINE) # true
      tx.has_style?(Wx::TE_READONLY) # false
    end

    # use a nested grid sizer to arrange bottom area
    arrange_grid( :cols => 2, :rows => 2, :proportion => 0,
                  :vgap => 2, :minsize => true, :padding => 1 ) do
      # a custom button subclass
      add( MyButton[ :label => 'baz' ], :proportion => 1 ) do | button |
        listen(:button, button, :on_baz_button)
      end

      # a drop down
      choices = add( Wx::Choice[ :choices => %w[ nasty nice salty ] ], 
                     :padding => 4 )
      choices << 'sweet'
      # access client data via a collection
      choices.data[3] = Object.new
      # iterate over a dropdown's content simply
      choices.each { | i | nil }
      # iterate over a dropdown's full content
      choices.each { | i, str, data | nil }

      # another button
      add( Wx::Button[ :label => 'foo' ] ) do | button |
        # handle using a method
        listen(:button, button, :on_foo_button)
        # handle using a block
        listen(:button, button) { | e | p "clicked in a block"; e.skip }
      end
      add( Wx::TextCtrl[ :value => 'foo' ], :align => 'right' )
    end
  end

  def on_close(event)
    puts "CLOSING"
    event.skip()
  end

  def on_button(event)
    p event
  end

  def on_foo_button(e)
    p "FOO"
    e.skip()
  end

  # you aren't required to receive the event
  def on_baz_button()
    p "baZ"
  end
end

class SugaryApp < Wx::App
  def on_init
    frame = SugaryFrame.new( nil, :title => "Arranger Application" )
    frame.show()
  end
end

SugaryApp.new.main_loop()
