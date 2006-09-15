# = WxSugar - Keyword Constructors Classes
# 
# This extension defines the keyword parameters for +new+ methods for
# widgets, windows and frames. It's for use with *Keyword Constructors*
# and is no use on its own - except if you are looking for a bug or want
# to add a  missing class.

# This is a dummy, this variable is not loaded until Wx init
# hush warnings if it has already been loaded when we get here
v = $VERBOSE
$VERBOSE = nil
Wx::NULL_BITMAP = nil
$VERBOSE = v

module WxSugar
  # accepts a string unadorned name of a WxWidgets class, and block, which 
  # defines the constructor parameters and style flags for that class.
  # If the named class exists in the available WxRuby, the block is run and 
  # the class may use keyword constructors. If the class is not available, the
  # block is ignored.
  def self.define_keyword_ctors(klass_name, &block)
    begin     
      klass =  Wx::const_get(klass_name)
    rescue NameError
      return nil
    end
    klass.module_eval { include WxSugar::KeywordConstructor }
    # automatically add :id as the first argument, unless this is a
    # Dialog subclass - which don't require this argument
    unless klass < Wx::Dialog
      klass.wx_ctor_params :id
    end
    klass.instance_eval(&block)
  end
end

### FRAMES
# Normal frame

# wxTopLevelWindow 	ABSTRACT: Any top level window, dialog or frame

# Normal frame
WxSugar.define_keyword_ctors('Frame') do
  wx_ctor_params :title => ''
  wx_ctor_params :pos, :size, :style => Wx::DEFAULT_FRAME_STYLE
  wx_ctor_params :name => 'frame'
end

# MDI child frame
WxSugar.define_keyword_ctors('MDIChildFrame') do
  wx_ctor_params :title => ''
  wx_ctor_params :pos, :size, :style => Wx::DEFAULT_FRAME_STYLE
  wx_ctor_params :name => 'frame'
end

# MDI parent frame
WxSugar.define_keyword_ctors('MDIParentFrame') do
  wx_ctor_params :title => ''
  wx_ctor_params :pos, :size
  wx_ctor_params :style => Wx::DEFAULT_FRAME_STYLE|Wx::VSCROLL|Wx::HSCROLL
  wx_ctor_params :name => 'frame'
end

# wxMiniFrame 	A frame with a small title bar
WxSugar.define_keyword_ctors('MiniFrame') do
  wx_ctor_params :title => ''
  wx_ctor_params :pos, :size
  wx_ctor_params :style =>  Wx::DEFAULT_FRAME_STYLE
  wx_ctor_params :name => 'frame'
end

# wxSplashScreen 	Splash screen class
# wxPropertySheetDialog 	Property sheet dialog
# wxTipWindow 	Shows text in a small window

# wxWizard 	A wizard dialog
WxSugar.define_keyword_ctors('Wizard') do
  wx_ctor_params :title => ''
  wx_ctor_params :bitmap => Wx::NULL_BITMAP
  wx_ctor_params :pos, :size
  wx_ctor_params :style => Wx::DEFAULT_DIALOG_STYLE
end


# MISCELLANEOUS WINDOWS

# A window whose colour changes according to current user settings
WxSugar.define_keyword_ctors('Panel') do
  wx_ctor_params :pos, :size, :style => Wx::TAB_TRAVERSAL
  wx_ctor_params :name => 'panel'
end

# wxScrolledWindow 	Window with automatically managed scrollbars
WxSugar.define_keyword_ctors('ScrolledWindow') do
  wx_ctor_params :pos, :size, :style => Wx::VSCROLL|Wx::HSCROLL
  wx_ctor_params :name => 'scrolledWindow'
  wx_ctor_flags  :h_scroll => Wx::HSCROLL, 
                 :v_scroll => Wx::VSCROLL
end

# wxGrid 	A grid (table) window
WxSugar.define_keyword_ctors('Grid') do
  wx_ctor_params :pos, :size, :style => Wx::WANTS_CHARS
  wx_ctor_params :name => 'grid'
end

# Window which can be split vertically or horizontally
WxSugar.define_keyword_ctors('SplitterWindow') do
  wx_ctor_params :pos, :size, :style => Wx::SP_3D
  wx_ctor_params :name => 'splitterWindow'
end

# Implements the status bar on a frame
WxSugar.define_keyword_ctors('StatusBar') do
  wx_ctor_params :style => Wx::ST_SIZEGRIP
  wx_ctor_params :name => 'statusBar'
end

# Toolbar class
WxSugar.define_keyword_ctors('ToolBar') do
  wx_ctor_params :pos, :size, :style => Wx::TB_HORIZONTAL|Wx::NO_BORDER
  wx_ctor_params :name => 'toolBar' # not as documented in Wx 2.6.3
end

# Notebook class
WxSugar.define_keyword_ctors('Notebook') do
  wx_ctor_params :pos, :size, :style, :name => 'noteBook' 
end

# Similar to notebook but using list control - undocumented
WxSugar.define_keyword_ctors('Listbook') do
  wx_ctor_params :pos, :size, :style, :name => 'listBook'
end

