# Functionality here must be loaded first to add custom events
require 'wx/classes/evthandler'

# These event handlers should only be defined if MediaCtrl is actually
# available; some builds may not include it
if defined?(Wx::MediaCtrl)
  mediactrl_event_types = [
    EventType['evt_media_finished', 1,
               Wx::EVT_MEDIA_FINISHED,
               Wx::MediaEvent],
    EventType['evt_media_stop', 1,
               Wx::EVT_MEDIA_STOP,
               Wx::MediaEvent],
    EventType['evt_media_loaded', 1,
              Wx::EVT_MEDIA_LOADED,
              Wx::MediaEvent]
  ]
  mediactrl_event_types.each do | ev_type | 
    Wx::EvtHandler.register_event_type(ev_type)
  end
end
