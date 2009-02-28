require 'redcloth'

# This set of classes are used to render the Textile sources to the
# final HTML output, using the redcloth module

# This is a subclass of redcloth which strips out all the ugly (to my
# eyes) tab indenting.
# 
# Permit use of RedCloth version 3 or version 4
s_klass = ( RedCloth.const_defined?(:TextileDoc) ) ?
              RedCloth::TextileDoc : 
              RedCloth

class WxRubyCloth < s_klass
  def to_html()
    super(:textile).gsub(/^\t+/, '')
  end
end

# The base class for a Textile -> 
class HTMLGenerator
  attr_reader :src, :src_file
  # +textile_file+ should be the filename of a source file.
  def initialize(textile_file)
    @src_file = textile_file
    @src      = File.read(@src_file)
  end
  
  # Render the textile input file to +file_or_io+, which may be an open
  # IO, or a filename. If a filename, the file is overwritten.
  def output(file_or_io, tpl_vars = {})
    tpl_vars['TIMESTAMP'] ||= Time.now.to_s
    redcloth = WxRubyCloth.new( src )
    above = self.class.const_get(:ABOVE).gsub(/%%(\w+)%%/) { tpl_vars[$1] }
    below = self.class.const_get(:BELOW).gsub(/%%(\w+)%%/) { tpl_vars[$1] }

    case file_or_io
    when String
      File.open(file_or_io, 'w+') do | f |
        f << above << redcloth.to_html << below
      end
    when IO
      file_or_io << above << redcloth.to_html << below
    else
      raise ArgumentError, "Can't output to #{file_or_io.inspect}"
    end
  end

  ABOVE = %q[<html>
<head>
<title>%%TITLE%%</title>
<link rel="stylesheet" type="text/css" href="wxruby.css" />
</head>
<body>
]

  BELOW = %q[
<p id="datestamp">[This page automatically generated from <a
href="%%FILENAME%%.txtl">the Textile source</a> at %%TIMESTAMP%%]</p>
</body>
</html>
]
end

# This class is specifically used to render a class documentation
# page. It titles the page according to the class documented.
class ClassFileHTMLGenerator < HTMLGenerator
  def output(out_file, tpl_vars = {})
    tpl_vars['FILENAME'] = src_file[/\w+(?=\.\w+$)/]
    if m = src.match(/^h1(?:\(.*?\))?\.(.*?)$/)
      tpl_vars['TITLE'] = m[1]
    else
      tpl_vars['TITLE'] = tpl_vars['FILENAME']
    end
    super(out_file, tpl_vars)
  end
  ABOVE = %q[<html>
<head>
<title>%%TITLE%%</title>
<link rel="stylesheet" type="text/css" href="wxruby.css" />
</head>
<body>
<a href="index.html" id="homelink">wxRuby Documentation Home</a>
]

end

# This is a special rendered for the index page to the class
# reference. It strips out references to classes that are not (yet)
# ported to WxRuby from WxWidgets.
class IndexPageGenerator < HTMLGenerator
  def wx_class_exists?(wx_class)
    wx_classes.include?(wx_class)
  end
  
  def wx_classes
    @wx_classes ||= available_wx_classes
  end

  # returns an alphabetical listing of actually available Wx:: classes
  def available_wx_classes
    require 'wx'
    wx_classes = Wx::constants.collect { | c | Wx::const_get(c) }.grep(Class)
    wx_classes.collect { | c | c.name.sub(/^Wxruby2\:\:/, '') }
  end

  WX_CLASS_DESC = /^\|([A-Z]\w+)\|/
  def output( index_file, tpl_vars = {} )
    if src.respond_to? :collect
      # Ruby 1.8.x String mixes Enumerable and String#each return each line
      src_lines = src
    else
      # Ruby 1.9 String#lines method returns an enumerator for each line (if no block is given)
      src_lines = src.lines
    end
    lines = src_lines.collect do | line | 
      if line.sub!(WX_CLASS_DESC) { | c | "|\"#{$1}\":#{$1.downcase}.html|" }
        # delete the line
        next line.replace('') unless wx_class_exists?($1)
      end
      line
    end
    @src = lines.reject { | l | l.empty? }.join("")
    tpl_vars['TITLE'] ||= 'WxRuby Documentation: Class Reference'
    super(index_file, tpl_vars)
  end
end

# TODO - this is a class to combine all the class pages into a single
# large HTML file that can then be converted to a PDF using hte HTMLDoc
# utility.
class OneBigFileHTMLGenerator < HTMLGenerator
  # How to call HTMLDoc to convert a big multi-class file into a PDF
  # system("htmldoc --linkstyle plain --bodyfont helvetica --toclevels 3 -f wxruby.pdf #{html_out}")
end
