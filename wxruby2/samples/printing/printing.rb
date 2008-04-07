#!/usr/bin/env ruby
# wxRuby2 Sample Code. Copyright (c) 2004-2008 wxRuby development team
# Freely reusable code: see SAMPLES-LICENSE.TXT for details
begin
  require 'rubygems' 
rescue LoadError
end
require 'wx'

class MyCanvas < Wx::ScrolledWindow
  #attr_accessor :frame
  
  def initialize(parent,pos,size,style = Wx::RETAINED)
    super(parent,-1,pos,size,style)
    @frame = parent
    set_background_colour(Wx::WHITE)
    evt_mouse_events() {|e| on_event(e)}
  end

  def on_draw(dc)
    @frame.draw(dc)
  end
  
  def on_event(event)
  end
end

class MyPrintout < Wx::Printout
  def initialize(title = "My printout")
    super(title)
  end
  
  def on_print_page(page)
    dc = get_dc
    if dc
        if page == 1
            draw_page_one(dc)
        elsif (page == 2)
            draw_page_two(dc)
        end
        dc.set_device_origin(0, 0)
        dc.set_user_scale(1.0, 1.0)

        buf = "PAGE #{page}"
        dc.draw_text(buf, 10, 10)

        return true
    else
        return false
    end
  end
  
  def on_begin_document(start_page,end_page)
    go_ahead = super(start_page, end_page)
    if (!go_ahead)
        return false
    end
    return true
  end
  
  def has_page(page)
    return (page == 1 || page == 2)
  end
  
  def get_page_info
    min_page = 1
    max_page = 2
    sel_page_from = 1
    sel_page_to = 2
    [min_page,max_page,sel_page_from,sel_page_to]
  end

  def draw_page_one(dc)
    # You might use THIS code if you were scaling
    # graphics of known size to fit on the page.

    # We know the graphic is 200x200. If we didn't know this,
    # we'd need to calculate it.
    max_x = 200
    max_y = 200

    # Let's have at least 50 device units margin
    margin_x = 50
    margin_y = 50

    # Add the margin to the graphic size
    max_x += (2*margin_x)
    max_y += (2*margin_y)

    # Get the size of the DC in pixels
    size = dc.get_size
    w = size.get_width
    h = size.get_height

    # Calculate a suitable scaling factor
    scale_x=(w/max_x)
    scale_y=(h/max_y)

    # Use x or y scaling factor, whichever fits on the DC
    #actualScale = Wx::min(scaleX,scaleY)
    if scale_x < scale_y
      actual_scale = scale_x
    else
      actual_scale = scale_y
    end

    # Calculate the position on the DC for centring the graphic
    pos_x = ((w - (200*actual_scale))/2.0)
    pos_y = ((h - (200*actual_scale))/2.0)

    # Set the scale and origin
    dc.set_user_scale(actual_scale, actual_scale)
    dc.set_device_origin( pos_x.to_i, pos_y.to_i )

    Wx::get_app.frame.draw(dc)
  end
  
  def draw_page_two(dc)
    # You might use THIS code to set the printer DC to ROUGHLY reflect
    # the screen text size. This page also draws lines of actual length
    # 5cm on the page.

    # Get the logical pixels per inch of screen and printer
    ppi_screen_x, ppi_screen_y = get_ppi_screen
    ppi_printer_x, ppi_printer_y = get_ppi_printer

    # This scales the DC so that the printout roughly represents the
    # the screen scaling. The text point size _should_ be the right size
    # but in fact is too small for some reason. This is a detail that will
    # need to be addressed at some point but can be fudged for the
    # moment.
    scale = ( ppi_printer_x.to_f / ppi_screen_x.to_f )

    # Now we have to check in case our real page size is reduced
    # (e.g. because we're drawing to a print preview memory DC)
    page_width, page_height = get_page_size_pixels
    size = dc.get_size
    w = size.get_width
    h = size.get_height
    
    # If printer pageWidth == current DC width, then this doesn't
    # change. But w might be the preview bitmap width, so scale down.
    overall_scale = scale * (w/page_width)
    dc.set_user_scale(overall_scale, overall_scale)

    # Calculate conversion factor for converting millimetres into
    # logical units.
    # There are approx. 25.4 mm to the inch. There are ppi
    # device units to the inch. Therefore 1 mm corresponds to
    # ppi/25.4 device units. We also divide by the
    # screen-to-printer scaling factor, because we need to
    # unscale to pass logical units to DrawLine.

    # Draw 50 mm by 50 mm L shape
    log_units_factor = (ppi_printer_x/(scale*25.4))
    log_units = (50*log_units_factor)
    dc.set_pen(Wx::BLACK_PEN)
    dc.draw_line(50, 250, (50.0 + log_units).to_i, 250)
    dc.draw_line(50, 250, 50, (250.0 + log_units).to_i)

    dc.set_background_mode(Wx::TRANSPARENT)
    dc.set_brush(Wx::TRANSPARENT_BRUSH)

    # GetTextExtent demo:
    words = ["This ", "is ", "GetTextExtent ", "testing ", "string. ", "Enjoy ", "it!"]
    w, h = 0,0
    x = 200
    y= 250
    fnt = Wx::Font.new(15, Wx::SWISS, Wx::NORMAL, Wx::NORMAL)

    dc.set_font(fnt)
    
    words.each do |word|
      w,h = dc.get_text_extent(word)
      dc.draw_rectangle(x, y, w.to_i, h.to_i)
      w,h = dc.get_text_extent(word)
      dc.draw_text(word, x, y)
      x += w
    end

    dc.set_font(Wx::get_app.test_font)

    dc.draw_text("Some test text", 200, 300 )

    left_margin = 20
    right_margin = 20
    top_margin = 20
    bottom_margin = 20

    page_width_mm, page_height_mm = get_page_size_mm

    left_margin_logical = (log_units_factor*left_margin).to_i
    top_margin_logical = (log_units_factor*top_margin).to_i
    bottom_margin_logical = (log_units_factor*(page_height_mm - bottom_margin)).to_i
    right_margin_logical = (log_units_factor*(page_width_mm - right_margin)).to_i

    dc.set_pen(Wx::RED_PEN)
    dc.draw_line( left_margin_logical, top_margin_logical,
                  right_margin_logical, top_margin_logical)
    dc.draw_line( left_margin_logical, bottom_margin_logical,
                  right_margin_logical,  bottom_margin_logical)

    write_page_header(self, dc, "A header", log_units_factor)
  end
  
  # Writes a header on a page. Margin units are in millimetres.
  def write_page_header(printout, dc, text, mm_to_logical)
    page_width_mm, page_height_mm = printout.get_page_size_mm

    left_margin = 10
    top_margin = 10
    right_margin = 10

    left_margin_logical = (mm_to_logical*left_margin).to_i
    top_margin_logical = (mm_to_logical*top_margin).to_i
    right_margin_logical = (mm_to_logical*(page_width_mm - right_margin)).to_i

    x_extent, y_extent= dc.get_text_extent(text)
    x_pos = (((((page_width_mm - left_margin - right_margin)/2.0)+left_margin)*mm_to_logical) - (x_extent/2.0))
    dc.draw_text(text, x_pos.to_i, top_margin_logical)

    dc.set_pen(Wx::BLACK_PEN)
    dc.draw_line( left_margin_logical, (top_margin_logical + y_extent).to_i,
                  right_margin_logical, (top_margin_logical + y_extent).to_i )

    return true
  end  
