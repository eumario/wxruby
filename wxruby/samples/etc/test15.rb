
require 'wxruby'
include Wx

ID_SPIN = 1000

class SpinDlg < Dialog
  def initialize
    super(nil, -1, "SpinDialog", DEFAULT_POSITION, Size.new(200, 150))

    spin = SpinCtrl.new(self, ID_SPIN, "", DEFAULT_POSITION, DEFAULT_SIZE,
                                  SP_ARROW_KEYS | SP_WRAP, 0, 10)

    dlgSizer = BoxSizer.new(HORIZONTAL)
    spinSizer = BoxSizer.new(VERTICAL)
    spinSizer.add(spin, 0, ALIGN_CENTER)
    dlgSizer.add(spinSizer, 0, ALIGN_CENTER)
    set_sizer(dlgSizer)
    set_auto_layout(TRUE)
    layout()

    evt_close {onClose}
  end

  def onClose
     destroy()
  end
end


class RbApp < App
  def on_init
    dlg = SpinDlg.new
    set_top_window(dlg)
    dlg.show(TRUE)
  end

end

a = RbApp.new
a.main_loop()
