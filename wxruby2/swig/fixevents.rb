# fixevents.rb
#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

#   This script post-processes the SWIG output
#   to write all of the event handlers
#   I know it's ugly :-(
require 'swig/classes/include/events'

$exclude = [
	'EVT_COMMAND',
	'EVT_TAB',
]

$windows_only = [
	'EVT_DIALUP',
	'EVT_TOGGLEBUTTON'
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
