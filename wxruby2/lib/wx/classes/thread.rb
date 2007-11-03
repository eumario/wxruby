module Wx
  THREAD_TIMER_ID = -(Wx::ID_HIGHEST+1000)
  class App
    def init_threaded_mode()
      @threaded_timer_interval = 25
      @timer = Wx::Timer.new(self,THREAD_TIMER_ID)
      @timer.start(@threaded_timer_interval)
      evt_timer(THREAD_TIMER_ID) { Thread.pass }
    end
  
    def shutdown_threaded_mode()
      @timer.stop
      @timer = nil
    end
  
    def set_threaded_interval(milliseconds)
      @threaded_timer_interval = milliseconds
    end
  
    def get_threaded_interval()
      @threaded_timer_interval
    end
  
    alias :threaded_interval :get_threaded_interval
    alias :threaded_interval= :set_threaded_interval
  end
end
