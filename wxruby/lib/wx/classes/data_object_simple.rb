# Provide some default implementations of these to make life easier
class Wx::DataObjectSimple
  def get_data_size(format)
    get_data_here(format).size
  end
end
