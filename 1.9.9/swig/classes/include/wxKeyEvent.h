// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxKeyEvent_h_)
#define _wxKeyEvent_h_
class wxKeyEvent : public wxEvent
{
public:
   wxKeyEvent(WXTYPE  keyEventType ) ;
  bool AltDown() const;
  bool ControlDown() const;
  int GetKeyCode() const;
  wxUint32 GetRawKeyCode() const;
  wxUint32 GetRawKeyFlags() const;
  long GetX() const;
  long GetY() const;
  bool MetaDown() const;
  int GetModifiers() const;
  wxPoint GetPosition() const;
  void GetPosition(long * x , long * y ) const;
  bool HasModifiers() const;
  bool ShiftDown() const;

  // override pure virtual methods from base classes
  virtual wxEvent* Clone() const;

  bool          m_scanCode;

#if wxUSE_UNICODE
  // This contains the full Unicode character
  // in a character events in Unicode mode
  wxChar        m_uniChar;
#endif

  // these fields contain the platform-specific information about
  // key that was pressed
  wxUint32      m_rawCode;
  wxUint32      m_rawFlags;
};


#endif
