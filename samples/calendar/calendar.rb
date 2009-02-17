#!/usr/bin/env ruby
# wxRuby2 Sample Code. Copyright (c) 2004-2008 wxRuby development team
# Freely reusable code: see SAMPLES-LICENSE.TXT for details
begin
  require 'rubygems' 
rescue LoadError
end
require 'wx'

include Wx

Calendar_Cal_Monday = 200
Calendar_Cal_Holidays = 201
Calendar_Cal_Special = 202
Calendar_Cal_Month = 203
Calendar_Cal_Year = 204
Calendar_Cal_SeqMonth = 205
Calendar_Cal_SurroundWeeks = 206


class MyCalendar < CalendarCtrl
  def initialize(parent, display_frame, initial_date, calendar_flags)
    super( parent, 
           :date  => initial_date, 
           :style => calendar_flags | RAISED_BORDER)

    @display = display_frame
    @date = initial_date
    @weekday_names = %w|Sun Mon Tue Wed Thu Fri Sat|

    evt_calendar self, :on_calendar
    evt_calendar_month self, :on_cal_month_change
    evt_calendar_year self, :on_cal_year_change
    evt_calendar_sel_changed self, :on_calendar_change
    evt_calendar_weekday_clicked self, :on_calendar_weekday_click
  end

  def on_calendar(event)
    @display.date = event.date
  end

  def on_calendar_change(event)
    @date = event.date
    log_status("Selected date: #{@date.strftime('%A %d %B %Y')}")
  end

  def on_cal_month_change
    log_status("Calendar month changed")
  end

  def on_cal_year_change
    log_status("Calendar year changed")
  end

  def on_calendar_weekday_click(event)
    wday = event.week_day
    log_status("Clicked on #{@weekday_names[wday]}")
  end
  
  attr_reader :date
end

