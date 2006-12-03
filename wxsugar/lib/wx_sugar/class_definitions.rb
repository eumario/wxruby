# The WxExtensions defines a number of contants which are groups of available
# WxRuby classes. 
#  
#  ALL_CLASSES : As it sounds
#  FRAME_CLASSES : All available WxWidgets that are standalone frames
#  DIALOG_CLASSES : All available dialog classes
#  MISC_WINDOW_CLASSES : Things that are displayed, but aren't 'controls'
#  CONTROL_CLASSES : Controls that accept user input
#  SIZER_CLASSES : Sizers

module WxSugar
  # helper function to check what widgets are available
  ALL_CLASSES = Wx::constants.collect { | c | Wx::const_get(c) }.grep(Class)
  
  # named constant groups
  def self.define_class_group(const_name, *possibles)
    klasses = []
    possibles.each do | poss |
      begin
        klasses << Wx.const_get(poss)
      rescue NameError
        next
      end
    end
    const_set(const_name, klasses)
  end 
end

WxSugar.define_class_group('FRAME_CLASSES',
  'TopLevelWindow',
  'Dialog',
  'Frame',
  'MDIChildFrame',
  'MDIParentFrame',
  'MiniFrame',
  'SplashScreen',
  'PropertySheetDialog',
  'TipWindow',
  'Wizard' )

WxSugar.define_class_group('MISC_WINDOW_CLASSES', 
  'Panel',
  'ScrolledWindow',
  'Grid',
  'SplitterWindow',
  'StatusBar',
  'ToolBar',
  'Notebook',
  'Listbook',
  'Choicebook',
  'SashWindow',
  'SashLayoutWindow',
  'VScrolledWindow',
  'WizardPage',
  'WizardPageSimple',
  'HtmlWindow'
)

WxSugar.define_class_group('CONTROL_CLASSES',
  'Control',
  'Button',
  'BitmapButton',
  'ToggleButton',
  'CalendarCtrl',
  'CheckBox',
  'CheckListBox',
  'Choice',
  'ComboBox',
  'DatePickerCtrl',
  'Gauge',
  'GenericDirCtrl',
  'HtmlListBox',
  'StaticBox',
  'ListBox',
  'ListCtrl',
  'ListView',
  'TextCtrl',
  'TreeCtrl',
  'ScrollBar',
  'SpinButton',
  'SpinCtrl',
  'StaticText',
  'StaticBitmap',
  'RadioBox',
  'RadioButton',
  'Slider',
  'VListBox'
)

# TODO
WxSugar::define_class_group('DIALOG_CLASSES',
                                 'Dialog', # Base class for common dialogs
                                 'wxColourDialog', # Colour chooser dialog
                                 'DirDialog', # Directory selector dialog
                                 'FileDialog', #	File selector dialog
                                 'FindReplaceDialog', # Search/replace dialog
                                 'MultiChoiceDialog', # Dialog to get one or more selections from a list
                                 'SingleChoiceDialog',# 	Dialog to get a single selection from a list and return the string
                                 'TextEntryDialog', # 	Dialog to get a single line of text from the user
                                 'PasswordEntryDialog', # Get a password from the user
                                 'FontDialog', # Font chooser dialog
                                 'PageSetupDialog', # Standard page setup dialog
                                 'PrintDialog', # 	Standard print dialog
                                 'MessageDialog', # Simple message box dialog
                                 'Wizard' # A wizard dialog. 
)

WxSugar::define_class_group('SIZER_CLASSES',
  'Sizer', # Abstract base class
  'GridSizer', # A sizer for laying out windows in a grid with all fields having the same size
  'FlexGridSizer', # A sizer for laying out windows in a flexible grid
  'BoxSizer', # A sizer for laying out windows in a row or column
  'StaticBoxSizer', # Same as wxBoxSizer, but with a surrounding static box
  'NotebookSizer' # Sizer to use with the   'Notebook', # control
)
