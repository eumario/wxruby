// These typemaps are used by TreeCtrl and TreeEvent to convert wx tree 
// item ids into simple 

%typemap(in) wxTreeItemId& "$1 = new wxTreeItemId(NUM2LONG($input));"
%typemap(out) wxTreeItemId "$result = LONG2NUM( (long)$1.m_pItem );"
%typemap(directorin) wxTreeItemId& "$input = LONG2NUM( (long)$1.m_pItem );"
%typemap(directorout) wxTreeItemId& "$result = new wxTreeItemId(NUM2LONG($1));"
%typemap(freearg) wxTreeItemId& "delete $1;"


