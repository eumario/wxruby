
require 'wxruby'
include Wx

ID_RADIOBOX = 1000

class RadioBoxDlg < Dialog
  def initialize
    super(nil, -1, "RadioboxDialog", DEFAULT_POSITION, Size.new(185, 185))

    list = [ "ABS", "Airbag", "Air conditioning" ]

    @m_pRadioBox = RadioBox.new(self, ID_RADIOBOX, " Car options ", DEFAULT_POSITION, DEFAULT_SIZE, list ,1, RA_SPECIFY_COLS)

    dlgSizer = BoxSizer.new(HORIZONTAL)
    radioboxSizer = BoxSizer.new(VERTICAL)
    radioboxSizer.add(@m_pRadioBox, 1, GROW)
    dlgSizer.add(radioboxSizer, 1, GROW)
    set_sizer(dlgSizer)
    set_auto_layout(TRUE)
    layout()

    evt_radiobox(ID_RADIOBOX) {onRadiobox}
    evt_close {onClose}
  end

  def onRadiobox
    selection = @m_pRadioBox.get_string_selection
    message_box("You selected " + selection)
  end

  def onClose
     destroy()
  end
end


class RbApp < App
  def OnInit
    dlg = RadioBoxDlg.new
    set_top_window(dlg)
    dlg.show(TRUE)
  end

end

a = RbApp.new
a.main_loop()
