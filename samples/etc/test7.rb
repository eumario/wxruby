
require 'wxruby'
include Wx

ID_CHECKLISTBOX = 1000

class CheckListBoxDlg < Dialog
  def initialize
    super(nil, -1, "Test", DEFAULT_POSITION, Size.new(150, 150))

    list = [ "ABS", "Airbag", "Air conditioning" ]

    @m_pCheckListBox = CheckListBox.new(self, ID_CHECKLISTBOX, DEFAULT_POSITION, DEFAULT_SIZE, list)

    dlgSizer = BoxSizer.new(HORIZONTAL)
    checkListBoxSizer = BoxSizer.new(VERTICAL)
    checkListBoxSizer.add(@m_pCheckListBox, 1, GROW)
    dlgSizer.add(checkListBoxSizer, 1, GROW)
    set_sizer(dlgSizer)
    set_auto_layout(TRUE)
    layout()

    evt_checklistbox(ID_CHECKLISTBOX) {|event| onCheck(event)}
    evt_close {onClose}
  end

  def onCheck(command)
    item = command.get_selection
    msg = sprintf("You clicked on item %d. The item is now %s", item,
               @m_pCheckListBox.is_checked(item) ? "checked" : "unchecked")
    message_box(msg)
  end

  def onClose
     destroy()
  end
end

class RbApp < App
  def OnInit
    dlg = CheckListBoxDlg.new
    set_top_window(dlg)
    dlg.show(TRUE)
  end

end

a = RbApp.new
a.main_loop()
