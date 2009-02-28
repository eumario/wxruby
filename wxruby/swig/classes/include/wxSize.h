// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license


#if !defined(_wxSize_h_)
#define _wxSize_h_
class wxSize
{
public:
   wxSize();
   wxSize(int  width, int  height);
  void DecBy(int dx, int dy);
  void DecBy(const wxSize& sz);
  void DecBy(int d);
  void DecTo(const wxSize& sz);
  int GetWidth() const;
  int GetHeight() const;    
  int GetX();
  int GetY();
  void IncBy(int dx, int dy);
  void IncBy(const wxSize& sz);
  void IncBy(int d);
  void IncTo(const wxSize& sz);
  bool IsFullySpecified() const;
  void Set(int  width, int  height);
  void SetDefaults(const wxSize& size);
  void SetHeight(int height );
  void SetWidth(int width );
};


#endif
