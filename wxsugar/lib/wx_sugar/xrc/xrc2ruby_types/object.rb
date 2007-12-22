module XRC2Ruby::ObjectTypes
  # Anything deriving from Wx::Object
  class Object
    attr_accessor :centered

    def inspect 
      "<#{self.class}>"
    end
    def self.next_id
      @id_counter ||= 0
      @id_counter += 1
    end

    attr_reader :parent, :win_class, :sub_class, :name
    def initialize(parent, win_class, sub_class = nil, var_name = nil)
      @parent    = parent
      @win_class = win_class.gsub(/^wx/, "Wx::")
      @sub_class = sub_class
      
      # A named and externally accessible item
      if var_name and not var_name.empty? and 
         var_name !~ /^ID_/ and var_name !~ /^wx/
        @name = "@#{var_name.downcase}"
      # Or just a local name
      else
        @local_id = Object.next_id
      end
    end

    def var_name
      @name || "#{self.class.name[/\w+$/].downcase}_#{@local_id}"
    end

    def output
      # Should be defined in subclasses
      Kernel.raise "Shouldn't be called"
    end
  end
end
