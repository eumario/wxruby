
require 'wxruby'
include Wx

ID_SPIN = 1000

class TextDlg < Dialog
  def initialize
    super(nil, -1, "TextDialog", DEFAULT_POSITION, Size.new(200, 150))

    text = TextCtrl.new(self,  -1, "",
                                    DEFAULT_POSITION, DEFAULT_SIZE,
                                    TE_MULTILINE)

    text << "This is line 1"

    dlgSizer = BoxSizer.new(HORIZONTAL)
    dlgSizer.add(text, 1, GROW)
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
    dlg = TextDlg.new
    dlg.show_modal
  end

end

a = RbApp.new
a.main_loop
