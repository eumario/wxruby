# fixevents.rb
#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project

#   This script post-processes the SWIG output
#   to write all of the event handlers
#   I know it's ugly :-(
require 'swig/classes/include/events'

File.open(ARGV[0], "a") do | out |


	$events.each do |evt|
		func = ""
		case evt[1]
		when 1
			func = "internal_evt_no_parameters"
		when 2
			func = "internal_evt_with_id"
		when 3
			func = "internal_evt_with_range"
		end

		out.puts <<FUNC_DEF
static VALUE #{evt[0].downcase}(int argc, VALUE *argv, VALUE self)
{
	return #{func}(argc,argv,self,#{evt[2]});
}

FUNC_DEF

	end

	out.puts <<INIT_FUNC
extern "C" {
void Init_WxRubyEvents()
{
INIT_FUNC
	$events.each do |evt|
		out.puts <<REGISTER_FUNC
	rb_define_method(cWxEvtHandler.klass, \"#{evt[0].downcase}\", VALUEFUNC(#{evt[0].downcase}),-1);
REGISTER_FUNC
	end

	out.puts "}"
	out.puts "}"

end

