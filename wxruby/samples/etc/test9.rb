
require 'wxruby'
include Wx

ID_COMBOBOX = 1000

class ComboBoxDlg < Dialog
  def initialize
    super(nil, -1, "ComboBoxDialog", DEFAULT_POSITION, Size.new(285, 185))

    list = [ "ABS", "Airbag", "Air conditioning" ]

    @m_pComboBox = ComboBox.new(self, ID_COMBOBOX, "", DEFAULT_POSITION, DEFAULT_SIZE, list)

    dlgSizer = BoxSizer.new(HORIZONTAL)
    comboboxSizer = BoxSizer.new(VERTICAL)
	@status = StaticText.new(self, -1, "", DEFAULT_POSITION)
	comboboxSizer.add(@status)
    comboboxSizer.add(@m_pComboBox, 1, GROW)
    dlgSizer.add(comboboxSizer, 1, GROW)
    set_sizer(dlgSizer)
    set_auto_layout(TRUE)
    layout()

    evt_combobox(ID_COMBOBOX) {|event| onComboBox(event) }
    evt_close {onClose}
  end

  def onComboBox(event)
    @status.set_label("You've selected item: " + event.get_string())
  end

  def onClose
     destroy()
  end
end


class RbApp < App
  def on_init
    dlg = ComboBoxDlg.new
    set_top_window(dlg)
    dlg.show(TRUE)
  end

end

a = RbApp.new
a.main_loop()
