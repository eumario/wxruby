// wxJoystick.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxJoystick_h_)
#define _wxJoystick_h_
class wxJoystick : public wxObject
{
public:
	/**
	 * \brief Constructor.   may be one of wxJOYSTICK1, wxJOYSTICK2, indicating the joystick
controller of interest. 
	 * \param int  
	*/

   wxJoystick(int joystick = wxJOYSTICK1) ;
	/**
	 * \brief Destroys the wxJoystick object. 
	*/

  virtual  ~wxJoystick() ;
	/**
	 * \brief Returns the state of the joystick buttons. Every button is mapped to a single
bit in the returned integer, with the first button being mapped to the least
significant bit, and so on.
A bitlist of wxJOY_BUTTONn identifiers, where n is 1, 2, 3 or 4 
is available for historical reasons. 
	*/

  int GetButtonState() const;
	/**
	 * \brief Returns the manufacturer id. 
	*/

  int GetManufacturerId() const;
	/**
	 * \brief Returns the movement threshold, the number of steps outside which the joystick is deemed to have
moved. 
	*/

  int GetMovementThreshold() const;
	/**
	 * \brief Returns the number of axes for this joystick. 
	*/

  int GetNumberAxes() const;
	/**
	 * \brief Returns the number of buttons for this joystick. 
	*/

  int GetNumberButtons() const;
	/**
	 * \brief Returns the number of joysticks currently attached to the computer. 
	*/

  int GetNumberJoysticks() const;
	/**
	 * \brief Returns the maximum polling frequency. 
	*/

  int GetPollingMax() const;
	/**
	 * \brief Returns the minimum polling frequency. 
	*/

  int GetPollingMin() const;
	/**
	 * \brief Returns the product id for the joystick. 
	*/

  int GetProductId() const;
	/**
	 * \brief Returns the product name for the joystick. 
	*/

  wxString GetProductName() const;
	/**
	 * \brief Returns the x, y position of the joystick. 
	*/

  wxPoint GetPosition() const;
	/**
	 * \brief Returns the point-of-view position, expressed in continuous, one-hundredth of a degree units,
but limited to return 0, 9000, 18000 or 27000.
Returns -1 on error. 
	*/

  int GetPOVPosition() const;
	/**
	 * \brief Returns the point-of-view position, expressed in continuous, one-hundredth of a degree units.
Returns -1 on error. 
	*/

  int GetPOVCTSPosition() const;
	/**
	 * \brief Returns the maximum rudder position. 
	*/

  int GetRudderMax() const;
	/**
	 * \brief Returns the minimum rudder position. 
	*/

  int GetRudderMin() const;
	/**
	 * \brief Returns the rudder position. 
	*/

  int GetRudderPosition() const;
	/**
	 * \brief Returns the maximum U position. 
	*/

  int GetUMax() const;
	/**
	 * \brief Returns the minimum U position. 
	*/

  int GetUMin() const;
	/**
	 * \brief Gets the position of the fifth axis of the joystick, if it exists. 
	*/

  int GetUPosition() const;
	/**
	 * \brief Returns the maximum V position. 
	*/

  int GetVMax() const;
	/**
	 * \brief Returns the minimum V position. 
	*/

  int GetVMin() const;
	/**
	 * \brief Gets the position of the sixth axis of the joystick, if it exists. 
	*/

  int GetVPosition() const;
	/**
	 * \brief Returns the maximum x position. 
	*/

  int GetXMax() const;
	/**
	 * \brief Returns the minimum x position. 
	*/

  int GetXMin() const;
	/**
	 * \brief Returns the maximum y position. 
	*/

  int GetYMax() const;
	/**
	 * \brief Returns the minimum y position. 
	*/

  int GetYMin() const;
	/**
	 * \brief Returns the maximum z position. 
	*/

  int GetZMax() const;
	/**
	 * \brief Returns the minimum z position. 
	*/

  int GetZMin() const;
	/**
	 * \brief Returns the z position of the joystick. 
	*/

  int GetZPosition() const;
	/**
	 * \brief Returns true if the joystick has a point of view control. 
	*/

  bool HasPOV() const;
	/**
	 * \brief Returns true if the joystick point-of-view supports discrete values (centered, forward, backward, left, and right). 
	*/

  bool HasPOV4Dir() const;
	/**
	 * \brief Returns true if the joystick point-of-view supports continuous degree bearings. 
	*/

  bool HasPOVCTS() const;
	/**
	 * \brief Returns true if there is a rudder attached to the computer. 
	*/

  bool HasRudder() const;
	/**
	 * \brief Returns true if the joystick has a U axis. 
	*/

  bool HasU() const;
	/**
	 * \brief Returns true if the joystick has a V axis. 
	*/

  bool HasV() const;
	/**
	 * \brief Returns true if the joystick has a Z axis. 
	*/

  bool HasZ() const;
	/**
	 * \brief Returns true if the joystick is functioning. 
	*/

  bool IsOk() const;
	/**
	 * \brief  
	*/

  bool ReleaseCapture() ;
	/**
	 * \brief  
	 * \param wxWindow*  
	 * \param int  
	*/

  bool SetCapture(wxWindow*  win , int pollingFreq = 0) ;
	/**
	 * \brief Sets the movement threshold, the number of steps outside which the joystick is deemed to have
moved. 
	 * \param int  
	*/

  void SetMovementThreshold(int  threshold ) ;
};


#endif
