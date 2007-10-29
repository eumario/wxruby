#!/usr/bin/env ruby
# wxRuby2 Sample Code. Copyright (c) 2007-???? Mario J. Steele
# Freely reusable code: see SAMPLES-LICENSE.TXT for details

# This sample is a demonstration of how to implement a Multi-Threaded
# Server, using Ruby's green threads, Ruby's Asynchronous Sockets and
# wxRuby, as to not block the GUI while receiving connections and data
# from clients.

begin
  require 'wx'
rescue LoadError => no_wx_err
  begin
    require 'rubygems'
    require 'wx'
  rescue LoadError
    raise no_wx_err
  end
end

require 'thread' # For Thread and Mutex
require 'socket' # For TCP/IP Communications

$LOAD_PATH << File.dirname(__FILE__)
require 'wxSocketGUI'	# Our GUI Interface
require 'SocketPackets'	# For simplfying Socket communciation

class MyServerFrame < SocketGUI
  include Socket::Constants
  @@constants = %w[
		ID_START
		ID_STOP
		ID_NAME
		ID_EXIT
		ID_TIMER_POLL
	]
  # ClientInfo holds information about each client connection to the server
  # making it easier to track information, and use that throughout the
  # server process.
  ClientInfo = Struct.new(
                           :name,		# User's Nickname
                           :host,		# User's Host Address
                           :port,		# User's Port
                           :sock,		# User's Sock
                           :buffer)	# Buffer for the socket
  
  # Creates the Menus used by the server.
  def create_menus()
    mb = Wx::MenuBar.new
    
    fileMenu = Wx::Menu.new
    fileMenu.append(ID_START,"&Start Server\tCtrl+S","Start listening for incomming connections")
    fileMenu.append(ID_STOP,"S&top Server\tCtrl+G","Stop listening for incomming connections, and disconnect all current connections")
    fileMenu.append_separator()
    fileMenu.append(ID_NAME,"&Nickname\tCtrl+N","Set your Nickname")
    fileMenu.append_separator()
    fileMenu.append(ID_EXIT,"E&xit\tCtrl+X","Exit the demo")
    
    mb.append(fileMenu,"&File")
    set_menu_bar(mb)
  end
  
  # Our initialize sequence, called by SocketGUI.
  def on_init()
    @nick = "Server"   # Server user's Nickname
    @port = 1234       # Port we're listening on
    @mutex = Mutex.new # For synchronization, so there's no corruption of memory
    @clients = []      # For the sockets that are connected
    @timer = Wx::Timer.new(self,ID_TIMER_POLL)
    # Used to poll for data
    
    evt_menu(ID_START) { on_start }
    evt_menu(ID_STOP) { on_stop }
    evt_menu(ID_NAME) { on_name }
    evt_menu(ID_EXIT) { on_exit }
    
    evt_close { |evt| on_close(evt) }
    evt_text_enter(@input.get_id) { on_text }
    evt_timer(ID_TIMER_POLL) { Thread.pass }
    
    get_menu_bar.enable(ID_START,true)
    get_menu_bar.enable(ID_STOP,false)
  end
  
  # MyServerFrame#on_start()
  # This function sets up the socket for listening to incoming connections, as
  # well as starting the Thread that will do the underline work for polling for
  # incoming connections as well as incoming data.
  def on_start
    if !@socket.nil?
      Wx::message_box("The server is already started!","Server startup error",Wx::ID_OK|Wx::ICON_ERROR)
      return
    end
    
    mbox = Wx::TextEntryDialog.new(self,"Enter the port you want to listen on (Default: 1234)",
                                    "Start Server","1234")
    if mbox.show_modal == Wx::ID_CANCEL
      return
    end
    @port = mbox.get_value.to_i
    @socket = Socket.new(AF_INET,SOCK_STREAM,0)
    @socket.bind(Socket.sockaddr_in(@port,$LOCALHOST_NAME))
    @socket.listen(5)
    append_prog_msg("[#{Time.now}] - Server started on port #{@port}.")
    update_users()
    get_menu_bar.enable(ID_START,false)
    get_menu_bar.enable(ID_STOP,true)
    start_server_thread()
  end
  
  # MyServerFrame#on_stop()
  # This is executed from the File > Stop menu item, which will first check to see
  # if we still have Active clients.  If so, confirm that the user wants to shutdown
  # the server.  If the user does, it'll start the MyServerFraem#shutdown() sequence.
  def on_stop()
    if @socket.nil?
      Wx::message_box("The server is currently not active!","Server shutdown",Wx::OK|Wx::ICON_ERROR)
      return
    end
    if @clients.size > 0
      ret = Wx::message_box("There are still clients connected, do you wish to shutdown still?","Server shutdown",Wx::YES|Wx::NO|Wx::ICON_QUESTION)
      if ret == Wx::NO
        return
      end
    end
    shutdown()
  end
  
  # MyServerFrame#on_name()
  # This is executed from the File > Nickname menu item, which will change the nickname
  # of the Server itself.  If there's active connections to the server, it will notify
  # all of the clients of the server's new nickname.
  def on_name
    mbox = Wx::TextEntryDialog.new(self,"Enter the new nickname you want to be (Default: Server)",
                                    "Change Nickname",@nick)
    ret = mbox.show_modal
    if ret == Wx::ID_CANCEL
      return
    end
    nick = mbox.get_value
    nick = nick.split(" ").join("_") if nick.index(" ")
    append_prog_msg("[#{Time.now}] - You changed your nickname to #{nick}.")
    @clients.each do |ci|
      ci.sock.send_packet("NICK #{@nick} #{nick}")
    end
    @nick = nick
    update_users()
  end
  
  # MyServerFrame#on_exit()
  # This is executed from the File > Exit menu item, it will simply delegate the actual
  # processing to MyServerFrame#on_close() event, by closing the window.
  def on_exit
    self.close
  end
  
  # MyServerFrame#on_close(evt)
  # This is executed from the OnCloseEvent that comes from when the user closes the
  # window, or executes the File > Exit menu item.  It will first check to see if the
  # if there's an Active Socket.  If there is, then it'll check and see if there are
  # any clients connected.  If there are clients connected, it will confirm with the
  # user that they want to shutdown the server.  If they don't, it will veto the
  # close event, and the server will continue to run.
  def on_close(evt)
    ret = Wx::YES
    if !@socket.nil?
      if @clients.size > 0
        ret = Wx::message_box("There are still clients connected to the server, do you wish to continue?","Shutdown",Wx::YES|Wx::NO|Wx::ICON_INFORMATION)
      end
    end
    if ret == Wx::NO
      evt.veto
    else
      shutdown()
      Wx::get_app.exit_main_loop
    end
  end
  
  # MyServerFrame#on_text()
  # This is executed when the user presses the Enter button from the input box.
  # It does small parsing to check what /commands are used, if any, then if it
  # doesn't find any, it'll pass through to actually sending the data.
  def on_text()
    msg = @input.get_value
    @input.set_value("")
    case msg
    when /\/start/
      on_start
    when /\/shutdown/
      on_stop
    when /\/nick/
      on_name
    when /\/exit/
      self.close
    when /\/me/
      append_msg("--> #{@nick} " + msg[4..-1])
      msg = "EMOTE #{@nick} " + msg[4..-1]
      @mutex.lock
      @clients.each do |ci|
        ci.sock.send_packet(msg)
      end
      @mutex.unlock
    else
      append_msg("--> #{@nick} says: " + msg)
      msg = "MSG #{@nick} " + msg
      @mutex.lock
      @clients.each do |ci|
        ci.sock.send_packet(msg)
      end
      @mutex.unlock
    end
  end
  
  # MyServerFrame#shutdown()
  # This is the actual clean up function that will shutdown the Server, and
  # disconnect any connected clients.  When this is executed, there should
  # already have a Mutex lock done, so that we can safely clean everything up.
  def shutdown()
    Thread.kill(@thread) unless @thread.nil?
    @timer.stop
    
    @clients.each do |ci|
      ci.sock.send_packet("SHUTDOWN Server is going down now!")
      ci.sock.close
    end
    @clients = []
    @socket.close unless @socket.nil?
    @socket = nil
    append_prog_msg("[#{Time.now}] - Server has been shutdown.")
    get_menu_bar.enable(ID_START,true)
    get_menu_bar.enable(ID_STOP,false)
  end
  
  # MyServerFrame#poll()
  # This function collects the sockets for clients, as well as the server
  # socket to poll for incoming connections or data from these sockets.
  # This returns three arrays of sockets from [read,write,error/oob]
  def poll
    pollers = [@socket]
    @clients.each do |ci|
      pollers << ci.sock
    end
    IO::select(pollers,nil,nil,0.3)
  end
  
  # MyServerFrame#check_server(socks)
  # This is the core of the processing for the server side.  It will check to
  # see if our server socket is in the return for MyServerFrame#poll(), if it's
  # there, then there's an incoming connection, and will run the accepting of
  # the new client connection, and tell the other clients that there is a new
  # incoming connection.  It will then remove the server socket from the array
  # so that it's not processed, as well as converting all the remaining sockets
  # if any, back into ClientInfo structures, there by returning them to be
  # processed by the MyServerFrame#check_clients()
  def check_server(socks)
    if socks.index(@socket)
      socks.delete(@socket) # Don't need it in socks
      sock, sockaddr = @socket.accept
      sockaddr = Socket.unpack_sockaddr_in(sockaddr)
      ci = ClientInfo.new("",sockaddr[1],sockaddr[0],sock,"")
      @clients.each do |sci|
        sci.sock.send_packet("CONN #{ci.host} #{ci.port}")
      end
      @clients << ci
      append_msg("[#{Time.now}] - New connection from #{ci.host}:#{ci.port}")
      update_users()
    end
    new_ci = []
    socks.each do |sock|
      @clients.each do |ci|
        if ci.sock == sock
          new_ci << ci
        end
      end
    end
    new_ci
  end
  
  # MyServerFrame#update_users()
  # This function actually updates the User listing of thoes currently connected
  # to the server.
  def update_users()
    clear_users()
    add_user(@nick)
    @clients.each do |ci|
      add_user(ci.name)
    end
  end
  
  # MyServerFrame#parse_message(ClientInfo,Message)
  # This function parses the incoming data from a Client, to see what is being
  # requested.  There are currently 6 commands that the server implemented.
  # CONNECT identifies the Client with their nickname.
  # NICK identifies the client's new nickname if they change it.
  # EMOTE identifies the message as being an Emote, or Action.
  # MSG identifies the message as being a normal message to the server.
  # WHO is an internal request to update who is connected to the server.
  # QUIT identifies that the client is closing the connection to the server.
  #
  # This function parses the message, and responds appropriately, weither it
  # be an internal message to be handled, or it's a repeater, that needs to be
  # sent to all the connected clients, as well as being displayed to the server.
  def parse_message(ci,msg)
    new_msg = nil
    case msg
    when /CONNECT/
      ci.name = msg[8..-1]
      append_msg("<-> #{ci.name} has joined the server!")
      new_msg = msg
      update_users()
    when /NICK/
      new_msg = "NICK #{ci.name} #{msg[5..-1]}"
      append_msg("<-> #{ci.name} has changed nickname to #{msg[5..-1]}")
      ci.name = msg[5..-1]
      update_users()
    when /EMOTE/
      new_msg = "EMOTE #{ci.name} #{msg[6..-1]}"
      append_msg("<-> #{ci.name} #{msg[6..-1]}")
    when /MSG/
      new_msg = "MSG #{ci.name} #{msg[4..-1]}"
      append_msg("<-> #{ci.name} says: #{msg[4..-1]}")
    when /WHO/
      who = "WHO #{@nick} "
      @clients.each do |cci|
        who += cci.name + " "
      end
      ci.sock.send_packet(who[0..-2])
    when /QUIT/
      new_msg = "QUIT #{ci.name}"
      append_msg("<-> #{ci.name} is dis-connecting.")
    else
      append_error("<-- Unknown message from #{ci.name}")
      append_error("<-- Message: #{msg}")
    end
    @clients.each do |cci|
      if cci != ci
        cci.sock.send_packet(new_msg)
      end
    end unless new_msg.nil?
  end
  
  # MyServerFrame#check_clients()
  # This method, will run through the collected client connections that show that
  # they have data available in their buffer.  It will first check to see if the
  # socket has been closed by utilizing the IO#eof? method.  If there is an end
  # of file detected, it means the client connection has been closed.  It will then
  # remove the client connection from our pool, and send the rest of the clients
  # that the user has indeed disconnected from the server.
  # After confirming that the connection hasn't been closed, it will check to
  # see what data is available, append it to the client's buffer, where it will
  # then process the data, for the LF (0x0A) termination, saying that this is the
  # end of the message, and then process that data through MyServerFrame#parse_message()
  def check_clients(aci)
    aci.each do |ci|
      if ci.sock.eof?
        ci.sock.close
        @clients.delete(ci)
        @clients.each do |cci|
          cci.sock.send_packet("DISCONN #{ci.name}")
        end
        append_prog_msg("[#{Time.now}] - Socket closed for #{ci.name}")
        update_users()
      else
        msg = ci.sock.recv_packet()
        ci.buffer += msg
        loop do
          at = ci.buffer.index("\n")
          if at.nil?
            break
          end
          data = ci.buffer[0..at-1]
          ci.buffer = ci.buffer[at+1..-1]
          parse_message(ci,data)
        end
      end
    end
  end
  
  # MyServerFrame#start_server_thread()
  # This is the meat and bones of the server, where it will continiously poll for
  # data in a seperate Thread, that will utilize the above methods for processing
  # the incoming connections, and data being inputed from clients.  This thread
  # does no yielding, or anything of the sort to wxRuby, as it's in a seperate
  # thread being controlled by Ruby.  This thread is given time to run, by the
  # Thread#yield() method, that is put into a context of a Timer that executes
  # every 300 Milliseconds, and so forth.  We start the timer here, so that way
  # we ensure that it get's started, and stopped at the correct times.
  def start_server_thread()
    @thread = Thread.new do
      @timer.start(25)
      loop do # We just run a continious loop.  on_stop() will kill this thread, and stop the timer.
        begin	# We run here, just incase there's some kind of error
          @mutex.lock # We lock the data, so there's no corruption between threads
          socks = poll() # We run a poll for any incoming data, or any new incoming connections
          unless socks.nil?
            ci = check_server(socks[0]) # Check to see if we have any incoming connections
            check_clients(ci)	# Check for client activity
          end
          @mutex.unlock # We can now release it, as we've done everything needed here
        rescue => e  # We have an error, so we need to process it.
          msg = ["An error has occured!"]
          msg << "#{e.backtrace.delete_at(0)}: #{e} (#{e.class})"
          e.backtrace.each do |line|
            msg << line
          end
          msg.each do |line|
            append_error(line)
          end
        end
      end
    end
  end
end

class MySocketApp < Wx::App
  def on_init
    frame = MyServerFrame.new(nil,-1,"Sockets Demo >> Server")
    frame.show
  end
end

MySocketApp.new.main_loop
