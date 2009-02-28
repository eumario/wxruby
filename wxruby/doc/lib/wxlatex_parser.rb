require 'latex_parser'
require 'redcloth'
require 'stringhelper'


# Class to parse WxWidgets Latex documentation into Textile
# format. At the moment
class WxWLatexParser < LatexParser
  attr_accessor :removing
  alias :removing? :removing
  attr_reader :wx_class, :rb_class

  def initialize(str)
    super(str)
    @sections = []
  end

  def append(arg)
    super(arg) unless removing?
  end

  CPP_TO_RUBY_TYPES = { 'long' => 'Integer', 
                        'unsigned long' => 'Integer', 
                        'int'  => 'Integer',
                        'wxDouble' => 'Float',
                        'wxRichTextRange' => 'Range',
                        'wxString' => 'String',
                        'double' => 'Float',
                        'unsigned char' => 'Integer',
                        'wxWindowID' => 'Integer',
                        'void' => '', 
                        'bool' => 'Boolean' }

  # modifies +cpp_type+ in place to a ruby type
  def fix_type(cpp_type)
    if CPP_TO_RUBY_TYPES.key?(cpp_type)
      cpp_type.replace( CPP_TO_RUBY_TYPES[cpp_type] )
    end
    cpp_type.sub!(/^wx/i, '')
  end

  WX_METHOD_NAME = /^wx([A-Z]\w+)::(?:wx)?(\w+)$/
  # return a two element array containing the Ruby classname and
  # CamelCaseMethodName  if +str+ looks like a wxMethod name, else false.
  def is_method?(str)
    if str =~ WX_METHOD_NAME
      return [$1, $2]
    else
      return false
    end
  end
  
  CPP_TO_RUBY_CONSTANTS = { 'wxDefaultPosition'  => 'DEFAULT_POSITION',
                            'wxDefaultSize'      => 'DEFAULT_SIZE',
                            'wxDefaultValidator' => 'DEFAULT_VALIDATOR',
                            'wxEmptyString'      => "''",
                            'NULL'               => 'nil' }

  # Doesn't modify in-place
  def fix_def_value(def_value)
    if CPP_TO_RUBY_CONSTANTS.key?(def_value)
      CPP_TO_RUBY_CONSTANTS[def_value]
    else
      def_value.sub(/^wx/, '')
    end
  end


  # fixes +cpp_method+ name (eg wxButton#GetLabel) to a ruby method name
  # (Button#get_label). Finds new methods. TODO - static functions.
  def fix_method(cpp_method)
    cpp_method.sub!(/^wx([A-Z]\w+)::wx\1/) { "#{$1}.new" }
    cpp_method.sub!(/^wx([A-Z]\w+)::operator ?\$([^$]+)\$/) { "#{$1}##{$2}" }
    cpp_method.sub!(WX_METHOD_NAME) { "#{$1}##{$2.un_camelcase}" }
  end


  # MAIN CONTENT METHODS
  def class_content(content)
    @wx_class  = content
    @rb_class  = content.sub(/^wx/, '')
    @sections  = []
    append "Wx::" << @rb_class
  end

  def section()
    @sections.last
  end

  def section=(section)
    @sections << section
  end

  def section_start
    append "h1. "
  end

  def wxheading_start
    self.removing = false
    if self.section # if we're inside a method description
      append "h4. "
    else
      append "h2. " 
    end
  end

  def wxheading_content(content)
    if content == 'Include files'
      self.removing = true
    else
      append content
    end
  end

  # windowstyle tag
  def windowstyle_content(content)
    append "@#{content}@"
  end

  def membersection_start
    self.removing = false
    append "h3. "
  end

  # record the current section
  def membersection_content(content)
    self.section = content
    fix_method(section)
    append section
  end

  def membersection_end()
    if buffer =~ /DESTRUCTOR/
      self.removing = true
      @sections.pop
    end
  end

  def func_start
    self.removing = false
  end

  def func_content(content)
    if not @ret_value
      @ret_value = content
      @ret_value.gsub!(/(static|virtual|const) ?/, '')
      @ret_value.sub!(/\s*[*&]$/, '')
      if @ret_value =~ /^wx(?!String)/
        looks_like_wx_class = true
      end
      fix_type(@ret_value)
      if looks_like_wx_class
        append " \"#{@ret_value}\":#{@ret_value.downcase}.html"
      else
        append " #{@ret_value}"
      end
    elsif not @func_name
      if content == wx_class
        @func_name = "#{rb_class}.new"
      elsif content =~ /operator ?$([^$]+)$/
        @func_name = $1
      else
        @func_name = content.un_camelcase
      end
      append " *#{@func_name}*("
    else # a param
      append content
    end
  end
  alias :constfunc_content :func_content

  # reformats a function description line so that it doesn't overrun lines
  def func_end
    @ret_value, @func_name, @params = nil, nil, nil

    # if zero-param function
    if buffer.empty?
      buffer << ")" 
      return
    end

    # remove 'default constructor'
    if buffer =~ /\*#{rb_class}\.new\*\($/
      self.removing = true
      return
    end

    buffer.gsub!(/\n/, '')
    new_buffer, *rest  = buffer.split(',')
    indent_point = new_buffer.index('(') - 2

    # reduce indent, adjusting by link href if the return value has a
    # Link on it.
    if new_buffer =~ /^ "(?:\w+)"(\:[^ ]+)/
      indent_point -= $1.length
    end

    while rest && param = rest.shift
      new_buffer << ', '
      # if adding a param would make it longer than a "line"
      if ( new_buffer =~ /$/ ) + param.length > 100
        new_buffer << "\n" << " " * indent_point 
      end
      new_buffer << param
    end
    new_buffer << ")"
    buffer.replace(new_buffer)
  end
  alias :constfunc_end :func_end

  def param_content(content)
    if not @param_type
      @param_type = content
      @param_type.gsub!(/(?:const|\*|\&)/, '')
      @param_type.strip!
      is_standard_class = true if CPP_TO_RUBY_TYPES.key?(@param_type)
      fix_type(@param_type)

      if is_standard_class # normal ruby class
        append "%(arg-type)#{@param_type}%"
      else # looks like wxRuby class
        append "%(arg-type)\"#{@param_type}\":#{@param_type.downcase}.html%"
      end
    elsif not @param_name
      @param_name = content
      @param_name.sub!(/\*/, '')
      @param_name.sub!(/``/, '"')
      @param_name.sub!(/\=\s+(\w+)/) { "= " << fix_def_value($1) }
      # would be nice to italicise argument names, but it doesn't work
      # with single-letter names (eg 'x')
      # @param_name.sub!(/(\w+/) { "_#{$1}_" }
      append " " << @param_name
    else
      append content
    end
  end

  def param_end
    buffer.squeeze!(' ') 
    @param_type, @param_name = nil, nil
  end

  def pythonnote_start
    self.removing = true
  end
  alias :perlnote_start :pythonnote_start

  def pythonnote_end
    self.removing = false
  end
  alias :perlnote_end :pythonnote_end


  def docparam_content(content)
    if not @param_name
      @param_name = content
      append "* _#{content}_ "
    else
      append content
    end
  end

  def docparam_end()
    # consume an extra new-line if another param is coming, tighten up listo
    if peek(11) == "\n\n\\docparam"
      scan(/\n/) 
    end
    @param_name = nil
  end

  def do_void()
    append ''
  end

  def do_rtfsp()
    scan(/\n/)
    append " "
  end

  def do_itemsep()
    if peek(1) == '='
      scan(/\=\w+/)
    end
  end

  # item in a enumerated list
  def do_item()
    if @special_command == 'enumerate'
      append '#'
    elsif @special_command == 'itemize'
      append '*'
    end
  end

  def destruct_content(content)
    append 'DESTRUCTOR'
  end

  def label_content(content)
    if wx_class
      content.sub!(/ctor$/, 'new')
      content.sub!(/#{wx_class.downcase}(\w+)/) { "#{@rb_class}_#{$1}" }
    end
    @anchor = content
  end

  def label_end
    # change anchored to end of whole output buffer
    output.sub!( /^(h\d|p)\. (.*)\z/ ) { "#{$1}(##{@anchor}). #{$2}" }
  end

  def twocolwidtha_content(content)
  end

  def twocolitem_start
    append '|'
  end

  def twocolitem_content(content)
    content.sub!(/EVT_(\w+)\((?:(id), )?func\)/) do
      "evt_#{$1.downcase}(#{$2})&nbsp;" +
      "{&nbsp;&#124;&nbsp;event&nbsp;&#124;&nbsp;...&nbsp;}"
    end
    content.gsub!(/\n/, '')
    if not @first
      @first = content
      append "#{content}|"
    else
      append content
    end
  end

  def twocolitem_end()
    append '|'
    @first = nil
  end

  def it_content(content)
    append "_#{content}_"
  end

  def bf_content(content)
    append "*#{content}*"
  end

  def tt_content(content)
    append "@#{content}@"
  end
  alias :texttt_content :tt_content

  # beginning of special command section, actual content shouldn't be
  # output 
  def begin_content(content)
    @special_command = content
  end

  # end of a begin special command - we scan forward and slurp up
  # everything if we're in a +verbatim+ command.
  def begin_end()
    if @special_command == 'verbatim'
      verbatim = scan_until(/(?=\\end\{verbatim\})/)
      verbatim.gsub!(/\n/, "\n ")
      # fix these because redcloth seems broken...
      # verbatim.gsub!(/</, "&lt;")
      # verbatim.gsub!(/>/, "&gt;")
      buffer.replace(verbatim)
    end
  end

  # The end of a special command section - the content is the name of
  # the special command (eg 'verbatim') that is being ended. 
  def end_content(content)
    @special_command = nil
  end

  # Store the name and target of a cross-reference - the actual creation
  # of the link is done in the method +helpref_end+
  def helpref_content(content)
    # the first bit of content is the link text
    if not @link_text
      @link_text = content
    # then the link target
    else
      @link_target = content
    end
  end

  # Actually create a cross-reference helplink.
  def helpref_end()
    # if it looks like a link to a Class::Method
    if is_method?(@link_text)
      fix_method(@link_text)
      klass, meth = @link_text.split(/[#.]/)
      # the link targets don't have underscores in them
      meth.delete!('_')
      append "\"#{@link_text}\":#{klass.downcase}.html##{klass}_#{meth}"
    # if just a link to a method
    elsif @link_text.camelcase?
      @link_text.un_camelcase!
      # the link targets don't have underscores in them
      tgt = @link_text.delete('_')
      tgt = 'new' if tgt == 'ctor'
      append "\"#{@link_text}\":##{rb_class}_#{tgt}"
    # if just a link to a class
    elsif @link_target =~ /^wx(\w+)$/
      append "\"#{@link_text}\":#{$1}.html"
    else
      append "\"#{@link_text}\":#{@link_target}.html"
    end
    @link_text, @link_target = nil, nil
  end

  # Clean up some naming conventions, and a few other oddities.
  def default_content(content)
    if content
      content.sub!(/^# /, ' #')
      content.sub!(/\\\\/, "\n")
      content.gsub!(/wx([A-Z_]+)/) { $1 }
      content.gsub!(/$(\-?\d?|\*|\+\**?)$/) { $1 }
      content.gsub!(/<wx\/([\w\.]+?)>/) { "&lt;wx/#{$1}&gt;" }
    end
    super(content)
  end
end

# Subclass of the main WxLatex parser, designed to break up the Latex
# docs (which sometimes contain several different classes in one file)
# into one-class-per-file output. 
class WxWLatexClassParser < WxWLatexParser
  def self.new_from_file(in_file, out_dir)
    new(File.read(in_file), out_dir)
  end

  # Because several Textile files may be output from a single Latex
  # source, you must specify an output directory +out_dir+ where the
  # resulting files will be written. The Textile document for each class
  # will be named after the class, in lowercase and *without*
  # underscores. This convention is required because of the way some
  # cross-reference links are specified in the Latex sources.
  def initialize(src, out_dir)
    super(src)
    @out_dir = File.expand_path( out_dir )
  end

  # redirect output to a new file
  def class_content(content)
    if rb_class # if we've just done a class, write to file
      write_pending_output()
    end
    self.output = ''
    super(content)
  end

  def terminate()
    if rb_class # if we've just done a class, write to file
      write_pending_output()
    end
  end

  def write_pending_output()
    output.sub!(/^h2. Members/) do
      # collect and index all class's methods
      meths = "<div id=\"methods\">\n\nh2. Methods\n" 
      meths << @sections.inject('') do | str, sect |
        if sect =~ /(\w+)$/
          tgt = $1.delete('_')
          str << "\n* \"#{sect}\":##{rb_class}_#{tgt}"
        end
        str
      end
      meths << "\n\n</div>\n"
    end
    out_file = File.join(@out_dir, 
                          rb_class.gsub(/\W/, '').downcase + '.txtl')
    File.open(out_file, 'w+') { | f | f.write output }
  end
end
