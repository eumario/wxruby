xml_file = ARGV[0]
input_dir = File.dirname(xml_file)
output_dir = File.join(input_dir, "classes/include")

require 'rexml/document'

$pure_virtuals =
{
    'wxArtProvider' =>
    [
    'CreateBitmap',
    ],
    'wxControlWithItems' =>
    [
    'Append', 'Clear', 'Delete', 'FindString', 
    'GetCount', 'GetItemClientData', 'GetItemClientObject', 
    'GetSelection', 'GetString', 
    'Select', 'setItemClientData', 'SetItemClientObject', 'SetString',
    ],
    'wxDC' =>
    [
    'Clear', 'SetFont', 'SetPen', 'SetBrush', 'SetBackground',
    'SetBackgroundMode', 'SetPalette', 'GetCharHeight', 'GetCharWidth',
    'CanDrawBitmap', 'CanGetTextExtent', 'GetDepth', 
    'SetLogicalFunction', 'DoFloodFill', 'GetPixel', 'DrawPoint',
    'DrawLine', 'DrawArc', 'DrawEllipticArc', 'DrawRectangle',
    'DrawRoundedRectangle', 'DrawEllipse', 'CrossHair', 
    'DrawIcon', 'DrawBitmap', 'DrawText', 'DrawRotatedText',
    'Blit', 'GetSize', 'DrawLines', 'DrawPolygon',
    'SetClippingRegionAsRegion', 'GetTextExtent', 
    ],
    'wxEvent' =>
    [
    'Clone',
    ],
    'wxSizer' =>
    [
    'CalcMin', 'RecalcSizes', 
    ],
}

def is_pure_virtual(class_name, method_name)
    pures = $pure_virtuals[class_name]
    if(!pures)
        return false
    end
    #puts("Checking pure: #{method_name}")
    return pures.index(method_name)
end

