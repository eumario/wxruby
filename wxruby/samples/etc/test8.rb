
require 'wxruby'
include Wx

ID_CHOICE = 1000

class ChoiceDlg < Dialog
  def initialize
    super(nil, -1, "ChoiceDialog", DEFAULT_POSITION, Size.new(185, 185))

    list = [ "ABS", "Airbag", "Air conditioning" ]

    @m_pChoice = Choice.new(self, ID_CHOICE, DEFAULT_POSITION, DEFAULT_SIZE, list)
    @m_pChoice.append("Automatic gear", 100)

	@m_pLabel = StaticText.new(self, -1, "default")
    dlgSizer = BoxSizer.new(HORIZONTAL)
    choiceSizer = BoxSizer.new(VERTICAL)
    choiceSizer.add(@m_pChoice, 1, GROW)
	choiceSizer.add(@m_pLabel)
    dlgSizer.add(choiceSizer, 1, GROW)
    set_sizer(dlgSizer)
    set_auto_layout(TRUE)
    layout()

    evt_choice(ID_CHOICE) {|event| onChoice(event) }
    evt_close {onClose}
  end

  def onChoice(event)
  	# The following will sometimes cause a segfault with 
	# the current implementation 2003-06-24 kbs
  	#GC.start
  	chose = event.get_selection
	data = event.get_client_data
	if(data == nil)
		data = 0
	end
	data += 1
	@m_pLabel.set_label(data.to_s)

	@m_pChoice.set_selection(chose)
	@m_pChoice.set_client_data(chose, data)
  end

  def onClose
     destroy()
  end
end


class RbApp < App
  def OnInit
    dlg = ChoiceDlg.new
    set_top_window(dlg)
    dlg.show(TRUE)
  end

end

a = RbApp.new
a.main_loop()
