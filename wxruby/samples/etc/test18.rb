
require 'wxruby'
include Wx

ID_SPIN = 1000

class StaticLineDlg < Dialog
  def initialize
    super(nil, -1, "StaticLineDialog", DEFAULT_POSITION, Size.new(200, 150))

    staticLine1 = StaticLine.new(self, -1);

    dlgSizer = BoxSizer.new(HORIZONTAL)
    dlgSizer.add(staticLine1, 1, ALIGN_CENTER)
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
  def OnInit
    dlg = StaticLineDlg.new
    dlg.show_modal
  end

end

a = RbApp.new
a.main_loop
