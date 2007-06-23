# Copyright 2004-2007 by Kevin Smith
# released under the MIT-style wxruby2 license

# This script post-processes SWIG's output of swig/Events.i to add in
# all the event handler methods (evt_xxx) to classes that inherit from
# EvtHandler. It reads 'swig/classes/include/events.rb' which contains
# definitions for every event type, and adds the relevant methods to the
# EvtHandler class.

# Load the $events global array of type definitions
require 'swig/classes/include/events'

# Little class to make accessing Event Type info a bit easier below
class WxEventType < Struct.new(:name, :type, :wx_const)
  # Events in Wx but not exposed in WxRuby (b/c they cause problems)
  EXCLUDED = [ /^EVT_TAB/, 'EVT_COMMAND' ]
  # These event types only work on Windows
  WINDOWS_ONLY = [ /^EVT_DIALUP/ ]

  def initialize(*args)
    super
    @excluded = true if EXCLUDED.any? { | x | x === name }
    @win_only = true if WINDOWS_ONLY.any? { | x | x === name }
  end

  def excluded?
    @excluded
  end

  def windows_only? 
    @win_only
  end
end

# Convert the raw arrays into informative event type objects
$events.map! { | x | WxEventType[ *x ] }

# Append this stuff to the default SWIG Events.i file
File.open(ARGV[0], "a") do | out |
  # First we loop over the events creating short C++ functions to hook
  # up events for each
  $events.each do | evt |
    next if evt.excluded?

    if evt.name =="EVT_MOUSE_EVENTS"
      out.puts <<FUNC_DEF
static VALUE evt_mouse_events(int argc, VALUE *argv, VALUE self)
{
    evt_left_down(argc,argv,self);
    evt_left_up(argc,argv,self);
    evt_middle_down(argc,argv,self);
    evt_middle_up(argc,argv,self);
    evt_right_down(argc,argv,self);
    evt_right_up(argc,argv,self);
    evt_motion(argc,argv,self);
    evt_left_dclick(argc,argv,self);
    evt_middle_dclick(argc,argv,self);
    evt_right_dclick(argc,argv,self);
    evt_leave_window(argc,argv,self);
    evt_enter_window(argc,argv,self);
    return evt_mousewheel(argc,argv,self);
}
FUNC_DEF
      next
    end

    func = case evt.type
      when 1 : "internal_evt_no_parameters"
      when 2 : "internal_evt_with_id"
      when 3 : "internal_evt_with_id_range"
    end

    out.puts "#ifdef __WXMSW__" if evt.windows_only?
    out.puts <<FUNC_DEF
static VALUE #{evt.name.downcase}(int argc, VALUE *argv, VALUE self)
  { return #{func}(argc, argv, self, #{evt.wx_const}); }

FUNC_DEF
    out.puts "#endif //__WXMSW__" if evt.windows_only?
  end

  # Then we loop over the events and register the ruby method for each
  out.puts <<INIT_FUNC
extern "C" {
void Init_wxEvents2()
{
INIT_FUNC
  $events.each do | evt |
    next if evt.excluded?

    out.puts "#ifdef __WXMSW__" if evt.windows_only?
    out.puts <<REGISTER_FUNC
	rb_define_method(cWxEvtHandler.klass, \"#{evt.name.downcase}\", VALUEFUNC(#{evt.name.downcase}),-1);
REGISTER_FUNC
    out.puts "#endif //__WXMSW__" if evt.windows_only?
  end

  out.puts "}"
  out.puts "}"
end
