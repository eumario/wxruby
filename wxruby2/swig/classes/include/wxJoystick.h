// wxJoystick.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxJoystick_h_)
#define _wxJoystick_h_
class wxJoystick : public wxObject
{
public:
   wxJoystick(int joystick = wxJOYSTICK1) ;
  virtual  ~wxJoystick() ;
  int GetButtonState() const;
  int GetManufacturerId() const;
  int GetMovementThreshold() const;
  int GetNumberAxes() const;
  int GetNumberButtons() const;
  int GetNumberJoysticks() const;
  int GetPollingMax() const;
  int GetPollingMin() const;
  int GetProductId() const;
  wxString GetProductName() const;
  wxPoint GetPosition() const;
  int GetPOVPosition() const;
  int GetPOVCTSPosition() const;
  int GetRudderMax() const;
  int GetRudderMin() const;
  int GetRudderPosition() const;
  int GetUMax() const;
  int GetUMin() const;
  int GetUPosition() const;
  int GetVMax() const;
  int GetVMin() const;
  int GetVPosition() const;
  int GetXMax() const;
  int GetXMin() const;
  int GetYMax() const;
  int GetYMin() const;
  int GetZMax() const;
  int GetZMin() const;
  int GetZPosition() const;
  bool HasPOV() const;
  bool HasPOV4Dir() const;
  bool HasPOVCTS() const;
  bool HasRudder() const;
  bool HasU() const;
  bool HasV() const;
  bool HasZ() const;
  bool IsOk() const;
  bool ReleaseCapture() ;
  bool SetCapture(wxWindow*  win , int pollingFreq = 0) ;
  void SetMovementThreshold(int  threshold ) ;
};


#endif
