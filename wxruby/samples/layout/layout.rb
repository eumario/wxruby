
require 'wxruby'
include Wx

LAYOUT_QUIT       = 100
LAYOUT_TEST       = 101
LAYOUT_ABOUT      = 102
LAYOUT_TEST_SIZER = 104
LAYOUT_TEST_NB    = 105


#-----------------------------------------------------------------
#  MySizerFrame
#-----------------------------------------------------------------
class MySizerFrame < Frame
    def initialize(frame,title,x,y)
        super(frame, -1, title, Point.new(x, y) )

        # we want to get a dialog that is stretchable because it
        # has a text ctrl in the middle. at the bottom, we have
        # two buttons which.
        topsizer = BoxSizer.new( VERTICAL )

        # 1) top: create StaticText with minimum size equal to its default size
        topsizer.add(
            StaticText.new( self, -1, "An explanation (ALIGN_RIGHT)." ),
            0,                         # make vertically unstretchable
            ALIGN_RIGHT |            # right align text
            NORTH | EAST | WEST,  # make border all around except BOTTOM
            5 )                      # set border width to 5

        # 2) top: create TextCtrl with minimum size (100x60)
        topsizer.add(
            TextCtrl.new( self, -1, "My text (EXPAND).", DEFAULT_POSITION, Size.new(100,60), TE_MULTILINE),
            1,            # make vertically stretchable
            EXPAND |    # make horizontally stretchable
            ALL,        #   and make border all around
            5 )         # set border width to 5

        # 2.5) Gratuitous test of StaticBoxSizers
        statsizer = StaticBoxSizer.new(
            StaticBox.new(self, -1, "A StaticBoxSizer"),
            VERTICAL )
        statsizer.add(
            StaticText.new(self, -1, "And some TEXT inside it"),
            0,
            CENTER |
            ALL,
            30)
        topsizer.add(statsizer, 1, EXPAND | ALL, 10)

        # 2.7) And a test of GridSizer
        gridsizer = GridSizer.new(2, 5, 5)
        gridsizer.add(StaticText.new(self, -1, "Label"), 0,
                  ALIGN_RIGHT | ALIGN_CENTER_VERTICAL)
        gridsizer.add(TextCtrl.new(self, -1, "Grid sizer demo"), 1,
                   GROW | ALIGN_CENTER_VERTICAL)
        gridsizer.add(StaticText.new(self, -1, "Another label"), 0,
                   ALIGN_RIGHT | ALIGN_CENTER_VERTICAL)
        gridsizer.add(TextCtrl.new(self, -1, "More text"), 1,
                   GROW | ALIGN_CENTER_VERTICAL)
        gridsizer.add(StaticText.new(self, -1, "Final label"), 0,
                   ALIGN_RIGHT | ALIGN_CENTER_VERTICAL)
        gridsizer.add(TextCtrl.new(self, -1, "And yet more text"), 1,
                   GROW | ALIGN_CENTER_VERTICAL)
        topsizer.add(gridsizer, 1, GROW | ALL, 10)


        # 3) middle: create StaticLine with minimum size (3x3)
        topsizer.add(
            StaticLine.new( self, -1, DEFAULT_POSITION, Size.new(3,3), HORIZONTAL),
            0,           # make vertically unstretchable
            EXPAND |   # make horizontally stretchable
            ALL,       #   and make border all around
            5 )         # set border width to 5


        # 4) bottom: create two centred Buttons
        button_box = BoxSizer.new( HORIZONTAL )
        button_box.add(
            Button.new( self, -1, "Two buttons in a box" ),
            0,           # make horizontally unstretchable
            ALL,       # make border all around
            7 )         # set border width to 7
        button_box.add(
            Button.new( self, -1, "(CENTER)" ),
            0,           # make horizontally unstretchable
            ALL,       # make border all around
            7 )         # set border width to 7

        topsizer.add(
            button_box,
            0,          # make vertically unstretchable
            CENTER ) # no border and centre horizontally

        # don't allow frame to get smaller than what the sizers tell it and also set
        # the initial size as calculated by the sizers
        topsizer.set_size_hints( self )

        set_sizer( topsizer )
    end

