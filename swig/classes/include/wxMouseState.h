// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxMouseState_h_)
#define _wxMouseState_h_

class wxMouseState
{
public:
  wxMouseState();

  wxCoord GetX();
  wxCoord GetY();

  bool LeftDown();
  bool MiddleDown();
  bool RightDown();

  bool ControlDown();
  bool ShiftDown();
  bool AltDown();
  bool MetaDown();
  bool CmdDown();

  void SetX(wxCoord x);
  void SetY(wxCoord y);

  void SetLeftDown(bool down);
  void SetMiddleDown(bool down);
  void SetRightDown(bool down);

  void SetControlDown(bool down);
  void SetShiftDown(bool down);
  void SetAltDown(bool down);
  void SetMetaDown(bool down);
};
 
#endif
