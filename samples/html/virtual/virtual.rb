require 'wxruby'

MINIMAL_QUIT,
MINIMAL_BACK,
MINIMAL_FORWARD,
MINIMAL_TEXT = (1..4).to_a

class MyVFS < Wx::FileSystemHandler
    def initialize
        super
    end

    def can_open(location)
        get_protocol(location) == "myVFS"
    end

    def open_file(fs, loc)
        buf = "<html><body><h2><i>You're in Node <u>#{loc}</u></i></h2><p>" +
              "Where do you want to go?<br><blockquote>" +
              "<a href=\"#{loc}-1\">sub-1</a><br>" +
              "<a href=\"#{loc}-2\">sub-2</a><br>" +
              "<a href=\"#{loc}-3\">sub-3</a><br>" +
              "</blockquote></body></html>"

        str = Wx::MemoryInputStream.new(buf)
        f = Wx::FSFile(str, loc, "text/html", "", Wx::DateTime::today)
    
        return f
    end
end

class MyApp < Wx::App
    def on_init
        frame = MyFrame.new("wxHtmlWindow testing application",
                Wx::Point.new(50, 50), Wx::Size.new(640, 480))

        frame.show(TRUE)
        set_top_window(frame)

        Wx::FileSystem::add_handler(MyVFS.new)

        return TRUE
    end
end

class MyFrame < Wx::Frame
    def initialize(title, pos, size)
        super(nil, -1, title, pos, size)

        evt_menu(MINIMAL_QUIT) {on_quit}
        evt_menu(MINIMAL_BACK) {on_back}
        evt_menu(MINIMAL_FORWARD) {on_forward}

        menu_file = Wx::Menu.new
        menu_nav = Wx::Menu.new

        menu_file.append(MINIMAL_QUIT, "E&xit")

        menu_nav.append(MINIMAL_BACK, "Go &BACK")
        menu_nav.append(MINIMAL_FORWARD, "Go &FORWARD")

        menu_bar = Wx::MenuBar
        menu_bar.append(menu_file, "&File")
        menuBar.append(menu_nav, "&Navigate")

        set_menu_bar(menu_bar)

        create_status_bar(2)

        @html = Wx::HtmlWindow.new(self)
        @html.set_related_frame(self, "VFS Demo: '%s'")
        @html.set_related_status_bar(1)
        @html.load_page("start.htm")
    end

    def on_quit
        close(TRUE)
    end

    def on_back
        Wx::message_box("You reached prehistory era!") if (!@html.history_back)
    end


    def on_forward
        Wx::message_box("No more items in history!") if (!@html.history_forward)
    end
end

a = MyApp.new
a.main_loop