$fixes = 
{
    'wxApp' =>
    {
    'virtual void OnAssert(const wxChar  *file , int  line , const wxChar  *cond , const wxChar  *msg )' =>
    '',
    },
    'wxArtProvider' =>
    {
    'wxBitmap CreateBitmap(const wxArtID&  id , const wxArtClient&  client , const wxSize&  size )' =>
    'virtual wxBitmap CreateBitmap(const wxArtID&  id , const wxArtClient&  client , const wxSize&  size )',
    },
    'wxBitmap' =>
    {
    'wxBitmap(void*  data , int  type , int  width , int  height , int depth = -1)' =>
    '',
    'wxBitmap(const wxString&  name , long  type )' =>
    'wxBitmap(wxString&  name , wxBitmapType  type=wxBITMAP_TYPE_XPM )',
    'wxBitmap(const char  bits[] , int  width , int  height , int depth = 1)' =>
    '//wxBitmap(const char  bits[] , int  width , int  height , int depth = 1)',
    'virtual bool Create(void*  data , int  type , int  width , int  height , int depth = -1)' =>
    '',
    'bool LoadFile(const wxString&  name , long  type )' =>
    'bool LoadFile(const wxString&  name , wxBitmapType  type )',
    'bool SaveFile(const wxString&  name , int  type , wxPalette*  palette = NULL)' =>
    'bool SaveFile(const wxString&  name , wxBitmapType  type , wxPalette*  palette = NULL)',
    },
    'wxBitmapButton' =>
    {
    'bool Create(wxWindow*  parent , wxWindowID  id , const wxBitmap&  bitmap , const wxPoint&  pos , const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  validator , const wxString&  name = "button")' =>
    'bool Create(wxWindow*  parent , wxWindowID  id , const wxBitmap&  bitmap , const wxPoint&  pos , const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "button")',
    'wxBitmap& GetBitmapDisabled() const' =>
    'const wxBitmap& GetBitmapDisabled() const',
    'wxBitmap& GetBitmapFocus() const' =>
    'const wxBitmap& GetBitmapFocus() const',
    'wxBitmap& GetBitmapLabel() const' =>
    'const wxBitmap& GetBitmapLabel() const',
    'wxBitmap& GetBitmapSelected() const' =>
    'const wxBitmap& GetBitmapSelected() const',
    },
    'wxBusyInfo'=>
    {
    'wxBusyInfo(const wxString&  msg , wxParent  *parent = NULL)'=>
    'wxBusyInfo(const wxString&  msg , wxWindow *parent = NULL)',
    },
    'wxButton' =>
    {
    'wxButton(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos , const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  validator , const wxString&  name = "button")' =>
    'wxButton(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "button")',
    'bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos , const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  validator , const wxString&  name = "button")' =>
    'bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos , const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "button")',
    },
    'wxCaret'=>
    {
    'wxCaret(wxWindowBase*  window , const wxSize&  size )'=>	    
    'wxCaret(wxWindow*  window , const wxSize&  size )',	    
    },
    'wxCheckBox' =>
    {
    'wxCheckBox(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  val , const wxString&  name = "checkBox")' =>
    'wxCheckBox(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  val = wxDefaultValidator, const wxString&  name = "checkBox")',
    'bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  val , const wxString&  name = "checkBox")' =>
    'bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  val = wxDefaultValidator, const wxString&  name = "checkBox")',
    },
    'wxCheckListBox'=>
    {
    'wxCheckListBox(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, int  n , const wxString  choices[] = NULL, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "listBox")'=>
    'wxCheckListBox(wxWindow*  parent , wxWindowID  id , const wxPoint& pos , const wxSize& size, int  n =0 , const wxString  choices[] = NULL, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "listBox")'
    },
    'wxChoice' =>
    {
    'bool Create(wxWindow * parent , wxWindowID  id , const wxPoint&  pos , const wxSize&  size , int  n , const wxString  choices[] , long style = 0, const wxString&  name = "choice")' =>
    'bool Create(wxWindow * parent , wxWindowID  id , const wxPoint&  pos , const wxSize&  size , int  n , const wxString  choices[] , long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "choice")',
    },
    'wxCloseEvent' =>
    {
    'void SetLoggingOff(bool  loggingOff ) const' =>
    'void SetLoggingOff(bool  loggingOff )',
    },
    'wxColourData'=>
    {
    'wxColour& GetColour() const'=>
    'wxColour GetColour() const',
    'wxColour& GetCustomColour(int  i ) const'=>
    'wxColour GetCustomColour(int  i )',
    },
    'wxComboBox'=>
    {
    'wxComboBox(wxWindow*  parent , wxWindowID  id , const wxString&  value = "", const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, int  n , const wxString  choices[] , long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "comboBox")'=>
    'wxComboBox(wxWindow*  parent , wxWindowID  id , const wxString&  value, const wxPoint& pos , const wxSize& size , int  n , const wxString  choices[] , long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "comboBox")',
    'bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  value = "", const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, int  n , const wxString  choices[] , long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "comboBox")'=>
    'bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  value, const wxPoint& pos , const wxSize& size , int  n , const wxString  choices[] , long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "comboBox")',
    },
    'wxConfigBase' =>
    {
    'wxConfigBase(const wxString&  appName = wxEmptyString, const wxString&  vendorName = wxEmptyString, const wxString&  localFilename = wxEmptyString, const wxString&  globalFilename = wxEmptyString, long style = 0, wxMBConv& conv = wxConvUTF8)'=>
     'wxConfigBase(const wxString&  appName = wxEmptyString, const wxString&  vendorName = wxEmptyString)',
    'uint  GetNumberOfEntries(bool  bRecursive = false) const'=>
    'int  GetNumberOfEntries(bool  bRecursive = false) const',
    'uint GetNumberOfGroups(bool  bRecursive = false) const'=>
    'int GetNumberOfGroups(bool  bRecursive = false) const',
    'const wxString& GetPath() const'=>
    'wxString GetPath() const',
    },
    'wxControl' =>
    {
    'wxString& GetLabel()' =>
    'wxString GetLabel()',
    },
    'wxDC' =>
    {
    'void DrawArc(wxCoord  x1 , wxCoord  y1 , wxCoord  x2 , wxCoord  y2 , double  xc , double  yc )' =>
    'void DrawArc(wxCoord  x1 , wxCoord  y1 , wxCoord  x2 , wxCoord  y2 , wxCoord  xc , wxCoord  yc )',
    },
    # Working around a SWIG issue...
    'wxCursor'=>
    {
    'wxCursor(const char  bits[] , int  width , int   height , int  hotSpotX = -1, int  hotSpotY = -1, const char  maskBits[] = NULL)'=>
    '//wxCursor(const char  bits[] , int  width , int   height , int  hotSpotX = -1, int  hotSpotY = -1, const char  maskBits[] = NULL)',
    },
    'wxDialog' =>
    {
    'virtual void OnCharHook(wxKeyEvent&  event )' =>
    '//virtual void OnCharHook(wxKeyEvent&  event )',
    },
    'wxFindReplaceData'=>
    {
    'const wxString& GetFindString()'=>
    'wxString GetFindString()',
    'const wxString& GetReplaceString()'=>
    'wxString GetReplaceString()',
    },
    'wxFindDialogEvent'=>
    {
    'const wxString& GetReplaceString() const'=>
    'wxString GetReplaceString() const',
    },
    'wxFlexGridSizer'=>
    {
    'void AddGrowableCol(size_t  idx , int  proportion = 0)'=>
    'void AddGrowableCol(size_t  idx)',
    'void AddGrowableRow(size_t  idx , int  proportion = 0)'=>
    'void AddGrowableRow(size_t  idx)',
     },
	'wxGrid'=>
	{
    'wxSize DoGetBestSize() const'=>"",
    'void InitRowHeights()'=>"",
    'void InitColWidths()'=>"",
    'int GetColWidth(int  col ) const'=>"",
    'int GetColLeft(int  col ) const'=>"",
    'int GetColRight(int  col ) const'=>"",
    'int GetRowHeight(int  row ) const'=>"",
    'int GetRowTop(int  row ) const'=>"",
    'int GetRowBottom(int  row ) const'=>"",
    'int SetOrCalcColumnSizes(bool  calcOnly , bool  setAsMin = true)'=>"",
    'int SetOrCalcRowSizes(bool  calcOnly , bool  setAsMin = true)'=>"",
    'void AutoSizeColOrRow(int  n , bool  setAsMin , bool  column )'=>"",
    'int GetColMinimalWidth(int  col ) const'=>"",
    'int GetRowMinimalHeight(int  col ) const'=>"",
    'bool CanHaveAttributes()'=>"",
    'wxGridCellAttr* GetOrCreateCellAttr(int  row , int  col ) const'=>"",
	},
    'wxIcon' =>
    {
    'wxIcon()' =>
    '',
    'wxIcon(const wxIcon&  icon )' =>
    '',
    'wxIcon(void*  data , int  type , int  width , int  height , int depth = -1)' =>
    '',
    'wxIcon(const char  bits[] , int  width , int  height , int depth = 1)' =>
    '',
    'wxIcon(int  width , int  height , int depth = -1)' =>
    '',
    'wxIcon(char**  bits )' =>
    '',
    'wxIcon(const char**  bits )' =>
    '',
    'wxIcon(const wxIconLocation&  loc )' =>
    '',
    'wxIcon(const wxString&  name , long  type , int desiredWidth = -1, int desiredHeight = -1)'=>
    'wxIcon(const wxString&  name , long  type = wxBITMAP_TYPE_ANY, int desiredWidth = -1, int desiredHeight = -1)',
    'bool LoadFile(const wxString&  name , long  type )' =>
    'bool LoadFile(const wxString&  name , wxBitmapType  type )',
    'bool SaveFile(const wxString&  name , int  type , wxPalette*  palette = NULL)' =>
    'bool SaveFile(const wxString&  name , wxBitmapType  type , wxPalette*  palette = NULL)',
    },
    'wxImage'=>
    {
    'bool Destroy()'=>
    'void Destroy()',
    # SWIG 1.3.22 Workaround
    'wxImage(int  width , int  height , bool clear = true)'=>
    'wxImage(int  width , int  height)',
    'bool Create(int  width , int  height , bool clear = true)'=>
    'void Create(int  width , int  height )',
    },
    'wxListBox'=>
    {
    'wxListBox(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, int  n , const wxString  choices[] = NULL, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "listBox")'=>
    'wxListBox(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, int  n = 0 , const wxString  choices[] = NULL, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "listBox")',
    'bool Create(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, int  n , const wxString  choices[] = NULL, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "listBox")'=>
    'bool Create(wxWindow*  parent , wxWindowID  id , const wxPoint& pos , const wxSize& size , int  n , const wxString  choices[] = NULL, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "listBox")',
	'void InsertItems(int  nItems , const wxString  *items , int  pos )'=>
	'void InsertItems(int  n, const wxString  choices []= NULL, int  pos = 0)',
    },
    #
    # NSK - the following are protected, but since we don't have a 
    # mechanism to mark that yet, I'll just wipe them out for now
    #
    'wxListCtrl'=>
    {
    'virtual wxListItemAttr * OnGetItemAttr(long  item )'=>
    '//virtual wxListItemAttr * OnGetItemAttr(long  item )',
    'virtual int OnGetItemImage(long  item )'=> 
    '//virtual int OnGetItemImage(long  item )', 
    'virtual wxString OnGetItemText(long  item , long  column )'=>
    '//virtual wxString OnGetItemText(long  item , long  column )',
    },
    'wxLog'=>
    {
    'virtual static void OnLog(wxLogLevel   level , const char *   message )'=> 
    'static void OnLog(wxLogLevel   level , const char *   message )',
    'virtual void DoLog(wxLogLevel  level , const wxChar  *msg , time_t  timestamp )'=>
    '//virtual void DoLog(wxLogLevel  level , const wxChar  *msg , time_t  timestamp )',
    'virtual void DoLogString(const wxChar  *msg , time_t  timestamp )'=>
    '//virtual void DoLogString(const wxChar  *msg , time_t  timestamp )',
    },
    'wxMask'=>
    {
    'wxMask(const \helpref{wxBitmap wxbitmap )'=>
    'wxMask(const wxBitmap & wxbitmap )',
    'wxMask(const \helpref{wxBitmap wxbitmap , const \helpref{wxColour wxcolour )'=>
    'wxMask(const wxBitmap & wxbitmap , const wxColour &wxcolour )',
    },
    'wxMDIChildFrame'=>
    {
    'bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  title , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString&  name = "frame")'=>
    'bool Create(wxMDIParentFrame*  parent , wxWindowID  id , const wxString&  title , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString&  name = "frame")',
    },
    'wxMDIParentFrame'=>
    {
    'virtual wxWindow* GetToolBar() const'=>
    'virtual wxToolBar* GetToolBar() const',
    'virtual void SetToolBar(wxWindow*  toolbar )'=>
    'virtual void SetToolBar(wxToolBar*  toolbar )',
    },
    'wxMemoryDC'=>
    {
    'SelectObject(const wxBitmap&  bitmap )'=>
    'void SelectObject(const wxBitmap&  bitmap )',
    },
    'wxMenu' =>
    {
    'bool Prepend(wxMenuItem * item )' =>
    'void Prepend(wxMenuItem * item )',
    'void PrependSeparator(size_t  pos )' =>
    'void PrependSeparator()',
    'void UpdateUI(wxEvtHandler* source = NULL) const' =>
    'void UpdateUI(wxEvtHandler* source = NULL)',
    },
    'wxNotebook'=>
    {
    'wxNotebook(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxString&  name = "notebook")'=>
    'wxNotebook(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxString&  name = "notebook")',
    'bool Create(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize&  size , long style = 0, const wxString&  name = "notebook")'=>
    'bool Create(wxWindow*  parent , wxWindowID  id , const wxPoint& pos , const wxSize&  size , long style , const wxString&  name = "notebook")'
    },
    'wxPanel' =>
    {
    'wxPanel()' =>
    '//wxPanel()',
    },
    'wxStaticBitmap'=>
    {
    'wxBitmap& GetBitmap() const'=>
    'wxBitmap GetBitmap() const',
    },
    'wxSingleChoiceDialog'=>
    {
    'wxSingleChoiceDialog(wxWindow*  parent , const wxString&  message , const wxString&  caption , int  n , const wxString*  choices , void** clientData = NULL, long  style = wxOK, const wxPoint&  pos = wxDefaultPosition)'=> 
     'wxSingleChoiceDialog(wxWindow*  parent , const wxString&  message , const wxString&  caption , int  n , const wxString  choices[] , char** clientData = NULL, long  style = wxOK, const wxPoint&  pos = wxDefaultPosition)',
     'void SetSelection(int  selection ) const'=>
     'void SetSelection(int  selection ) ',
    },
    'wxTipProvider'=>
    {
    'wxString GetTip()'=>
    'virtual wxString GetTip()=0',
    },
    'wxTipWindow'=>
    {
    'wxTipWindow(wxWindow*  parent , const wxString&  text , wxCoord  maxLength = 100, wxTipWindow**  windowPtr )'=>
    'wxTipWindow(wxWindow*  parent , const wxString&  text , wxCoord  maxLength = 100, wxTipWindow**  windowPtr = NULL )',
    },
    'wxToggleButton'=>
    {
	'wxToggleButton(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  val , const wxString&  name = "checkBox")'=>
'wxToggleButton(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  val = wxDefaultValidator, const wxString&  name = "checkBox")',
	'bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  val , const wxString&  name = "checkBox")'=>
	'bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  val = wxDefaultValidator, const wxString&  name = "checkBox")'
    },
    'wxToolBar'=>
    {
    'int GetToolPos(int  toolId ) const'=>
    '//int GetToolPos(int  toolId ) const',
    'wxToolBarTool * InsertTool(size_t  pos , wxToolBarTool*  tool )'=>
    '//wxToolBarTool * InsertTool(size_t  pos , wxToolBarTool*  tool )',
    'wxToolBarTool* AddTool(wxToolBarTool*  tool )'=>
    '//wxToolBarTool* AddTool(wxToolBarTool*  tool )',
    },
    'wxWindow' =>
    {
    'virtual void DragAcceptFiles(bool  accept )' =>
    '',
    'wxAccessibile* GetAccessible()' =>
    '//wxAccessible* GetAccessible()',
    'virtual void GetTextExtent(const wxString&  string , int*  x , int*  y , int*  descent = NULL, int*  externalLeading = NULL, const wxFont*  font = NULL, bool use16 = false) const' =>
    'virtual void GetTextExtent(const wxString&  string , int*  x , int*  y , int*  descent = NULL, int*  externalLeading = NULL, const wxFont*  font = NULL) const',
    'void SetAccessible(wxAccessibile*  accessible )' =>
    '//void SetAccessible(wxAccessible*  accessible )',
    'virtual void SetBackgroundColour(const wxColour&  colour )' =>
    'virtual bool SetBackgroundColour(const wxColour&  colour )',
    'virtual void SetForegroundColour(const wxColour&  colour )' =>
    'virtual bool SetForegroundColour(const wxColour&  colour )',
    'void SetCaret(wxCaret * caret ) const'=>
    'void SetCaret(wxCaret * caret )',
    'virtual void SetCursor(const wxCursor& cursor )' =>
    'virtual bool SetCursor(const wxCursor& cursor )',
    'virtual void SetPalette(wxPalette*  palette )' =>
    'virtual void SetPalette(const wxPalette*  palette )',
    },
}

