# Copyright 2004-2007 by Kevin Smith
# released under the MIT-style wxruby2 license

# This script post-processes SWIG's output of swig/Events.i to add in
# all the event handler methods (evt_xxx) to classes that inherit from
# EvtHandler. It reads 'swig/classes/include/events.rb' which contains
# definitions for every event type, and adds the relevant methods to the
# EvtHandler class.

require 'swig/classes/include/events'

$exclude = [
	'EVT_COMMAND',
	'EVT_TAB',
]

$windows_only = [
	'EVT_DIALUP'
]

File.open(ARGV[0], "a") do | out |


	$events.each do |evt|
		exclude = false
		windows = false
		$windows_only.each do |name|
			if (evt[0].index(name) != nil)
				windows = true
			end
		end
		$exclude.each do |name|
			if (evt[0].index(name) != nil)
				exclude = true
			end
		end
		next if exclude	
        if(evt[0]=="EVT_MOUSE_EVENTS")
		out.puts "#ifdef __WXMSW__" if windows
		
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

		out.puts "#endif //__WXMSW__" if windows
        next
        end
		func = ""
		case evt[1]
		when 1
			func = "internal_evt_no_parameters"
		when 2
			func = "internal_evt_with_id"
		when 3
			func = "internal_evt_with_id_range"
		end

		out.puts "#ifdef __WXMSW__" if windows
		
		out.puts <<FUNC_DEF
static VALUE #{evt[0].downcase}(int argc, VALUE *argv, VALUE self)
{
	return #{func}(argc,argv,self,#{evt[2]});
}

FUNC_DEF

		out.puts "#endif //__WXMSW__" if windows

	end

	out.puts <<INIT_FUNC
extern "C" {
void Init_wxEvents2()
{
INIT_FUNC
	$events.each do |evt|
		windows = false
		exclude = false
		$windows_only.each do |name|
			if (evt[0].index(name) != nil)
				windows = true
			end
		end
		$exclude.each do |name|
			if (evt[0].index(name) != nil)
				exclude = true
			end
		end
		next if exclude	


		out.puts "#ifdef __WXMSW__" if windows

		out.puts <<REGISTER_FUNC
	rb_define_method(cWxEvtHandler.klass, \"#{evt[0].downcase}\", VALUEFUNC(#{evt[0].downcase}),-1);
REGISTER_FUNC

		out.puts "#endif //__WXMSW__" if windows

	end

	out.puts "}"
	out.puts "}"

end
