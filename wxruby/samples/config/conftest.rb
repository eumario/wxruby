require 'wxruby'
include Wx

ConfTest_Quit = 0
ConfTest_About = 1
ConfTest_Delete = 2

class MyFrame < Frame

    def initialize
        super(nil, -1, "Config Demo")

        # menu
        file_menu = Menu.new

        file_menu.append(ConfTest_Delete, "&Delete", "Delete config file")
        file_menu.append_separator()
        file_menu.append(ConfTest_About, "&About\tF1", "About this sample")
        file_menu.append_separator()
        file_menu.append(ConfTest_Quit, "E&xit\tAlt-X", "Exit the program")
        menu_bar = MenuBar.new
        menu_bar.append(file_menu, "&File")
        set_menu_bar(menu_bar)

        create_status_bar()

        # child controls
        panel = Panel.new(self)
        StaticText.new(panel, -1, "These controls remember their values!",
                             Point.new(10, 10), Size.new(300, 20))
        @m_text = TextCtrl.new(panel, -1, "", Point.new(10, 40), Size.new(300, 20))
        @m_check = CheckBox.new(panel, -1, "show welcome message box at startup",
                               Point.new(10, 70), Size.new(300, 20))

        # restore the control's values from the config

        # NB: in this program, the config object is already created at this moment
        # because we had called Get() from MyApp::on_init(). However, if you later
        # change the code and don't create it before this line, it won't break
        # anything - unlike if you manually create Config object with Create()
        # or in any other way (then you must be sure to create it before using it!).
        pConfig = ConfigBase::get()
        # we could write Read("/Controls/Text") as well, it's just to show set_path()
        pConfig.set_path("/Controls")

        @m_text.set_value(pConfig.read("Text", ""))
        @m_check.set_value(pConfig.read_bool("Check", TRUE))

        # set_path() understands ".."
        pConfig.set_path("../MainFrame")

        # restore frame position and size
        x = pConfig.read_int("x", 50)
        y = pConfig.read_int("y", 50)
        w = pConfig.read_int("w", 350)
        h = pConfig.read_int("h", 200)
        move(Point.new(x, y))
        set_client_size(Size.new(w, h))

        pConfig.set_path("/")
        s = pConfig.read("TestValue")
        if s!=""
          log_status(self, "TestValue from config is '%s'", s)
        else
          log_status(self, "TestValue not found in the config")
        end


        evt_menu(ConfTest_Quit) {onQuit}
        evt_menu(ConfTest_About) {onAbout}
        evt_menu(ConfTest_Delete) {onDelete}
        evt_close {onClose}
    end

    def onClose
        pConfig = ConfigBase::get()
        if pConfig != nil
            # save the control's values to the config
            pConfig.write("/Controls/Text", @m_text.get_value())
            pConfig.write("/Controls/Check", @m_check.get_value())

            # save the frame position
			size = get_client_size
			w = size.get_width
			h = size.get_height
			pos = get_position
            x = pos.x
			y = pos.y
            pConfig.write("/MainFrame/x", x)
            pConfig.write("/MainFrame/y", y)
            pConfig.write("/MainFrame/w", w)
            pConfig.write("/MainFrame/h", h)

            pConfig.write("/TestValue", "A test value")

        end
        destroy()
    end

    def onQuit
        close(TRUE)
    end

    def onAbout
        message_box("Config demo\n© 1998-2001 Vadim Zeitlin", "About",
                   ICON_INFORMATION | OK)
    end

    def onDelete
        pConfig = ConfigBase::get()
        if pConfig == nil
            log_error("No config to delete!")
            return nil
        end

        if pConfig.delete_all()
            log_message("Config file/registry key successfully deleted.")

            ConfigBase::set(nil).free
            ConfigBase::dont_create_on_demand()
        else
            log_error("Deleting config file/registry key failed.")
        end
    end
end

class MyApp < App
    def on_init()

        # we're using Config's "create-on-demand" feature: it will create the
        # config object when it's used for the first time. It has a number of
        # advantages compared with explicitly creating our Config:
        #  1) we don't pay for it if we don't use it
        #  2) there is no danger to create it twice

        # application and vendor name are used by Config to construct the name
        # of the config file/registry key and must be set before the first call
        # to Get() if you want to override the default values (the application
        # name is the name of the executable and the vendor name is the same)
        set_vendor_name("Windows")
        set_app_name("conftest") # not needed, it's the default value

        pConfig = ConfigBase::get()
        # uncomment this to force writing back of the defaults for all values
        # if they're not present in the config - this can give the user an idea
        # of all possible settings for this program
        pConfig.set_record_defaults()

        ConfigBase::set(nil)
        # or you could also write something like this:
        #  FileConfig *pConfig = new FileConfig("conftest")
        #  ConfigBase::Set(pConfig)
        # where you can also specify the file names explicitly if you wish.
        # Of course, calling Set() is optional and you only must do it if
        # you want to later retrieve this pointer with Get().

        # create the main program window
        frame = MyFrame.new
        frame.show(TRUE)
        set_top_window(frame)

        # use our config object...
        if pConfig.read_bool("/Controls/Check", TRUE)
            message_box("You can disable this message box by unchecking\n" +
                       "the checkbox in the main window (of course, a real\n" +
                       "program would have a checkbox right here but we\n" +
                     "keep it simple)", "Welcome to Config demo",
                     ICON_INFORMATION | OK)
        end

        return TRUE
    end
end


a = MyApp.new
a.main_loop()
