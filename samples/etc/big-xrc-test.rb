#!/usr/bin/env ruby

#
# Test script for XRC widget access.
#

require "wxruby"

# Hash of object classes and names.
# Toggle button is commented out because it causes a
# segfault in Wx::Window.find_window_by_name()
xrc_windows = [
    ["Panel", "content_panel"],
    ["Notebook", "test_notebook"],
    ["StaticText", "text_static"],
    ["StaticBitmap", "static_bitmap"],
    ["StaticLine", "line_h_static"],
    ["StaticLine", "line_v_static"],
    ["Button", "test_button"],
    ["BitmapButton", "test_bitmap_button"],
#   ["ToggleButton", "test_toggle_button"],
    ["SpinButton", "test_spin_button"],
    ["RadioButton", "test_radio_button"],
    ["CheckBox", "test_checkbox"],
    ["RadioBox", "test_radiobox"],
    ["ComboBox", "test_combobox"],
    ["Choice", "test_choice"],
    ["TextCtrl", "test_text"],
    ["SpinCtrl", "test_spin"],
    ["ListBox", "test_listbox"],
    ["ListCtrl", "test_list"],
    ["CalendarCtrl", "test_calendar"],
    ["Gauge", "test_gauge"],
    ["Slider", "test_slider"],
    ["ScrollBar", "test_scrollbar"],
    ["CheckList", "test_checklist"],
    ["TreeCtrl", "test_tree"],
    ["GenericDirCtrl", "test_dir"]
]

# Not sure how to look these up in the XRC file.
xrc_sizers = [
    ["StaticBoxSizer", "text_static_box"],
    ["StaticBoxSizer", "lines_static_box"]
]

# Load the frame.
Wx::App.new()
xml = Wx::XmlResource.get()
xml.init_all_handlers()
xml.load("big-xrc-test.xrc")
frame = xml.load_frame(nil, "xrc_test_frame")

# Look for all window-derived objects in the frame.
xrc_windows.each do |xrc_obj|
    obj = Wx::Window.find_window_by_name(xrc_obj[1], frame)
    message = obj.nil? ? "FAILED" : "OK"
    puts "%s - %s: %s" % [message.center(6), xrc_obj[0], xrc_obj[1]]
end
