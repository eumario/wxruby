// wxListView.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxListView_h_)
#define _wxListView_h_
class wxListView : public wxListCtrl
{
public:
  void ClearColumnImage(int  col ) ;
  void Focus(long  index ) ;
  long GetFirstSelected() const;
  long GetFocusedItem() const;
  long GetNextSelected(long  item ) const;
  bool IsSelected(long  index ) ;
  void Select(bool  on = true) ;
  void SetColumnImage(int  col , int  image ) ;
};


#endif
