# Pure-ruby implementation of the corresponding Wx class. Shows a
# relevant section of help, if available, or a native popup
require 'wx/classes/simplehelpprovider'
class Wx::HelpControllerHelpProvider < Wx::SimpleHelpProvider
  def initialize(help_controller)
    super()
    @hc = help_controller
  end

  # Show help for +win+; if the help text for +win+ is a string with a
  # single integer only, treats that as a section id for help and shows
  # that, otherwise shows a popup (native-style on Windows) of the text.
  def show_help(win)
    help_text = get_help(win)
    return false if help_text.empty?
    if help_text =~ /\A\d+\z/
      @hc.display_context_popup(help_text.to_i)
    else
      @hc.display_text_popup(help_text, Wx::get_mouse_position)
    end
    true
  end
end