# Similar to notebook but using choice control
WxSugar.define_keyword_ctors('Choicebook') do
  wx_ctor_params :pos, :size, :style, :name => 'choiceBook'
end

# wxSashWindow:	Window with four optional sashes that can be dragged
WxSugar.define_keyword_ctors('SashWindow') do
  wx_ctor_params :pos, :size
  wx_ctor_params :style =>  Wx::CLIP_CHILDREN|Wx::SW_3D
  wx_ctor_params :name => 'sashWindow'
end

# wxSashLayoutWindow: Window that can be involved in an IDE-like layout
# arrangement
WxSugar.define_keyword_ctors('SashWindow') do
  wx_ctor_params :pos, :size
  wx_ctor_params :style =>  Wx::CLIP_CHILDREN|Wx::SW_3D
  wx_ctor_params :name => 'layoutWindow'
end

# wxVScrolledWindow: As wxScrolledWindow but supports lines of variable height

# wxWizardPage: A base class for the page in wizard dialog.
WxSugar.define_keyword_ctors('WizardPage') do
  wx_ctor_params :bitmap => Wx::NULL_BITMAP
end

# wxWizardPageSimple: A page in wizard dialog.
WxSugar.define_keyword_ctors('WizardPageSimple') do
  wx_ctor_params :prev,  :next, :bitmap => Wx::NULL_BITMAP
end

### DIALOGS
# wxDialog 	Base class for common dialogs
WxSugar.define_keyword_ctors('Dialog') do
  wx_ctor_params :title => ''
  wx_ctor_params :pos, :size, :style => Wx::DEFAULT_DIALOG_STYLE
  wx_ctor_params :name => 'dialogBox'
end

# wxColourDialog 	Colour chooser dialog
WxSugar.define_keyword_ctors('ColourDialog') do
  wx_ctor_params :colour_data => nil
end

# wxDirDialog 	Directory selector dialog
WxSugar.define_keyword_ctors('DirDialog') do
  wx_ctor_params :message => 'Choose a directory'
  wx_ctor_params :default_path => ''
  wx_ctor_params :style, :pos, :size, :name => 'wxDirCtrl'
end

# wxFileDialog 	File selector dialog
WxSugar.define_keyword_ctors('FileDialog') do
  wx_ctor_params :message => 'Choose a file'
  wx_ctor_params :default_dir  => ''
  wx_ctor_params :default_file => ''
  wx_ctor_params :wildcard => '*.*'
  wx_ctor_params :style, :pos
end

# wxFindReplaceDialog 	Text search/replace dialog
WxSugar.define_keyword_ctors('FindReplaceDialog') do
  wx_ctor_params :find_replace_data => Wx::FindReplaceData.new()
  wx_ctor_params :title => 'findReplaceDialog'
  wx_ctor_params :style
end

# wxMultiChoiceDialog 	Dialog to get one or more selections from a list
# wxSingleChoiceDialog 	Dialog to get a single selection from a list and return the string

# Dialog to get a single line of text from the user
WxSugar.define_keyword_ctors('TextEntryDialog') do
  wx_ctor_params :message => ''
  wx_ctor_params :caption => 'Please enter text'
  wx_ctor_params :default_value => ''
  wx_ctor_params :style => Wx::OK|Wx::CANCEL|Wx::CENTRE
  wx_ctor_params :pos
end

# wxPasswordEntryDialog 	Dialog to get a password from the user
# WxSugar.define_keyword_ctors('PasswordEntryDialog') do
#   wx_ctor_params :message => ''
#   wx_ctor_params :caption => 'Enter password'
#   wx_ctor_params :default_value => ''
#   wx_ctor_params :style => Wx::OK|Wx::CANCEL|Wx::CENTRE
#   wx_ctor_params :pos
# end

# wxFontDialog 	Font chooser dialog
# wxPageSetupDialog 	Standard page setup dialog
# wxPrintDialog 	Standard print dialog

# Simple message box dialog
WxSugar.define_keyword_ctors('MessageDialog') do
  wx_ctor_params :message => ''
  wx_ctor_params :caption => 'Message box'
  wx_ctor_params :style => Wx::OK|Wx::CANCEL
  wx_ctor_params :pos
end

### CONTROLS

# Push button control, displaying text
WxSugar.define_keyword_ctors('Button') do
  wx_ctor_params :label => ''
  wx_ctor_params :pos, :size, :style
#  wx_ctor_params :validator, :name => 'button'
end

# Push button control, displaying a bitmap
WxSugar.define_keyword_ctors('BitmapButton') do
  wx_ctor_params :bitmap, :pos, :size, :style => Wx::BU_AUTODRAW
end

# A button which stays pressed when clicked by user.
WxSugar.define_keyword_ctors('ToggleButton') do
  wx_ctor_params :label, :pos, :size, :style
  # wx_ctor_params :validator, :name => 'checkBox'
end

# Control showing an entire calendar month
WxSugar.define_keyword_ctors('CalendarCtrl') do
  wx_ctor_params :date => Time.now()
  wx_ctor_params :pos, :size, :style => Wx::CAL_SHOW_HOLIDAYS
  wx_ctor_params :name => 'calendar'
