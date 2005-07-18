# fixmainmodule.rb
#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project

#   This fix is for code that seems to not play nice with SWIG
#   In Menu 
#   wxMenuItem* Append(int itemid, const wxString& text, const wxString& help = wxEmptyString, int kind = wxITEM_NORMAL)
#   and
#   void Append(int itemid, const wxString& text, const wxString& help, bool isCheckable)
#
#   SWIG thinks they have the same message signature and chaos is the result

broken = ARGV[0]+".old"
File.rename(ARGV[0], broken)

File.open(ARGV[0], "w") do | out |
    File.foreach(broken) do | line |
        if(line.index("(wxMenuItem *)(arg1)->Append(arg2,(wxString const &)*arg3,(wxString const &)*arg4,arg5)"))
          line = line.gsub('(wxMenuItem *)(arg1)->Append(arg2,(wxString const &)*arg3,(wxString const &)*arg4,arg5)',
                           '(wxMenuItem *)(arg1)->Append(arg2,(wxString const &)*arg3,(wxString const &)*arg4,(wxItemKind)arg5)'
                          )
        end
        out.puts(line)
    end

end

File.delete(broken)