end

class MyApp < Wx::App
  attr_accessor :frame,:test_font,:print_data,:page_setup_data
  
  def on_init
    @test_font = Wx::Font.new(10, Wx::SWISS, Wx::NORMAL, Wx::NORMAL)

    # Create the main frame window
    @frame = MyFrame.new(nil, "wxRuby Printing Demo", Wx::Point.new(0, 0), Wx::Size.new(400, 400))

    # Give it a status line
    @frame.create_status_bar(2)


    # Load icon and bitmap
    if Wx::PLATFORM == "WXMSW"
      icon_file = File.join(File.dirname(__FILE__), 'mondrian.ico')
      @frame.set_icon( Wx::Icon.new(icon_file, Wx::BITMAP_TYPE_ICO) )
    else
      icon_file = File.join(File.dirname(__FILE__), 'mondrian.xpm')
      @frame.set_icon( Wx::Icon.new(icon_file, Wx::BITMAP_TYPE_XPM) )
    end    

    # Make a menubar
    file_menu = Wx::Menu.new

    file_menu.append(WXPRINT_PRINT, "&Print...","Print")
    file_menu.append(WXPRINT_PAGE_SETUP, "Page Set&up...","Page setup")
    file_menu.append(WXPRINT_PREVIEW, "Print Pre&view","Preview")

=begin
    # Accelerators
    wxAcceleratorEntry entries[1];
    entries[0].Set(wxACCEL_CTRL, (int) 'V', WXPRINT_PREVIEW);
    wxAcceleratorTable accel(1, entries);
    frame->SetAcceleratorTable(accel);
=end

    file_menu.append_separator()
    file_menu.append(WXPRINT_ANGLEUP, "Angle up\tAlt-U","Raise rotated text angle")
    file_menu.append(WXPRINT_ANGLEDOWN, "Angle down\tAlt-D","Lower rotated text angle")
    file_menu.append_separator()
    file_menu.append(WXPRINT_QUIT, "E&xit","Exit program")

    help_menu = Wx::Menu.new
    help_menu.append(WXPRINT_ABOUT, "&About","About this demo")

    menu_bar = Wx::MenuBar.new

    menu_bar.append(file_menu, "&File")
    menu_bar.append(help_menu, "&Help")

    # Associate the menu bar with the frame
    @frame.set_menu_bar(menu_bar)

    canvas = MyCanvas.new(@frame, Wx::Point.new(0, 0), Wx::Size.new(100, 100), Wx::RETAINED|Wx::HSCROLL|Wx::VSCROLL)

    # Give it scrollbars: the virtual canvas is 20 * 50 = 1000 pixels in each direction
    canvas.set_scrollbars(20, 20, 50, 50)

    @frame.canvas = canvas

    @frame.centre(Wx::BOTH)
    @frame.show()

    @frame.set_status_text("Printing demo")

    set_top_window(@frame)
    
    @print_data = Wx::PrintData.new
    @page_setup_data = Wx::PageSetupDialogData.new

    return true
  end
  
  def on_exit
    return true    
  end
end


MyApp.new.main_loop()
