# A data-oriented editable table control.
class Wx::Grid
  # The following extensions are all to prevent crashes associated with
  # garbage collection of Grid-related classes; they do not extend the
  # public functionality of the class in any way. 
  # 
  # The GridCellRenderers and GridCellEditors pose a problem for ruby's
  # GC, in that Wx makes them owned by the grid once they have been set
  # for a cell or group of cells. However, because they are SWIG
  # directors we cannot allow the ruby object they are originally
  # associated with to be swept by GC.
  #
  # The code below stores Ruby redefines all methods that may
  # potentially set an Editor or Renderer, and stores a reference to
  # it in an instance variable, so they are not disposed of up when GC sweeps.
  wx_init = self.instance_method(:initialize)
  define_method(:initialize) do | *args |
    wx_init.bind(self).call(*args)
    @__default_editor   = nil
    @__default_renderer = nil

    @__cell_editors   = []
    @__cell_renderers = []

    @__col_renderers = []
    @__col_editors   = []
    @__row_renderers = []
    @__row_editors   = []
  end
  
  # store default editor
  wx_set_default_editor = self.instance_method(:set_default_editor)
  define_method(:set_default_editor) do | editr |
    wx_set_default_editor.bind(self).call(editr)
    @__default_editor = editr
  end

  # store default renderer
  wx_set_default_renderer = self.instance_method(:set_default_renderer)
  define_method(:set_default_renderer) do | rendr |
    wx_set_default_renderer.bind(self).call(rendr)
    @__default_renderer = rendr
   end

  # store cell editors
  wx_set_cell_editor = self.instance_method(:set_cell_editor)
  define_method(:set_cell_editor) do | row, col, editr |
    wx_set_cell_editor.bind(self).call(row, col, editr)
    @__cell_editors[row] ||= []
    @__cell_editors[row][col] = editr
   end

  # store cell renderer
  wx_set_cell_renderer = self.instance_method(:set_cell_renderer)
  define_method(:set_cell_renderer) do | row, col, rendr |
    wx_set_cell_renderer.bind(self).call(row, col, rendr)
    @__cell_renderers[row] ||= []
    @__cell_renderers[row][col] = rendr
  end

  wx_set_col_attr = self.instance_method(:set_col_attr)
  define_method(:set_col_attr) do | col, attr |
    wx_set_col_attr.bind(self).call(col, attr)
    if attr.has_editor
      @__col_editors[col] = attr.get_editor(self, 0, col)
    end
    if attr.has_renderer
      @__col_renderers[col] = attr.get_renderer(self, 0, col)
    end
  end  

  wx_set_row_attr = self.instance_method(:set_row_attr)
  define_method(:set_row_attr) do | row, attr |
    wx_set_row_attr.bind(self).call(row, attr)
    if attr.has_editor
      @__row_editors[row] = attr.get_editor(self, row, 0)
    end

    if attr.has_renderer
      @__row_renderers[row] = attr.get_renderer(self, row, 0)
    end
  end  

  # This and the following methods do a bit of book-keeping - as rows
  # and columns are deleted and inserted, the position of the columns
  # and rows with stored editors and renderers may move.
  wx_insert_rows = self.instance_method(:insert_rows)
  define_method(:insert_rows) do | pos, num, update |
    wx_insert_rows.bind(self).call(pos, num, update)
    num.times { @__row_editors.insert(pos, nil) }
    num.times { @__row_renderers.insert(pos, nil) }
    num.times { @__cell_editors.insert(pos, []) }
    num.times { @__cell_renderers.insert(pos, []) }
  end

  wx_insert_cols = self.instance_method(:insert_cols)
  define_method(:insert_cols) do | pos, num, update |
    wx_insert_cols.bind(self).call(pos, num, update)
    num.times { @__col_editors.insert(pos, nil) }
    num.times { @__col_renderers.insert(pos, nil) }
    num.times do
      @__cell_editors.map { | col | col.insert(pos, []) if col }
    end
    num.times do
      @__cell_renderers.map { | col | col.insert(pos, []) if col }
    end
  end

  wx_delete_rows = self.instance_method(:delete_rows)
  define_method(:delete_rows) do | pos, num, update |
    wx_delete_rows.bind(self).call(pos, num, update)
    @__row_editors.slice!(pos, num)
    @__row_renderers.slice!(pos, num)
    @__cell_editors.slice!(pos, num)
    @__cell_renderers.slice!(pos, num)
  end
 
  wx_delete_cols = self.instance_method(:delete_cols)
  define_method(:delete_cols) do | pos, num, update |
    wx_delete_cols.bind(self).call(pos, num, update)
    @__col_editors.slice!(pos, num)
    @__col_renderers.slice!(pos, num)
    num.times do
      @__cell_editors.map { | col | col.slice!(pos, num) if col }
    end
    num.times do
      @__cell_renderers.map { | col | col.slice!(pos, num) if col }
    end
  end
end
