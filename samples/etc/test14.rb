
require 'wxruby'
include Wx

ID_RADIOBOX = 1000

class SliderDlg < Dialog
  def initialize
    super(nil, -1, "SliderDialog", DEFAULT_POSITION, Size.new(200, 150))

    list = [ "ABS", "Airbag", "Air conditioning" ]

    slider = Slider.new(self, -1, 5, 1, 10 , DEFAULT_POSITION, Size.new(80, 30),
                                  SL_HORIZONTAL | SL_AUTOTICKS | SL_LABELS)

    slider.set_line_size(1)
    slider.set_page_size(2)

    dlgSizer = BoxSizer.new(HORIZONTAL)
    sliderSizer = BoxSizer.new(VERTICAL)
    sliderSizer.add(slider, 0, ALIGN_CENTER)
    dlgSizer.add(sliderSizer, 0, ALIGN_CENTER)
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
  def OnInit
    dlg = SliderDlg.new
    set_top_window(dlg)
    dlg.show(TRUE)
  end

end

a = RbApp.new
a.main_loop()
