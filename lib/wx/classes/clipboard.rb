class Wx::Clipboard
  # See if we like these better
  alias :place :set_data
  alias :fetch :get_data

  class << self
    # This is provided internally by the SWIG interface file, but all
    # public access should be via Clipboard.open; see below
    private :get_global_clipboard

    # Class method to provide access to the clipboard within a ruby
    # block. Tests that the clipboard could be accessed, and ensures
    # that it is closed when the block is finished.
    def open
      clip = nil
      # Trying to access the segfault outside main_loop will segfault on
      # some platforms (eg, GTK)
      unless Wx::const_defined?(:THE_APP)
        raise RuntimeError, 
              "The clipboard can only be accessed when the App is running"
      end

      clip = get_global_clipboard
      unless clip.open
        Kernel.raise "Could not open clipboard"
      end
      yield clip
     ensure
       clip.close if clip
    end
  end
end
