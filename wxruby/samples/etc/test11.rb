
require 'wxruby'
include Wx

ID_LISTBOX = 1000

class ListBoxDlg < Dialog
  def initialize
    super(nil, -1, "ListboxDialog", DEFAULT_POSITION, Size.new(185, 185))

    list = [ "ABS", "Airbag", "Air conditioning" ]

    @m_pListBox = ListBox.new(self, ID_LISTBOX, DEFAULT_POSITION, DEFAULT_SIZE, list)

    dlgSizer = BoxSizer.new(HORIZONTAL)
    listboxSizer = BoxSizer.new(VERTICAL)
    listboxSizer.add(@m_pListBox, 1, GROW)
    dlgSizer.add(listboxSizer, 1, GROW)
    set_sizer(dlgSizer)
    set_auto_layout(TRUE)
    layout()

    evt_listbox_dclick(ID_LISTBOX) {onListboxDClick}
    evt_close {onClose}
  end

  def onListboxDClick
    selection = @m_pListBox.get_string_selection
    message_box("You double clicked on " + selection)
  end

  def onClose
     destroy()
  end
end

class RbApp < App
  def on_init
    dlg = ListBoxDlg.new
    set_top_window(dlg)
    dlg.show(TRUE)
  end

end

a = RbApp.new
a.main_loop()
