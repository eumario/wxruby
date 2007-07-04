class Wx::XmlResource
  # The standard .load method returns a boolean indicating success or
  # failure. Failure might result from bad XML, or a non-existent
  # file. In ruby, in these circumstances, it's more natural to raise an
  # Exception than expect the user to test the return value.
  wx_load = self.instance_method(:load)
  define_method(:load) do | fname |
    result = wx_load.bind(self).call(fname)
    if not result
      Kernel.raise( RuntimeError,
                    "Failed to load XRC from '#{fname}'; " +
                    "check the file exists and is valid XML")
    end
    fname
  end
end
