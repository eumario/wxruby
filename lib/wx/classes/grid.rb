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
  # For the default Grid editors and renderers, and for those attached
  # to individual cells, marking is done in C++ in the SWIG wrapping, in
  # swig/classes/Grid.i. However, because of deficiencies in the
  # wxWidgets API, it seems the only way to deal with renderers and
  # editors associated with columns and rows is to handle them in Ruby.
  # The code below stores Ruby references to the editors and renderers
  # so they are picked up when GC sweeps.
  wx_init = self.instance_method(:initialize)
  define_method(:initialize) do | *args |
    wx_init.bind(self).call(*args)
    @__col_renderers = []
    @__col_editors   = []
    @__row_renderers = []
    @__row_editors   = []
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
  define_method(:insert_rows) do | pos, num |
    gc_was_disabled = GC.disable
    wx_insert_rows.bind(self).call(pos, num)
    num.times { @__row_editors.insert(pos, nil) }
    num.times { @__row_renderers.insert(pos, nil) }
    GC.enable unless gc_was_disabled
  end

  wx_insert_cols = self.instance_method(:insert_cols)
  define_method(:insert_cols) do | pos, num |
    gc_was_disabled = GC.disable
    wx_insert_cols.bind(self).call(pos, num)
    num.times { @__col_editors.insert(pos, nil) }
    num.times { @__col_renderers.insert(pos, nil) }
    GC.enable unless gc_was_disabled
  end

  wx_delete_rows = self.instance_method(:delete_rows)
  define_method(:delete_rows) do | pos, num |
    gc_was_disabled = GC.disable
    wx_delete_rows.bind(self).call(pos, num)
    @__row_editors.slice!(pos, num)
    @__row_renderers.slice!(pos, num)
    GC.enable unless gc_was_disabled
  end
 
  wx_delete_cols = self.instance_method(:delete_cols)
  define_method(:delete_cols) do | pos, num |
    gc_was_disabled = GC.disable
    wx_delete_cols.bind(self).call(pos, num)
    @__col_editors.slice!(pos, num)
    @__col_renderers.slice!(pos, num)
    GC.enable unless gc_was_disabled
  end
end
