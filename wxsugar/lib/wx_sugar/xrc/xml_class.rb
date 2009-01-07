# Representation of a single GUI class defined in XRC. wxRuby permits
# subclasses of Frames, Dialog and Panels to be loaded from XRC. 
class XRCClass
  # Only these classes may be subclassed in Ruby
  VALID_CLASSES = %|wxFrame wxDialog wxPanel wxWizard|

  # Simple struct to hold details of a individual named control
  Control = Struct.new(:name, :sub_class)

  # base_id   : the Wx identifier of the main window
  # wx_class  : the Wx class which this window inherits from
  # sub_class : the ruby class name of this window class
  # controls  : an array of identified controls within this window
  # file_name : the XRC file from which this class can be loaded
  attr_reader :base_id, :wx_class, :sub_class, :controls, :file_name
  
  # Checks to see if a valid class can be created from +xml_elem+, and
  # returns one if it can, or nil if it can't. To be a valid class, the
  # window must inherit from Frame, Dialog or Window, and must define a
  # subclass name.
  def self.extract(xml_elem, xrc_file)
    p_class = xml_elem.attributes['class']
    if not VALID_CLASSES.include?(p_class)
      warn "Cannot create wrapper for subclass of #{p_class}"
      return 
    end

    if not xml_elem.attributes['subclass']
      warn "Cannot create wrapper for class without 'subclass'
      attribute"
      return
    end
    new(xml_elem, xrc_file)
  end

  # Create a new class from +xml_elem+
  def initialize(xml_elem, xrc_file)
    @xml_src   = xml_elem
    @file_name = xrc_file

    @base_id   = xml_elem.attributes['name']
    @wx_class  = xml_elem.attributes['class']
    @sub_class = xml_elem.attributes['subclass']
    @controls  = []
    read_controls
  end

  def superclass
    wx_class.sub(/^wx/, "Wx::")
  end

  def load_func
    unadorned = wx_class.sub(/^wx/, '').downcase
    "load_#{unadorned}_subclass"
  end

  private
  # Scans the XRC definition of this class for named contained
  # controls. Controls which are given a non-default name in the RAD
  # tool are picked up, and will be given attribute readers in the Ruby
  # class. Additionally, if a "subclass" attribute is specified for the
  # control, the Ruby control will be extended with that class. 
  def read_controls
    finder = "/resource/object[@name='#{base_id}']//*[@name]"
    REXML::XPath.each(@xml_src, finder) do | elem |
      ctrl_name = elem.attributes['name']
      # skip default names
      next if ctrl_name =~ /^wx/
      next if ctrl_name =~ /^ID_/
      ctrl_subclass = elem.attributes['subclass']
      @controls << Control.new(ctrl_name, ctrl_subclass)
    end
  end
end
