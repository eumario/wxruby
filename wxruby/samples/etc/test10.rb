
require 'wxruby'
include Wx

ID_TIMER = 1000

class GaugeDlg < Dialog
  def initialize
    super(nil, -1, "GaugeDialog", DEFAULT_POSITION, Size.new(185, 185))

    @m_pGauge = Gauge.new(self, -1, 100, DEFAULT_POSITION, Size.new(150, 20), GA_SMOOTH)

    @m_pTimer = Timer.new(self, ID_TIMER)
    @m_pTimer.start(100)

    dlgSizer = BoxSizer.new(HORIZONTAL)
    gaugeSizer = BoxSizer.new(VERTICAL)
    gaugeSizer.add(@m_pGauge, 1, ALIGN_CENTER)
    dlgSizer.add(gaugeSizer, 1, ALIGN_CENTER)
    set_sizer(dlgSizer)
    set_auto_layout(TRUE)
    layout()

    evt_timer(ID_TIMER) {onTimer}
    evt_close {onClose}
  end

  def onTimer
    value = @m_pGauge.get_value
    if value == @m_pGauge.get_range
      @m_pTimer.stop()
	  destroy
    else
      @m_pGauge.set_value(value + 1)
    end
  end

  def onClose
     destroy()
  end
  
 
end

class RbApp < App
  def OnInit
    dlg = GaugeDlg.new
    set_top_window(dlg)
    dlg.show(TRUE)
  end

end

a = RbApp.new
a.main_loop()
