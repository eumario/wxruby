/**********************************************************************

  date.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "date.h"

void WxDateTime::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"DateTime", rb_cObject);
	rb_define_alloc_func(rubyClass,WxDateTime::alloc);
	rb_define_singleton_method(rubyClass, "today", VALUEFUNC(WxDateTime::Today), 0);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxDateTime::init), -1);
	rb_define_method(rubyClass, "get_day", VALUEFUNC(WxDateTime::GetDay), 0);
	rb_define_method(rubyClass, "format_iso_date", VALUEFUNC(WxDateTime::FormatISODate), 0);
	rb_define_method(rubyClass, "to_time", VALUEFUNC(WxDateTime::ToTime), 0);
	rb_define_method(rubyClass, "is_valid", VALUEFUNC(WxDateTime::IsValid), 0);
	
}

VALUE
WxDateTime::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE 
WxDateTime::ToTime(VALUE self)
{
    wxDateTime *ptr;
    Data_Get_Struct(self, wxDateTime, ptr);
    return rb_time_new(ptr->GetTicks(),0);

}

VALUE
WxDateTime::init(int argc, VALUE *argv, VALUE self)
{
    typedef unsigned short wxDateTime_t;

    // constants
    // ------------------------------------------------------------------------

        // the timezones
    enum TZ
    {
        // the time in the current time zone
        Local,

        // zones from GMT (= Greenwhich Mean Time): they're guaranteed to be
        // consequent numbers, so writing something like `GMT0 + offset' is
        // safe if abs(offset) <= 12

        // underscore stands for minus
        GMT_12, GMT_11, GMT_10, GMT_9, GMT_8, GMT_7,
        GMT_6, GMT_5, GMT_4, GMT_3, GMT_2, GMT_1,
        GMT0,
        GMT1, GMT2, GMT3, GMT4, GMT5, GMT6,
        GMT7, GMT8, GMT9, GMT10, GMT11, GMT12,
        // Note that GMT12 and GMT_12 are not the same: there is a difference
        // of exactly one day between them

        // some symbolic names for TZ

        // Europe
        WET = GMT0,                         // Western Europe Time
        WEST = GMT1,                        // Western Europe Summer Time
        CET = GMT1,                         // Central Europe Time
        CEST = GMT2,                        // Central Europe Summer Time
        EET = GMT2,                         // Eastern Europe Time
        EEST = GMT3,                        // Eastern Europe Summer Time
        MSK = GMT3,                         // Moscow Time
        MSD = GMT4,                         // Moscow Summer Time

        // US and Canada
        AST = GMT_4,                        // Atlantic Standard Time
        ADT = GMT_3,                        // Atlantic Daylight Time
        EST = GMT_5,                        // Eastern Standard Time
        EDT = GMT_4,                        // Eastern Daylight Saving Time
        CST = GMT_6,                        // Central Standard Time
        CDT = GMT_5,                        // Central Daylight Saving Time
        MST = GMT_7,                        // Mountain Standard Time
        MDT = GMT_6,                        // Mountain Daylight Saving Time
        PST = GMT_8,                        // Pacific Standard Time
        PDT = GMT_7,                        // Pacific Daylight Saving Time
        HST = GMT_10,                       // Hawaiian Standard Time
        AKST = GMT_9,                       // Alaska Standard Time
        AKDT = GMT_8,                       // Alaska Daylight Saving Time

        // Australia

        A_WST = GMT8,                       // Western Standard Time
        A_CST = GMT12 + 1,                  // Central Standard Time (+9.5)
        A_EST = GMT10,                      // Eastern Standard Time
        A_ESST = GMT11,                     // Eastern Summer Time

        // TODO add more symbolic timezone names here

        // Universal Coordinated Time = the new and politically correct name
        // for GMT
        UTC = GMT0
    };

        // the calendar systems we know about: notice that it's valid (for
        // this classes purpose anyhow) to work with any of these calendars
        // even with the dates before the historical appearance of the
        // calendar
    enum Calendar
    {
        Gregorian,  // current calendar
        Julian      // calendar in use since -45 until the 1582 (or later)

        // TODO Hebrew, Chinese, Maya, ... (just kidding) (or then may be not?)
    };

        // these values only are used to identify the different dates of
        // adoption of the Gregorian calendar (see IsGregorian())
        //
        // All data and comments taken verbatim from "The Calendar FAQ (v 2.0)"
        // by Claus Tøndering, http://www.pip.dknet.dk/~c-t/calendar.html
        // except for the comments "we take".
        //
        // Symbol "->" should be read as "was followed by" in the comments
        // which follow.
    enum GregorianAdoption
    {
        Gr_Unknown,    // no data for this country or it's too uncertain to use
        Gr_Standard,   // on the day 0 of Gregorian calendar: 15 Oct 1582

        Gr_Alaska,             // Oct 1867 when Alaska became part of the USA
        Gr_Albania,            // Dec 1912

        Gr_Austria = Gr_Unknown,    // Different regions on different dates
        Gr_Austria_Brixen,          // 5 Oct 1583 -> 16 Oct 1583
        Gr_Austria_Salzburg = Gr_Austria_Brixen,
        Gr_Austria_Tyrol = Gr_Austria_Brixen,
        Gr_Austria_Carinthia,       // 14 Dec 1583 -> 25 Dec 1583
        Gr_Austria_Styria = Gr_Austria_Carinthia,

        Gr_Belgium,            // Then part of the Netherlands

        Gr_Bulgaria = Gr_Unknown, // Unknown precisely (from 1915 to 1920)
        Gr_Bulgaria_1,         //      18 Mar 1916 -> 1 Apr 1916
        Gr_Bulgaria_2,         //      31 Mar 1916 -> 14 Apr 1916
        Gr_Bulgaria_3,         //      3 Sep 1920 -> 17 Sep 1920

        Gr_Canada = Gr_Unknown,   // Different regions followed the changes in
                               // Great Britain or France

        Gr_China = Gr_Unknown,    // Different authorities say:
        Gr_China_1,            //      18 Dec 1911 -> 1 Jan 1912
        Gr_China_2,            //      18 Dec 1928 -> 1 Jan 1929

        Gr_Czechoslovakia,     // (Bohemia and Moravia) 6 Jan 1584 -> 17 Jan 1584
        Gr_Denmark,            // (including Norway) 18 Feb 1700 -> 1 Mar 1700
        Gr_Egypt,              // 1875
        Gr_Estonia,            // 1918
        Gr_Finland,            // Then part of Sweden

        Gr_France,             // 9 Dec 1582 -> 20 Dec 1582
        Gr_France_Alsace,      //      4 Feb 1682 -> 16 Feb 1682
        Gr_France_Lorraine,    //      16 Feb 1760 -> 28 Feb 1760
        Gr_France_Strasbourg,  // February 1682

        Gr_Germany = Gr_Unknown,  // Different states on different dates:
        Gr_Germany_Catholic,   //      1583-1585 (we take 1584)
        Gr_Germany_Prussia,    //      22 Aug 1610 -> 2 Sep 1610
        Gr_Germany_Protestant, //      18 Feb 1700 -> 1 Mar 1700

        Gr_GreatBritain,       // 2 Sep 1752 -> 14 Sep 1752 (use 'cal(1)')

        Gr_Greece,             // 9 Mar 1924 -> 23 Mar 1924
        Gr_Hungary,            // 21 Oct 1587 -> 1 Nov 1587
        Gr_Ireland = Gr_GreatBritain,
        Gr_Italy = Gr_Standard,

        Gr_Japan = Gr_Unknown,    // Different authorities say:
        Gr_Japan_1,            //      19 Dec 1872 -> 1 Jan 1873
        Gr_Japan_2,            //      19 Dec 1892 -> 1 Jan 1893
        Gr_Japan_3,            //      18 Dec 1918 -> 1 Jan 1919

        Gr_Latvia,             // 1915-1918 (we take 1915)
        Gr_Lithuania,          // 1915
        Gr_Luxemburg,          // 14 Dec 1582 -> 25 Dec 1582
        Gr_Netherlands = Gr_Belgium, // (including Belgium) 1 Jan 1583

        // this is too weird to take into account: the Gregorian calendar was
        // introduced twice in Groningen, first time 28 Feb 1583 was followed
        // by 11 Mar 1583, then it has gone back to Julian in the summer of
        // 1584 and then 13 Dec 1700 -> 12 Jan 1701 - which is
        // the date we take here
        Gr_Netherlands_Groningen,  // 13 Dec 1700 -> 12 Jan 1701
        Gr_Netherlands_Gelderland, // 30 Jun 1700 -> 12 Jul 1700
        Gr_Netherlands_Utrecht,    // (and Overijssel) 30 Nov 1700->12 Dec 1700
        Gr_Netherlands_Friesland,  // (and Drenthe) 31 Dec 1700 -> 12 Jan 1701

        Gr_Norway = Gr_Denmark,       // Then part of Denmark
        Gr_Poland = Gr_Standard,
        Gr_Portugal = Gr_Standard,
        Gr_Romania,                // 31 Mar 1919 -> 14 Apr 1919
        Gr_Russia,                 // 31 Jan 1918 -> 14 Feb 1918
        Gr_Scotland = Gr_GreatBritain,
        Gr_Spain = Gr_Standard,

        // Sweden has a curious history. Sweden decided to make a gradual
        // change from the Julian to the Gregorian calendar. By dropping every
        // leap year from 1700 through 1740 the eleven superfluous days would
        // be omitted and from 1 Mar 1740 they would be in sync with the
        // Gregorian calendar. (But in the meantime they would be in sync with
        // nobody!)
        //
        // So 1700 (which should have been a leap year in the Julian calendar)
        // was not a leap year in Sweden. However, by mistake 1704 and 1708
        // became leap years. This left Sweden out of synchronisation with
        // both the Julian and the Gregorian world, so they decided to go back
        // to the Julian calendar. In order to do this, they inserted an extra
        // day in 1712, making that year a double leap year! So in 1712,
        // February had 30 days in Sweden.
        //
        // Later, in 1753, Sweden changed to the Gregorian calendar by
        // dropping 11 days like everyone else.
        Gr_Sweden = Gr_Finland,       // 17 Feb 1753 -> 1 Mar 1753

        Gr_Switzerland = Gr_Unknown,// Different cantons used different dates
        Gr_Switzerland_Catholic,    //      1583, 1584 or 1597 (we take 1584)
        Gr_Switzerland_Protestant,  //      31 Dec 1700 -> 12 Jan 1701

        Gr_Turkey,                 // 1 Jan 1927
        Gr_USA = Gr_GreatBritain,
        Gr_Wales = Gr_GreatBritain,
        Gr_Yugoslavia              // 1919
    };

        // the country parameter is used so far for calculating the start and
        // the end of DST period and for deciding whether the date is a work
        // day or not
        //
        // TODO move this to intl.h
    enum Country
    {
        Country_Unknown, // no special information for this country
        Country_Default, // set the default country with SetCountry() method
                         // or use the default country with any other

        // TODO add more countries (for this we must know about DST and/or
        //      holidays for this country)

        // Western European countries: we assume that they all follow the same
        // DST rules (true or false?)
        Country_WesternEurope_Start,
        Country_EEC = Country_WesternEurope_Start,
        France,
        Germany,
        UK,
        Country_WesternEurope_End = UK,

        Russia,

        USA
    };

        // symbolic names for the months
    enum Month
    {
        Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec, Inv_Month
    };

        // symbolic names for the weekdays
    enum WeekDay
    {
        Sun, Mon, Tue, Wed, Thu, Fri, Sat, Inv_WeekDay
    };

        // invalid value for the year
    enum Year
    {
        Inv_Year = SHRT_MIN    // should hold in wxDateTime_t
    };

        // flags for GetWeekDayName and GetMonthName
    enum NameFlags
    {
        Name_Full = 0x01,       // return full name
        Name_Abbr = 0x02        // return abbreviated name
    };

        // flags for GetWeekOfYear and GetWeekOfMonth
    enum WeekFlags
    {
        Default_First,   // Sunday_First for US, Monday_First for the rest
        Monday_First,    // week starts with a Monday
        Sunday_First     // week starts with a Sunday
    };

    time_t timet;
    double jdn;
    wxDateTime_t day;
    int month = Inv_Month;
    int year = Inv_Year;
    wxDateTime_t hour = 0;
    wxDateTime_t minute = 0;
    wxDateTime_t second = 0;
    wxDateTime_t millisec = 0;

    wxDateTime *ptr;
    Data_Get_Struct(self, wxDateTime, ptr);
    if(argc==0) {
      ptr = new wxDateTime();
    } else if(argc==1 && TYPE(argv[0])==T_FIXNUM) {
      timet = (time_t)NUM2INT(argv[0]);
      ptr = new wxDateTime(timet);
    } else if(argc==1 && TYPE(argv[0])==T_FLOAT) {
      jdn = (double)(RFLOAT(argv[0])->value);
      ptr = new wxDateTime(jdn);
    } else {
      day = (wxDateTime_t)NUM2INT(argv[0]);
      if(argc>1) month = NUM2INT(argv[1]);
      if(argc>2) year = NUM2INT(argv[2]);
      if(argc>3) hour = (wxDateTime_t)NUM2INT(argv[3]);
      if(argc>4) minute = (wxDateTime_t)NUM2INT(argv[4]);
      if(argc>5) second = (wxDateTime_t)NUM2INT(argv[5]);
      if(argc>6) millisec = (wxDateTime_t)NUM2INT(argv[6]);
      ptr = new wxDateTime(day,(enum wxDateTime::Month)month,year,hour,minute,second,millisec);
    }

    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxDateTime::init0(const wxDateTime &dateTime)
{
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    if(!dateTime.IsValid())
      DATA_PTR(self) = (void*)&wxDefaultDateTime;
    else
      DATA_PTR(self) = new wxDateTime(dateTime.GetTicks());
    return self;
}

VALUE
WxDateTime::GetDay(VALUE self)
{
    wxDateTime *ptr;
    Data_Get_Struct(self, wxDateTime, ptr);
    return INT2NUM(ptr->GetDay());
}

VALUE 
WxDateTime::IsValid(VALUE self)
{
    wxDateTime *ptr;
    Data_Get_Struct(self, wxDateTime, ptr);
    return CppBoolToRubyBool(ptr->IsValid());
}


VALUE
WxDateTime::FormatISODate(VALUE self)
{
    wxDateTime *ptr;
    Data_Get_Struct(self, wxDateTime, ptr);
    return rb_str_new2(ptr->FormatISODate());
}

VALUE
WxDateTime::Today(VALUE self)
{
    return WxDateTime::init0(wxDateTime::Today());
}

VALUE WxDateTime::rubyClass;

class ZAutoDefineWxDateTime
{
public:
   ZAutoDefineWxDateTime()
    {
       WxDateTime::DefineClass();
    }
};
static ZAutoDefineWxDateTime x;
