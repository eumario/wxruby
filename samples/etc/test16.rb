
require 'wxruby'
include Wx

ID_SPIN = 1000

class StaticBitmapDlg < Dialog
  def initialize
    super(nil, -1, "StaticBitmapDialog", DEFAULT_POSITION, Size.new(200, 150))

    staticBitmap = StaticBitmap.new(self, -1, Bitmap.new("books.bmp",BITMAP_TYPE_BMP))

    dlgSizer = BoxSizer.new(HORIZONTAL)
    dlgSizer.add(staticBitmap, 1, ALIGN_CENTER)
    set_sizer(dlgSizer)
    set_auto_layout(TRUE)
    layout()

    evt_close {onClose}
  end

  def onClose
     destroy()
	get_app.exit_main_loop
  end
end


class RbApp < App
  def on_init
    dlg = StaticBitmapDlg.new
    dlg.show_modal
  end

end

a = RbApp.new
a.main_loop
