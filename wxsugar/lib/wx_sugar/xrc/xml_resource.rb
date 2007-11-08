require 'rexml/document'
# Parser for a complete wxWidgets XRC file. XRC files may contain one
# or more definitions of Wx Frames, Dialogs or Panels.
class XRCResource
  attr_reader :xrc_file, :classes

  # Read and seek for classes within the XML file +xrc_file+
  def initialize(xrc_file)
    @xrc_file = xrc_file
    xml_content = File.read(xrc_file)
    # workaround for an ?bug in recent REXML, which fails to match
    # certain XPath expressions when xmlns is declared
    xml_content.sub!(/xmlns="[^"]+"/, '')
    @xml_doc = REXML::Document.new(xml_content)
    @classes = []
    REXML::XPath.each(@xml_doc.root, "/resource/object") do | elem |
      if xml_klass = XRCClass.extract(elem, @xrc_file)
        @classes << xml_klass
      end
    end
  end
end
