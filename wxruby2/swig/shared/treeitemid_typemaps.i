// These typemaps are used by TreeCtrl and TreeEvent to convert wx tree 
// item ids into simple 

%typemap(in) wxTreeItemId& "$1 = new wxTreeItemId((void*)NUM2LONG($input));"
%typemap(out) wxTreeItemId "$result = LONG2NUM( (size_t)$1.m_pItem );"
%typemap(directorin) wxTreeItemId& "$input = LONG2NUM( (size_t)$1.m_pItem );"
%typemap(directorout) wxTreeItemId& "$result = new wxTreeItemId((void*)NUM2LONG($1));"
%typemap(freearg) wxTreeItemId& "delete $1;"