end

# 	Checkbox control
WxSugar.define_keyword_ctors('CheckBox') do
  wx_ctor_params :label => ''
  wx_ctor_params :pos, :size, :style
  # wx_ctor_params :validator, :name => 'checkBox'
end

# A listbox with a checkbox to the left of each item
WxSugar.define_keyword_ctors('CheckListBox') do 	
  wx_ctor_params :pos, :size, :choices, :style
  # wx_ctor_params :validator, :name => 'listBox'
end

# wxChoice 	Choice control (a combobox without the editable area)
WxSugar.define_keyword_ctors('Choice') do
  wx_ctor_params :pos, :size, :choices, :style
#  wx_ctor_params :validator, :name => 'choice'
end

# wxComboBox 	A choice with an editable area
WxSugar.define_keyword_ctors('ComboBox') do
  wx_ctor_params :value => ''
  wx_ctor_params :pos, :size, :choices => []
  wx_ctor_params :style
#  wx_ctor_params :validator, :name => 'comboBox'
end

# wxDatePickerCtrl 	Small date picker control

# wxGauge 	A control to represent a varying quantity, such as time
# remaining
WxSugar.define_keyword_ctors('Gauge') do
  wx_ctor_params :range, :pos, :size, :style => Wx::GA_HORIZONTAL
  # wx_ctor_params :validator, :name
end

# wxGenericDirCtrl 	A control for displaying a directory tree
# wxHtmlListBox 	A listbox showing HTML content
# wxListBox 	A list of strings for single or multiple selection
WxSugar.define_keyword_ctors('ListBox') do
  wx_ctor_params :pos, :size, :choices => []
  wx_ctor_params :style
end

# wxListCtrl 	A control for displaying lists of strings and/or icons, plus a multicolumn report view
WxSugar.define_keyword_ctors('ListCtrl') do
  wx_ctor_params :pos, :size, :style => Wx::LC_ICON
#  wx_ctor_params :validator, :name => 'listCtrlNameStr'
end

# wxListView 	A simpler interface (facade for wxListCtrl in report mode

# wxTreeCtrl 	Tree (hierarchy) control
WxSugar.define_keyword_ctors('TreeCtrl') do
  wx_ctor_params :pos, :size, :style => Wx::TR_HAS_BUTTONS
#  wx_ctor_params :validator, :name => 'treeCtrl'
end

# wxScrollBar 	Scrollbar control
# wxSpinButton 	A spin or 'up-down' control
WxSugar.define_keyword_ctors('SpinCtrl') do
  wx_ctor_params :pos, :size, :style => Wx::SP_HORIZONTAL
#  wx_ctor_params :validator, :name => 'treeCtrl'
end

# wxSpinCtrl 	A spin control - i.e. spin button and text control
WxSugar.define_keyword_ctors('SpinCtrl') do
  wx_ctor_params :pos, :size, :style => Wx::SP_ARROW_KEYS
  wx_ctor_params :min => 0
  wx_ctor_params :max => 100
  wx_ctor_params :initial => 0
#  wx_ctor_params :validator, :name => 'treeCtrl'
end

# One or more lines of non-editable text
WxSugar.define_keyword_ctors('StaticText') do
  wx_ctor_params :label, :pos, :size, :style, :name => 'staticText'
end

WxSugar.define_keyword_ctors('StaticBox') do
  wx_ctor_params :label, :pos, :size, :style, :name => 'staticBox'
end

WxSugar.define_keyword_ctors('StaticLine') do
  wx_ctor_params :pos, :size, :style => Wx::LI_HORIZONTAL
  wx_ctor_params :name => 'staticBox'
end

# wxStaticBitmap 	A control to display a bitmap
WxSugar.define_keyword_ctors('StaticBitmap') do
  wx_ctor_params :label, :pos, :size, :style
end


# wxRadioBox 	A group of radio buttons
WxSugar.define_keyword_ctors('RadioBox') do
  wx_ctor_params :label => ''
  wx_ctor_params :pos, :size, :choices => []
  wx_ctor_params :major_dimension => 0
  wx_ctor_params :style => Wx::RA_SPECIFY_COLS

#  wx_ctor_params :validator, :name => 'radioBox'
end


# wxRadioButton 	A round button to be used with others in a mutually exclusive way
WxSugar.define_keyword_ctors('RadioBox') do
  wx_ctor_params :label => ''
  wx_ctor_params :pos, :size, :style => 0
  #  wx_ctor_params :validator, :name => 'radioButton'
end

# wxSlider 	A slider that can be dragged by the user
WxSugar.define_keyword_ctors('Slider') do
  wx_ctor_params :min_value, :max_value
  wx_ctor_params :pos, :size, :style => Wx::SL_HORIZONTAL
  #  wx_ctor_params :validator, :name => 'radioButton'
end

# wxVListBox 	A listbox supporting variable height rows

# wxTextCtrl 	Single or multiline text editing control
WxSugar.define_keyword_ctors('TextCtrl') do
  wx_ctor_params :value => ''
  wx_ctor_params :pos, :size, :style
end

