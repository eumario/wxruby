# Copyright 2004-2009, wxRuby Development Team
# released under the MIT-style wxruby2 license

# This file describes the class -> superclass relationships among all
# wxRuby / wxWidgets classes. It's used by wxRuby's SWIG fixing script
# fixmodule.rb to implement correct inheritance between all the
# different classes defined in different SWIG modules. 
#
# The only time this file should normally need to be edited is when
# adding a previously unported class that is not yet listed. 

$parents = {
    'wxAcceleratorTable' => 'wxObject',
    'wxAccessible' => 'wxObject',
    'wxActivateEvent' => 'wxEvent',
    'wxAnimation' => 'wxGDIObject',
    'wxAnimationCtrl' => 'wxControl',
    'wxApp' => 'wxEvtHandler',
    'wxArtProvider' => 'wxObject',
    'wxAuiDefaultDockArt' => 'wxAuiDockArt',
    'wxAuiManager' => 'wxEvtHandler',
    'wxAuiManagerEvent' => 'wxEvent',
    'wxAuiNotebook' => 'wxControl',
    'wxAuiNotebookEvent' => 'wxNotifyEvent',
    'wxAutomationObject' => 'wxObject',
    'wxBitmap' => 'wxGDIObject',
    'wxBitmapButton' => 'wxButton',
    'wxBitmapComboBox' => 'wxComboBox',
    'wxBitmapDataObject' => 'wxDataObjectSimple',
    'wxBitmapHandler' => 'wxObject',
    'wxBookCtrlBase' => 'wxControl',
    'wxBookCtrlBaseEvent' => 'wxNotifyEvent',
    'wxBoxSizer' => 'wxSizer',
    'wxBrush' => 'wxGDIObject',
    'wxBrushList' => 'wxList',
    'wxBufferedInputStream' => 'wxFilterInputStream',
    'wxBufferedOutputStream' => 'wxFilterOutputStream',
    'wxButton' => 'wxControl',
    'wxCSConv' => 'wxMBConv',
    'wxCalculateLayoutEvent' => 'wxEvent',
    'wxCalendarCtrl' => 'wxControl',
    'wxCalendarEvent' => 'wxDateEvent',
    'wxCheckBox' => 'wxControl',
    'wxCheckListBox' => 'wxListBox',
    'wxChildFocusEvent' => 'wxCommandEvent',
    'wxChoice' => 'wxControlWithItems',
    'wxChoicebook' => 'wxBookCtrlBase',
    'wxChoicebookEvent' => 'wxBookCtrlBaseEvent',	
    'wxClient' => 'wxObject',
    'wxClientDC' => 'wxWindowDC',
    'wxClipboard' => 'wxObject',
    'wxCloseEvent' => 'wxEvent',
    'wxColour' => 'wxObject',
    'wxColourData' => 'wxObject',
    'wxColourDatabase' => 'wxList',
    'wxColourDialog' => 'wxDialog',
    'wxComboBox' => 'wxControlWithItems',
    'wxCommand' => 'wxObject',
    'wxCommandEvent' => 'wxEvent',
    'wxCommandProcessor' => 'wxObject',
    'wxConnection' => 'wxObject',
    'wxContextHelp' => 'wxObject',
    'wxContextHelpButton' => 'wxBitmapButton',
    'wxControl' => 'wxWindow',
    'wxControlWithItems' => 'wxControl',
    'wxCountingOutputStream' => 'wxOutputStream',
    'wxCursor' => 'wxBitmap',
    'wxCustomDataObject' => 'wxDataObjectSimple',
    'wxDateEvent' => 'wxCommandEvent',
    'wxDC' => 'wxObject',
    'wxDataObjectComposite' => 'wxDataObject',
    'wxDataObjectSimple' => 'wxDataObject',
    'wxDatePickerCtrl' => 'wxControl',
    'wxDialUpEvent' => 'wxEvent',
    'wxDialog' => 'wxTopLevelWindow',
    'wxDirDialog' => 'wxDialog',
    'wxDocChildFrame' => 'wxFrame',
    'wxDocMDIChildFrame' => 'wxMDIChildFrame',
    'wxDocMDIParentFrame' => 'wxMDIParentFrame',
    'wxDocManager' => 'wxEvtHandler',
    'wxDocParentFrame' => 'wxFrame',
    'wxDocTemplate' => 'wxObject',
    'wxDocument' => 'wxEvtHandler',
    'wxDragImage' => 'wxObject',
    'wxDropFilesEvent' => 'wxEvent',
    'wxEncodingConverter' => 'wxObject',
    'wxEraseEvent' => 'wxEvent',
    'wxEvent' => 'wxObject',
    'wxEvtHandler' => 'wxObject',
    'wxExprDatabase' => 'wxList',
    'wxFFileInputStream' => 'wxInputStream',
    'wxFFileOutputStream' => 'wxOutputStream',
    'wxFFileStream' => 'wxFFileOutputStream',
    'wxFSFile' => 'wxObject',
    'wxFTP' => 'wxProtocol',
    'wxFileDataObject' => 'wxDataObjectSimple',
    'wxFileDialog' => 'wxDialog',
    'wxFileDropTarget' => 'wxDropTarget',
    'wxFileHistory' => 'wxObject',
    'wxFileInputStream' => 'wxInputStream',
    'wxFileOutputStream' => 'wxOutputStream',
    'wxFileStream' => 'wxFileOutputStream',
    'wxFileSystem' => 'wxObject',
    'wxFileSystemHandler' => 'wxObject',
    'wxFilterInputStream' => 'wxInputStream',
    'wxFilterOutputStream' => 'wxOutputStream',
    'wxFindDialogEvent' => 'wxCommandEvent',
    'wxFindReplaceData' => 'wxObject',
    'wxFindReplaceDialog' => 'wxDialog',
    'wxFlexGridSizer' => 'wxGridSizer',
    'wxFocusEvent' => 'wxEvent',
    'wxFont' => 'wxGDIObject',
    'wxFontData' => 'wxObject',
    'wxFontDialog' => 'wxDialog',
    'wxFontList' => 'wxList',
    'wxFrame' => 'wxTopLevelWindow',
    'wxGBSizerItem' => 'wxSizerItem',
    'wxGCDC' => 'wxDC',
    'wxGDIObject' => 'wxObject',
    'wxGLCanvas' => 'wxWindow',
    'wxGLContext' => 'wxObject',
    'wxGauge' => 'wxControl',
    'wxGenericDirCtrl' => 'wxControl',
    'wxGenericValidator' => 'wxValidator',
    'wxGraphicsBrush' => 'wxGraphicsObject',
    'wxGraphicsContext' => 'wxGraphicsObject',
    'wxGraphicsFont' => 'wxGraphicsObject',
    'wxGraphicsMatrix' => 'wxGraphicsObject',
    'wxGraphicsObject' => 'wxObject',
    'wxGraphicsPath' => 'wxGraphicsObject',
    'wxGraphicsPen' => 'wxGraphicsObject',
    'wxGrid' => 'wxScrolledWindow',
    'wxGridBagSizer' => 'wxFlexGridSizer',
    'wxGridCellBoolEditor' => 'wxGridCellEditor',
    'wxGridCellBoolRenderer' => 'wxGridCellRenderer',
    'wxGridCellChoiceEditor' => 'wxGridCellEditor',
    'wxGridCellFloatEditor' => 'wxGridCellTextEditor',
    'wxGridCellFloatRenderer' => 'wxGridCellStringRenderer',
    'wxGridCellNumberEditor' => 'wxGridCellTextEditor',
    'wxGridCellNumberRenderer' => 'wxGridCellStringRenderer',
    'wxGridCellStringRenderer' => 'wxGridCellRenderer',
    'wxGridCellTextEditor' => 'wxGridCellEditor',
    'wxGridEditorCreatedEvent' => 'wxCommandEvent',
    'wxGridEvent' => 'wxNotifyEvent',
    'wxGridRangeSelectEvent' => 'wxNotifyEvent',
    'wxGridSizeEvent' => 'wxNotifyEvent',
    'wxGridSizer' => 'wxSizer',
    'wxGridTableBase' => 'wxObject',
    'wxHTTP' => 'wxProtocol',
    'wxHashTable' => 'wxObject',
    'wxHelpController' => 'wxObject',
    'wxHelpControllerHelpProvider' => 'wxSimpleHelpProvider',
    'wxHelpEvent' => 'wxCommandEvent',
    'wxHtmlCell' => 'wxObject',
    'wxHtmlCellEvent' => 'wxCommandEvent',
    'wxHtmlColourCell' => 'wxHtmlCell',
    'wxHtmlContainerCell' => 'wxHtmlCell',
    'wxHtmlDCRenderer' => 'wxObject',
    'wxHtmlEasyPrinting' => 'wxObject',
    'wxHtmlFilter' => 'wxObject',
    'wxHtmlHelpData' => 'wxObject',
    'wxHtmlHelpFrame' => 'wxFrame',
    'wxHtmlLinkEvent' => 'wxCommandEvent',
    'wxHtmlLinkInfo' => 'wxObject',
    'wxHtmlListBox' => 'wxVListBox',
    'wxHtmlParser' => 'wxObject',
    'wxHtmlPrintout' => 'wxPrintout',
    'wxHtmlTag' => 'wxObject',
    'wxHtmlTagHandler' => 'wxObject',
    'wxHtmlTagsModule' => 'wxModule',
    'wxHtmlWidgetCell' => 'wxHtmlCell',
    'wxHtmlWinParser' => 'wxHtmlParser',
    'wxHtmlWinTagHandler' => 'wxHtmlTagHandler',
    'wxHtmlWindow' => 'wxScrolledWindow',
    'wxHyperlinkCtrl' => 'wxControl',
    'wxHyperlinkEvent' => 'wxCommandEvent',
    'wxIPV4address' => 'wxSockAddress',
    'wxIconizeEvent' => 'wxEvent',
    'wxIdleEvent' => 'wxEvent',
    'wxImage' => 'wxObject',
    'wxImageHandler' => 'wxObject',
    'wxImageList' => 'wxObject',
    'wxIndividualLayoutConstraint' => 'wxObject',
    'wxInitDialogEvent' => 'wxEvent',
    'wxInputStream' => 'wxStreamBase',
    'wxJoystick' => 'wxObject',
    'wxJoystickEvent' => 'wxEvent',
    'wxKeyEvent' => 'wxEvent',
    'wxLayoutAlgorithm' => 'wxObject',
    'wxLayoutConstraints' => 'wxObject',
    'wxList' => 'wxObject',
    'wxListbook' => 'wxBookCtrlBase',
    'wxListbookEvent' => 'wxBookCtrlBaseEvent',	
    'wxListBox' => 'wxControlWithItems',
    'wxListCtrl' => 'wxControl',
    'wxListEvent' => 'wxNotifyEvent',
    'wxListItem' => 'wxObject',
    'wxListView' => 'wxListCtrl',
    'wxLogChain' => 'wxLog',
    'wxLogGui' => 'wxLog',
    'wxLogNull' => 'wxLog',
    'wxLogPassThrough' => 'wxLogChain',
    'wxLogStderr' => 'wxLog',
    'wxLogStream' => 'wxLog',
    'wxLogTextCtrl' => 'wxLog',
    'wxLogWindow' => 'wxLogPassThrough',
    'wxMBConvFile' => 'wxMBConv',
    'wxMBConvUTF7' => 'wxMBConv',
    'wxMBConvUTF8' => 'wxMBConv',
    'wxMDIChildFrame' => 'wxFrame',
    'wxMDIClientWindow' => 'wxWindow',
    'wxMDIParentFrame' => 'wxFrame',
    'wxMask' => 'wxObject',
    'wxMaximizeEvent' => 'wxEvent',
    'wxMediaEvent' => 'wxNotifyEvent',
    'wxMediaCtrl' => 'wxControl',
    'wxMemoryDC' => 'wxDC',
    'wxMemoryFSHandler' => 'wxFileSystemHandler',
    'wxMemoryInputStream' => 'wxInputStream',
    'wxMemoryOutputStream' => 'wxOutputStream',
    'wxMenu' => 'wxEvtHandler',
    'wxMenuBar' => 'wxWindow',
    'wxMenuEvent' => 'wxEvent',
    'wxMenuItem' => 'wxObject',
    'wxMessageDialog' => 'wxDialog',
    'wxMetafile' => 'wxObject',
    'wxMetafileDC' => 'wxDC',
    'wxMiniFrame' => 'wxFrame',
    'wxModule' => 'wxObject',
    'wxMouseCaptureChangedEvent' => 'wxEvent',
    'wxMouseEvent' => 'wxEvent',
    'wxMoveEvent' => 'wxEvent',
    'wxMultiChoiceDialog' => 'wxDialog',
    'wxNavigationKeyEvent' => 'wxEvent',
    'wxNotebook' => 'wxBookCtrlBase',
    'wxNotebookEvent' => 'wxBookCtrlBaseEvent',
    'wxNotebookSizer' => 'wxSizer',
    'wxNotifyEvent' => 'wxCommandEvent',
    'wxOutputStream' => 'wxStreamBase',
    'wxPageSetupDialog' => 'wxDialog',
    'wxPageSetupDialogData' => 'wxObject',
    'wxPaintDC' => 'wxWindowDC',
    'wxPaintEvent' => 'wxEvent',
    'wxPalette' => 'wxGDIObject',
    'wxPanel' => 'wxWindow',
    'wxPasswordEntryDialog' => 'wxTextEntryDialog',
    'wxPathList' => 'wxList',
    'wxPen' => 'wxGDIObject',
    'wxPlotCurve' => 'wxObject',
    'wxPlotWindow' => 'wxScrolledWindow',
    'wxPostScriptDC' => 'wxDC',
    'wxPreviewCanvas' => 'wxScrolledWindow',
    'wxPreviewControlBar' => 'wxPanel',
    'wxPreviewFrame' => 'wxFrame',
    'wxPrintData' => 'wxObject',
    'wxPrintDialog' => 'wxDialog',
    'wxPrintDialogData' => 'wxObject',
    'wxPrintPreview' => 'wxObject',
    'wxPrinter' => 'wxObject',
    'wxPrinterDC' => 'wxDC',
    'wxPrintout' => 'wxObject',
    'wxPrivateDropTarget' => 'wxDropTarget',
    'wxProcess' => 'wxEvtHandler',
    'wxProcessEvent' => 'wxEvent',
    'wxProgressDialog' => 'wxDialog',
    'wxPropertySheetDialog' => 'wxDialog',
    'wxProtocol' => 'wxSocketClient',
    'wxQuantize' => 'wxObject',
    'wxQueryLayoutInfoEvent' => 'wxEvent',
    'wxRadioBox' => 'wxControl',
    'wxRadioButton' => 'wxControl',
    'wxRegion' => 'wxGDIObject',
    'wxRegionIterator' => 'wxObject',
    'wxRichTextCharacterStyleDefinition' => 'wxRichTextStyleDefinition',
    'wxRichTextCtrl' => 'wxTextCtrl',
    'wxRichTextEvent' => 'wxNotifyEvent',
    'wxRichTextFileHandler' => 'wxObject',
    'wxRichTextFormattingDialog' => 'wxPropertySheetDialog',
    'wxRichTextHeaderFooterData' => 'wxObject',
    'wxRichTextHTMLHandler' => 'wxRichTextFileHandler',
    'wxRichTextListStyleDefinition' => 'wxRichTextParagraphStyleDefinition',
    'wxRichTextParagraphStyleDefinition' => 'wxRichTextStyleDefinition',
    'wxRichTextPrinting' => 'wxPrintout',
    'wxRichTextPrintout' => 'wxPrintout',
    'wxRichTextStyleDefinition' => 'wxObject',
    'wxRichTextStyleListBox' => 'wxHtmlListBox',
    'wxRichTextStyleListCtrl' => 'wxControl',
    'wxRichTextStyleSheet' => 'wxObject',
    'wxRichTextXMLHandler' => 'wxRichTextFileHandler',
    'wxSashEvent' => 'wxCommandEvent',
    'wxSashLayoutWindow' => 'wxSashWindow',
    'wxSashWindow' => 'wxWindow',
    'wxScreenDC' => 'wxDC',
    'wxScrollBar' => 'wxControl',
    'wxScrollEvent' => 'wxCommandEvent',
    'wxScrollWinEvent' => 'wxEvent',
    'wxScrolledWindow' => 'wxPanel',
    'wxSearchCtrl' => 'wxTextCtrl',
    'wxShowEvent' => 'wxEvent',
    'wxSimpleHelpProvider' => 'wxHelpProvider',
    'wxSingleChoiceDialog' => 'wxDialog',
    'wxSizeEvent' => 'wxEvent',
    'wxSizer' => 'wxObject',
    'wxSizerItem' => 'wxObject',
    'wxSlider' => 'wxControl',
    'wxSockAddress' => 'wxObject',
    'wxSocketBase' => 'wxObject',
    'wxSocketClient' => 'wxSocketBase',
    'wxSocketEvent' => 'wxEvent',
    'wxSocketInputStream' => 'wxInputStream',
    'wxSocketOutputStream' => 'wxOutputStream',
    'wxSocketServer' => 'wxSocketBase',
    'wxSpinButton' => 'wxControl',
    'wxSpinCtrl' => 'wxControl',
    'wxSpinEvent' => 'wxNotifyEvent',
    'wxSplashScreen' => 'wxFrame',
    'wxSplitterEvent' => 'wxNotifyEvent',
    'wxSplitterWindow' => 'wxWindow',
    'wxStaticBitmap' => 'wxControl',
    'wxStaticBox' => 'wxControl',
    'wxStaticBoxSizer' => 'wxBoxSizer',
    'wxStaticLine' => 'wxControl',
    'wxStaticText' => 'wxControl',
    'wxStatusBar' => 'wxWindow',
    'wxStringClientData' => 'wxClientData',
    'wxStringList' => 'wxList',
    'wxStringTokenizer' => 'wxObject',
    'wxStyledTextCtrl' => 'wxTextCtrl',
    'wxStyledTextEvent' => 'wxCommandEvent',
    'wxSysColourChangedEvent' => 'wxEvent',
    'wxSymbolPickerDialog' => 'wxDialog',
    'wxSystemOptions' => 'wxObject',
    'wxSystemSettings' => 'wxObject',
    'wxTabCtrl' => 'wxControl',
    'wxTabEvent' => 'wxCommandEvent',
    'wxTaskBarIcon' => 'wxEvtHandler',
    'wxTextCtrl' => 'wxControl',
    'wxTextDataObject' => 'wxDataObjectSimple',
    'wxTextDropTarget' => 'wxDropTarget',
    'wxTextEntryDialog' => 'wxDialog',
    'wxTextUrlEvent' => 'wxCommandEvent',
    'wxTextValidator' => 'wxValidator',
    'wxTimer' => 'wxEvtHandler',
    'wxTipWindow' => 'wxWindow',
    'wxToggleButton' => 'wxControl',
    'wxToolBar' => 'wxControl',
    'wxToolbook' => 'wxBookCtrlBase',
    'wxToolbookEvent' => 'wxBookCtrlBaseEvent',
    'wxToolTip' => 'wxObject',
	'wxTopLevelWindow' => 'wxWindow',
    'wxTreebook' => 'wxBookCtrlBase',
    'wxTreebookEvent' => 'wxBookCtrlBaseEvent',
    'wxTreeCtrl' => 'wxControl',
    'wxTreeEvent' => 'wxNotifyEvent',
    'wxTreeItemData' => 'wxClientData',
    'wxURL' => 'wxObject',
    'wxUpdateUIEvent' => 'wxCommandEvent',
    'wxVListBox' => 'wxVScrolledWindow',
    'wxVScrolledWindow' => 'wxPanel',
    'wxValidator' => 'wxEvtHandler',
    'wxVariant' => 'wxObject',
    'wxVariantData' => 'wxObject',
    'wxView' => 'wxEvtHandler',
    'wxWave' => 'wxObject',
    'wxWindow' => 'wxEvtHandler',
    'wxWindowDC' => 'wxDC',
    'wxWizard' => 'wxDialog',
    'wxWizardEvent' => 'wxNotifyEvent',
    'wxWizardPage' => 'wxPanel',
    'wxWizardPageSimple' => 'wxWizardPage',
    'wxXmlResource' => 'wxObject',
    'wxXmlResourceHandler' => 'wxObject',
    'wxZipInputStream' => 'wxInputStream',
    'wxZlibInputStream' => 'wxFilterInputStream',
    'wxZlibOutputStream' => 'wxFilterOutputStream',
}

if RUBY_PLATFORM =~ /linux/
  $parents['wxIcon'] = 'wxBitmap'
else
  $parents['wxIcon'] = 'wxGDIObject'
end
