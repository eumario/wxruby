
require 'wxruby'
include Wx

ID_RADIOBUTTON_1 = 1000
ID_RADIOBUTTON_2 = 1001
ID_RADIOBUTTON_3 = 1002

ID_RADIOBOX = 1000

class RadiobuttonDlg < Dialog
  def initialize
    super(nil, -1, "RadiobuttonDialog", DEFAULT_POSITION, Size.new(385, 185))

    @m_pRadiobutton1 = RadioButton.new(self, ID_RADIOBUTTON_1, "ABS", DEFAULT_POSITION, DEFAULT_SIZE, RB_GROUP)
    @m_pRadiobutton2 = RadioButton.new(self, ID_RADIOBUTTON_2, "Airbag")
    @m_pRadiobutton3 = RadioButton.new(self, ID_RADIOBUTTON_3, "Air Conditioning")

    dlgSizer = BoxSizer.new(HORIZONTAL)
    radioButtonSizer = BoxSizer.new(VERTICAL)
    radioButtonSizer.add(@m_pRadiobutton1)
    radioButtonSizer.add(@m_pRadiobutton2)
    radioButtonSizer.add(@m_pRadiobutton3)
    dlgSizer.add(radioButtonSizer, 1, GROW)
    set_sizer(dlgSizer)
    set_auto_layout(TRUE)
    layout()

    evt_radiobutton(ID_RADIOBUTTON_1) {|event| onRadioButton(event) }
    evt_radiobutton(ID_RADIOBUTTON_2) {|event| onRadioButton(event) }
    evt_radiobutton(ID_RADIOBUTTON_3) {|event| onRadioButton(event) }
    evt_close {onClose}
  end

  def onRadioButton(event)
    current = nil
    case event.get_id
      when ID_RADIOBUTTON_1
         current = @m_pRadiobutton1
      when ID_RADIOBUTTON_2
         current = @m_pRadiobutton2
      when ID_RADIOBUTTON_3
         current = @m_pRadiobutton3
    end
    if current != nil
      set_title("You've selected " + current.get_label)
    end
  end

  def onClose
     destroy()
  end
end

class RbApp < App
  def on_init
    dlg = RadiobuttonDlg.new
    set_top_window(dlg)
    dlg.show(TRUE)
  end

end

a = RbApp.new
a.main_loop()
