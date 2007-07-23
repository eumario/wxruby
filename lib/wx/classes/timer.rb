# Class allowing periodic or timed events to be fired
class Wx::Timer
  # This class can be linked to an owner - an instance of a class
  # derived from EvtHandler which will receive Timer events. However,
  # event if a Wx::Timer is attached to a Wx::Window, it is (unlike most
  # classes) NOT automatically deleted when the window is destroyed. If
  # the Timer continues ticking, it will send events to the
  # now-destroyed window, causing segfaults. So the little acrobatics
  # below set up a hook when a Timer's owner is set, and then ensure the
  # timer is stopped when the window is destroyed.

  # Redefine initialize
  wx_init = self.instance_method(:initialize)
  define_method(:initialize) do | *args |
    setup_owner_destruction_hook(args[0])
    wx_init.bind(self).call(*args)
  end

  # Redefine set_owner
  wx_set_owner = self.instance_method(:set_owner)
  define_method(:set_owner) do | *args |
    setup_owner_destruction_hook(args[0])
    wx_set_owner.bind(self).call(*args)
  end

  private 
  # This method notes in Ruby the ownership of the timer, from both
  # sides, and sets up an event hook if needed for the window's
  # destruction.
  def setup_owner_destruction_hook(new_owner)
    this_timer = self

    # Class-wide list of global (unowned) timers
    @@__unowned_timers__ ||= []

    # remove from list of previous owner
    if @__owner__
      @__owner__.instance_eval { @__owned_timers__.delete(this_timer) }
    end

    # If becoming global unowned timer, add to list of those timers
    if not new_owner
      @__owner__ = nil
      @@__unowned_timers__ << self      
      return
    end
    
    # Otherwise, if previously unowned, remove from global owned
    @@__unowned_timers__.delete(self)
    @__owner__ = new_owner

    # Then add to list of new owner, setting destructor hook if required    
    new_owner.instance_eval do
      if not @__owned_timers__
        @__owned_timers__ = []
        unless self.kind_of?(Wx::App) # Don't set up hook on App
          evt_window_destroy do | evt |
            # If it's the owning window being destroyed...
            if evt.get_event_object == self
              @__owned_timers__.each { | timer | timer.stop }
            end
            evt.skip
          end
        end
      end
      @__owned_timers__ << this_timer
    end
  end
end
