#!/usr/bin/env ruby
# wxRuby2 Sample Code. Copyright (c) 2004-2008 wxRuby development team
# Freely reusable code: see SAMPLES-LICENSE.TXT for details

begin
  require 'rubygems'
  require 'wx'
rescue LoadError
  require 'wx'
end

# GridTableBase is an alternative way to provide data to a Wx::Grid. A
# subclass of Wx::GridTableBase is created which is reqiured to provide
# methods to report the total size of the Grid in rows and columns, and
# the contents and style of individual cells.
# 
# Then, when creating the Grid, instead of calling create_grid and
# set_value to populate it, the GridTableBase-derived class is
# associated with the Grid, and provides these functions (see below)
# 
# This approach is typically useful for dealing with very large sets of
# data, as each cell's value is only requested as it becomes visible.v
class MyGridTable < Wx::GridTableBase
  attr_reader :cols, :rows
  def initialize(rows, cols)
    super()
    @rows = rows
    @cols = cols
    @val = 'a'
  end

  # Firstly, a GridTableBase must indicate the size of the grid in
  # terms of rows ...
  def get_number_rows
    @rows
  end

  # ... and columns
  def get_number_cols
    @cols
  end

  # Most importantly, it should be able to return any given cell's
  # contents, given its row and column reference
  def get_value(row, col)
    "#{@val} - #{row}"
  end 

  # It should also return the attributes that should apply to any given
  # cell; this example give alternate rows red text letters
  def get_attr(row, col, attr_kind)
    attr = Wx::GridCellAttr.new
    if (row % 2).zero?
      attr.text_colour = Wx::RED
    end
    attr
  end

  # It should indicate whether any given cell is empty
  def is_empty_cell(row, col)
    false
  end

  # It may also provide labels for the columns and rows
  def get_col_label_value(col)
    "Col: #{col}"
  end

  # If the Grid is to support write as well as read operations,
  # set_value should also be implemented. In this case, the change is
  # merely echoed back and doesn't alter the underlying value; a real
  # implementation could, for example, write back to a database
  def set_value(x, y, val)
    puts "Changing the value of cell (#{x}, #{y}) to '#{val}'"
  end
end

# A derivative class illustrating that it is possible to change
# parameters of the GridTable and have the main control update.
class MyMutableGridTable < MyGridTable
  def increment_value
    @val = @val.succ
  end
end


class GridFrame < Wx::Frame
  def initialize()
    super(nil, :title => 'GridTableBase demo')
    main_sizer = Wx::BoxSizer.new(Wx::VERTICAL)
    # Create a grid and associate an instance of the GridTable as the
    # data provider for the grid
    @grid = Wx::Grid.new(self)
    @grid.table = MyMutableGridTable.new(10, 10)

    main_sizer.add(@grid, 1, Wx::EXPAND|Wx::ALL, 5)

    # Add some buttons that can change the contents
    butt_sizer = Wx::BoxSizer.new(Wx::HORIZONTAL)

    butt_1 = Wx::Button.new(self, :label => "Add row")
    # When resizing the grid to have a new number of rows or columns,
    # need to allocate a new grid table source
    evt_button(butt_1) do
      @grid.table = MyMutableGridTable.new( @grid.table.rows + 1, 
                                            @grid.table.cols)
      @grid.refresh
    end
    butt_sizer.add(butt_1)

    butt_2 = Wx::Button.new(self, :label => "Add column")
    evt_button(butt_2) do
      @grid.table = MyMutableGridTable.new( @grid.table.rows, 
                                            @grid.table.cols + 1)
      @grid.refresh
    end
    butt_sizer.add(butt_2)

    # For other changes, can just change a value in the existing
    # GridTable
    butt_3 = Wx::Button.new(self, :label => "Increment letter")
    evt_button(butt_3) do
      @grid.table.increment_value
      @grid.refresh
    end
    butt_sizer.add(butt_3)
    
    main_sizer.add(butt_sizer, 0, Wx::EXPAND|Wx::ALL, 5)
    self.sizer = main_sizer
  end
end

Wx::App.run do 
  GridFrame.new.show
end

