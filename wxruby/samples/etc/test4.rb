
require 'wxruby'
include Wx

ID_BUTTON_SELECT = 1000

class ButtonDlg < Dialog
  def initialize
    super(nil, -1, "ButtonDialog", DEFAULT_POSITION, Size.new(150, 150))
    @m_pButton = BitmapButton.new(self, ID_BUTTON_SELECT, Bitmap.new("books.bmp",BITMAP_TYPE_BMP))

    # Setting the button in the middle of the dialog.
    dlgSizer = BoxSizer.new(HORIZONTAL)
    buttonSizer = BoxSizer.new(VERTICAL)
    buttonSizer.add(@m_pButton, 0, ALIGN_CENTER)
    dlgSizer.add(buttonSizer, 1, ALIGN_CENTER)
    set_sizer(dlgSizer)
    set_auto_layout(TRUE)
    layout()
    evt_button(ID_BUTTON_SELECT) {onButtonSelect}
    evt_close {onClose}
  end

  def onButtonSelect
    message_box("You clicked my button")
  end

  def onClose
     destroy()
	 get_app.exit_main_loop
  end
end


class RbApp < App
  def on_init
    dlg = ButtonDlg.new
    dlg.show_modal
  end

end

a = RbApp.new
a.main_loop()
