
require 'wxruby'
include Wx

ID_CHECKBOX = 1000

class CheckBoxDlg < Dialog
  def initialize
    super(nil, -1, "CheckBoxDialog", DEFAULT_POSITION, Size.new(150, 150))

    @m_pCheckBox = CheckBox.new(self, ID_CHECKBOX, "Check Me")

    dlgSizer = BoxSizer.new(HORIZONTAL)
    checkBoxSizer = BoxSizer.new(VERTICAL)
    checkBoxSizer.add(@m_pCheckBox, 0, ALIGN_CENTER)
    dlgSizer.add(checkBoxSizer, 1, ALIGN_CENTER)
    set_sizer(dlgSizer)
    set_auto_layout(TRUE)
    layout()

    evt_checkbox(ID_CHECKBOX) {|event| onCheck(event)}
    evt_close {onClose}
  end

  def onCheck(event)
    if ( event.is_checked() )
      message_box("You checked")
    else
      message_box("You unchecked!")
    end
  end

  def onClose
     destroy()
  end
end


class RbApp < App
  def on_init
    dlg = CheckBoxDlg.new
    set_top_window(dlg)
    dlg.show(TRUE)
  end

end

a = RbApp.new
a.main_loop()
