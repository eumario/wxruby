
require 'wxruby'
include Wx

ID_SPIN = 1000

class StaticBoxDlg < Dialog
  def initialize
    super(nil, -1, "StaticBoxDialog", DEFAULT_POSITION, Size.new(200, 150))

    staticBox1 = StaticBox.new(self, -1, "Box 1");
    staticBox2 = StaticBox.new(self, -1, "Box 2");

    dlgSizer = StaticBoxSizer.new(staticBox1,HORIZONTAL)
    staticBoxSizer = StaticBoxSizer.new(staticBox2, VERTICAL);
    dlgSizer.add(staticBoxSizer, 1, GROW)
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
    dlg = StaticBoxDlg.new
    dlg.show_modal
  end

end

a = RbApp.new
a.main_loop
