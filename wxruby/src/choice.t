/**********************************************************************

  choice.t -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

//$$ CLASS Choice : Control
//$$ AS_SUBCLASS

//$$ METHODS_BEGIN
  wxChoice(wxWindow * parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, const wxString choices[] = 0, long style = 0, const wxValidator& validator = wxDefaultValidator, const wxString& name = "choice"); // MODIFIED!

#(2)  void Append(const wxString& item);
#(2)  void Append(const wxString& item, void* clientData);
  void Clear();
#(1)  bool Create(wxWindow * parent, wxWindowID id, const wxPoint& pos, const wxSize& size, int n, const wxString choices[], long style = 0, const wxString& name = ``choice");
  void Delete(int n);
  int FindString(const wxString& string);
  int GetColumns();
#(2)  void* GetClientData(int n);
  int GetCount();
  int GetSelection();
  wxString GetString(int n);
  wxString GetStringSelection();
#(3)  int Number();
#(2)  void SetClientData(int n, void* data);
  void SetColumns(int n = 1);
  void SetSelection(int n);
  void SetString(int n, const wxString& text);
  void SetStringSelection(const wxString& string);
//$$ METHODS_END

//(1) Not needed because we don't support the empty constructor
#(1)  bool Create(wxWindow * parent, wxWindowID id, const wxPoint& pos, const wxSize& size, int n, const wxString choices[], long style = 0, const wxString& name = ``choice");

//(2) Need to support client data somehow (later)
#(2)  void Append(const wxString& item);
#(2)  void Append(const wxString& item, void* clientData);
#(2)  void* GetClientData(int n);
#(2)  void SetClientData(int n, void* data);

//(3) Obsolete, and not available in all wxWindows builds
#(3)  int Number();


//$$ BEGIN_H_FILE
class WxChoice
{
public:
	//$$ RB_DECLARE

    static void Append(int argc, VALUE *argv, VALUE self);
    static void SetClientData(VALUE self,VALUE vn,VALUE vdata);
    static VALUE GetClientData(VALUE self,VALUE vn);
};
//$$ END_H_FILE


//$$ BEGIN_CPP_FILE

void WxChoice::DefineClass()
{
	//$$ RB_DEFINE
	
    rb_define_method(rubyClass, "append", VALUEFUNC(WxChoice::Append), -1);
    //rb_define_method(rubyClass, "set_client_data", VALUEFUNC(WxChoice::SetClientData), 2);
    //rb_define_method(rubyClass, "get_client_data", VALUEFUNC(WxChoice::GetClientData), 1);
}

//$$ RB_IMPLEMENT

void
WxChoice::Append(int argc, VALUE *argv, VALUE self)
{
    wxString item = wxString(StringValuePtr(argv[0]));
//    void* clientData;
    wxChoice *ptr;
    Data_Get_Struct(self, wxChoice, ptr);
/*    if(argc>1) {
        VALUE vdata = rb_hash_new();
        rb_hash_aset(vdata,rb_str_new2("data"),argv[1]);
        clientData = (void*)vdata;
        ptr->Append(item,clientData);
    } else {
*/
        ptr->Append(item);
//    }
}



//$$ END_CPP_FILE