def fix_error_in_xml(class_name, method_proto)
    class_fixes = $fixes[class_name]
    if(class_fixes)
        #puts("Checking fixes for #{class_name}")
        #puts(method_proto)
        key = method_proto.strip
        fixed_proto = class_fixes[key]
        if(fixed_proto)
            #puts
            #puts("Applying fix: #{fixed_proto}")
            class_fixes.delete(key)
            if(class_fixes.size == 0)
                $fixes.delete(class_name)
            end
            return fixed_proto
        end
    end
    return method_proto
end

$need_virtual_destructor =
[
    'wxBoxSizer',
    'wxStaticText',
    'wxCloseEvent',
    'wxCommandEvent',
    'wxControl',
    'wxCursor',
    'wxGDIObject',
    'wxPaintDC',
    'wxPaintEvent',
    'wxUpdateUIEvent',
    'wxWindowDC',
]

$missing =
{
    'wxBitmapButton' =>
    [
    'wxBitmap& GetBitmapDisabled()',
    'wxBitmap& GetBitmapFocus()',
    'wxBitmap& GetBitmapLabel()',
    'wxBitmap& GetBitmapSelected()',
    ],
    'wxChoice' =>
    [
    'void SetSelection(int  n )',
	'void SetStringSelection(wxString &)',
    ],
    'wxComboBox'=>
    [
    'void Append(const wxString& item)',
	'void SetSelection(int n)',
	'void SetStringSelection(wxString &)',
    ],
	'wxListBox'=>
	[
	'void SetSelection(int n, const bool select = TRUE)',
	'void SetStringSelection(const wxString& string, const bool select = TRUE)',
	'void Append(const wxString& item)',
	'void Delete(int n)',
	'int FindString(wxString & string)',
	'int GetCount()',
	'int GetSelection()',
	'wxString GetString(int n)',
	'wxString GetStringSelection()',
	'void SetString(int n, wxString& string)',
	'void Select(int n)',
	],
	'wxTextCtrl'=>
	[
	'wxTextCtrl & operator<<(const char *)',
	'wxTextCtrl & operator<<(int)',
	'wxTextCtrl & operator<<(double)',
	'wxTextCtrl & operator<<(bool)',
	],
    'wxToolBar'=>
    [
    'void SetRows(int rows)',
    ],
    'wxLayoutConstraints'=>
    [
    'wxIndividualLayoutConstraint bottom,height,left,right,top,width'
    ],
	'wxPoint'=>
	[
	'int x',
	'int y'
	]

}

