#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxCalendarCtrl

%{
#include <wx/calctrl.h>
%}

%ignore wxCalendarCtrl::wxCalendarCtrl();

%include "include/wxCalendarCtrl.h"

enum
{
    // show Sunday as the first day of the week (default)
    wxCAL_SUNDAY_FIRST               = 0x0000,
                                                                                
    // show Monder as the first day of the week
    wxCAL_MONDAY_FIRST               = 0x0001,
                                                                                
    // highlight holidays
    wxCAL_SHOW_HOLIDAYS              = 0x0002,
                                                                                
    // disable the year change control, show only the month change one
    wxCAL_NO_YEAR_CHANGE             = 0x0004,
                                                                                
    // don't allow changing neither month nor year (implies
    // wxCAL_NO_YEAR_CHANGE)
    wxCAL_NO_MONTH_CHANGE            = 0x000c,
                                                                                
    // use MS-style month-selection instead of combo-spin combination
    wxCAL_SEQUENTIAL_MONTH_SELECTION = 0x0010,
                                                                                
    // show the neighbouring weeks in the previous and next month
    wxCAL_SHOW_SURROUNDING_WEEKS     = 0x0020
};

enum wxCalendarHitTestResult
{
    wxCAL_HITTEST_NOWHERE,      // outside of anything
    wxCAL_HITTEST_HEADER,       // on the header (weekdays)
    wxCAL_HITTEST_DAY,          // on a day in the calendar
    wxCAL_HITTEST_INCMONTH,
    wxCAL_HITTEST_DECMONTH,
    wxCAL_HITTEST_SURROUNDING_WEEK
};

// border types for a date
enum wxCalendarDateBorder
{
    wxCAL_BORDER_NONE,          // no border (default)
    wxCAL_BORDER_SQUARE,        // a rectangular border
    wxCAL_BORDER_ROUND          // a round border
};
