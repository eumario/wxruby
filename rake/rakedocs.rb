require 'fileutils'
# This file adds tasks to generate wxRuby documentation from
# the LaTeX wxWidgets documentation.
#
# Created 08/11/2006 by Sean Long, refactored by Alex Fenton
#
# Assumptions:
# 1) tex2rtf is installed and in the execution path. tex2rtf is included
#    with the wxWidgets source distribution in the utils sub directory.
#    see http://www.wxwidgets.org/wiki/index.php/Tex2RTF for informmation
# 2) The environment variable WXWIN is defined and point to the
#    wxWidgets source directory 
# 3) You have the tex files that the documentation is generated from;
#    they are included with the wxAll version of wxWidgets:
#   (http://prdownloads.sourceforge.net/wxwindows/wxWidgets-2.6.3.tar.gz) 

# Add on some useful helper methods to String for converting
# CamelCaseMethodNames to ruby_style_method_names
class String
  UCC_ACRONYMS = /([A-Z0-9_]{2,})(?=[A-Z][a-z])/
  UCC_CAPITALS = /([a-z])(?=[A-Z0-9_])/
  UCC_NUMBERS  = /(\d+)(?=[A-Za-z_])/

  def un_camelcase(word_sep = '_')
    dup.un_camelcase!(word_sep)
  end

  def un_camelcase!(word_sep = '_')
    gsub!(UCC_ACRONYMS) { $1 + word_sep }
    gsub!(UCC_CAPITALS) { $1 + word_sep }
    gsub!(UCC_NUMBERS)  { $1 + word_sep }
    downcase!
    self
  end

  def camelcase(word_sep = '_')
    dup.camelcase!(word_sep)
  end

  def camelcase!(word_sep = '_')
    gsub!(/(?:\A|#{word_sep})([a-z])/) { $1.upcase }
    self
  end
end

# Class for parsing the source latex files into wxRuby-ish latex files
class ClassParser
  attr_accessor :src_file, :rb_class, :wx_class, :section, :output
  attr_accessor :verbatim, :removing

  alias :removing? :removing
  alias :verbatim? :verbatim

  # +file_name+ is the file to be parsed
  def initialize(file_name)
    self.src_file = file_name
    self.section  = nil
    self.wx_class = nil
    self.rb_class = nil
    self.output   = ''
  end
  
  # The start of a whole class
  CLASS_HEADING  = /^\\section\{\\class\{([_A-Za-z0-9]+)\}\}/x

  # The start of a section
  MEM_SECTION = /\A\\membersection/
  # particular types of section
  METHOD_HEADING = /#{MEM_SECTION}\{([\\_A-Za-z0-9]+)::([_$=!\sA-Za-z0-9]+)\}/
  STATIC_HEADING = /#{MEM_SECTION}\{(::)?([\\_A-Za-z0-9]+)\}/
  DESTRUCTOR     = /#{MEM_SECTION}\{.*\\destruct\{/

  # method definitions
  FUNC_LINE      = /^\\(func|constfunc)/
  METH_SIGNATURE = /^#{FUNC_LINE}\{([\\_A-Za-z0-9\s*&]*)\}\{([\\_$=!\sA-Za-z0-9]+)\}/

  # evt handler tables
  EVT_HANDLER    = /^\\twocolitem\{\{(.*?)EVT\\_([\\_(),\sA-Za-z0-9]+)/

  # any inline method reference
  INLINE_METHOD  = /([A-Z]{1,1}[_A-Za-z0-9]+)::([A-Z]{1,1}[_A-Za-z0-9]*)/

  # include files, not needed
  INCLUDE_HEADING = /^\\wxheading\{Include files\}/
  INCLUDE_LINE    = /<([\/a-z])+\.h>/
  PYTH_OR_PERL    = /^\\(python|perl)note/

  BEGIN_VERBATIM = /^\\begin\{verbatim\}/
  END_VERBATIM   = /^\\end\{verbatim\}/
  COMMENT      = /^%[^\n]*/

  # things that are always renamed
  KNOWN_RENAMES = { 'wxDefaultPosition'=>'DEFAULT\_POSITION',
                    'wxDefaultSize'=>'DEFAULT\_SIZE' }
 
  # References to Wx**** here are permitted, not corrected as bad classnames
  WX_PREFIX_ALLOWED = %w[Widgets Windows Python Perl Ruby]

  # do the parsing and return the modified latex; after parsing, the output is
  # stored as the attribute +output+
  def parse()
    self.verbatim = false
    self.removing = false

    file_as_string = File.read(src_file)
    # Start running through the lines
    file_as_string.each_line do | line |  
      # stuff to ignore and pass thru un-modified
      case line
      when BEGIN_VERBATIM
        self.verbatim = true
      when END_VERBATIM
        self.verbatim = false
      when DESTRUCTOR # start removing if destructor
        self.removing = true if self.verbatim == false
      when MEM_SECTION # other headings stop removing
        self.removing = false
      when INCLUDE_HEADING, INCLUDE_LINE
        next # skip this line
      end

      # skip this line if removing this section
      next if removing?
        
      # just include this line if in 'verbatim' section or comment
      if verbatim? or line =~ COMMENT
        output << line
        next
      end  

      case line
      when CLASS_HEADING
        class_name = $1
        class_name = fix_class_name(class_name)
        line.sub!(CLASS_HEADING, "\\\\section{\\\\class{#{class_name}}}")
      when METHOD_HEADING
        #remove c++ things we do not need
        line.tr!('&*','')
        class_name = $1
        sep = '\#'
        meth_name = $2.sub('operator ','').sub('operator','')
        self.section = $2
        if class_name == meth_name
          sep = '.'
          meth_name = 'new'
        end
        class_name = fix_class_name(class_name)
        meth_name.un_camelcase!('\_')
        line.sub!(METHOD_HEADING,
                  "\\\\membersection{#{class_name}#{sep}#{meth_name}}")
      # Functions that don't belong to a class
      when STATIC_HEADING
        scope_indicator = $1  #don't need
        func_name = $2
        line.gsub!(/(?:\\&|\*)/, '')
        func_name = func_name.gsub(/^wx\\_/,'')
        func_name = func_name.gsub(/^wx/i,'').un_camelcase('\_')
        line.sub!(STATIC_HEADING,  "\\\\membersection{Wx::#{func_name}}")
        #handle the functions
      when FUNC_LINE
        #remove c++ things we do not need
        line.gsub!(/(?:\\&|\*)/, '')
        line.gsub!(/const ?(?!a-z)/, '')

        if line =~ METH_SIGNATURE
          func_type, return_type, meth_name = $1, $2, $3
          meth_name.gsub!(/operator ?/, '')
          # find the new method
          meth_name = 'new' if meth_name == self.wx_class
          #for global functions          
          meth_name = meth_name.gsub(/^wx\\_/,'').gsub(/^wx/,'')
          meth_name.un_camelcase!('\_')
          return_type = return_type.sub(/virtual/, '').strip
          
          if return_type == "void" || return_type == "static void"
            return_type = ''
          end

          line.sub!(METH_SIGNATURE, 
                    "\\#{func_type}{#{return_type}}{#{meth_name}}")
        end
        line.gsub!('int ','Integer ')        
      # rename the event handlers   
      when EVT_HANDLER
        bitty, event_handler = $1, $2
        event_handler.gsub!(/[,]?\s*func/,'')
        event_handler.downcase!
        event_handler << " {\\it \\{ |event| ... \\} }"
        line.sub!(EVT_HANDLER, 
                  "\\twocolitem{{#{bitty}evt\\_#{event_handler}")
      else # all other handlers
        #fix method and function names not in method/function prototypes
        #TODO: May need to gather all the old names and new names in 1 pass
        #      thru tex files and then run once more to convert all these.
      end

      # ALL OTHER STUFF
      # dictionary of known types that need to be renamed
      KNOWN_RENAMES.each { | key, val| line.gsub!(key,val) }
      
      #replace instances of wxSomeClassName with SomeClassName
      line.gsub!(/wx([A-Z]\w+)/) do | match | 
        WX_PREFIX_ALLOWED.include?($1) ? match : $1
      end
      
      #replace instances of SomeClassName::MethodName with
      #SomeClassName#method_name
      line.gsub!(INLINE_METHOD) { "#{$1}\\##{$2.un_camelcase!('\_')}" }

      output << line
    end
    output
  end

  private  
  def fix_class_name(class_name)
    self.wx_class = class_name
    self.rb_class = class_name.sub(/^wx/i,'')
  end
  
  def filter_args(args)
    filtered = args.gsub(/\\helpref\{(\w*)\}\{(\w*)\}/, '\1') 
    return filtered
  end
end # ClassParser


# Rake tasks
def create_documentation_tasks
  $ruby_docs_dir = File.expand_path(File.join(Dir.pwd,'docs','latex','wx'))  
  
  desc "Create the documentation from scratch"
  task :docs => [:html_docs_clean,:gen_tex_docs,:html_docs]
    
  desc "Create LaTeX files from wxWidgets version that are more Ruby like."
  task :gen_tex_docs do
    wxdir = ENV['WXWIN']
    if wxdir == nil
      raise "The environment variable WXWIN is not set. " +
            "Make sure it is set to the path of the wxWidgets source."
    end

    #set the path to the wxWidgets latex docs  
    orig_docs_dir = File.expand_path(File.join(wxdir,'docs','latex','wx'))         
    if not File.exists?(orig_docs_dir)
      msg = %{Could not find the wxWidgets latex docs.

Make sure that the directory '#{orig_docs_dir}' exists, if it does not then you need to download the complete source distribution of wxWidgets.

see http://wxWidgets.org }  
        raise msg
    end
    
    #set the output directory for wxRuby version of docs    
    FileUtils.mkdir_p($ruby_docs_dir) unless File.exists?($ruby_docs_dir)
    
    # Copy all the contents of orig_docs_dir to ruby_docs_dir 
    # That way all the non *.tex files are copied over
    puts "Copying non LaTeX files from wxWidgets docs to wxRuby docs dir..."    

    Dir.chdir(orig_docs_dir) do   
      FileUtils.cp(Dir.glob('*'), $ruby_docs_dir)
    end

    puts "Done."
    
    puts 'Generating wxRuby version of wxWidget LaTeX documentation.'
    puts 'Processing:'

    Dir.chdir(orig_docs_dir)
    Dir.glob("*.tex").each do | file_name |
      file_path = File.join(orig_docs_dir, file_name)  
      puts file_path + '...'
      cp = ClassParser.new(file_path)
      out_file = File.join( $ruby_docs_dir, file_name )
      File.open( out_file, 'w+' ) { | f | f.write( cp.parse ) }      
    end
    puts "Finished conversion."    
  end
  
  desc "Convert LaTeX docs to HTML documentation."
  task :html_docs do
    #create the HTML output path
    html_docs_dir = File.expand_path(File.join($ruby_docs_dir,"..","..",'html'))
    FileUtils.mkdir_p(html_docs_dir) unless File.exists?( html_docs_dir )
    
    index_page = File.join(html_docs_dir, 'wx.html')
    tex_stylesheet = ENV['TEX2RTF_STYLESHEET'] || 'tex2rtf_css.ini'
    tex_args = ENV['TEX2RTF_ARGS'] || '-checkcurleybraces -checksyntax -html'
    Dir.chdir($ruby_docs_dir) do
      #create the docs
      tex_cmd = "tex2rtf manual.tex %s %s -macros %s" % 
                [ index_page, tex_args, tex_stylesheet ]
      sh tex_cmd
      #copy the image files to location of docs
      FileUtils.cp(Dir.glob('*.gif'), html_docs_dir)
    end
  end

  desc "Clean up temporary files from HTML documentation generation."
  task :html_docs_clean do
    if File.exist?($ruby_docs_dir)
      FileUtils.cd($ruby_docs_dir) do
        FileUtils.rm_rf(Dir.glob('*.con'))
      end
    end
  end
end
