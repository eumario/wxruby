require 'wx'
include Wx

class MyFrame < Frame
  def initialize()
    super(nil,-1,'test')

        panel = self#Panel.new(self)
	@m_spintext = TextCtrl.new( panel, -1, '')
  	#@m_spintext.destroy
  end
end

class RbApp < App
  def on_init
    frame = MyFrame.new
    frame.show(TRUE)
  end
end

a = RbApp.new
a.main_loop()
