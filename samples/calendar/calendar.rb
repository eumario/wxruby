require 'wx'
include Wx

require 'date'


Calendar_File_About = 100
Calendar_File_Quit = 101
Calendar_Cal_Monday = 200
Calendar_Cal_Holidays = 201
Calendar_Cal_Special = 202
Calendar_Cal_Month = 203
Calendar_Cal_Year = 204
Calendar_Cal_SeqMonth = 205
Calendar_Cal_SurroundWeeks = 206


def format_date(d)
    return "#{d.year}-#{d.mon}-#{d.day}"
end

class MyCalendar < CalendarCtrl
    def initialize(parent, initial_date, calendar_flags)
        super(parent, -1, 
                    initial_date,
                    DEFAULT_POSITION,
                    DEFAULT_SIZE,
                    calendar_flags | RAISED_BORDER)

        @parent = parent
        @date = initial_date
        @weekday_names = ['Sun', 'Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat']

        id = get_id
        evt_calendar(id) {|event| onCalendar(event)}
        evt_calendar_month(id) {onCalMonthChange}
        evt_calendar_year(id) {onCalYearChange}
        evt_calendar_sel_changed(id) {|event| onCalendarChange(event)}
        evt_calendar_weekday_clicked(id) {|event| onCalendarWeekDayClick(event)}
    end

    def onCalendar(event)
        @date = event.get_date
        log_message("Double-clicked #{format_date(@date)}")
        @parent.set_date(@date)
    end

    def onCalendarChange(event)
        @date = event.get_date
        log_status("Selected date: #{format_date(@date)}")
    end

    def onCalMonthChange
        log_status("Calendar month changed")
    end

    def onCalYearChange
        log_status("Calendar year changed")
    end

    def onCalendarWeekDayClick(event)
        wday = event.get_week_day
        log_status("Clicked on #{@weekday_names[wday]}")
    end
    
    attr_reader :date
end

