require 'wxruby'
include Wx


Calendar_File_About = 100
Calendar_File_Quit = 101
Calendar_Cal_Monday = 200
Calendar_Cal_Holidays = 201
Calendar_Cal_Special = 202
Calendar_Cal_Month = 203
Calendar_Cal_Year = 204
Calendar_Cal_SeqMonth = 205
Calendar_Cal_SurroundWeeks = 206
Calendar_CalCtrl = 1000


class MyPanel < Panel
    def initialize(frame)
        super(frame, -1)

        set_auto_layout(TRUE)

        date = sprintf("Selected date: %s",
                    DateTime::today().format_iso_date())
        @m_date = StaticText.new(self, -1, date)
        @m_calendar = CalendarCtrl.new(self, Calendar_CalCtrl,
                                        DEFAULT_DATE_TIME,
                                        DEFAULT_POSITION,
                                        DEFAULT_SIZE,
                                        CAL_MONDAY_FIRST |
                                        CAL_SHOW_HOLIDAYS |
                                        RAISED_BORDER)

        c = LayoutConstraints.new
        c.left.same_as(self, LAYOUT_LEFT, 10)
        c.centre_y.same_as(self, LAYOUT_CENTRE_Y)
        c.height.as_is()
        c.width.as_is()

        @m_date.set_constraints(c)

        c = LayoutConstraints.new
        c.left.same_as(@m_date, LAYOUT_RIGHT, 20)
        c.centre_y.same_as(self, LAYOUT_CENTRE_Y)
        c.height.as_is()
        c.width.as_is()

        @m_calendar.set_constraints(c)


        evt_calendar(Calendar_CalCtrl) {|event| onCalendar(event)}
        evt_calendar_month(Calendar_CalCtrl) {onCalMonthChange}
        evt_calendar_year(Calendar_CalCtrl) {onCalYearChange}
        evt_calendar_sel_changed(Calendar_CalCtrl) {|event| onCalendarChange(event)}
        evt_calendar_weekday_clicked(Calendar_CalCtrl) {|event| onCalendarWeekDayClick(event)}

    end

    def onCalendar(event)
        log_message("Selected %s from calendar",
                     event.get_date().format_iso_date())
    end

    def onCalendarChange(event)
        s = sprintf("Selected date: %s", event.get_date().format_iso_date())
        @m_date.set_label(s)
    end

    def onCalMonthChange
        log_status("Calendar month changed")
    end

    def onCalYearChange
        log_status("Calendar year changed")
    end

    def onCalendarWeekDayClick(event)
        log_message("Clicked on %s",
                     DateTime::get_week_day_name(event.get_week_day()))
    end

    def toggle_cal_style(on,flag)
        style = @m_calendar.get_window_style_flag()
        if  on
            style |= flag
        else
            style &= ~flag
        end
        @m_calendar.set_window_style(style)
        @m_calendar.refresh()
    end

    def highlight_special(on)
        if on
            attrRedCircle = CalendarDateAttr.new(CAL_BORDER_ROUND, RED)
            attrGreenSquare = CalendarDateAttr.new(CAL_BORDER_SQUARE, GREEN)
            attrHeaderLike = CalendarDateAttr.new(BLUE, LIGHT_GREY)

            @m_calendar.set_attr(17, attrRedCircle)
            @m_calendar.set_attr(29, attrGreenSquare)
            @m_calendar.set_attr(13, attrHeaderLike)
        else
            @m_calendar.reset_attr(17)
            @m_calendar.reset_attr(29)
            @m_calendar.reset_attr(13)
        end
        @m_calendar.refresh()
    end

    def get_cal()
        @m_calendar
    end

end

class MyFrame < Frame
    def initialize(title,pos,size)
        super(nil, -1, title, pos, size)
        # create a menu bar
        menuFile = Menu.new

        menuFile.append(Calendar_File_About, "&About...\tCtrl-A", "Show about dialog")
        menuFile.append_separator()
        menuFile.append(Calendar_File_Quit, "E&xit\tAlt-X", "Quit self program")

        menuCal = Menu.new
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
        menuBar = MenuBar.new
        menuBar.append(menuFile, "&File")
        menuBar.append(menuCal, "&Calendar")

        menuBar.check(Calendar_Cal_Monday, TRUE)
        menuBar.check(Calendar_Cal_Holidays, TRUE)
        menuBar.check(Calendar_Cal_Month, TRUE)
        menuBar.check(Calendar_Cal_Year, TRUE)

        # ... and attach self menu bar to the frame
        set_menu_bar(menuBar)


        @m_panel = MyPanel.new(self)

        # create a status bar just for fun (by default with 1 pane only)
        create_status_bar(2)
        set_status_text("Welcome to Windows!")

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

    def onQuit
        # TRUE is to force the frame to close
        close(TRUE)
    end

    def onAbout
        message_box("CalendarCtrl sample\n© 2000 Vadim Zeitlin",
                 "About Calendar", OK | ICON_INFORMATION, self)
    end

    def onCalMonday(event)
        enable = get_menu_bar().is_checked(event.get_id())
        @m_panel.toggle_cal_style(enable, CAL_MONDAY_FIRST)
    end

    def onCalHolidays(event)
        enable = get_menu_bar().is_checked(event.get_id())
        @m_panel.get_cal().enable_holiday_display(enable)
    end

	def onCalSpecial(event)
        @m_panel.highlight_special(get_menu_bar().is_checked(event.get_id()))
    end

	def onCalAllowMonth(event)
        allow = get_menu_bar().is_checked(event.get_id())
        @m_panel.get_cal().enable_month_change(allow)
    end

	def onCalAllowYear(event)
        allow = get_menu_bar().is_checked(event.get_id())
        @m_panel.get_cal().enable_year_change(allow)
    end

	def onCalSeqMonth(event)
        allow = get_menu_bar().is_checked(event.get_id())
        @m_panel.toggle_cal_style(allow, CAL_SEQUENTIAL_MONTH_SELECTION)
    end

	def onCalShowSurroundingWeeks(event)
        allow = get_menu_bar().is_checked(event.get_id())
        @m_panel.toggle_cal_style(allow, CAL_SHOW_SURROUNDING_WEEKS)
    end

	def onAllowYearUpdate(event)
        event.enable( get_menu_bar().is_checked(Calendar_Cal_Month))
    end
end


class RbApp < App
    def on_init()
  	    frame = MyFrame.new("Calendar Windows sample", Point.new(50, 50), Size.new(450, 340))
	    frame.show(TRUE)
    end
end

a = RbApp.new
a.main_loop()
