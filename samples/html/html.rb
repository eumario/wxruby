#!/usr/bin/env ruby
# wxRuby2 Sample Code. Copyright (c) 2004-2008 wxRuby development team
# Freely reusable code: see SAMPLES-LICENSE.TXT for details
begin
  require 'rubygems' 
rescue LoadError
end
require 'wx'

require 'net/http'
require 'uri'

class MyHtmlWindow < Wx::HtmlWindow
  attr_reader :html_src
  def initialize(*args)
    super
    evt_html_link_clicked self, :on_link_clicked
    evt_html_cell_hover self, :on_hover
  end

  def load_page_from_uri(uri)
    case uri
    when URI::HTTP
      Wx::BusyCursor.busy do
        begin
          res = Net::HTTP.start(uri.host, uri.port) do | http |
            http.get(uri.path)
          end
          @loaded_uri = uri
          set_page(res.body)
        rescue => err
          msg = "Could not load page:\n#{err}"
          Wx::MessageDialog.new(nil, msg, 'Error loading page', 
                                 Wx::OK|Wx::ICON_ERROR).show_modal
          return ''
        end
      end
      return @loaded_uri
    when URI::Generic
      if @loaded_uri and @loaded_uri.kind_of?(URI::HTTP)
        return load_page_from_uri( @loaded_uri.merge(uri) )
      elsif @loaded_uri # current viewing a file
        if uri.to_s =~ /^\//
          return load_file(uri.path)
        elsif not uri.path.empty?
          local_file = File.join( File.dirname(@loaded_uri.path), uri.path)
          return load_file( local_file )
        end
      end
    end

    dlg = Wx::MessageDialog.new(nil, "Can't load link",
                                 "Unable to load the link #{uri}",
                                 Wx::ICON_ERROR)
    dlg.show_modal
  end

  def load_file(file)
    @loaded_uri = URI.parse("file:////" + file)
    super file
    @loaded_uri
  end
  
  def set_page(html)
    super html
    @html_src = html
    related_frame.addr_bar.value = @loaded_uri.to_s
  end

  def on_link_clicked(event)
    href = event.link_info.href
    return if href =~ /^#/
    link_uri = URI.parse(href)
    @loaded_uri = load_page_from_uri(link_uri)
  end

  def on_hover(event)
    if link = event.cell.link
      related_frame.set_status_text(link.href)
    else
      related_frame.status_text = ''
    end
  end
end