class MyFrame < Frame
    def initialize(title)
        super(nil, -1, title)

        add_menu_bar
        add_status_bar

        @calendar_flags = CAL_MONDAY_FIRST | CAL_SHOW_HOLIDAYS

        date = DateTime.now
        @m_date = StaticText.new(self, -1, "")
        @m_calendar = MyCalendar.new(self, date, @calendar_flags)

        @sizer = BoxSizer.new(VERTICAL)
        configure_window

    	evt_menu(Calendar_File_Quit) {onQuit}
    	evt_menu(Calendar_File_About) {onAbout}

    	evt_menu(Calendar_Cal_Monday) {|event| onCalMonday(event)}
    	evt_menu(Calendar_Cal_Holidays) {|event| onCalHolidays(event)}
    	evt_menu(Calendar_Cal_Special) {|event| onCalSpecial(event)}

    	evt_menu(Calendar_Cal_Month) {|event| onCalAllowMonth(event)}
    	evt_menu(Calendar_Cal_Year) {|event| onCalAllowYear(event)}

    	evt_menu(Calendar_Cal_SeqMonth) {|event| onCalSeqMonth(event)}
    	evt_menu(Calendar_Cal_SurroundWeeks) {|event| onCalShowSurroundingWeeks(event)}

    	evt_update_ui(Calendar_Cal_Year) {|event| onAllowYearUpdate(event)}
    end
    
    def add_menu_bar
        # create a menu bar
        menuFile = Menu.new("")   # Parameter should NOT be needed!

        menuFile.append(Calendar_File_About, "&About...\tCtrl-A", "Show about dialog")
        menuFile.append_separator()
        menuFile.append(Calendar_File_Quit, "E&xit\tAlt-X", "Quit self program")

        menuCal = Menu.new("")   # Parameter should NOT be needed!
        menuCal.append(Calendar_Cal_Monday,
                        "Monday &first weekday\tCtrl-F",
                        "Toggle between Mon and Sun as the first week day",
                        ITEM_CHECK)
        menuCal.append(Calendar_Cal_Holidays, "Show &holidays\tCtrl-H",
                        "Toggle highlighting the holidays",
                        ITEM_CHECK)
        menuCal.append(Calendar_Cal_Special, "Highlight &special dates\tCtrl-S",
                        "Test custom highlighting",
                        ITEM_CHECK)
        menuCal.append(Calendar_Cal_SurroundWeeks,
                        "Show s&urrounding weeks\tCtrl-W",
                        "Show the neighbouring weeks in the prev/next month",
                        ITEM_CHECK)
        menuCal.append_separator()
        menuCal.append(Calendar_Cal_SeqMonth,
                        "To&ggle month selector style\tCtrl-G",
                        "Use another style for the calendar controls",
                        ITEM_CHECK)
        menuCal.append(Calendar_Cal_Month, "&Month can be changed\tCtrl-M",
                        "Allow changing the month in the calendar",
                        ITEM_CHECK)
        menuCal.append(Calendar_Cal_Year, "&Year can be changed\tCtrl-Y",
                        "Allow changing the year in the calendar",
                        ITEM_CHECK)

        # now append the freshly created menu to the menu bar...
        menuBar = MenuBar.new(0)       # Parameter should NOT be needed!
        menuBar.append(menuFile, "&File")
        menuBar.append(menuCal, "&Calendar")

        menuBar.check(Calendar_Cal_Monday, TRUE)
        menuBar.check(Calendar_Cal_Holidays, TRUE)
        menuBar.check(Calendar_Cal_Month, TRUE)
        menuBar.check(Calendar_Cal_Year, TRUE)

        # ... and attach self menu bar to the frame
        set_menu_bar(menuBar)
    end

    def add_status_bar
        # create a status bar just for fun (by default with 1 pane only)
        create_status_bar
        set_status_text("Welcome to Windows!")
    end
    
    def configure_window
        @sizer.add(@m_calendar, 0)
        @sizer.add(@m_date, 1)
        @sizer.set_size_hints(self)
        layout
        set_sizer(@sizer)
    end
    
    def onQuit
        # TRUE is to force the frame to close
        close(TRUE)
    end

    def onAbout
        message_box("wxRuby CalendarCtrl sample\nby Kevin Smith\n" +
                 "based on the wxWidgets version by Vadim Zeitlin",
                 "About Calendar", OK | ICON_INFORMATION, self)
    end

    def onCalMonday(event)
        enable = get_menu_bar().is_checked(event.get_id())
        toggle_cal_style(enable, CAL_MONDAY_FIRST)
    end

    def onCalHolidays(event)
        enable = get_menu_bar().is_checked(event.get_id())
        @m_calendar.enable_holiday_display(enable)
    end

	def onCalSpecial(event)
        highlight_special(get_menu_bar().is_checked(event.get_id()))
    end

	def onCalAllowMonth(event)
        allow = get_menu_bar().is_checked(event.get_id())
        @m_calendar.enable_month_change(allow)
    end

	def onCalAllowYear(event)
        allow = get_menu_bar().is_checked(event.get_id())
        @m_calendar.enable_year_change(allow)
    end

	def onCalSeqMonth(event)
        allow = get_menu_bar().is_checked(event.get_id())
        toggle_cal_style(allow, CAL_SEQUENTIAL_MONTH_SELECTION)
    end

	def onCalShowSurroundingWeeks(event)
        allow = get_menu_bar().is_checked(event.get_id())
        toggle_cal_style(allow, CAL_SHOW_SURROUNDING_WEEKS)
    end

	def onAllowYearUpdate(event)
        event.enable( get_menu_bar().is_checked(Calendar_Cal_Month))
    end

    def toggle_cal_style(on,flag)
        style = @m_calendar.get_window_style_flag
        date = @m_calendar.date
        @sizer.remove(@m_calendar)
        @sizer.remove(@m_date)
        @m_calendar.destroy
        if  on
            style |= flag
        else
            style &= ~flag
        end
        @m_calendar = MyCalendar.new(self, date, style)
        @sizer.add(@m_calendar, 0)
        @sizer.add(@m_date, 1)
        layout
    end

    def highlight_special(on)
        if on
            attrRedCircle = CalendarDateAttr.new(CAL_BORDER_ROUND, RED)
            attrGreenSquare = CalendarDateAttr.new(CAL_BORDER_SQUARE, GREEN)
#            attrHeaderLike = CalendarDateAttr.new(BLUE, LIGHT_GREY)

            @m_calendar.set_attr(17, attrRedCircle)
            @m_calendar.set_attr(29, attrGreenSquare)
#            @m_calendar.set_attr(13, attrHeaderLike)
        else
            @m_calendar.reset_attr(17)
            @m_calendar.reset_attr(29)
            @m_calendar.reset_attr(13)
        end
        @m_calendar.refresh()
    end

    def set_date(d)
        @m_date.set_label(format_date(d))
    end
    
end


class RbApp < App
    def on_init()
  	    frame = MyFrame.new("Calendar Windows sample")
	    frame.show(TRUE)
    end
end

a = RbApp.new
a.main_loop()
