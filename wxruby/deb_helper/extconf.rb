#!/usr/bin/env ruby
# Fake Extension Configuration file
# This is created, simply cause wxRuby is compiled in a different method
# however setup.rb requires that there be a extconf.rb for binary extensions.
#
# This is simply to ensure that the wxruby.so file gets placed into the
# (arch)-(platform)/ extensions directory of the lib folder.

puts "creating Makefile"
File.open("Makefile","w") do |fh|
	fh.puts <<EOF
wxruby:
	cp %s .
	strip wxruby2.so
clean:
	rm -rf wxruby2.so
distclean: clean
	rm -rf Makefile
EOF
end
