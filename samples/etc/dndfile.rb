# Example by Gergely Kontra
require 'wxruby'

class MyFileDropTarget < Wx::FileDropTarget
  def initialize list
    super()
    @list=list
  end
  def on_drop_files x,y,files
    for f in files
      @list.insert_item @list.get_item_count, f
    end
    return true
  end
end

class MyListCtrl < Wx::ListCtrl
  def initialize parent
    super parent,-1,Wx::DEFAULT_POSITION,Wx::DEFAULT_SIZE,Wx::LC_LIST
    set_drop_target MyFileDropTarget.new(self)
  end
end

class MyFrame < Wx::Frame
  def initialize title
    super nil, -1, title
    MyListCtrl.new self
  end
end

class DndFileApp < Wx::App
  def on_init
    frame = MyFrame.new "I accept files - Drop files on me!!!"
	frame.show
  end
end

a = DndFileApp.new
a.main_loop()
