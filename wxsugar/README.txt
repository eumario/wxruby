=== WxSugar ===

NOTE (November 2008) : WxSugar is slightly depleted at the moment
because much of the core functionality has been folded into the core
wxRuby library. The main purpose of the package at the moment is:

1) To provide the xrcise add-on tool
2) To provide backward compatibility and bugfixes for apps already using
   the library

CONTINUING ...

wxSugar is a set of pure-ruby extensions that work on top of the core
wxRuby library. wxRuby aims to provide a comprehensive port of the
wxWidgets GUI API. This means that it inherits some of the rather
clumsy, verbose syntax of a C++ library. 

Therefore wxSugar wraps the same powerful cross-platform GUI features in
the 'sweeter', more expressive syntax that has made the Ruby language
popular. Typical ruby-isms include:

* the use of blocks to scope effects, generalise methods and iterate collections
* pseudo-keyword-constructors provided by hashes
* metaprogramming to modularise and transparently extend in-built functionality 

As well as enhancing and easing the use of wxRuby, it also provides a
testing ground for features which may in the future be considered for
inclusion in the core wxRuby library.

= INSTALLATION =

The easiest way to install WxSugar is via rubygems. On Windows, open a
comand prompt and type

 gem install wx_sugar

or, on OS X, Linux and other Unix-ish systems, type
 
 sudo gem install wx_sugar

If you prefer to install from a tarball, simply unpack the package and
do:

 rake install

or, on OS X, Linux and other Unix-ish systems

 sudo rake install

= DOCUMENTATION =

Documentation is supplied in lib/wx_sugar.rb and in the individual
extension files.

= LICENCE =

WxSugar is licensed under the liberal MIT-like WxRuby2 licence, which is
compatible with free and commercial software. See LICENCE.txt for more
details.

= HELP AND FURTHER INFORMATION =

Questions, suggestions and bugs concerning WxSugar can be discussed on
the WxRuby mailing lists, or or via the WxRuby Tracker. See the WxRuby
website for more details:

http://wxruby.rubyforge.org/
