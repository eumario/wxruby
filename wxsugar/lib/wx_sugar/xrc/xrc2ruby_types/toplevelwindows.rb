module XRC2Ruby::ObjectTypes
  # All windows which may be top-level containers (eg Frames,
  # Dialogs). In particular, they may become named ruby subclasses
  class TopLevelWindow < Window
    include Parent
    attr_accessor :title
    def output
      if not named_windows.empty?
        attr_reader = "attr_reader " + 
          named_windows.map { | name | name.tr('@', ':') }.join(', ')
      end

      @name = "self"
      # get child widgets code and indent to four spaces
      "class #{sub_class} < #{win_class}
  #{attr_reader}" +
  ( XRC2Ruby.use_gettext ? "include GetText\n" : "" ) + "
  def initialize(parent)
    super(parent, #{args})
" + child_output.gsub(/^/, '    ') + "
  end
end"
    end
  end

  class Dialog < TopLevelWindow; end
  class Frame < TopLevelWindow; end
  class MiniFrame < TopLevelWindow; end
end
