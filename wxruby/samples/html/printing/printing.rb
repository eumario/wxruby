require 'wxruby'

MINIMAL_QUIT,
MINIMAL_PRINT,
MINIMAL_PREVIEW,
MINIMAL_PAGESETUP,
MINIMAL_PRINTSETUP,
MINIMAL_OPEN = (1..6).to_a


class MyApp < Wx::App
    def on_init
        #Wx::Image::add_handler(Wx::PNGHandler.new)
        #Wx::Image::add_handler(Wx::JPEGHandler.new)
        #Wx::Image::add_handler(Wx::GIFHandler.new)

        frame = MyFrame.new("Printing test", Wx::Point.new(150, 50),
                Wx::Size.new(640, 480))

        frame.show(TRUE)
        set_top_window(frame)

        return TRUE
    end
end

class MyFrame < Wx::Frame
    def initialize(title, pos, size)
        super(nil, -1, title, pos, size)

        evt_menu(MINIMAL_QUIT) {on_quit}
        evt_menu(Wx::ID_ABOUT) {on_about}
        evt_menu(MINIMAL_PRINT) {on_print}
        evt_menu(MINIMAL_PREVIEW) {on_preview}
        evt_menu(MINIMAL_PAGESETUP) {on_page_setup}
        evt_menu(MINIMAL_PRINTSETUP) {on_print_setup}
        evt_menu(MINIMAL_OPEN) {on_open}

        menu_file = Wx::Menu.new
        menu_file.append(MINIMAL_OPEN, "Open...\tCtrl-O")
        menu_file.append_separator
        menu_file.append(MINIMAL_PAGESETUP, "Page Setup")
        menu_file.append(MINIMAL_PRINTSETUP, "Printer Setup")
        menu_file.append(MINIMAL_PRINT, "Print...")
        menu_file.append(MINIMAL_PREVIEW, "Preview...")
        menu_file.append_separator
        menu_file.append(Wx::ID_ABOUT, "&About")
        menu_file.append_separator
        menu_file.append(MINIMAL_QUIT, "&Exit")

        menu_bar = Wx::MenuBar.new;
        menu_bar.append(menu_file, "&File")

        set_menu_bar(menu_bar)

        create_status_bar(1)

        m_Html = Wx::HtmlWindow.new(self)
        m_Html.set_related_frame(self, "HTML : %s")
        m_Html.set_related_status_bar(0)
        @m_Name = "test.htm"
        m_Html.load_page(@m_Name)
 
        @m_Prn = Wx::HtmlEasyPrinting.new("Easy Printing Demo", self)
        @m_Prn.set_header(@m_Name + "(@PAGENUM@/@PAGESCNT@)<hr>", Wx::PAGE_ALL)
    end

    def on_quit
        close(TRUE)
    end

    def on_about
        Wx::MessageBox.new("HTML printing sample\n\n(c) Vaclav Slavik, 1999")
    end


    def on_print_setup
        @m_Prn.printer_setup
    end

    def on_page_setup
        @m_Prn.page_setup
    end

    def on_print
        @m_Prn.print_file(@m_Name)
    end

    def on_preview
        @m_Prn.preview_file(@m_Name)
    end

    def on_open
        dialog = Wx::FileDialog.new(self, "Open HTML page", "", "", "*.htm", 0)

        if (dialog.show_modal == Wx::ID_OK)
            @m_Name = dialog.get_path
            @m_Html.load_page(@m_Name)
            @m_Prn.set_header(@m_Name + "(@PAGENUM@/@PAGESCNT@)<hr>", Wx::PAGE_ALL)
        end
    end
end

a = MyApp.new
a.main_loop()

