#!/MinGW/bin/ruby

# Poor man's doc generator for wxRuby.  Gerard Vreeswijk, 2003 (c).
#
# Here is my contribution, made on a lost Sunday afternoon.  It was
# meant to reflect the wxRuby classes and instance methods available
# from the wxRuby source, rather than form wxWindows docs.
#
# I know it is far from adequate and sometimes wide of the mark, but
# at least it is a start to something better.
# Comments to get to a rewrite are welcome.
# I know one comment myself: use the ruby parser shipped with rdoc.

#
# -------------------------------------------------------------------
# Might want to tweak the following constants.

WxRubyDIR      = 'E:/Dev/RubyDev/wxruby'
# The following constant is not used in this program (yet).
WxWinDoc       = 'C:/Zip/wxWindows/wxWindows-2.4.1-HTML/wxWindows-2.4.1/docs/html'
DumpDIR        = 'raw_docs'

#
# No tweaking of constants is needed beyond this line.
# -------------------------------------------------------------------

INTRO          = <<EOF
<P>
This is an extraction of files from wxRuby's 'src' and 'samples' dir.
First, *.cpp files in 'src' and subdirs were scanned on wxRuby instance methods.
Then, *.rb and *.rbw files in 'samples' and subdirs
were scanned on the use of initialization and instance methods.
Extraction is done sloppily, without a real Ruby parser.
Completeness and correctness is therefore far from guaranteed.
Use completely at your own risk.
</P><P>
- HTML generating script last modified: <I>#{File.mtime($0)}</I>.<BR>
- HTML generated at: <I>#{Time.now}</I>.
</P>
EOF

if FileTest.directory?('src') && FileTest.directory?('samples')
   WxRubySamples  = 'samples'
   WxRubySource   = 'src'
else
   WxRubySource   = "#{WxRubyDIR}/src"
   WxRubySamples  = "#{WxRubyDIR}/samples"
   unless FileTest.directory?(WxRubySource) && FileTest.directory?(WxRubySamples)
      print <<EOF
This script must be run in the wxRuby directory with 'src' and
'samples' subdirectories, or must know where these two subdirectories
are.  (Change constants 'WxRubySource' and 'WxRubySamples' in the script.)
EOF
      exit 1
   end
end