# The frame or self-contained window for this application
class HtmlFrame < Wx::Frame
  attr_reader :html_win, :addr_bar

  def initialize(title, pos, size, style = Wx::DEFAULT_FRAME_STYLE)
    # A main application frame has no parent (nil)
    # -1 means this frame will be supplied a default id
    super(nil, -1, title, pos, size, style)
    setup_menus
    setup_panel
    create_status_bar
    self.status_text = "Welcome to wxRuby!"
  end

  def setup_panel
    panel = Wx::Panel.new(self, -1)

    sizer = Wx::BoxSizer.new(Wx::VERTICAL)
    top_sizer = Wx::BoxSizer.new(Wx::HORIZONTAL)
    
    @go_butt  = Wx::StaticText.new(panel, -1, 'Location:')
    top_sizer.add(@go_butt, 0, Wx::ALL, 4)
    @addr_bar = Wx::TextCtrl.new(panel, -1, 'HOME', Wx::DEFAULT_POSITION,
                                Wx::DEFAULT_SIZE, Wx::TE_READONLY)
    top_sizer.add(@addr_bar, 1, Wx::ALL, 4)
    sizer.add(top_sizer, 0, Wx::EXPAND|Wx::TOP|Wx::BOTTOM, 4)

    @html_win = MyHtmlWindow.new(panel, -1)
    @html_win.set_related_frame(self, 'HTML Window: %s')

    @html_win.set_page(DATA.read)
    sizer.add(@html_win, 1, Wx::ALL|Wx::GROW, 4)
    panel.set_sizer(sizer)
  end

  def setup_menus
    menu_file = Wx::Menu.new()
    menu_help = Wx::Menu.new()
    # Using Wx::ID_ABOUT default id means the menu item will be placed
    # in the correct platform-specific place
    menu_help.append(Wx::ID_ABOUT, "&About...\tF1", "Show about dialog")
    menu_file.append(Wx::ID_OPEN, "&Open File...\tCtrl-O", "Open File")
    menu_file.append(Wx::ID_HIGHEST + 1, "&Open URL...\tCtrl-U", "Open URL")
    menu_file.append(Wx::ID_PRINT, "&Print...\tCtrl-P", "Print")

    menu_file.append(Wx::ID_PREVIEW, "&Preview...\tCtrl-Shift-P", 
                     "Print Preview")
    menu_file.append(Wx::ID_EXIT, "E&xit\tAlt-X", "Quit this program")

    menu_bar = Wx::MenuBar.new()
    menu_bar.append(menu_file, "&File")
    menu_bar.append(menu_help, "&Help")
    # Assign the menus to this frame
    self.menu_bar = menu_bar
    # handle menu events
    evt_menu Wx::ID_OPEN, :on_open_file
    evt_menu Wx::ID_HIGHEST + 1, :on_open_url
    evt_menu Wx::ID_PRINT, :on_print
    evt_menu Wx::ID_PREVIEW, :on_preview
    evt_menu Wx::ID_EXIT, :on_quit
    evt_menu Wx::ID_ABOUT, :on_about
  end

  # end the application
  def on_quit
    close
  end

  def on_open_file
    f_dlg = Wx::FileDialog.new(self, "Open an HTML file", "", "", 
                                "HTML files (*.html;*.htm)|*.html;*.htm)", 
                                Wx::OPEN)
    if not f_dlg.show_modal == Wx::ID_OK
      return
    end
    html_file = f_dlg.get_path
    if html_file.index("\\")
      html_file = html_file.split("\\").join("/")
    end
    @html_win.load_file(html_file)
  end

  def on_open_url
    url = Wx::get_text_from_user('Enter URL to open', 'Enter URL')
    if not url.empty?
      uri = URI.parse(url)
      uri.path = '/' if uri.path.empty?
      @html_win.load_page_from_uri(uri)
    end
  end

  # show an 'About' dialog
  def on_about
    msg =  sprintf("This is the About dialog of the HTML sample.\n" \
                   "Welcome to wxRuby, version %s", Wx::WXRUBY_VERSION)

    # create a simple message dialog with OK button
    about_dlg = Wx::MessageDialog.new( self, msg, 'About WxRuby HTML',
                                       Wx::OK|Wx::ICON_INFORMATION )
    about_dlg.show_modal()
	about_dlg.destroy()
  end

  def on_preview
    print = Wx::HtmlEasyPrinting.new('Print HTML', self)
    print.preview_text(@html_win.html_src)
  end

  def on_print
    print = Wx::HtmlEasyPrinting.new('Print HTML', self)
    print.print_text(@html_win.html_src)
  end

  # utility function to find an icon relative to this ruby script
  def local_icon_file(icon_name)
    File.join( File.dirname(__FILE__), icon_name) 
  end
end

# Wx::App is the container class for any wxruby app - only a single
# instance is required
class HtmlApp < Wx::App
  def on_init
    frame = HtmlFrame.new("Minimal wxRuby App",
                             Wx::Point.new(50, 50), 
                             Wx::Size.new(450, 340))
    set_app_name('HtmlDemo')
    # required
    frame.show()
  end
end

# Create an instance ...
app = HtmlApp.new
# ... and run the application
app.main_loop()

__END__
<html>
<head>
<title>WxRuby HTML Demo</title>
</head>

<body bgcolor="#ffffff">
<h1>The HtmlWindow widget</h1>
<p>This is a very simple demonstration of
<strong>Wx::HtmlWindow</strong>, a control for displaying hypertext. The
  control understands most HTML tags, including links, tables, images,
  lists and the venerable FONT tag. It does not know about CSS or
  Javascript; it is not really intended for building a general-purpose
  web browser.</p>
<h2>This demo</h2>
<p>In this demo you can open local files for viewing (by choosing the
File / Open). If you have an internet connection http:// links will be
downloaded as well. Its features are otherwise limited - for example,
this example doesn't know about HTML anchor targets, because it has
over-ridden default link handling to show how to subclass and
specialise HtmlWindow in Ruby.</a>
<h2>Html Easy Printing</h2>
<p>A useful feature included with WxRuby is a simple interface for
printing HTML. You can see this in action by choosing 'Print' or
'Preview' from the File menu.</p>
<h3>Further information</h3>
<p>Here's a table with some links</p>
<table border="1">
<tr>
<td>WxRuby online documentation</td>
<td><a href="http://wxruby.rubyforge.org/doc/">http://wxruby.rubyforge.org/doc/</a></td>
</tr>
<tr>
<td>WxRuby Wiki</td>
<td><a href="http://wxruby.rubyforge.org/wiki/wiki.pl">http://wxruby.rubyforge.org/wiki/wiki.pl</a></td>
</tr>
</table>

</body>
</html>
