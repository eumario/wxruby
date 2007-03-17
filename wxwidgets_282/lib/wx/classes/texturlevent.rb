class Wx::TextUrlEvent
  # Returns the string URL  that is being interacted with in this event
  def get_url
    get_event_object.get_value[get_url_start .. get_url_end]
  end
end
