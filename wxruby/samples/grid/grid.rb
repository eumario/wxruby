# Translated from:
# http://www.lpthe.jussieu.fr/~zeitlin/wxWindows/docs/wxwin516.htm#topic974

require 'wxruby'

class MyFrame < Wx::Frame

  def initialize(parent, id = -1, title = "MyFrame", 
                 pos   = Wx::DEFAULT_POSITION,
                 size  = Wx::DEFAULT_SIZE,
                 style = Wx::DEFAULT_FRAME_STYLE)

    super(parent, id, title, pos, size, style)

    create_status_bar()
    set_status_text(Wx::VERSION_STRING)

    panel = Wx::Panel.new(self)
    
    make_grid(panel) 
    
  end

  def make_grid(panel)
  
      # Create a wxGrid object
      @grid = Wx::Grid.new(panel, :grid.id, Wx::Point.new(10,10),
                                        Wx::Size.new(925,275))

      # Then we call CreateGrid to set the dimensions of the grid
      # (11 rows and 12 columns in this example)
      @grid.create_grid( 11, 12 )

      # We can set the sizes of individual rows and columns
      # in pixels, and the label value string
      @grid.set_row_size( 0, 60 )
      @grid.set_row_label_value( 0, "Row1" )
      @grid.set_row_label_alignment(Wx::ALIGN_CENTRE, Wx::ALIGN_CENTRE)
            
      @grid.set_col_size( 0, 120 )
      @grid.set_col_label_value( 0, "Col1" )
      @grid.set_col_label_alignment(Wx::ALIGN_CENTRE, Wx::ALIGN_CENTRE)
      
      # And set grid cell contents as strings
      @grid.set_cell_value( 0, 0, "wxGrid is good" )

      # We can specify that some cells are read-only
      @grid.set_cell_value( 0, 3, "This is read-only" )
      @grid.set_read_only( 0, 3 )

      # Colours can be specified for grid cell contents
      @grid.set_cell_value(3, 3, "white on black")
      @grid.set_cell_text_colour(3, 3, Wx::WHITE)
      @grid.set_cell_background_colour(3, 3, Wx::BLACK)

      # We can specify the some cells will store numeric 
      # values rather than strings. Here we set grid column 5 
      # to hold floating point values displayed with width 
      # of 6 and precision of 2
      @grid.set_col_format_float(5, 6, 2)
      @grid.set_cell_value(0, 6, "3.1415")
  end
  
end

class MyApp < Wx::App
    def on_init
        frame = MyFrame.new(nil, -1, "Grid Sample",
                            Wx::Point.new(10, 100),
                            Wx::Size.new(1000,400))
        frame.show(TRUE)
        
        set_top_window(frame)
    end
end

app = MyApp.new
app.main_loop()
