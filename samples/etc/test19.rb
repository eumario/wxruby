
require 'wxruby'
include Wx

ID_SPIN = 1000

class StaticTextDlg < Dialog
  def initialize
    super(nil, -1, "StaticTextDialog", DEFAULT_POSITION, Size.new(200, 150))

    staticText = StaticText.new(self,  -1, "This is line 1\nThis is line 2")

    dlgSizer = BoxSizer.new(HORIZONTAL)
    dlgSizer.add(staticText, 1, ALIGN_CENTER)
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
    dlg = StaticTextDlg.new
    dlg.show_modal
  end

end

a = RbApp.new
a.main_loop
