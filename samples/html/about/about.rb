
require 'wxruby'

MINIMAL_QUIT,
MINIMAL_ABOUT,
MINIMSL_BACK,
MINIMAL_FORWARD,
MINIMAL_TEXT = (1..5).to_a

class MyFrame < Wx::Frame
    def initialize(title, pos, size)
        super(nil, -1, title, pos, size)

        evt_menu(MINIMAL_QUIT) {on_quit}
        evt_menu(MINIMAL_ABOUT) {on_about}

        menu_file = Wx::Menu.new
        menu_file.append(MINIMAL_ABOUT, "&About")
        menu_file.append(MINIMAL_QUIT, "E&xit")

        menu_bar = Wx::MenuBar.new
        menu_bar.append(menu_file, "&File")

        set_menu_bar(menu_bar)
    end

   def on_quit
      close(TRUE)
   end

   def on_about
        dlg = Wx::Dialog.new(self, -1, "About")

        topsizer = Wx::BoxSizer.new(Wx::VERTICAL)

        html = Wx::HtmlWindow.new(dlg, -1, Wx::DEFAULT_POSITION, Wx::Size.new(380, 160), Wx::HW_SCROLLBAR_NEVER)
        html.set_borders(0)
        html.load_page("data/about.htm")
        #html.set_size(html.get_internal_representation.get_width,  # FIXME
        #              html.get_internal_representation.get_height)

        topsizer.add(html, 1, Wx::ALL, 10)

        #topsizer.add(Wx::StaticLine.new(dlg, -1), 0, Wx::EXPAND | Wx::LEFT | Wx::RIGHT, 10) # FIXME

        bu1 = Wx::Button.new(dlg, Wx::ID_OK, "OK")
        bu1.set_default

        topsizer.add(bu1, 0, Wx::ALL | Wx::ALIGN_RIGHT, 15)

        dlg.set_auto_layout(TRUE)
        dlg.set_sizer(topsizer)
        topsizer.fit(dlg)

        dlg.show_modal
    end
end

class MyApp < Wx::App
   def on_init
      #Wx::Image::add_handler(Wx::PNGHandler.new) FIXME
      frame = MyFrame.new("wxHtmlWindow testing application",
              Wx::Point.new(50, 50), Wx::Size.new(150, 50))

      frame.show(TRUE)
      set_top_window(frame)
   end
end

a = MyApp.new
a.main_loop()