class ClassTree

   def initialize
      @constants = []
      @tree = {}
      @children_of = {}
      @parent_of = {}
   end

   def create(klass)
      return if @tree.has_key? klass
      @tree[klass] = {
         'methods' => [],
         'create_samples' => [],
         'instance_samples' => []
      }
      @children_of[klass] = {}
   end

   def subclass(subklass, klass)
      create(subklass)
      create(klass)
      @children_of[klass][subklass] = true
      @parent_of[subklass] = klass
   end

   def header(klass)
      header = klass
      header += " &lt; " + @parent_of[klass] if @parent_of.has_key? klass
      header
   end


   def add_constant(constant)
      @constants << constant
   end

   def add_official_method(klass, method)
      @tree[klass]['methods'] << method
   end

   def add_sample_creation(variable, klass, method, args, sourcefile)

      args.chop! while args.count('(') < args.count(')')

      code = '<B>' + ( variable.length>0 ?
         %{<FONT color="#009900">#{variable}</FONT> } +
         %{<FONT color="#FF0000">=</FONT> } : '' ) +
         %{<FONT color="#000099">#{klass}</FONT>.} +
         %{<FONT color="#000000">#{method}</FONT>} +
         %{<FONT color="#660066">#{args}</FONT>} + '</B>'

      source = %{<A href="#{sourcefile}">#{File.basename(sourcefile)}<A>}
      sample = '<CODE>'+code+'</CODE>&nbsp;&nbsp;&nbsp;#&nbsp;'+source+'<BR>'

      create(klass) unless @tree[klass]
      @tree[klass]['create_samples'] << sample
   end

   def add_sample_instance(variable, instance, method, args, sourcefile, klass)

      args.chop! while args.count('(') < args.count(')')

      code = '<B>' + ( variable.length>0 ?
         %{<FONT color="#000000">#{variable}</FONT> } +
         %{<FONT color="#FF0000">=</FONT> } : '' ) +
         %{<FONT color="#009900">#{instance}</FONT>.} +
         %{<FONT color="#999900">#{method}</FONT>} +
         %{<FONT color="#660066">#{args}</FONT>} + '</B>'

      source = %{<A href="#{sourcefile}">#{File.basename(sourcefile)}<A>}
      sample = '<CODE>'+code+'</CODE>&nbsp;&nbsp;&nbsp;#&nbsp;'+source+'<BR>'

      create(klass) unless @tree[klass]
      @tree[klass]['instance_samples'] << sample
   end

   def sorted
      return @sorted if @sorted
      keys = @tree.keys.delete_if{ |klass| @parent_of.has_key? klass }.sort
      @sorted = keys.collect { |k|
         all_children_and_grand_children_of(k)
      }.flatten
      return @sorted
   end

   def all_children_and_grand_children_of(k)
      result  = [k]
      if @children_of[k]
         result += @children_of[k].keys.collect{ |c|
            all_children_and_grand_children_of(c)
         }.flatten.sort_by { |x| x.length }
      end
      result
   end

   def part(klass, category)
      @tree[klass][category].sort
   end

   def constants # no attr_reader here
      @constants.sort
   end

end

class FileCache
   def initialize
      @seen = {}
      @base = {}
   end
   def seen(name)
      if @seen[base(name)]
         return true
      else
         @seen[base(name)] = true
         return false
      end
   end
   def base(name)
      @base[name] ||= File.basename(name)
      @base[name]
   end
end

def analyze_source_directory
   require 'find'
   Find.find(WxRubySource) do |name|
      next if $fileCache.seen(name)
      case $fileCache.base(name)
         when 'const.cpp'
            analyze_constants(name)
         when /\.cpp$/
            analyze_cpp(name)
      end
   end
end

def analyze_constants(name)
   File.foreach(name) { |line|
      case line
         when /rb_define_const\(.*?"(.*)"/
            $classTree.add_constant($1)
      end
   }
end

def analyze_cpp(name)
   klass = ''
   File.foreach(name) { |line|
      case line
         when /rb_define_class_under\(.*?"(.*)"/
            klass = $1
            $classTree.create(klass)
         when /rb_define_method\(.*?"(.*)"/
            $classTree.add_official_method(klass, $1)
      end
   }
end

def analyze_sample_directory
   require 'find'
   Find.find(WxRubySamples) do |name|
      next if $fileCache.seen(name)
      case $fileCache.base(name)
         when /\.rbw?$/
            analyze_sample(name)
      end
   end
end

def analyze_sample(name)
   coupled = {}
   variable, klass, method, args = '', '', '', ''
   File.foreach(name) { |line|
      if line =~ /^\s*class\s*(\w+)\s*<\s*(\w+)/
         $classTree.subclass($1, $2)
      elsif line =~ /(\w+)\s*=\s*(\w+)\.(\w+)(.*)/
         variable, klass, method, args = $1, $2, $3, $4
      elsif line =~ /(\w+)\.(\w+)(.*)/
         klass, method, args = $1, $2, $3
      elsif args.length > 0
         args += "<BR>\n" + "&nbsp;"*4 + line
      else
         next
      end
      if args.count('(') <= args.count(')')
         if method=='new'
            coupled[variable] = klass if variable.length>0
            $classTree.add_sample_creation( variable, klass, method, args, name )
         elsif coup = coupled[klass]
            $classTree.add_sample_instance( variable, klass, method, args, name, coup )
         end
         variable, args, klass, method = '', '', '', ''
      end
   }
end


def dump_html
   dump_dir
   dump_index_html
   dump_style_sheet
   dump_contents_html
   dump_main_html
end

def dump_dir
   if FileTest.exist?( DumpDIR )
      if not FileTest.directory?( DumpDIR )
         puts "Exiting: #{DumpDIR} exists, but is not directory."
         exit 1
      end
   else
      Dir.mkdir("raw_docs")
   end
end


def dump_index_html
   File.open("#{DumpDIR}/index.html", "w") { |index|
      index.print <<EOF
<HTML>
<HEAD>
<TITLE>Poor man's doc of wxRuby}</TITLE>
</HEAD>
<FRAMESET cols="20%,80%">
  <FRAME src="contents.html" name="contents">
  <FRAME src="main.html" name="main">
</FRAMESET>
</HTML>
EOF
   }
end


def dump_style_sheet
   File.open("#{DumpDIR}/raw_docs.css", "w") { |index|
      index.print <<EOF
BODY {background: #FFFFFF;
}

BODY,TH,TR,TD,P    {
      color: #000000;
      font-size: 10pt;
}

INPUT {
      color: #000000;
      font-size: 9pt;
}

A:LINK    {color: #000000; text-decoration: none}
A:VISITED {color: #000000; text-decoration: none}
A:HOVER   {color: #000000; font-weight: normal; background-color: #FFAAAA}
A:ACTIVE  {color: #000000; font-weight: normal; background-color: #FF0000}

H1 {font-family: Arial;
    color: #005020;
    font-size: 14pt;
}

H2 {font-family: Arial;
    color: #222244;
    font-size: 12pt
}

H3 {font-family: Arial;
    color: #222244;
    font-size: 10pt
}
EOF
   }
end

def dump_contents_html
   File.open("#{DumpDIR}/contents.html", "w") { |contents|
      contents.print <<EOF
<HTML>
<HEAD>
<LINK rel="stylesheet" href="raw_docs.css" type="text/css">
</HEAD>
<BODY>
<H1>Poor man's doc of wxRuby</H1>
<H2>Contents</H2>
<LI>
   <A href="contents.html\#constants" target="contents">CONSTANTS</A>
</LI>
EOF
   $classTree.sorted.each { |klass|
      contents.print <<EOF
<LI>
   <A href="main.html\##{klass}" target="main">#{klass}</A>
</LI>
EOF
   }
   contents.print <<EOF
<A name="constants"></A>
<H2>Constants</H2>
EOF
   $classTree.constants.each { |c|
      contents.print <<EOF
<LI>
   #{c}
</LI>
EOF
}
   contents.print <<EOF
</BODY>
</HTML>
EOF
   }
end


def dump_main_html
   File.open("#{DumpDIR}/main.html", "w") { |main|
      main.print <<EOF
<HTML>
<HEAD>
<LINK rel="stylesheet" href="raw_docs.css" type="text/css">
</HEAD>
<BODY>
<H1>Poor man's doc of wxRuby</H1>

<P>
#{INTRO}
</P>
<HR>
EOF
      $classTree.sorted.each { |klass|
         main.print <<EOF
<a name="#{klass}">
<H3>#{$classTree.header(klass)}</H3>
EOF
         methods = $classTree.part(klass, 'methods')
         if methods.length > 0
            main.print <<EOF
Methods available:<BR>
EOF
            list = methods.collect { |method|
               %{<LI><B><CODE><FONT color="#999900">#{method}</FONT></CODE></B></LI>}
            }
            main.print "<OL>\n" + list.sort.join("\n") + "</OL>\n"
            main.print "\n<BR>\n"
         end
         create_samples = $classTree.part(klass, 'create_samples')
         if create_samples.length > 0
            main.print <<EOF
Creation examples:<BR>
EOF
            create_samples.each { |sample| main.print sample }
            main.print "\n<BR>\n"
         end
         instance_samples = $classTree.part(klass, 'instance_samples')
         if instance_samples.length > 0
            main.print <<EOF
Instance method examples:<BR>
EOF
            instance_samples.each { |sample| main.print sample }
            main.print "\n<BR>\n"
         end
         main.print "\n<HR>\n"
      }
      main.print <<EOF
</BODY>
</HTML>
EOF
   }
end

def analyze_wxdocs_directory
   # analyze wxWindows HTML documentation directory.
   # Wish this was in XML for better parsing.
end


$fileCache = FileCache.new
$classTree = ClassTree.new

analyze_source_directory
analyze_sample_directory
analyze_wxdocs_directory
dump_html








