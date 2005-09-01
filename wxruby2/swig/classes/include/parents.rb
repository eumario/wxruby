# parents.rb
#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

# this file was originally created based on an XML 
# file describing the wx api, but now it is manually 
# maintained. fix it if it is broken.

$parents = {
    'wxAcceleratorTable' => 'wxObject',
    'wxAccessible' => 'wxObject',
    'wxActivateEvent' => 'wxEvent',
    'wxApp' => 'wxEvtHandler',
    'wxArtProvider' => 'wxObject',
    'wxAutomationObject' => 'wxObject',
    'wxBitmap' => 'wxGDIObject',
    'wxBitmapButton' => 'wxButton',
    'wxBitmapDataObject' => 'wxDataObjectSimple',
    'wxBitmapHandler' => 'wxObject',
    'wxBoxSizer' => 'wxSizer',
    'wxBrush' => 'wxGDIObject',
    'wxBrushList' => 'wxList',
    'wxBufferedInputStream' => 'wxFilterInputStream',
    'wxBufferedOutputStream' => 'wxFilterOutputStream',
    'wxButton' => 'wxControl',
    'wxCSConv' => 'wxMBConv',
    'wxCalculateLayoutEvent' => 'wxEvent',
    'wxCalendarCtrl' => 'wxControl',
    'wxCalendarEvent' => 'wxEvent',
    'wxCheckBox' => 'wxControl',
    'wxCheckListBox' => 'wxListBox',
    'wxChoice' => 'wxControlWithItems',
    'wxChoicebook' => 'wxControl',
    'wxChoicebookEvent' => 'wxNotifyEvent',	
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
    'wxDC' => 'wxObject',
    'wxDataObjectComposite' => 'wxDataObject',
    'wxDataObjectSimple' => 'wxDataObject',
    'wxDialUpEvent' => 'wxEvent',
    'wxDialog' => 'wxWindow',
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
    'wxGDIObject' => 'wxObject',
    'wxGLCanvas' => 'wxWindow',
    'wxGauge' => 'wxControl',
    'wxGenericDirCtrl' => 'wxControl',
    'wxGenericValidator' => 'wxValidator',
    'wxGrid' => 'wxScrolledWindow',
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
    'wxHtmlColourCell' => 'wxHtmlCell',
    'wxHtmlContainerCell' => 'wxHtmlCell',
    'wxHtmlDCRenderer' => 'wxObject',
    'wxHtmlEasyPrinting' => 'wxObject',
    'wxHtmlFilter' => 'wxObject',
    'wxHtmlHelpData' => 'wxObject',
    'wxHtmlHelpFrame' => 'wxFrame',
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
    'wxIPV4address' => 'wxSockAddress',
    'wxIcon' => 'wxBitmap',
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
    'wxListbook' => 'wxControl',
    'wxListbookEvent' => 'wxNotifyEvent',	
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
    'wxMultipleChoiceDialog' => 'wxDialog',
    'wxNotebook' => 'wxControl',
    'wxNotebookEvent' => 'wxNotifyEvent',
    'wxNotebookSizer' => 'wxSizer',
    'wxNotifyEvent' => 'wxCommandEvent',
    'wxOutputStream' => 'wxStreamBase',
    'wxPageSetupDialog' => 'wxDialog',
    'wxPageSetupDialogData' => 'wxObject',
    'wxPaintDC' => 'wxWindowDC',
    'wxPaintEvent' => 'wxEvent',
    'wxPalette' => 'wxGDIObject',
    'wxPanel' => 'wxWindow',
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
    'wxProtocol' => 'wxSocketClient',
    'wxQuantize' => 'wxObject',
    'wxQueryCol' => 'wxObject',
    'wxQueryField' => 'wxObject',
    'wxQueryLayoutInfoEvent' => 'wxEvent',
    'wxRadioBox' => 'wxControl',
    'wxRadioButton' => 'wxControl',
    'wxRegion' => 'wxGDIObject',
    'wxRegionIterator' => 'wxObject',
    'wxSashEvent' => 'wxCommandEvent',
    'wxSashLayoutWindow' => 'wxSashWindow',
    'wxSashWindow' => 'wxWindow',
    'wxScreenDC' => 'wxDC',
    'wxScrollBar' => 'wxControl',
    'wxScrollEvent' => 'wxCommandEvent',
    'wxScrollWinEvent' => 'wxEvent',
    'wxScrolledWindow' => 'wxPanel',
    'wxSimpleHelpProvider' => 'wxHelpProvider',
    'wxSingleChoiceDialog' => 'wxDialog',
    'wxSizeEvent' => 'wxEvent',
    'wxSizer' => 'wxObject',
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
    'wxSysColourChangedEvent' => 'wxEvent',
    'wxSystemOptions' => 'wxObject',
    'wxSystemSettings' => 'wxObject',
    'wxTabCtrl' => 'wxControl',
    'wxTabEvent' => 'wxCommandEvent',
    'wxTaskBarIcon' => 'wxEvtHandler',
    'wxTextCtrl' => 'wxControl',
    'wxTextDataObject' => 'wxDataObjectSimple',
    'wxTextDropTarget' => 'wxDropTarget',
    'wxTextEntryDialog' => 'wxDialog',
    'wxTextValidator' => 'wxValidator',
    'wxTimer' => 'wxEvtHandler',
    'wxTipWindow' => 'wxWindow',
    'wxToggleButton' => 'wxControl',
    'wxToolBar' => 'wxControl',
    'wxToolTip' => 'wxObject',
	'wxTopLevelWindow' => 'wxWindow',
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