class MyFrame < Frame
  def initialize(title)
    super(nil, -1, title)
    @panel = Wx::Panel.new(self)
    add_menu_bar
    add_status_bar

    @calendar_flags = CAL_MONDAY_FIRST | CAL_SHOW_HOLIDAYS

    @calendar = MyCalendar.new(@panel, self, Time.now, @calendar_flags)

    @sizer = BoxSizer.new(VERTICAL)
    configure_window

  	evt_menu Wx::ID_EXIT, :on_quit
  	evt_menu Wx::ID_ABOUT, :on_about

  	evt_menu Calendar_Cal_Monday, :on_cal_monday
  	evt_menu Calendar_Cal_Holidays, :on_cal_holidays
  	evt_menu Calendar_Cal_Special, :on_cal_special

  	evt_menu Calendar_Cal_Month, :on_cal_allow_month
  	evt_menu Calendar_Cal_Year, :on_cal_allow_year

  	evt_menu Calendar_Cal_SeqMonth, :on_cal_seq_month
  	evt_menu Calendar_Cal_SurroundWeeks, :on_cal_show_surrounding_weeks

  	evt_update_ui Calendar_Cal_Year, :on_allow_year_update
  end
  
  def add_menu_bar
    # create a menu bar
    menu_file = Menu.new

    menu_file.append(Wx::ID_ABOUT, "&About...\tCtrl-A", "Show about dialog")
    menu_file.append_separator
    menu_file.append(Wx::ID_EXIT, "E&xit\tAlt-X", "Quit self program")

    menu_cal = Menu.new
    menu_cal.append(Calendar_Cal_Monday,
                     "Monday &first weekday\tCtrl-F",
                     "Toggle between Mon and Sun as the first week day",
                     ITEM_CHECK)
    menu_cal.append(Calendar_Cal_Holidays, "Show &holidays\tCtrl-H",
                     "Toggle highlighting the holidays",
                     ITEM_CHECK)
    menu_cal.append(Calendar_Cal_Special, "Highlight &special dates\tCtrl-S",
                     "Test custom highlighting",
                     ITEM_CHECK)
    menu_cal.append(Calendar_Cal_SurroundWeeks,
                     "Show s&urrounding weeks\tCtrl-W",
                     "Show the neighbouring weeks in the prev/next month",
                     ITEM_CHECK)
    menu_cal.append_separator
    menu_cal.append(Calendar_Cal_SeqMonth,
                     "To&ggle month selector style\tCtrl-G",
                     "Use another style for the calendar controls",
                     ITEM_CHECK)
    menu_cal.append(Calendar_Cal_Month, "&Month can be changed\tCtrl-M",
                     "Allow changing the month in the calendar",
                     ITEM_CHECK)
    menu_cal.append(Calendar_Cal_Year, "&Year can be changed\tCtrl-Y",
                     "Allow changing the year in the calendar",
                     ITEM_CHECK)

    # now append the freshly created menu to the menu bar...
    menu_bar = MenuBar.new
    menu_bar.append(menu_file, "&File")
    menu_bar.append(menu_cal, "&Calendar")

    menu_bar.check(Calendar_Cal_Monday, TRUE)
    menu_bar.check(Calendar_Cal_Holidays, TRUE)
    menu_bar.check(Calendar_Cal_Month, TRUE)
    menu_bar.check(Calendar_Cal_Year, TRUE)

    # ... and attach self menu bar to the frame
    self.menu_bar = menu_bar
  end

  def add_status_bar
    # create a status bar just for fun (by default with 1 pane only)
    create_status_bar
    set_status_text("Welcome to Windows!")
  end
  
  def configure_window
    @sizer.add(@calendar, 0, Wx::ALIGN_CENTRE|Wx::ALL, 5)
    @sizer.size_hints = @panel
    layout
    @panel.sizer = @sizer
  end
  
  def on_quit
    # true is to force the frame to close
    close(true)
  end

  def on_about
    message_box("wxRuby CalendarCtrl sample\nby Kevin Smith\n" +
                 "based on the wxWidgets version by Vadim Zeitlin",
                 "About Calendar", OK | ICON_INFORMATION, self)
  end

  def on_cal_monday(event)
    enable = get_menu_bar().is_checked(event.get_id())
    toggle_cal_style(enable, CAL_MONDAY_FIRST)
  end

  def on_cal_holidays(event)
    enable = get_menu_bar().is_checked(event.get_id())
    @calendar.enable_holiday_display(enable)
  end

  def on_cal_special(event)
    highlight_special(get_menu_bar().is_checked(event.get_id()))
  end

  def on_cal_allow_month(event)
    allow = get_menu_bar().is_checked(event.get_id())
    @calendar.enable_month_change(allow)
  end

  def on_cal_allow_year(event)
    allow = get_menu_bar().is_checked(event.get_id())
    @calendar.enable_year_change(allow)
  end

  def on_cal_seq_month(event)
    allow = get_menu_bar().is_checked(event.get_id())
    toggle_cal_style(allow, CAL_SEQUENTIAL_MONTH_SELECTION)
  end

  def on_cal_show_surrounding_weeks(event)
    allow = get_menu_bar().is_checked(event.get_id())
    toggle_cal_style(allow, CAL_SHOW_SURROUNDING_WEEKS)
  end

  def on_allow_year_update(event)
    event.enable( get_menu_bar().is_checked(Calendar_Cal_Month))
  end

  def toggle_cal_style(on,flag)
    style = @calendar.get_window_style_flag
    date = @calendar.date
    @sizer.detach(@calendar)
    @calendar.destroy
    if  on
      style |= flag
    else
      style &= ~flag
    end
    @calendar = MyCalendar.new(@panel, self, date, style)
    @sizer.add(@calendar, 0, Wx::ALIGN_CENTRE|Wx::ALL, 5)
    @panel.layout
  end

  def highlight_special(on)
    if on
      attr_red_circle = CalendarDateAttr.new(CAL_BORDER_ROUND, RED)
      attr_green_square = CalendarDateAttr.new(CAL_BORDER_SQUARE, GREEN)
      # This wraps correctly, but causes problems because the colour is freed
      # when the attribute is reset.
      #
      # attr_header_like = CalendarDateAttr.new(BLUE, LIGHT_GREY)

      @calendar.set_attr(17, attr_red_circle)
      @calendar.set_attr(29, attr_green_square)
      # @calendar.set_attr(13, attr_header_like)
    else
      @calendar.reset_attr(17)
      @calendar.reset_attr(29)
      # @calendar.reset_attr(13)
    end
    @calendar.refresh()
  end

  def set_date(d)
    str = "%s-%s-%s" % [ d.year, d.mon, d.day ]
    Wx::MessageDialog.new( self, "The selected date is #{str}", 
                           "Date chosen" ).show_modal
  end
  
end


class RbApp < App
  def on_init()
    frame = MyFrame.new("Calendar Windows sample")
    frame.show(true)
  end
end

a = RbApp.new
a.main_loop()
