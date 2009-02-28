#!/usr/bin/env ruby
# wxRuby2 Sample Code. Copyright (c) 2007-???? Mario J. Steele
# Freely reusable code: see SAMPLES-LICENSE.TXT for details

# This sample is of a client impelmentation using Ruby's green
# threads, Ruby's Asynchronous Sockets, and wxRuby Widgets, so as
# to not block the GUI while waiting for data.

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

require 'thread'   # For Thread and Mutex
require 'socket'   # For TCP/IP Communications

$LOAD_PATH << File.dirname(__FILE__)
require 'wxSocketGUI'   # Our GUI Interface
require 'SocketPackets' # For simplfying Socket communciation

class String
  # String#index_from(index,to_index)
  # This finds the to_index from the index onwards till the end of the string.
  # Returns the find_index + offset value of index.
  def index_from(i,mtch)
    self[i..-1].index(mtch) + i
  end
end


class MyClientFrame < SocketGUI
  include Socket::Constants
  @@constants = %w[
		ID_CONNECT
		ID_DISCONNECT
		ID_NAME
		ID_EXIT
		ID_TIMER_POLL
	]
  
  # Creates the menus used by the Client.
  def create_menus()
    mb = Wx::MenuBar.new
    
    fileMenu = Wx::Menu.new
    fileMenu.append(ID_CONNECT,"&Connect\tCtrl+S","Connect to a server")
    fileMenu.append(ID_DISCONNECT,"&Disconnect\tCtrl+G","Disconnect from a server")
    fileMenu.append_separator()
    fileMenu.append(ID_NAME,"&Nickname\tCtrl+N","Set your nickname")
    fileMenu.append_separator()
    fileMenu.append(ID_EXIT,"E&xit\tCtrl+X","Exit the client")
    
    mb.append(fileMenu,"&File")
    
    set_menu_bar(mb)
  end
  
  # Called from SocketGUI, to initialize our client window.
  def on_init()
    @nick = "Client"
    @port = "1234"
    @addr = $LOCALHOST_NAME
    @mutex = Mutex.new
    @buffer = ""
    @timer = Wx::Timer.new(self,ID_TIMER_POLL)
    
    evt_menu(ID_CONNECT) { on_connect }
    evt_menu(ID_DISCONNECT) { on_disconnect }
    evt_menu(ID_NAME) { on_name }
    evt_menu(ID_EXIT) { on_exit }
    
    evt_close { |evt| on_close(evt) }
    evt_text_enter(@input.get_id) { on_text }
    evt_timer(ID_TIMER_POLL) { Thread.pass }
    
    get_menu_bar.enable(ID_CONNECT,true)
    get_menu_bar.enable(ID_DISCONNECT,false)
  end
  
  # MyClientFrame#on_connect()
  # Called from File > Connect, which prompts the user where they want to connect
  # to, and starts the process for connecting to the server.  Since we're looking
  # at a possibility of the connection not being completed immediately, we delegate
  # the confirmation from the connection, to our polling loop here.  And we utilize
  # the less known method Socket#connect_nonblock().  Oviously, Ruby will throw
  # an exception if the connection isn't completed immedately, which is alright,
  # we are expecting such.  So we ignore any errors, and process thoes in our poll
  # loop for connecting.
  def on_connect
    unless @socket.nil?
      Wx::message_box("You are already connected to a server!","Connect to...",Wx::ID_OK|Wx::ICON_ERROR)
      return
    end
    msgbox = Wx::TextEntryDialog.new(self,"Enter the server you wish to connect to: (Default: #{$LOCALHOST_NAME}:1234)",
                                      "Connect to server",@addr + ":" + @port.to_s)
    ret = msgbox.show_modal
    if ret == Wx::ID_CANCEL
      return
    end
    @socket = Socket.new(AF_INET,SOCK_STREAM,0)
    sockaddr = msgbox.get_value
    unless sockaddr.index(":")
      sockaddr += ":1234"
    end
    @host,@port = sockaddr.split(":")
    sockaddr = Socket.sockaddr_in(@port,@host)
    begin
      @socket.connect_nonblock(sockaddr)
    rescue
      # We're polling for connection anyways
    end
    append_prog_msg("Attempting to connect to #{@host}:#{@port}")
    get_menu_bar.enable(ID_CONNECT,false)
    get_menu_bar.enable(ID_DISCONNECT,false)
    start_client_thread
  end
  
  # MyClientFrame#disconnect()
  # This method utitilizes the closing of the socket connection, and killing
  # any thread that may be running, and since we have no threads, we don't need
  # the timer to be running, so we stop that as well.
  def disconnect()
    return if @socket.nil?
		Thread.kill(@thread) unless @thread.nil?
    @socket.send_packet("QUIT")
    @socket.close()
    @socket = nil
    @timer.stop
    get_menu_bar.enable(ID_CONNECT,true)
    get_menu_bar.enable(ID_DISCONNECT,false)
  end
  
  # MyClientFrame#on_disconnect()
  # This method is ran from File > Disconnect and processes the disconnection from
  # the server.
  def on_disconnect()
    disconnect()
    append_prog_msg("You have disconnected from the server.")
  end
  
  # MyClientFrame#on_name()
  # This method is ran from File > Nickname, and processes the nickname that the
  # client will use.
  def on_name
    msgbox = Wx::TextEntryDialog.new(self,"Enter the new nickname you want to be (Default: Client)",
                                      "Change Nickname",@nick)
    ret = msgbox.show_modal
    if ret == Wx::ID_CANCEL
      return
    end
    
    nick = msgbox.get_value
    nick = nick.split(" ").join("_") if nick.index(" ")
    @socket.send_packet("NICK #{nick}") unless @socket.nil?
    append_prog_msg("You changed nicknames from #{@nick} to #{nick}")
    @nick = nick
    @socket.send_packet("WHO") unless @socket.nil?
  end
  
  # MyClientFrame#on_exit()
  # This method is ran from File > Exit, and delegates the control over to
  # MyClientFrame#on_close() to do it's checks to see if they are still connected
  # or not.
  def on_exit
    self.close
  end
  
  # MyClientFrame#on_close(evt)
  # This method is ran from the OnCloseEvent, and checks to see if the client is still
  # connected to the server.  If they are, it will confirm if they want to disconnect
  # from the server or not.  If they don't want to disconnect, it will veto the close
  # event.
  def on_close(evt)
    unless @socket.nil?
      ret = Wx::message_box("You are still connected to the server, do you wish to disconnect?","Disconnect",Wx::YES|Wx::NO|Wx::ICON_QUESTION)
      if ret == Wx::NO
        evt.veto
      else
        disconnect()
        Wx::get_app.exit_main_loop()
      end
    else
      Wx::get_app.exit_main_loop()
    end
  end
  
  # MyClientFrame#on_text()
  # This method is executed from when the user presses the Enter button from the
  # input box.  It will processes it for any /commands, and run them as nesscary
  # otherwise, it will send the data to the server.
  def on_text
    msg = @input.get_value
    @input.set_value("")
    case msg
    when /\/connect/
      on_connect
    when /\/disconnect/
      on_disconnect
    when /\/nick/
      on_name
    when /\/exit/
			self.close
		when /\/eval/
			evl_str = msg[5..-1]
			append_prog_msg(self.instance_eval(evl_str).inspect)
    when /\/me/
      append_msg("<-- #{@nick} #{msg[4..-1]}")
      msg = "EMOTE " + msg[4..-1]
      @socket.send_packet(msg)
    else
      append_msg("<-- #{@nick} says: #{msg}")
      msg = "MSG " + msg
      @socket.send_packet(msg)
    end
  end
  
  # MyClientFrame#poll_connect()
  # This method is called from within the polling thread, and will run till
  # it either finds that the socket has been completed, and connected to a server,
  # otherwise, it will check to see if there is an error.  If there is, then that
  # means we weren't able to connect to the server.  This will then run the method
  # Socket#connect() inside a rescue condition, so that we can see why we wasn't
  # able to connect to the server.
  def poll_connect()
    loop do
      @mutex.lock
      ret = IO::select(nil,[@socket],[@socket],0.3)
      unless ret.nil?
				if Wx::PLATFORM == "WXMSW"
					unless ret[2] == []
						# We have an error
						error = nil
						begin
							error = @socket.connect(Socket.sockaddr_in(@port,@host))
						rescue => e
							error = e
						end
						append_error("Error attempting to connect to #{@host}:#{@port}")
						append_error("Message: #{e} (#{e.class})")
						@mutex.unlock
						@socket.close()
						@socket = nil
						get_menu_bar.enable(ID_CONNECT,true)
						get_menu_bar.enable(ID_DISCONNECT,false)
						@timer.stop()
						Thread.kill(@thread)
						@thread.exit
						return
					end
				else # For WXGTK and WXMAC
					# Since on WXGTK and WXMAC doesn't return the error part in ret, we need
					# to check and see if we are connected.
					error = nil
					begin
						error = @socket.connect(Socket.sockaddr_in(@port,@host))
					rescue => e
						error = e
					end
					if error.class != Fixnum && !error.nil?
						# We're not connected!
						append_error("Error attempting to connect to #{@host}:#{@port}")
						append_error("Message: #{e} (#{e.class})")
						@mutex.unlock
						@socket.close()
						@socket = nil
						get_menu_bar.enable(ID_CONNECT,true)
						get_menu_bar.enable(ID_DISCONNECT,false)
						@timer.stop()
						Thread.kill(@thread)
						@thread.exit
						return
					end
				end
        append_prog_msg("Connected to #{@host}:#{@port}")
        get_menu_bar.enable(ID_CONNECT,false)
        get_menu_bar.enable(ID_DISCONNECT,true)
        @socket.send_packet("CONNECT #{@nick}")
        @socket.send_packet("WHO")
        @mutex.unlock
        break
      end
      @mutex.unlock
    end
  end
  
  # MyClientFrame#parse_message(msg)
  # This method checks to see what message is being received from the server
  # add display it to the user, as needed.
  def parse_message(msg)
    case msg
    when /CONNECT/
      append_msg("--> #{msg[8..-1]} has joined the chat server.")
      #@users.insert_item(0,msg[8..-1],0)
      add_user(msg[8..-1])
    when /DISCONN/
      append_msg("--> #{msg[8..-1]} has been removed from the chat server.")
    when /CONN/
      append_msg("<!> New connection incoming to the server.")
    when /WHO/
      cmd, *usrs = msg.split(" ")
      clear_users()
      usrs.each do |usr|
        add_user(usr)
      end
    when /NICK/
      a = msg.index_from(5," ")
      old = msg[5..a-1]
      new = msg[a+1..-1]
      append_msg("--> #{old} has changed their nickname to #{new}")
      @socket.send_packet("WHO")
    when /MSG/
      a = msg.index_from(4," ")
      user = msg[4..a-1]
      txt = msg[a+1..-1]
      append_msg("--> #{user} says: #{txt}")
    when /EMOTE/
      a = msg.index_from(6," ")
      user = msg[6..a-1]
      txt = msg[a+1..-1]
      append_msg("--> #{user} #{txt}")
    when /QUIT/
      append_msg("--> #{msg[5..-1]} is quitting the chat server.")
      @socket.send_packet("WHO")
    when /SHUTDOWN/
      append_msg("--> #{msg[9..-1]}")
    else
      append_error("Unknown message received from the server.")
      append_error("Message: #{msg}")
    end
  end
  
  # MyClientFrame#poll_data()
  # This method will poll the connection for incoming data, and to see if it
  # has been disconnected from the server or not.  It will continue to poll
  # till a connection has been closed, either by the server, or by the user.
  def poll_data()
    loop do
      @mutex.lock
      ret = IO::select([@socket],nil,nil,0.3)
      unless ret.nil?
        if @socket.eof?
          append_prog_msg("You have been disconnected from the server!")
          get_menu_bar.enable(ID_CONNECT,true)
          get_menu_bar.enable(ID_DISCONNECT,false)
          @socket.close
          @socket = nil
          @timer.stop
          @mutex.unlock
					@thread.exit
          break
        end
        msg = @socket.recv_packet()
        @buffer += msg
        loop do
          at = @buffer.index("\n")
          if at.nil?
            break
          end
          data = @buffer[0..at-1]
          @buffer = @buffer[at+1..-1]
          parse_message(data)
        end
      end
      @mutex.unlock
    end
  end
  
  # MyClientFrame#start_client_thread()
  # This method will actually start the polling of a connection for the connection
  # and data.  First it will start the polling of the connection, after it successfully
  # receives the connection, it will start polling for incoming data.
  def start_client_thread
    @thread = Thread.new do
      @timer.start(25)
      poll_connect()
      poll_data()
    end
  end
end

class MySocketApp < Wx::App
  def on_init
		Thread.abort_on_exception = true
    frame = MyClientFrame.new(nil,-1,"Socket Demo >> Client")
    frame.show
  end
end

MySocketApp.new.main_loop
