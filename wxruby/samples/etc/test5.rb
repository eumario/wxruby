
require 'wxruby'
include Wx

ID_CALENDAR = 1000

class CalendarDlg < Dialog
  def initialize
    super(nil, -1, "CalendarDialog", DEFAULT_POSITION, Size.new(285, 185))
    @m_pCalendar = CalendarCtrl.new(self, ID_CALENDAR, DEFAULT_DATE_TIME,
                                     DEFAULT_POSITION, DEFAULT_SIZE,
                                     CAL_MONDAY_FIRST |
                                     CAL_SHOW_HOLIDAYS |
                                     RAISED_BORDER)

    dlgSizer = BoxSizer.new(HORIZONTAL)
    calendarSizer = BoxSizer.new(VERTICAL)
    calendarSizer.add(@m_pCalendar, 1, GROW)
    dlgSizer.add(calendarSizer, 1, GROW)
    set_sizer(dlgSizer)
    set_auto_layout(TRUE)
    layout()

    evt_calendar(ID_CALENDAR) {|event| onCalendar(event) }
    evt_close {onClose}
  end

  def onCalendar(event)
    day = event.get_date.get_day
    on = false
    attr = @m_pCalendar.get_attr(day)
    if attr != nil
      if attr.get_background_colour == RED
         on = true
      end
    end
    newAttr = CalendarDateAttr.new(BLACK, on ? WHITE : RED)
    @m_pCalendar.set_attr(day, newAttr)
  end

  def onClose
     destroy()
  end
end

class RbApp < App
  def on_init
    dlg = CalendarDlg.new
    set_top_window(dlg)
    dlg.show
  end

end

a = RbApp.new
a.main_loop()