end

# Define a new text subwindow that can respond to drag-and-drop
class MyTextWindow < TextCtrl
    def initialize(frame, x=-1, y=-1, width=-1, height=-1, style=TE_MULTILINE)
        super(frame, -1, "", Point.new(x, y), Size.new(width, height), style)

    end

end


# Define a new canvas which can receive some events
class MyWindow < Window
    def initialize(frame, x, y, w, h, style)
        super(frame, -1, Point.new(x, y), Size.new(w, h), style)

        evt_paint {onPaint}
    end

    # Define the repainting behaviour
    def onPaint
        dc = PaintDC.new(self)
        dc.set_pen(GREEN_PEN)
        dc.draw_line(0, 0, 200, 200)
        dc.draw_line(200, 0, 0, 200)

        dc.set_brush(CYAN_BRUSH)
        dc.set_pen(RED_PEN)

        dc.draw_rectangle(100, 100, 100, 50)
        dc.draw_rounded_rectangle(150, 150, 100, 50, 20)

        dc.draw_ellipse(250, 250, 100, 50)
        dc.draw_spline([Point.new(50, 200),Point.new(50, 100),Point.new(200, 10)])
        dc.draw_line(50, 230, 200, 230)

        dc.set_pen(BLACK_PEN)
        dc.draw_arc(50, 300, 100, 250, 100, 300 )
        dc.free
    end

end

# Define a new frame
class MyFrame < Frame
    def initialize(frame,title,x,y,w,h)
        super(frame, -1, title, Point.new(x, y), Size.new(w, h))

        evt_menu(LAYOUT_QUIT) {onQuit}
        evt_menu(LAYOUT_TEST_SIZER) {onTestSizers}
        evt_menu(LAYOUT_TEST_NB) {onTestNotebookSizers}
        evt_menu(LAYOUT_ABOUT) {onAbout}
    end

    def onQuit
        close(TRUE)
    end

    def onTestSizers
        newFrame = MySizerFrame.new(nil, "Sizer Test Frame", 50, 50)
        newFrame.show(TRUE)
    end

    def onTestNotebookSizers

        dialog = Dialog.new( self, -1, "Notebook Sizer Test Dialog")

        # Begin with first hierarchy: a notebook at the top and
        # and OK button at the bottom.

        topsizer = BoxSizer.new( VERTICAL )

        notebook = Notebook.new( dialog, -1 )
        nbs = NotebookSizer.new( notebook )
        topsizer.add( nbs, 1, GROW )

        button = Button.new( dialog, ID_OK, "OK" )
        topsizer.add( button, 0, ALIGN_RIGHT | ALL, 10 )

        # First page: one big text ctrl
        multi = TextCtrl.new( notebook, -1, "TextCtrl.", DEFAULT_POSITION, DEFAULT_SIZE, TE_MULTILINE )
        notebook.add_page( multi, "Page One" )

        # Second page: a text ctrl and a button
        panel = Panel.new( notebook, -1 )
        notebook.add_page( panel, "Page Two" )

        panelsizer = BoxSizer.new( VERTICAL )

        text = TextCtrl.new( panel, -1, "TextLine 1.", DEFAULT_POSITION, Size.new(250,-1) )
        panelsizer.add( text, 0, GROW|ALL, 30 )
        text = TextCtrl.new( panel, -1, "TextLine 2.", DEFAULT_POSITION, Size.new(250,-1) )
        panelsizer.add( text, 0, GROW|ALL, 30 )
        button2 = Button.new( panel, -1, "Hallo" )
        panelsizer.add( button2, 0, ALIGN_RIGHT | WEST|EAST|SOUTH, 30 )

        panel.set_auto_layout( TRUE )
        panel.set_sizer( panelsizer )

        # Tell dialog to use sizer

        dialog.set_auto_layout( TRUE )
        dialog.set_sizer( topsizer )
        topsizer.fit( dialog )
        topsizer.set_size_hints( dialog )

        dialog.show_modal()
    end

    def onAbout
        message_box("Windows GUI library layout demo\n",
                "About Layout Demo", OK|CENTRE)
    end

