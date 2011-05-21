require 'erb'
require 'ostruct'

# Provides templated output of a Ruby subclass from an XRC specification
# of a ruby Frame, Dialog or Panel class.
class Outputter
  # Valid options are :app_name and :module_name
  attr_accessor :options, :klass

  # Creates a new outputter from the XRCClass +xrc_class+
  def initialize(xrc_class, options = {})
    @klass = xrc_class
    @options = options
  end

  # Writes the ruby code to the file or stream +io+
  def output(io = $stdout)
    tpl = ERB.new(TEMPLATE)
    io.puts( tpl.result(binding) )
  end

  # Returns the fully-qualified (including module namespace prefix) for
  # +name+.
  def fq_name(name)
    options[:namespace] ? "#{options[:namespace]}::#{name}" : name
  end

  # Returns the options object 
  def opts
    OpenStruct.new(options)
  end

  # Utility function to format the attr_readers line so it doesn't wrap
  # in editors
  def clean_id_attr_readers(str, start_len = 15, one_per_line = false)
    new_string = ''
    
    if one_per_line
      str.split(',').each do | x |
        new_string << "#{x},"
        new_string << "\n" + " " * (start_len-2)        
      end
    else      
      wanted_length = 72
      current_line_length = start_len
      str.split(',').each do | x |
        if (current_line_length + x.length) > wanted_length
          new_string << "\n" + " " * (start_len-2)
          current_line_length = start_len
        end
        new_string << "#{x},"
        current_line_length += x.length      
      end 
    end
    return new_string 
  end
end


Outputter::TEMPLATE = <<'TEMPLATE'
<% if opts.app_name %>
require 'wx'
<% if opts.namespace %>
module <%= opts.namespace %>
end
<% end %><% end %>
# This class was automatically generated from XRC source. It is not
# recommended that this file is edited directly; instead, inherit from
# this class and extend its behaviour there.  
#
# Source file: <%= klass.file_name %> 
# Generated at: <%= Time.now %>

class <%= fq_name(klass.sub_class) %> < <%= klass.superclass %>
  <% if not klass.controls.empty? %><% ids = klass.controls.map { | ctrl | ":#{ctrl.name.downcase}" }.join(', ') %>
  attr_reader <%= clean_id_attr_readers(ids) %>
  <% end %>
  def initialize(parent = nil)
    super()
    xml = Wx::XmlResource.get
    xml.flags = 2 # Wx::XRC_NO_SUBCLASSING
    xml.init_all_handlers
    xml.load("<%= klass.file_name %>")
    xml.<%= klass.load_func %>(self, parent, "<%= klass.base_id %>")

    finder = lambda do | x | 
      int_id = Wx::xrcid(x)
      begin
        Wx::Window.find_window_by_id(int_id, self) || int_id
      # Temporary hack to work around regression in 1.9.2; remove
      # begin/rescue clause in later versions
      rescue RuntimeError
        int_id
      end
    end
    <% klass.controls.each do | ctrl | %>
    @<%= ctrl.name.downcase %> = finder.call("<%= ctrl.name %>")<% if ctrl.sub_class %>
    @<%= ctrl.name.downcase %>.extend(<%= fq_name(ctrl.sub_class) %>)<% end %><% end %>
    if self.class.method_defined? "on_init"
      self.on_init()
    end
  end
end

<% if opts.app_name %>
class <%= opts.app_name %> < Wx::App
  def on_init
    f =  <%= opts.module_name %>::<%= fq_name(klass.sub_class) %>.new
    f.show
  end
end
<%= opts.app_name %>.new.main_loop
<% end %>
TEMPLATE
