# wxRuby2 Sample Code. Copyright (c) 2007-???? Mario J. Steele
# Freely reusable code: see SAMPLES-LICENSE.TXT for details

class Socket
  # Socket#recv_packet() 
  #
  # This method retrives 1kb of data from the socket.  It uses
  # IO#readpartial due to the fact, that IO#read() uses buffered IO,
  # which can cause errors.  Where as the IO#readpartial() will read up
  # to the maximum of 1024 bytes from the socket, and return what it
  # retrives.
  def recv_packet()
    self.readpartial(1024)
  end
  
  # Socket#send_packet()
  #
  # This method will send the packet, and ensure that a LF (0x0A) is at
  # the end of the data to be sent, as this is used as the determination
  # of the end of a packet.
  def send_packet(msg)
    if !msg.index("\n")
      msg += "\n"
    end
    self.write(msg)
  end
end
