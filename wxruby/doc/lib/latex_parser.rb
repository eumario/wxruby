require 'strscan'

# This is the base class for a Latex parser. It's a stream-oriented
# parser that accumulates its output in a string. It will need to be
# subclassed to do anything much useful except strip out the text-only
# content. 
# When an element (the start or end of a command, or text content) is
# found, it searches for a handling method in the subclass.
#
# To handle the start of a command +command+, define a method called
# +command_start+. So, to handle the start of a 'foo' command in the
# Latex, create a method +foo_start+. The method receives no
# arguments. The command is always added to the stack of seen methods,
# and a new content buffer created for it.
# 
# To handle text content, create a method called +command_content+,
# where +command+ is the name of the current Latex element. So, to
# handle textt content within a +foo+ element, create a a method
# +foo_content+ which receives a single argument, the text content.
#
# To handle the close of a command, create a method called
# +command_end+. This method will normally remove the command from the
# stack of opened commands, and append its buffer to the buffer of the
# next outermost containing command.
# 
# Some Latex commands are 'standalone' in that they do not have any
# associated content - there is no opening brace after them. For
# example, +\rtfsp+. Such commmands do not fire a 'start' method, but
# instead should be handled by definining a +do_command+ method - for
# example, +do_rtfsp+.
class LatexParser < StringScanner
  attr_accessor :tag_stack, :output, :buffers
  def self.new_from_file(file)
    new(File.read(file))
  end

  # Create a new Latex parser, with +str+ being the Latex text source.
  def initialize(str)
    @source = str
    # delete comments
    @source.gsub!(/(^|[^\\])%[^\n]*?\n/) { $1 }
    # unescape escapes
    @source.gsub!(/\\([&_])/, '\1')
    super(@source)
    @tag_stack   = []
    @buffers  = []
    @output = ''
  end

  # the output buffer of the current command.
  def buffer
    @buffers.last
  end

  # the current command that we're inside
  def tag
    @tag_stack.last
  end

  
  # add some text. Each content-containing command has its own buffer,
  # which is added to the parent buffer as the command is completed. At
  # the top level (outside all commands), appended text is added to
  # output. If you define command_content methods, it is up to them to
  # call this +append+ method to add the output. This allows them to
  # manipulate the text they add before it is finally output.
  def append(text)
    text ||= ''
    buffer ? buffer << text : output << text
  end

  # Handle a content-less command.
  def do_standalone(a_standalone)
    if respond_to?("do_#{a_standalone}")
      send "do_#{a_standalone}"
    end
  end

  # Handle the start of a new command tag.
  def do_start_tag(new_tag)
    tag_stack.push(new_tag)
    buffers.push('')
    if respond_to?("#{tag}_start")
      send "#{tag}_start"
    end
  end
  
  # Handle the end of a content-containing command.
  def do_end_tag()
    if respond_to?("#{tag}_end")
      send "#{tag}_end"
    end
    tag_stack.pop()
    do_content( buffers.pop )
  end

  # Handle textual content, passing to the appropriate command's handler
  # if inside a command.
  def do_content(content)
    if respond_to?("#{tag}_content")
      send "#{tag}_content", content
    else
      default_content(content)
    end
  end

  # The main parsing engine - steps through the elements in the Latex
  # document, firing content and command handling methods in turn and
  # accumulating the output in the string attribute +output+. Returns
  # the output.
  def parse()
    while not eos?
      # At start of a command
      if command = scan(/\\\w+/)
        command = command[1 .. -1]
        if peek(1) == '{'
          do_start_tag(command)
        else
          do_standalone(command)
        end
      # An opening brace - start of command content
      elsif scan(/\{/)
        # empties
        do_content('') if peek(1) == '}'
        # inner commands - weird?
        if command = scan(/\\\w+ /)
          do_start_tag(command[1..-1].strip)
        end
      # Closing brace - end of command content
      elsif scan(/\}/)
        do_end_tag unless peek(1) == '{' # if expecting more for this tag
      # Anything else - scan until the start of a command, or the end
      elsif content = scan_until(/(?=\{?\\\w+|\}|\z)/)
        do_content(content)
      else
        raise "Bad scan at #{pos}: '#{peek(20)}'"
      end
    end
    terminate()
    return output
  end
  
  # Default content handler - append the text content to the next
  # outermost buffer.
  def default_content(content)
    append content
  end
end
