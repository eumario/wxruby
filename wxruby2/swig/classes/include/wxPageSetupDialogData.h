// wxPageSetupDialogData.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPageSetupDialogData_h_)
#define _wxPageSetupDialogData_h_
class wxPageSetupDialogData : public wxObject
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxPageSetupDialogData() ;
	/**
	 * \brief Copy constructor. 
	 * \param wxPageSetupDialogData&  
	*/

   wxPageSetupDialogData(wxPageSetupDialogData&  data ) ;
	/**
	 * \brief Construct an object from a print dialog data object. 
	 * \param wxPrintData&  
	*/

   wxPageSetupDialogData(wxPrintData&  printData ) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxPageSetupDialogData() ;
	/**
	 * \brief Enables or disables the `Help' button (Windows only). 
	 * \param bool   
	*/

  void EnableHelp(bool  flag ) ;
	/**
	 * \brief Enables or disables the margin controls (Windows only). 
	 * \param bool   
	*/

  void EnableMargins(bool  flag ) ;
	/**
	 * \brief Enables or disables the orientation control (Windows only). 
	 * \param bool   
	*/

  void EnableOrientation(bool  flag ) ;
	/**
	 * \brief Enables or disables the paper size control (Windows only). 
	 * \param bool   
	*/

  void EnablePaper(bool  flag ) ;
	/**
	 * \brief Enables or disables the   button, which invokes a printer setup dialog. 
	 * \param bool   
	*/

  void EnablePrinter(bool  flag ) ;
	/**
	 * \brief Returns true if the page setup dialog will take its minimum margin values from the currently
selected printer properties. Windows only. 
	*/

  bool GetDefaultMinMargins() const;
	/**
	 * \brief Returns true if the margin controls are enabled (Windows only). 
	*/

  bool GetEnableMargins() const;
	/**
	 * \brief Returns true if the orientation control is enabled (Windows only). 
	*/

  bool GetEnableOrientation() const;
	/**
	 * \brief Returns true if the paper size control is enabled (Windows only). 
	*/

  bool GetEnablePaper() const;
	/**
	 * \brief Returns true if the printer setup button is enabled. 
	*/

  bool GetEnablePrinter() const;
	/**
	 * \brief Returns true if the printer setup button is enabled. 
	*/

  bool GetEnableHelp() const;
	/**
	 * \brief Returns true if the dialog will simply return default printer information (such as orientation)
instead of showing a dialog. Windows only. 
	*/

  bool GetDefaultInfo() const;
	/**
	 * \brief Returns the left (x) and top (y) margins in millimetres. 
	*/

  wxPoint GetMarginTopLeft() const;
	/**
	 * \brief Returns the right (x) and bottom (y) margins in millimetres. 
	*/

  wxPoint GetMarginBottomRight() const;
	/**
	 * \brief Returns the left (x) and top (y) minimum margins the user can enter (Windows only). Units
are in millimetres 
	*/

  wxPoint GetMinMarginTopLeft() const;
	/**
	 * \brief Returns the right (x) and bottom (y) minimum margins the user can enter (Windows only). Units
are in millimetres 
	*/

  wxPoint GetMinMarginBottomRight() const;
	/**
	 * \brief Returns the paper id (stored in the internal wxPrintData object).

For further information, see  . 
	*/

  wxPaperSize GetPaperId() const;
	/**
	 * \brief Returns the paper size in millimetres. 
	*/

  wxSize GetPaperSize() const;
	/**
	 * \brief Returns a reference to the   associated with this object. 
	*/

  wxPrintData& GetPrintData() ;
	/**
	 * \brief Returns true if the print data associated with the dialog data is valid.
This can return false on Windows if the current printer is not set, for example.
On all other platforms, it returns true. 
	*/

  bool Ok() const;
	/**
	 * \brief Pass true if the dialog will simply return default printer information (such as orientation)
instead of showing a dialog. Windows only. 
	 * \param bool  
	*/

  void SetDefaultInfo(bool  flag ) ;
	/**
	 * \brief Pass true if the page setup dialog will take its minimum margin values from the currently
selected printer properties. Windows only. Units are in millimetres 
	 * \param bool  
	*/

  void SetDefaultMinMargins(bool  flag ) ;
	/**
	 * \brief Sets the left (x) and top (y) margins in millimetres. 
	 * \param const wxPoint&   
	*/

  void SetMarginTopLeft(const wxPoint&  pt ) ;
	/**
	 * \brief Sets the right (x) and bottom (y) margins in millimetres. 
	 * \param const wxPoint&   
	*/

  void SetMarginBottomRight(const wxPoint&  pt ) ;
	/**
	 * \brief Sets the left (x) and top (y) minimum margins the user can enter (Windows only). Units are
in millimetres. 
	 * \param const wxPoint&   
	*/

  void SetMinMarginTopLeft(const wxPoint&  pt ) ;
	/**
	 * \brief Sets the right (x) and bottom (y) minimum margins the user can enter (Windows only). Units are
in millimetres. 
	 * \param const wxPoint&   
	*/

  void SetMinMarginBottomRight(const wxPoint&  pt ) ;
	/**
	 * \brief Sets the paper size id. For further information, see  .

Calling this function overrides the explicit paper dimensions passed in  . 
	 * \param wxPaperSize&   
	*/

  void SetPaperId(wxPaperSize&  id ) ;
	/**
	 * \brief Sets the paper size in millimetres. If a corresponding paper id is found, it will be set in the
internal wxPrintData object, otherwise the paper size overrides the paper id. 
	 * \param const wxSize&   
	*/

  void SetPaperSize(const wxSize&  size ) ;
	/**
	 * \brief Sets the   associated with this object. 
	 * \param const wxPrintData&  
	*/

  void SetPrintData(const wxPrintData&  printData ) ;
};


#endif
