
require 'wxruby'
include Wx

# menu items
CLIENT_QUIT = 1000
CLIENT_ABOUT = 1002
CLIENT_OPEN = 1003
CLIENT_TEST1 = 1004
CLIENT_TEST2 = 1005
CLIENT_TEST3 = 1006
CLIENT_CLOSE = 1007
CLIENT_TESTURL = 1008
CLIENT_DGRAM = 1009

# id for socket
SOCKET_ID = 1010

class MyFrame < Frame
    def initialize
        super(nil, -1,
                     "Socket demo: Client",
                     DEFAULT_POSITION, Size.new(300, 200))

        # Give the frame an icon
        set_icon(Icon.new("mondrian.xpm"))

        # Make menus
        @m_menuFile = Menu.new
        @m_menuFile.append(CLIENT_ABOUT, "&About...\tCtrl-A", "show about dialog")
        @m_menuFile.append_separator()
        @m_menuFile.append(CLIENT_QUIT, "E&xit\tAlt-X", "Quit client")

        @m_menuSocket = Menu.new
        @m_menuSocket.append(CLIENT_OPEN, "&Open session", "connect to server")
        @m_menuSocket.append_separator()
        @m_menuSocket.append(CLIENT_TEST1, "Test &1", "Test basic functionality")
        @m_menuSocket.append(CLIENT_TEST2, "Test &2", "Test read_msg and write_msg")
        @m_menuSocket.append(CLIENT_TEST3, "Test &3", "Test large data transfer")
        @m_menuSocket.append_separator()
        @m_menuSocket.append(CLIENT_CLOSE, "&close session", "close connection")

        @m_menuDatagramSocket = Menu.new
        @m_menuDatagramSocket.append(CLIENT_DGRAM, "Send Datagram", "Test UDP sockets")

        @m_menuProtocols = Menu.new
        @m_menuProtocols.append(CLIENT_TESTURL, "Test URL", "Get data from the specified URL")

        # append menus to the menubar
        @m_menuBar = MenuBar.new
        @m_menuBar.append(@m_menuFile, "&File")
        @m_menuBar.append(@m_menuSocket, "&SocketClient")
        @m_menuBar.append(@m_menuDatagramSocket, "&DatagramSocket")
        @m_menuBar.append(@m_menuProtocols, "&Protocols")
        set_menu_bar(@m_menuBar)

        # Status bar
        create_status_bar(2)

        # Make a textctrl for logging
        @m_text  = TextCtrl.new(self, -1,
                               "Welcome to Socket demo: Client\nClient ready\n",
                               DEFAULT_POSITION, DEFAULT_SIZE,
                               TE_MULTILINE | TE_READONLY)

        # Create the socket
        @m_sock = SocketClient.new

        # Setup the event handler and subscribe to most events
        @m_sock.set_event_handler(self, SOCKET_ID)
        @m_sock.set_notify(SOCKET_CONNECTION_FLAG |
                        SOCKET_INPUT_FLAG |
                        SOCKET_LOST_FLAG)
        @m_sock.notify(TRUE)

        @m_busy = FALSE
        UpdateStatusBar()

        evt_menu(CLIENT_QUIT) {|event| onQuit(event) }
        evt_menu(CLIENT_ABOUT) {|event| onAbout(event) }
        evt_menu(CLIENT_OPEN) {|event| onOpenConnection(event) }
        evt_menu(CLIENT_TEST1) {|event| onTest1(event) }
        evt_menu(CLIENT_TEST2) {|event| onTest2(event) }
        evt_menu(CLIENT_TEST3) {|event| onTest3(event) }
        evt_menu(CLIENT_CLOSE) {|event| onCloseConnection(event) }
        evt_menu(CLIENT_DGRAM) {|event| onDatagram(event) }
        evt_menu(CLIENT_TESTURL) {|event| onTestURL(event) }
        evt_socket(SOCKET_ID) {|event| onSocketEvent(event) }

    end

    def onQuit(event)
      # TRUE is to force the frame to close
      close(TRUE)
    end

    def onAbout(event)
      message_box("Socket demo: Client\n(c) 1999 Guillermo Rodriguez Garcia\n",
                   "About Client",
                   OK | ICON_INFORMATION, self)
    end

    def onOpenConnection(event)

      @m_menuSocket.enable(CLIENT_OPEN, FALSE)
      @m_menuSocket.enable(CLIENT_CLOSE, FALSE)

      # Ask user for server address
      hostname = get_text_from_user(
        "Enter the address of the Socket demo server:",
        "connect ...",
        "localhost")

      # Mini-tutorial for connect() :-)
      # ---------------------------
      #
      # There are two ways to use connect(): blocking and non-blocking,
      # depending on the value passed as the 'wait' (2nd) parameter.
      #
      # connect(addr, TRUE) will wait until the connection completes,
      # returning TRUE on success and FALSE on failure. This call blocks
      # the GUI (self might be changed in future releases to honour the
      # SOCKET_BLOCK flag).
      #
      # connect(addr, FALSE) will issue a nonblocking connection request
      # and return immediately. If the return value is TRUE, then the
      # connection has been already succesfully established. If it is
      # FALSE, you must wait for the request to complete, either with
      # wait_on_connect() or by watching SOCKET_CONNECTION / LOST
      # events (please read the documentation).
      #
      # wait_on_connect() itself never blocks the GUI (self might change
      # in the future to honour the SOCKET_BLOCK flag). This call will
      # return FALSE on timeout, or TRUE if the connection request
      # completes, which in turn might mean:
      #
      #   a) That the connection was successfully established
      #   b) That the connection request failed (for example, because
      #      it was refused by the peer.
      #
      # Use is_connected() to distinguish between these two.
      #
      # So, in a brief, you should do one of the following things:
      #
      # For blocking connect:
      #
      #   success = client.connect(addr, TRUE)
      #
      # For nonblocking connect:
      #
      #   client.connect(addr, FALSE)
      #
      #   waitmore = TRUE
      #   while (! client.wait_on_connect(seconds, millis) && waitmore )
      #
      #     # possibly give some feedback to the user,
      #     # update waitmore if needed.
      #   end
      #   success = client.is_connected()
      #
      # And that's all :-)

      @m_text.append_text("\nTrying to connect (timeout = 10 sec) ...\n")
      @m_sock.connect(hostname,3000, FALSE)
      @m_sock.wait_on_connect(10)

      if @m_sock.is_connected()
        @m_text.append_text("Succeeded ! Connection established\n")
      else
        @m_sock.close()
        @m_text.append_text("Failed ! Unable to connect\n")
        message_box("Can't connect to the specified host", "Alert !")
      end

      UpdateStatusBar()
    end

    def onTest1(event)

      # Disable socket menu entries (exception: close Session)
      @m_busy = TRUE
      UpdateStatusBar()

      @m_text.append_text("\n=== Test 1 begins ===\n")

      # Tell the server which test we are running
      c = 0xBE.chr
      @m_sock.write(c, 1)

      # Send some data and read it back. We know the size of the
      # buffer, so we can specify the exact number of bytes to be
      # sent or received and use the SOCKET_WAITALL flag. Also,
      # we have disabled menu entries which could interfere with
      # the test, so we can safely avoid the SOCKET_BLOCK flag.
      #
      # First we send a byte with the length of the string, then
      # we send the string itself (do NOT try to send any integral
      # value larger than a byte "as is" across the network, or
      # you might be in trouble! Ever heard about big and little
      # endian computers?)

      @m_sock.set_flags(SOCKET_WAITALL)

      buf1 = "Test string (less than 256 chars!)"
      len = buf1.length
      buf2 = "\0" * len

      @m_text.append_text("Sending a test buffer to the server ...")
      len2 = [len].pack("C")
      @m_sock.write(len2, 1)
      @m_sock.write(buf1, len)
      @m_text.append_text(@m_sock.error() ? "failed !\n" : "done\n")

      @m_text.append_text("Receiving the buffer back from server ...")
      @m_sock.read(buf2, len)
      @m_text.append_text(@m_sock.error() ? "failed !\n" : "done\n")

      @m_text.append_text("Comparing the two buffers ...")
      if buf1[0,len] != buf2[0,len]
        @m_text.append_text("failed!\n")
        @m_text.append_text("Test 1 failed !\n")
      else
        @m_text.append_text("done\n")
        @m_text.append_text("Test 1 passed !\n")
      end
      @m_text.append_text("=== Test 1 ends ===\n")

      @m_busy = FALSE
      UpdateStatusBar()
    end

    def onTest2(event)
      # Disable socket menu entries (exception: close Session)
      @m_busy = TRUE
      UpdateStatusBar()

      @m_text.append_text("\n=== Test 2 begins ===\n")

      # Tell the server which test we are running
      c = 0xCE.chr
      @m_sock.write(c, 1)

      # Here we use read_msg and write_msg to send messages with
      # a header with size information. Also, the reception is
      # event triggered, so we test input events as well.
      #
      # We need to set no flags here (read_msg and write_msg are
      # not affected by flags)

      @m_sock.set_flags(SOCKET_WAITALL)

      s = get_text_from_user(
        "Enter an arbitrary string to send to the server:",
        "Test 2 ...",
        "Yes I like Windows!")

      msg1 = s
      len = msg1.length
      msg2 = "\0" * len

      @m_text.append_text("Sending the string with write_msg ...")
      @m_sock.write_msg(msg1, len)
      @m_text.append_text(@m_sock.error() ? "failed !\n" : "done\n")
      @m_text.append_text("Waiting for an event (timeout = 2 sec)\n")

      # Wait until data available (will also return if the connection is lost)
      @m_sock.wait_for_read(2)

      if @m_sock.is_data()
        @m_text.append_text("Reading the string back with read_msg ...")
        @m_sock.read_msg(msg2, len)
        @m_text.append_text(@m_sock.error() ? "failed !\n" : "done\n")
        @m_text.append_text("Comparing the two buffers ...")
        if msg1[0,len] != msg2[0,len]
          @m_text.append_text("failed!\n")
          @m_text.append_text("Test 2 failed !\n")
        else
          @m_text.append_text("done\n")
          @m_text.append_text("Test 2 passed !\n")
        end
      else
        @m_text.append_text("Timeout ! Test 2 failed.\n")
      end
      @m_text.append_text("=== Test 2 ends ===\n")

      @m_busy = FALSE
      UpdateStatusBar()
    end

    def onTest3(event)
      # Disable socket menu entries (exception: close Session)
      @m_busy = TRUE
      UpdateStatusBar()

      @m_text.append_text("\n=== Test 3 begins ===\n")

      # Tell the server which test we are running
      c = 0xDE.chr
      @m_sock.write(c, 1)

      # This test also is similar to the first one but it sends a
      # large buffer so that Socket is actually forced to split
      # it into pieces and take care of sending everything before
      # returning.

      @m_sock.set_flags(SOCKET_WAITALL)

      # Note that len is in kbytes here!
      len  = 32
      buf1 = "\0" * (len * 1024)
      buf2 = "\0" * (len * 1024)

      for i in 0 ... (len * 1024)
         buf1[i] = i % 256
      end

      @m_text.append_text("Sending a large buffer (32K) to the server ...")
      len2 = [len].pack("C")
      @m_sock.write(len2, 1)
      @m_sock.write(buf1, len * 1024)
      @m_text.append_text(@m_sock.error() ? "failed !\n" : "done\n")

      @m_text.append_text("Receiving the buffer back from server ...")
      @m_sock.read(buf2, len * 1024)
      @m_text.append_text(@m_sock.error() ? "failed !\n" : "done\n")

      @m_text.append_text("Comparing the two buffers ...")
      if buf1[0,len] != buf2[0,len]
        @m_text.append_text("failed!\n")
        @m_text.append_text("Test 3 failed !\n")
      else
        @m_text.append_text("done\n")
        @m_text.append_text("Test 3 passed !\n")
      end
      @m_text.append_text("=== Test 3 ends ===\n")

      @m_busy = FALSE
      UpdateStatusBar()
    end

    def onCloseConnection(event)
      @m_sock.close()
      UpdateStatusBar()
    end

    def onDatagram(event)
      @m_text.append_text("\n=== Datagram test begins ===\n")
      @m_text.append_text("Sorry, not implemented\n")
      @m_text.append_text("=== Datagram test ends ===\n")
    end

    def onTestURL(event)
      # Note that we are creating a new socket here, so self
      # won't mess with the client/server demo.

      # Ask for the URL
      @m_text.append_text("\n=== URL test begins ===\n")
      urlname = get_text_from_user("Enter an URL to get",
                                           "URL:",
                                           "http://localhost")

      # Parse the URL
      url = URL.new(urlname)
      if url.get_error() != URL_NOERR
        @m_text.append_text("error: couldn't parse URL\n")
        @m_text.append_text("=== URL test ends ===\n")
        return nil
      end

      # Try to get the input stream (connects to the given URL)
      @m_text.append_text("Trying to establish connection...\n")
      Wx::yield()
      data = url.get_input_stream()
      if !data
        @m_text.append_text("error: couldn't read from URL\n")
        @m_text.append_text("=== URL test ends ===\n")
        return nil
      end

      # Print the contents type and file size
      s = sprintf("Contents type: %s\nStarting to download...\n",
                 url.get_protocol().get_content_type())
      @m_text.append_text(s)
      Wx::yield()

      # Get the data
      sout = FileOutputStream.new("test.url")
      if !sout.ok()
        @m_text.append_text("error: couldn't open file for output\n")
        @m_text.append_text("=== URL test ends ===\n")
        return nil
      end

      data.read(sout)
      @m_text.append_text("Results written to file: test.url\n")
      @m_text.append_text("Done.\n")
      @m_text.append_text("=== URL test ends ===\n")

      data.free
    end

    def onSocketEvent(event)
      s = "OnSocketEvent: "

      case event.get_socket_event()
        when SOCKET_INPUT
            s << "SOCKET_INPUT\n"
        when SOCKET_LOST
            s << "SOCKET_LOST\n"
        when SOCKET_CONNECTION
            s << "SOCKET_CONNECTION\n"
        else
            s << "Unexpected event !\n"
      end

      @m_text.append_text(s)
      UpdateStatusBar()
    end

    # convenience functions
    def UpdateStatusBar()
      s = ""
      if !@m_sock.is_connected()
        s = "Not connected"
      else
        hostname,service = @m_sock.get_peer()
        s = sprintf("%s : %d", hostname,service)
      end

      set_status_text(s, 1)

      @m_menuSocket.enable(CLIENT_OPEN, !@m_sock.is_connected() && !@m_busy)
      @m_menuSocket.enable(CLIENT_TEST1, @m_sock.is_connected() && !@m_busy)
      @m_menuSocket.enable(CLIENT_TEST2, @m_sock.is_connected() && !@m_busy)
      @m_menuSocket.enable(CLIENT_TEST3, @m_sock.is_connected() && !@m_busy)
      @m_menuSocket.enable(CLIENT_CLOSE, @m_sock.is_connected())
    end

end

class MyApp < App
    def on_init
        # Create the main application window
        frame = MyFrame.new

        # show it and tell the application that it's our main window
        frame.show(TRUE)
        set_top_window(frame)
    end
end

a = MyApp.new
a.main_loop()