end

class MyApp < App
    
    def on_init()

        # Create the main frame window
        frame = MyFrame.new(nil, "Windows Layout Demo", -1, -1, 400, 300)

        frame.set_auto_layout(TRUE)

        # Give it a status line
        frame.create_status_bar(2)

        # Make a menubar
        file_menu = Menu.new

        file_menu.append(LAYOUT_TEST_SIZER, "&Test sizers",      "Test sizer")
        file_menu.append(LAYOUT_TEST_NB, "&Test notebook sizers",      "Test notebook sizer")

        file_menu.append_separator()
        file_menu.append(LAYOUT_QUIT, "E&xit",                "Quit program")

        help_menu = Menu.new
        help_menu.append(LAYOUT_ABOUT, "&About",              "About layout demo")

        menu_bar = MenuBar.new

        menu_bar.append(file_menu, "&File")
        menu_bar.append(help_menu, "&Help")

        # Associate the menu bar with the frame
        frame.set_menu_bar(menu_bar)

        # Make a panel
        panel = Panel.new(frame)

        # Create some panel items
        btn1 = Button.new(panel, -1, "A button (1)")

        b1 = LayoutConstraints.new
        b1.centre_x.same_as(panel, LAYOUT_CENTRE_X)
        b1.top.same_as(panel, LAYOUT_TOP, 5)
        b1.width.percent_of(panel, LAYOUT_WIDTH, 80)
        b1.height.as_is()
        btn1.set_constraints(b1)

        list = ListBox.new(panel, -1,
            Point.new(-1, -1), Size.new(200, 100))
        list.append("Apple")
        list.append("Pear")
        list.append("Orange")
        list.append("Banana")
        list.append("Fruit")

        b2 = LayoutConstraints.new
        b2.left.same_as(panel, LAYOUT_LEFT, 5)
        b2.top.below(btn1, 5)
        b2.width.percent_of(panel, LAYOUT_WIDTH, 40)
        b2.bottom.same_as(panel, LAYOUT_BOTTOM, 5)
        list.set_constraints(b2)

        mtext = TextCtrl.new(panel, -1, "Some text")

        b3 = LayoutConstraints.new
        b3.top.below(btn1, 5)
        b3.left.right_of(list, 5)
        b3.right.same_as(panel, LAYOUT_RIGHT, 5)
        b3.bottom.same_as(panel, LAYOUT_BOTTOM, 5)
        mtext.set_constraints(b3)

        @canvas = MyWindow.new(frame, 0, 0, 400, 400, RETAINED)

        # Make a text window
        text_window = MyTextWindow.new(frame, 0, 250, 400, 150)

        # Set constraints for panel subwindow
        c1 = LayoutConstraints.new

        c1.left.same_as(frame, LAYOUT_LEFT)
        c1.top.same_as(frame, LAYOUT_TOP)
        c1.right.percent_of(frame, LAYOUT_WIDTH, 50)
        c1.height.percent_of(frame, LAYOUT_HEIGHT, 50)

        panel.set_constraints(c1)

        # Set constraints for canvas subwindow
        c2 = LayoutConstraints.new

        c2.left.same_as(panel, LAYOUT_RIGHT)
        c2.top.same_as(frame, LAYOUT_TOP)
        c2.right.same_as(frame, LAYOUT_RIGHT)
        c2.height.percent_of(frame, LAYOUT_HEIGHT, 50)

        @canvas.set_constraints(c2)

        # Set constraints for text subwindow
        c3 = LayoutConstraints.new
        c3.left.same_as(frame, LAYOUT_LEFT)
        c3.top.below(panel)
        c3.right.same_as(frame, LAYOUT_RIGHT)
        c3.bottom.same_as(frame, LAYOUT_BOTTOM)

        text_window.set_constraints(c3)

        frame.show(TRUE)

        frame.set_status_text("Windows layout demo")

        set_top_window(frame)

    end
end

a = MyApp.new
a.main_loop()