def get_missing_methods(class_name)
    missing = []
    methods = $missing[class_name]
    if(methods)
        missing = methods.collect do | m | m end
        #puts("Adding #{missing.size} methods to #{class_name}")
    end
    at = 
    if($need_virtual_destructor.index(class_name))
        missing << "virtual ~#{class_name}()"
        $need_virtual_destructor.delete(class_name)
    end
    return missing
end

$events = {}

class WxEvent
    NO_PARAM = 1
    WITH_ID = 2
    WITH_RANGE = 3

    attr_reader :name
    attr_reader :type
    attr_reader :evt_id

    def initialize(name, e) 
        
        if /(id1, id2, event, func)/ =~ name
            @type = WITH_RANGE
        elsif /(id, func)/ =~ name
            @type = WITH_ID
        else
            @type = NO_PARAM
        end

        @name = name.gsub(/\(.*\)/,"")
        @evt_id = e
    end

    def WxEvent.fix_errors_in_xml()
        $event_fixes.each do |name, value|
            $events[name] = value
        end
    end

    def to_s
        return "[\"#{@name}\", #{@type}, \"#{@evt_id}\"],"
    end 

end





$event_fixes = {
"EVT_CALENDAR(id, func)"=>WxEvent.new("EVT_CALENDAR(id, func)", "wxEVT_CALENDAR_DOUBLECLICKED"),
"EVT_CALENDAR_DAY(id, func)"=>WxEvent.new("EVT_CALENDAR_DAY(id, func)", "wxEVT_CALENDAR_DAY_CHANGED"),
"EVT_CALENDAR_MONTH(id, func)"=>WxEvent.new("EVT_CALENDAR_MONTH(id, func)", "wxEVT_CALENDAR_MONTH_CHANGED"),
"EVT_CALENDAR_SEL_CHANGED(id, func)"=>WxEvent.new("EVT_CALENDAR_SEL_CHANGED(id, func)", "wxEVT_CALENDAR_SEL_CHANGED"),
"EVT_CALENDAR_WEEKDAY_CLICKED(id, func)"=>WxEvent.new("EVT_CALENDAR_WEEKDAY_CLICKED(id, func)", "wxEVT_CALENDAR_WEEKDAY_CLICKED"),
"EVT_CALENDAR_YEAR(id, func)"=>WxEvent.new("EVT_CALENDAR_YEAR(id, func)", "wxEVT_CALENDAR_YEAR_CHANGED"),
"EVT_CLOSE(func)"=>WxEvent.new("EVT_CLOSE(func)", "wxEVT_CLOSE_WINDOW"),
"EVT_COMMAND(id, event, func)"=>WxEvent.new("EVT_COMMAND(id, event, func)", "wxEVT_NULL"),
"EVT_COMMAND_RANGE(id1, id2, event, func)"=>WxEvent.new("EVT_COMMAND_RANGE(id1, id2, event, func)", "wxEVT_NULL"),
"EVT_CONTEXT_MENU(func)"=>WxEvent.new("EVT_CONTEXT_MENU(func)", "wxEVT_CONTEXT_MENU"),
"EVT_DIALUP_CONNECTED(func)"=>WxEvent.new("EVT_DIALUP_CONNECTED(func)", "wxEVT_DIALUP_CONNECTED"),
"EVT_DIALUP_DISCONNECTED(func)"=>WxEvent.new("EVT_DIALUP_DISCONNECTED(func)", "wxEVT_DIALUP_DISCONNECTED"),
"EVT_END_SESSION(func)"=>WxEvent.new("EVT_END_SESSION(func)", "wxEVT_END_SESSION"),
"EVT_FIND(id, func)"=>WxEvent.new("EVT_FIND(id, func)", "wxEVT_COMMAND_FIND"),
"EVT_FIND_CLOSE(id, func)"=>WxEvent.new("EVT_FIND_CLOSE(id, func)", "wxEVT_COMMAND_FIND_CLOSE"),
"EVT_FIND_NEXT(id, func)"=>WxEvent.new("EVT_FIND_NEXT(id, func)", "wxEVT_COMMAND_FIND_NEXT"),
"EVT_FIND_REPLACE(id, func)"=>WxEvent.new("EVT_FIND_REPLACE(id, func)", "wxEVT_COMMAND_FIND_REPLACE"),
"EVT_FIND_REPLACE_ALL(id, func)"=>WxEvent.new("EVT_FIND_REPLACE_ALL(id, func)", "wxEVT_COMMAND_FIND_REPLACE_ALL"),
"EVT_LIST_BEGIN_DRAG(id, func)"=>WxEvent.new("EVT_LIST_BEGIN_DRAG(id, func)", "wxEVT_COMMAND_LIST_BEGIN_DRAG"),
"EVT_LIST_BEGIN_LABEL_EDIT(id, func)"=>WxEvent.new("EVT_LIST_BEGIN_LABEL_EDIT(id, func)", "wxEVT_COMMAND_LIST_BEGIN_LABEL_EDIT"),
"EVT_LIST_BEGIN_RDRAG(id, func)"=>WxEvent.new("EVT_LIST_BEGIN_RDRAG(id, func)", "wxEVT_COMMAND_LIST_BEGIN_RDRAG"),
"EVT_LIST_CACHE_HINT(id, func)"=>WxEvent.new("EVT_LIST_CACHE_HINT(id, func)", "wxEVT_COMMAND_LIST_CACHE_HINT"),
"EVT_LIST_COL_BEGIN_DRAG(id, func)"=>WxEvent.new("EVT_LIST_COL_BEGIN_DRAG(id, func)", "wxEVT_COMMAND_LIST_COL_BEGIN_DRAG"),
"EVT_LIST_COL_CLICK(id, func)"=>WxEvent.new("EVT_LIST_COL_CLICK(id, func)", "wxEVT_COMMAND_LIST_COL_CLICK"),
"EVT_LIST_COL_DRAGGING(id, func)"=>WxEvent.new("EVT_LIST_COL_DRAGGING(id, func)", "wxEVT_COMMAND_LIST_COL_DRAGGING"),
"EVT_LIST_COL_END_DRAG(id, func)"=>WxEvent.new("EVT_LIST_COL_END_DRAG(id, func)", "wxEVT_COMMAND_LIST_COL_END_DRAG"),
"EVT_LIST_COL_RIGHT_CLICK(id, func)"=>WxEvent.new("EVT_LIST_COL_RIGHT_CLICK(id, func)", "wxEVT_COMMAND_LIST_COL_RIGHT_CLICK"),
"EVT_LIST_DELETE_ALL_ITEMS(id, func)"=>WxEvent.new("EVT_LIST_DELETE_ALL_ITEMS(id, func)", "wxEVT_COMMAND_LIST_DELETE_ALL_ITEMS"),
"EVT_LIST_DELETE_ITEM(id, func)"=>WxEvent.new("EVT_LIST_DELETE_ITEM(id, func)", "wxEVT_COMMAND_LIST_DELETE_ITEM"),
"EVT_LIST_END_LABEL_EDIT(id, func)"=>WxEvent.new("EVT_LIST_END_LABEL_EDIT(id, func)", "wxEVT_COMMAND_LIST_END_LABEL_EDIT"),
"EVT_LIST_GET_INFO(id, func)"=>WxEvent.new("EVT_LIST_GET_INFO(id, func)","wxEVT_COMMAND_LIST_GET_INFO"),
"EVT_LIST_SET_INFO(id, func)"=>WxEvent.new("EVT_LIST_SET_INFO(id, func)","wxEVT_COMMAND_LIST_SET_INFO"),
"EVT_LIST_INSERT_ITEM(id, func)"=>WxEvent.new("EVT_LIST_INSERT_ITEM(id, func)", "wxEVT_COMMAND_LIST_INSERT_ITEM"),
"EVT_LIST_ITEM_ACTIVATED(id, func)"=>WxEvent.new("EVT_LIST_ITEM_ACTIVATED(id, func)", "wxEVT_COMMAND_LIST_ITEM_ACTIVATED"),
"EVT_LIST_ITEM_DESELECTED(id, func)"=>WxEvent.new("EVT_LIST_ITEM_DESELECTED(id, func)", "wxEVT_COMMAND_LIST_ITEM_DESELECTED"),
"EVT_LIST_ITEM_FOCUSED(id, func)"=>WxEvent.new("EVT_LIST_ITEM_FOCUSED(id, func)", "wxEVT_COMMAND_LIST_ITEM_FOCUSED"),
"EVT_LIST_ITEM_MIDDLE_CLICK(id, func)"=>WxEvent.new("EVT_LIST_ITEM_MIDDLE_CLICK(id, func)", "wxEVT_COMMAND_LIST_ITEM_MIDDLE_CLICK"),
"EVT_LIST_ITEM_RIGHT_CLICK(id, func)"=>WxEvent.new("EVT_LIST_ITEM_RIGHT_CLICK(id, func)", "wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK"),
"EVT_LIST_ITEM_SELECTED(id, func)"=>WxEvent.new("EVT_LIST_ITEM_SELECTED(id, func)", "wxEVT_COMMAND_LIST_ITEM_SELECTED"),
"EVT_LIST_KEY_DOWN(id, func)"=>WxEvent.new("EVT_LIST_KEY_DOWN(id, func)", "wxEVT_COMMAND_LIST_KEY_DOWN"),
"EVT_MENU(id, func)"=>WxEvent.new("EVT_MENU(id, func)", "wxEVT_COMMAND_MENU_SELECTED"),
"EVT_MENU_CLOSE(func)"=>WxEvent.new("EVT_MENU_CLOSE(func)", "wxEVT_MENU_CLOSE"),
"EVT_MENU_HIGHLIGHT(id, func)"=>WxEvent.new("EVT_MENU_HIGHLIGHT(id, func)", "wxEVT_MENU_HIGHLIGHT"),
"EVT_MENU_HIGHLIGHT_ALL(func)"=>WxEvent.new("EVT_MENU_HIGHLIGHT_ALL(func)", "wxEVT_MENU_HIGHLIGHT"),
"EVT_MENU_OPEN(func)"=>WxEvent.new("EVT_MENU_OPEN(func)", "wxEVT_MENU_OPEN"),
"EVT_MENU_RANGE(id1, id2, func)"=>WxEvent.new("EVT_MENU_RANGE(id1, id2, func)", "wxEVT_COMMAND_MENU_SELECTED"),
"EVT_MOUSE_EVENTS(func)"=>WxEvent.new("EVT_MOUSE_EVENTS(func)", "0"),
"EVT_NOTEBOOK_PAGE_CHANGED(id, func)"=>WxEvent.new("EVT_NOTEBOOK_PAGE_CHANGED(id, func)","wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED"),
"EVT_NOTEBOOK_PAGE_CHANGING(id, func)"=>WxEvent.new("EVT_NOTEBOOK_PAGE_CHANGING(id, func)","wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGING"),
"EVT_QUERY_END_SESSION(func)"=>WxEvent.new("EVT_QUERY_END_SESSION(func)", "wxEVT_QUERY_END_SESSION"),
"EVT_SASH_DRAGGED_RANGE(id1, id2, func)"=>WxEvent.new("EVT_SASH_DRAGGED_RANGE(id1, id2, func)","wxEVT_SASH_DRAGGED"),
"EVT_SCROLLWIN(func)"=>WxEvent.new("EVT_SCROLLWIN(func)", "0"),
"EVT_SOCKET(id, func)"=>WxEvent.new("EVT_SOCKET(id, func)", "wxEVT_SOCKET"),
"EVT_SPINCTRL(id, func)"=>WxEvent.new("EVT_SPINCTRL(id, func)", "wxEVT_COMMAND_SPINCTRL_UPDATED"),
"EVT_SPIN(id, func)"=>WxEvent.new("EVT_SPIN(id, func)","wxEVT_SCROLL_THUMBTRACK"),
"EVT_SPIN_UP(id, func)"=>WxEvent.new("EVT_SPIN_UP(id, func)","wxEVT_SCROLL_LINEDOWN"),
"EVT_SPIN_DOWN(id, func)"=>WxEvent.new("EVT_SPIN_DOWN(id, func)","wxEVT_SCROLL_LINEUP"),

"EVT_TEXT_MAXLEN(id, func)"=>WxEvent.new("EVT_TEXT_MAXLEN(id, func)", "wxEVT_COMMAND_TEXT_MAXLEN"),
"EVT_TEXT_URL(id, func)"=>WxEvent.new("EVT_TEXT_URL(id, func)", "wxEVT_COMMAND_TEXT_URL"),
"EVT_TOGGLEBUTTON(id, func)"=>WxEvent.new("EVT_TOGGLEBUTTON(id, func)", "wxEVT_COMMAND_TOGGLEBUTTON_CLICKED"),
"EVT_TREE_BEGIN_DRAG(id, func)"=>WxEvent.new("EVT_TREE_BEGIN_DRAG(id, func)", "wxEVT_COMMAND_TREE_BEGIN_DRAG"),
"EVT_TREE_BEGIN_LABEL_EDIT(id, func)"=>WxEvent.new("EVT_TREE_BEGIN_LABEL_EDIT(id, func)", "wxEVT_COMMAND_TREE_BEGIN_LABEL_EDIT"),
"EVT_TREE_BEGIN_RDRAG(id, func)"=>WxEvent.new("EVT_TREE_BEGIN_RDRAG(id, func)", "wxEVT_COMMAND_TREE_BEGIN_RDRAG"),
"EVT_TREE_DELETE_ITEM(id, func)"=>WxEvent.new("EVT_TREE_DELETE_ITEM(id, func)", "wxEVT_COMMAND_TREE_DELETE_ITEM"),
"EVT_TREE_END_DRAG(id, func)"=>WxEvent.new("EVT_TREE_END_DRAG(id, func)", "wxEVT_COMMAND_TREE_END_DRAG"),
"EVT_TREE_END_LABEL_EDIT(id, func)"=>WxEvent.new("EVT_TREE_END_LABEL_EDIT(id, func)", "wxEVT_COMMAND_TREE_END_LABEL_EDIT"),
"EVT_TREE_GET_INFO(id, func)"=>WxEvent.new("EVT_TREE_GET_INFO(id, func)", "wxEVT_COMMAND_TREE_GET_INFO"),
"EVT_TREE_ITEM_ACTIVATED(id, func)"=>WxEvent.new("EVT_TREE_ITEM_ACTIVATED(id, func)", "wxEVT_COMMAND_TREE_ITEM_ACTIVATED"),
"EVT_TREE_ITEM_COLLAPSED(id, func)"=>WxEvent.new("EVT_TREE_ITEM_COLLAPSED(id, func)", "wxEVT_COMMAND_TREE_ITEM_COLLAPSED"),
"EVT_TREE_ITEM_COLLAPSING(id, func)"=>WxEvent.new("EVT_TREE_ITEM_COLLAPSING(id, func)", "wxEVT_COMMAND_TREE_ITEM_COLLAPSING"),
"EVT_TREE_ITEM_EXPANDED(id, func)"=>WxEvent.new("EVT_TREE_ITEM_EXPANDED(id, func)", "wxEVT_COMMAND_TREE_ITEM_EXPANDED"),
"EVT_TREE_ITEM_EXPANDING(id, func)"=>WxEvent.new("EVT_TREE_ITEM_EXPANDING(id, func)", "wxEVT_COMMAND_TREE_ITEM_EXPANDING"),
"EVT_TREE_ITEM_MIDDLE_CLICK(id, func)"=>WxEvent.new("EVT_TREE_ITEM_MIDDLE_CLICK(id, func)", "wxEVT_COMMAND_TREE_ITEM_MIDDLE_CLICK"),
"EVT_TREE_ITEM_RIGHT_CLICK(id, func)"=>WxEvent.new("EVT_TREE_ITEM_RIGHT_CLICK(id, func)", "wxEVT_COMMAND_TREE_ITEM_RIGHT_CLICK"),
"EVT_TREE_KEY_DOWN(id, func)"=>WxEvent.new("EVT_TREE_KEY_DOWN(id, func)", "wxEVT_COMMAND_TREE_KEY_DOWN"),
"EVT_TREE_SEL_CHANGED(id, func)"=>WxEvent.new("EVT_TREE_SEL_CHANGED(id, func)", "wxEVT_COMMAND_TREE_SEL_CHANGED"),
"EVT_TREE_SEL_CHANGING(id, func)"=>WxEvent.new("EVT_TREE_SEL_CHANGING(id, func)", "wxEVT_COMMAND_TREE_SEL_CHANGING"),
"EVT_TREE_SET_INFO(id, func)"=>WxEvent.new("EVT_TREE_SET_INFO(id, func)", "wxEVT_COMMAND_TREE_SET_INFO"),
"EVT_WIZARD_CANCEL(id, func)"=>WxEvent.new("EVT_WIZARD_CANCEL(id, func)", "wxEVT_WIZARD_CANCEL"),
"EVT_WIZARD_FINISHED(id, func)"=>WxEvent.new("EVT_WIZARD_FINISHED(id, func)", "wxEVT_WIZARD_FINISHED"),
"EVT_WIZARD_HELP(id, func)"=>WxEvent.new("EVT_WIZARD_HELP(id, func)", "wxEVT_WIZARD_HELP"),
"EVT_WIZARD_PAGE_CHANGED(id, func)"=>WxEvent.new("EVT_WIZARD_PAGE_CHANGED(id, func)", "wxEVT_WIZARD_PAGE_CHANGED"),
"EVT_WIZARD_PAGE_CHANGING(id, func)"=>WxEvent.new("EVT_WIZARD_PAGE_CHANGING(id, func)", "wxEVT_WIZARD_PAGE_CHANGING"),
}


