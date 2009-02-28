class Wx::XmlResource
  # XRC_NO_SUBCLASSING should always be in place in wxRuby - we can't
  # currently link directly to wxRuby subclasses.
  class << self
    wx_get = self.instance_method(:get)
    define_method(:get) do 
      res = wx_get.bind(self).call
      res.flags |= Wx::XRC_NO_SUBCLASSING
      res
    end
  end

  # WxRuby already has all XRC handlers built in so there's no way to
  # control init_all_handlers to reduce binary size. So save users
  # having to call it.
  wx_init = self.instance_method(:initialize)
  define_method(:initialize) do | *args |
    result = wx_init.bind(self).call(*args)
    result.flags |= Wx::XRC_NO_SUBCLASSING
    result.init_all_handlers
  end

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

  # Returns a Wx::Wizard object from the element named +name+ in the
  # loaded XRC file. The Wizard will have the parent +parent+.
  # 
  # This method is not available in wxWidgets, but is here for
  # completeness and also to document how to use load_object (see
  # below).
  def load_wizard(parent, name)
    wiz = Wx::Wizard.new()
    load_wizard_subclass(wiz, parent, name)
    wiz
  end

  # Completes the loading of a incomplete instance of Wx::Wizard.
  def load_wizard_subclass(wizard, parent, name)
    load_object(wizard, parent, name, "wxWizard")
  end
end
