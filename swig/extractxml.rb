xml_file = ARGV[0]
input_dir = File.dirname(xml_file)
output_dir = File.join(input_dir, "classes/include")

require 'nqxml/treeparser'

def isTagStart(node, name)
    entity = node.entity
    return (entity.class == NQXML::Tag &&
        entity.isTagStart && 
        entity.name == name)
end

def isTagEnd(node, name)
    entity = node.entity
    #puts("isTagEnd(#{entity})")
    return (entity.class == NQXML::Tag &&
        entity.isTagEnd && 
        entity.name == name)
end

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
    'bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  value, const wxPoint& pos , const wxSize& size , int  n , const wxString  choices[] , long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "comboBox")'
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
    ],
    'wxComboBox'=>
    [
    'void Append(const wxString& item)',
    ],
    'wxToolBar'=>
    [
    'void SetRows(int rows)',
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

class WxParameter
    def initialize(node)
        @parameter_type = node.entity.attrs['type']
        @name = node.entity.attrs['name']
        @value = node.entity.attrs['value']
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
        @return_type = node.entity.attrs['type']
        @suffix = node.entity.attrs['suffix']
        @parameters = []
        node.children.each do | function_info |
            if(isTagStart(function_info, 'parameters'))
                function_info.children.each do | parameter |
                    @parameters << WxParameter.new(parameter)
                end
            end
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
        @name = node.entity.attrs['name']
        @parents = []
        @members = []
        node.children.each do | class_info |
            if(isTagStart(class_info, 'parents'))
                load_parent_classes(class_info)
            elsif(isTagStart(class_info, 'members'))
                load_class_members(class_info)
            else
                #puts(class_info.entity)
            end
        end
    end

    def load_parent_classes(parents_node)
        parents_node.children.each do | parent |
            if(isTagStart(parent, 'classref'))
               # NSK - filter out non-wx base classes we don't care about.
	       if (parent.entity.attrs['name'].index('wx') == 0)
                 @parents << (parent.entity.attrs['name'])
	       end
            end
        end
    end
    
    def load_class_members(class_info)
        class_info.children.each do | member |
            if(isTagStart(member, 'member'))
                function_name = member.entity.attrs['name']
                member.children.each do | function |
                    if(isTagStart(function, 'function'))
                        load_function(function, function_name)
                    end
                end
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

begin
    file = File.new(xml_file)
    puts("Parsing #{file.path}...may take a few MINUTES...")
    # Creating a TreeParser parses the input. We immediately
    # ask for the Document object.
    $doc = NQXML::TreeParser.new(file).document
rescue NQXML::ParserError => ex
    puts
    puts "parser error on line #{ex.line()}," +
        " col #{ex.column()}: #{$!}"
end

# Print the entities in the document's prolog.
#$doc.prolog.each { | entity | puts entity.to_s }

# Do something with the nodes in the document.
parents = []
rootNode = $doc.rootNode
#puts "The root entity is #{rootNode.entity}"
rootNode.children.each do | node |
    #puts("--->#{node.entity}")
    if(isTagStart(node, 'class'))
        c = WxClass.new(node)
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
    else
        #puts("Skipping #{node.entity}")
    end
end

parent_file = "parents.rb"
File.open(File.join(output_dir, parent_file), "w") do | out |
    puts_banner(out, parent_file, "#")
    out.puts("$parents = {")
    out.puts(parents.join("\n"))
    out.puts("}")
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