class WxParameter
    def initialize(node)
        @parameter_type = node.attributes['type']
        @name = node.attributes['name']
        @value = node.attributes['value']
        if(@value)
            @value.gsub!(/``/, '"')
	    if (/^[\"]/ =~ @value) and not ( /^[\"].*[\"]/ =~ @value)
                @value = "#{@value}\""
            end
        end
    end
    
    def to_s
        if(@value)
            default_value = "= #{@value}"
        else
            default_value = ''
        end
        return "#{@parameter_type} #{@name} #{default_value}"
    end
end

class WxMethod
    attr_reader :name
    
    def initialize(node, function_name)
        # sometimes the member name is right and the
        # function name is wrong, so use the member name
        @name = function_name
        @return_type = node.attributes['type']
        @suffix = node.attributes['suffix']
        @parameters = []
        node.each_element('parameters/parameter') do | parameter |
          @parameters << WxParameter.new(parameter)
        end
    end
    
    def clear_type
        @return_type = ''
    end
    
    def to_s
        params = @parameters.collect do | p |
            p.to_s
        end
        prefix = @return_type
        if(@name.index("On") == 0 || @name.index('~') == 0)
            if(!prefix.index("virtual"))
                prefix = "virtual #{prefix}"
            end
        end
        params = "(" + params.join(', ') + ")"
        return "#{prefix} #{@name}#{params} #{@suffix}"
    end
    
end

class WxClass
    attr_reader :name
    
    def initialize(node)
        @name = node.attributes['name']
        @parents = []
        @members = []
puts("Class: #{@name}: #{node.xpath}")
        node.each_element do | class_info | 
            if(class_info.xpath =~ /parents$/)
                load_parent_classes(class_info)
            end
            if(class_info.xpath =~ /members$/)
                load_class_members(class_info)
            end
            if(class_info.xpath =~ /events$/)
                load_events(class_info)
            end
        end
    end

    def load_parent_classes(parents_node)
        parents_node.each_element('classref') do | parent |
#          if(parent.xpath =~ /classref$/)
            # NSK - filter out non-wx base classes we don't care about.
            name = parent.attributes['name']
            if (name.index('wx') == 0)
              @parents << name
            end
 #         end
        end
    end
    
    def load_class_members(class_info)
      class_info.each_element('member') do | member |
        function_name = member.attributes['name']
        member.each_element('function') do | function |
                load_function(function, function_name)
        end
      end
    end
    
    def load_function(node, function_name)
      m = WxMethod.new(node, function_name)
      if(!m.name)
          return
      end
      if(m.name == @name || m.name == "~#{@name}")
          m.clear_type
      end
      if(m.name.index('operator') == 0 ||
              m.name == 'new' ||
              m.name == 'delete')
          return
      end
      @members << m
      #puts("Method: #{m.to_s}")
    end

    def load_events(class_info)
      class_info.each_element('event') do | member |
        evt_id = ""
        event_name = member.attributes['name']
        member.each do|child|
          if (/wxEVT[A-Z_]*/ =~ child.value)
            evt_id = $&
          end
        end
        $events[event_name] = WxEvent.new(event_name,evt_id)
      end
    end

  
    def parent
        return @parents[0]
    end
    
    def to_s
        lines = []
        class_def = "class #{@name}"
        if(@parents.size > 0)
            class_def += " : public #{parent}"
        end
        lines << class_def
        lines << "{"
        lines << "public:"
        @members.each do | member |
            fixed = fix_error_in_xml(@name, member.to_s)
            if(is_pure_virtual(@name, member.name))
                fixed += ' = 0'
                #puts("Found pure: #{member.name}")
            end
            lines << "  #{fixed};"
        end
        missing_from_xml = get_missing_methods(@name)
        if(missing_from_xml.size > 0)
            lines << "  // the following were missing from the xml"
        end
        missing_from_xml.each do | m |
            lines << "  #{m};"
        end
        lines << "};"
        lines << ""
        lines << ""
        lines << ""
        return lines.join("\n")
    end
end

def puts_banner(out, filename, start)
    out.puts("#{start} #{filename}")
    out.puts("#{start} This file was automatically generated")
    out.puts("#{start} by extractxml.rb, part of the wxRuby project")
    out.puts("#{start} Do not make changes directly to this file!")
    out.puts
end

file = File.new(xml_file)
puts("Parsing #{file.path}...may take a few MINUTES...")
$doc = REXML::Document.new(file)

parents = []
$doc.elements.each('classes/class') do | element |
    #puts element.attributes['name']
    c = WxClass.new(element)
    if(c.parent)
        parents << "    '#{c.name}' => '#{c.parent}',"
    end
    h = "#{c.name}.h"
    #puts("writing #{h}")
    #print('.'); $stdout.flush
    file = File.join(output_dir, h)
    File.open(file, "w") do | out |
        puts_banner(out, h, "//")
        out.puts("#if !defined(_#{c.name}_h_)")
        out.puts("#define _#{c.name}_h_")
        out.puts(c.to_s)
        out.puts("#endif")
    end
end

parent_file = "parents.rb"
File.open(File.join(output_dir, parent_file), "w") do | out |
    puts_banner(out, parent_file, "#")
    out.puts("$parents = {")
    out.puts(parents.join("\n"))
    out.puts("}")
end

File.open(File.join(output_dir,"events.rb"),"w") do |out|
    WxEvent.fix_errors_in_xml
    out.puts("$events = [")
    $events.each_with_index do |name, val|
		out.puts name[1].to_s 
    end
    out.puts("]")

end

if($fixes.size > 0)
    puts("ERROR: Not all fixes applied:")
    puts ($fixes.values)
    exit(1)
end

if($need_virtual_destructor.size > 0)
    puts("ERROR: Not all virtual destructors applied:")
    puts($need_virtual_destructor)
    exit(1)
end

#puts
 