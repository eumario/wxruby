@echo off
if "%OS%" == "Windows_NT" goto WinNT
ruby -Sx "%0" %1 %2 %3 %4 %5 %6 %7 %8 %9
goto endofruby
:WinNT
ruby -Sx "%~nx0" %*
goto endofruby
#!/bin/ruby
#
#   irb.rb - intaractive ruby
#   	$Release Version: 0.7.3 $
#   	$Revision$
#   	$Date$
#   	by Keiju ISHITSUKA(keiju@ishitsuka.com)
#

begin
  require 'rake'
rescue LoadError
  require 'rubygems'
  require_gem 'rake'
end
RakeApp.new.run
:endofruby
