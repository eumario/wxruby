
require 'wxruby'
include Wx

# IDs for the controls and the menu commands
# menu items
SERVER_QUIT = 1000
SERVER_ABOUT = 1001

# id for sockets
SERVER_ID = 1002
SOCKET_ID = 1003

MAX_MSG_SIZE = 10000

class MyFrame < Frame
    def initialize
        super(nil, -1,"Socket demo: Server",
                             DEFAULT_POSITION, Size.new(300, 200))

        # Give the frame an icon
        set_icon(Icon.new("mondrian.xpm"))

        # Make menus
        @m_menuFile = Menu.new
        @m_menuFile.append(SERVER_ABOUT, "&About...\tCtrl-A", "Show about dialog")
        @m_menuFile.append_separator()
        @m_menuFile.append(SERVER_QUIT, "E&xit\tAlt-X", "Quit server")

        # append menus to the menubar
        @m_menuBar = MenuBar.new
        @m_menuBar.append(@m_menuFile, "&File")
        set_menu_bar(@m_menuBar)

        # Status bar
        create_status_bar(2)

        # Make a textctrl for logging
        @m_text  = TextCtrl.new(self, -1,
                               "Welcome to Socket demo: Server\n",
                               DEFAULT_POSITION, DEFAULT_SIZE,
                               TE_MULTILINE | TE_READONLY)

        # Create the socket
        @m_server = SocketServer.new("localhost",3000)

        # We use ok() here to see if the server is really listening
        if !@m_server.ok()
            @m_text.append_text("Could not listen at the specified port !\n\n")
            return nil
        else
            @m_text.append_text("Server listening.\n\n")
        end

        # Setup the event handler and subscribe to connection events
        @m_server.set_event_handler(self, SERVER_ID)
        @m_server.set_notify(SOCKET_CONNECTION_FLAG)
        @m_server.notify(TRUE)

        @m_busy = FALSE
        @m_numClients = 0
        UpdateStatusBar()

        evt_menu(SERVER_QUIT) {|event| onQuit(event) }
        evt_menu(SERVER_ABOUT) {|event| onAbout(event) }
        evt_socket(SERVER_ID) {|event| onServerEvent(event) }
        evt_socket(SOCKET_ID) {|event| onSocketEvent(event) }

    end

    def onQuit(event)
      # TRUE is to force the frame to close
      close(TRUE)
    end

    def onAbout(event)
      message_box("Socket demo: Server\n(c) 1999 Guillermo Rodriguez Garcia\n",
                   "About Server",
                   OK | ICON_INFORMATION, self)
    end

    def Test1(sock)
      @m_text.append_text("Test 1 begins\n")

      # Receive data from socket and send it back. We will first
      # get a byte with the buffer size, so we can specify the
      # exact size and use the SOCKET_WAITALL flag. Also, we
      # disabled input events so we won't have unwanted reentrance.
      # This way we can avoid the infamous SOCKET_BLOCK flag.

      sock.set_flags(SOCKET_WAITALL)

      # read the size
      len = "\0"
      sock.read(len, 1)
      len = len.unpack("C")[0]
      buf = "\0" * len

      # read the data
      sock.read(buf, len)
      @m_text.append_text("Got the data, sending it back\n")

      # write it back
      sock.write(buf, len)

      @m_text.append_text("Test 1 ends\n\n")
    end

    def Test2(sock)

      buf = "\0" * MAX_MSG_SIZE

      @m_text.append_text("Test 2 begins\n")

      # We don't need to set flags because read_msg and write_msg
      # are not affected by them anyway.

      # read the message
      len = sock.read_msg(buf, MAX_MSG_SIZE).last_count()
      s = sprintf("Client says: %s\n", buf)
      @m_text.append_text(s)
      @m_text.append_text("Sending the data back\n")

      # write it back
      sock.write_msg(buf, len)

      @m_text.append_text("Test 2 ends\n\n")

    end

    def Test3(sock)
      @m_text.append_text("Test 3 begins\n")

      # This test is similar to the first one, but the len is
      # expressed in kbytes - self tests large data transfers.

      sock.set_flags(SOCKET_WAITALL)

      # read the size
      len = "\0"
      sock.read(len, 1)
      len = len.unpack("C")[0]
      buf = "\0" * (len * 1024)

      # read the data
      sock.read(buf, len * 1024)
      @m_text.append_text("Got the data, sending it back\n")

      # write it back
      sock.write(buf, len * 1024)

      @m_text.append_text("Test 3 ends\n\n")
    end

    def onServerEvent(event)

      s = "OnServerEvent: "

      case event.get_socket_event()
        when SOCKET_CONNECTION
            s << "SOCKET_CONNECTION\n"
        else
            s << "Unexpected event !\n"
      end

      @m_text.append_text(s)

      # accept new connection if there is one in the pending
      # connections queue, else exit. We use accept(FALSE) for
      # non-blocking accept (although if we got here, there
      # should ALWAYS be a pending connection).

      sock = @m_server.accept(FALSE)

      if sock
        @m_text.append_text("New client connection accepted\n\n")
      else
        @m_text.append_text("Error: couldn't accept a new connection\n\n")
        return nil
      end

      sock.set_event_handler(self, SOCKET_ID)
      sock.set_notify(SOCKET_INPUT_FLAG | SOCKET_LOST_FLAG)
      sock.notify(TRUE)

      @m_numClients += 1
      UpdateStatusBar()
    end

    def onSocketEvent(event)

      s = "OnSocketEvent: "
      sock = event.get_socket()

      # First, print a message
      case event.get_socket_event()
        when SOCKET_INPUT
            s << "SOCKET_INPUT\n"
        when SOCKET_LOST
            s << "SOCKET_LOST\n"
        else
            s << "Unexpected event !\n"
      end

      @m_text.append_text(s)

      # Now we process the event
      case event.get_socket_event()
        when SOCKET_INPUT
          # We disable input events, so that the test doesn't trigger
          # SocketEvent again.
          sock.set_notify(SOCKET_LOST_FLAG)

          # Which test are we going to run?
          c = "\0"
          sock.read(c, 1)

          case c[0]
            when 0xBE
                Test1(sock)
            when 0xCE
                Test2(sock)
            when 0xDE
                Test3(sock)
            else
                @m_text.append_text("Unknown test id received from client\n\n")
          end

          # Enable input events again.
          sock.set_notify(SOCKET_LOST_FLAG | SOCKET_INPUT_FLAG)

        when SOCKET_LOST

          @m_numClients -= 1

          # Destroy() should be used instead of delete wherever possible,
          # due to the fact that Socket uses 'delayed events' (see the
          # documentation for PostEvent) and we don't want an event to
          # arrive to the event handler (the frame, here) after the socket
          # has been deleted. Also, we might be doing some other thing with
          # the socket at the same time for example, we might be in the
          # middle of a test or something. Destroy() takes care of all
          # self for us.

          @m_text.append_text("Deleting socket.\n\n")
          sock.destroy()
      end

      UpdateStatusBar()
    end

    # convenience functions
    def UpdateStatusBar()
      s = sprintf("%d clients connected", @m_numClients)
      set_status_text(s, 1)
    end

end

class MyApp < App
    def on_init
        # Create the main application window
        frame = MyFrame.new

        # Show it and tell the application that it's our main window
        frame.show(TRUE)
        set_top_window(frame)        
    end
end

a = MyApp.new
a.main_loop()
