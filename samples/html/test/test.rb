require 'wxruby'

MINIMAL_QUIT,
MINIMAL_PAGEOPEN,
MINIMAL_BACK,
MINIMAL_FORWARD,
MINIMAL_PROCESSOR,
MINIMAL_TEXT = (1..6).to_a

class MyApp < Wx::App
    def on_init
#if wxUSE_SYSTEM_OPTIONS
#       Wx::SystemOptions::set_option("no-maskblt", 1) FIXME
#endif

        Wx::init_all_image_handlers
#if wxUSE_FS_INET && wxUSE_STREAMS && wxUSE_SOCKETS
#       Wx::FileSystem::add_handler(Wx::InternetFSHandler.new) FIXME
#endif

        set_vendor_name("wxWindows")
        set_app_name("wxHtmlTest")

        frame = MyFrame.new("wxHtmlWindow testing application",
            Wx::Point.new(50, 50), Wx::Size.new(640, 480))

        frame.show(TRUE)
        set_top_window(frame)

        return TRUE
    end
end

class MyFrame < Wx::Frame
    def initialize(title, pos, size)
        super(nil, -1, title, pos, size, Wx::DEFAULT_FRAME_STYLE,
          "html_test_app")

        evt_menu(MINIMAL_QUIT) {on_quit}
        evt_menu(MINIMAL_PAGEOPEN) {on_page_open}
        evt_menu(MINIMAL_BACK) {on_back}
        evt_menu(MINIMAL_FORWARD) {on_forward}
        evt_menu(MINIMAL_PROCESSOR) {on_processor}

        menu_file = Wx::Menu.new
        menu_nav = Wx::Menu.new

        menu_file.append(MINIMAL_PAGEOPEN, "&Open HTML page...")
        menu_file.append_separator
        menu_file.append(MINIMAL_PROCESSOR, "&Remove bold attribute", "", Wx::ITEM_CHECK)
        menu_file.append_separator
        menu_file.append(MINIMAL_QUIT, "&Close frame")

        menu_nav.append(MINIMAL_BACK, "Go &BACK")
        menu_nav.append(MINIMAL_FORWARD, "Go &FORWARD")

        menu_bar = Wx::MenuBar.new
        menu_bar.append(menu_file, "&File")
        menu_bar.append(menu_nav, "&Navigate")

        set_menu_bar(menu_bar)

        create_status_bar(1);

        @m_Processor = BoldProcessor.new
        @m_Processor.enable(FALSE)
        @m_Html = Wx::HtmlWindow.new(self)
        @m_Html.set_related_frame(self, "HTML : %s")
        @m_Html.set_related_status_bar(0)
        @m_Html.read_customization(Wx::Config::get)
        @m_Html.load_page("test.htm")
        @m_Html.add_processor(@m_Processor)
    end

    def on_quit
        @m_Html.write_customization(Wx::Config::get)
        Wx::Config::set(nil)
        close(TRUE)
    end

    def on_page_open
        p = Wx::file_selector("Open HTML document", "", "", "", "HTML files|*.htm")
        if (p != "")
            @m_Html.load_page(p)
        end
    end

    def on_back
        Wx::message_box("You reached prehistory era!") if (!@m_Html.history_back)
    end

    def on_forward
        Wx::message_box("No more items in history!") if (!@m_Html.history_forward)
    end

    def on_processor
        @m_Processor.enable(!@m_Processor.is_enabled)
        @m_Html.load_page(@m_Html.get_opened_page)
    end
end

class BoldProcessor < Wx::HtmlProcessor
    def process(s)
        r = s
        r.gsub!(/<b>/i, "")
        r.gsub!(/<\/b>/i, "")
        return r
    end
end

a = MyApp.new
a.main_loop()

