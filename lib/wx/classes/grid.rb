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
  # So we keep track of editors and renderers that have been set for
  # particular cells or as the default within hashes that are instance
  # variables of the Grid object. This means that as long as the Grid is
  # not garbage collected, the associated renderers will be marked in
  # the GC mark phase and so preserved.
  #
  # For most classes we handle GC on the SWIG side but honestly it'd be
  # a whole lot more messy coding... 
  wx_init = self.instance_method(:initialize)
  define_method(:initialize) do | *args |
    wx_init.bind(self).call(*args)

    @__renderers = {}
    @__editors   = {}
  end

  wx_set_cell_renderer = self.instance_method(:set_cell_renderer)
  define_method(:set_cell_renderer) do | row, col, rendr |
    wx_set_cell_renderer.bind(self).call(row, col, rendr)
    @__renderers[ [row, col] ] = rendr
  end

  wx_set_default_renderer = self.instance_method(:set_default_renderer)
  define_method(:set_default_renderer) do | rendr |
    wx_set_default_renderer.bind(self).call(rendr)
    @__renderers[ nil ] = rendr
  end

  wx_set_cell_editor = self.instance_method(:set_cell_editor)
  define_method(:set_cell_editor) do | row, col, editr |
    wx_set_cell_editor.bind(self).call(row, col, editr)
    @__editors[ [row, col] ] = editr
  end

  wx_set_default_editor = self.instance_method(:set_default_editor)
  define_method(:set_default_editor) do | editr |
    wx_set_default_editor.bind(self).call(editr)
    @__editors[ nil ] = editr
  end
end
