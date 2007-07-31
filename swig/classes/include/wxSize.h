// Copyright 2006 - 2007 by Kevin Smith
// released under the MIT-style wxruby2 license


#if !defined(_wxSize_h_)
#define _wxSize_h_
class wxSize
{
public:
   wxSize();
   wxSize(int  width, int  height);
  int GetWidth() const;
  int GetHeight() const;
  void Set(int  width, int  height);
  void SetHeight(int height );
  void SetWidth(int width );
};


#endif
