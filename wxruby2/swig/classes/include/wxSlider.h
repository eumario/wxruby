// wxSlider.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSlider_h_)
#define _wxSlider_h_
class wxSlider : public wxControl
{
public:
   wxSlider() ;
   wxSlider(wxWindow*  parent , wxWindowID  id , int  value  , int  minValue , int  maxValue , const wxPoint&  point = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxSL_HORIZONTAL, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "slider") ;
  virtual  ~wxSlider() ;
  void ClearSel() ;
  void ClearTicks() ;
  bool Create(wxWindow*  parent , wxWindowID  id , int  value  , int  minValue , int  maxValue , const wxPoint&  point = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxSL_HORIZONTAL, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "slider") ;
  int GetLineSize() const;
  int GetMax() const;
  int GetMin() const;
  int GetPageSize() const;
  int GetSelEnd() const;
  int GetSelStart() const;
  int GetThumbLength() const;
  int GetTickFreq() const;
  int GetValue() const;
  void SetRange(int  minValue , int  maxValue ) ;
  void SetTickFreq(int  n , int  pos ) ;
  void SetLineSize(int  lineSize ) ;
  void SetPageSize(int  pageSize ) ;
  void SetSelection(int  startPos , int  endPos ) ;
  void SetThumbLength(int  len ) ;
  void SetTick(int  tickPos ) ;
  void SetValue(int  value ) ;
};


#endif
