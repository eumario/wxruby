// wxPrintData.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPrintData_h_)
#define _wxPrintData_h_
class wxPrintData : public wxObject
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxPrintData() ;
	/**
	 * \brief Copy constructor. 
	 * \param const wxPrintData&  
	*/

   wxPrintData(const wxPrintData&  data ) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxPrintData() ;
	/**
	 * \brief Returns true if collation is on. 
	*/

  bool GetCollate() const;
	/**
	 * \brief Returns true if colour printing is on. 
	*/

  bool GetColour() const;
	/**
	 * \brief Returns the duplex mode. One of wxDUPLEX_SIMPLEX, wxDUPLEX_HORIZONTAL, wxDUPLEX_VERTICAL. 
	*/

  wxDuplexMode GetDuplex() const;
	/**
	 * \brief Returns the number of copies requested by the user. 
	*/

  int GetNoCopies() const;
	/**
	 * \brief Gets the orientation. This can be wxLANDSCAPE or wxPORTRAIT. 
	*/

  int GetOrientation() const;
	/**
	 * \brief Returns the paper size id. For more information, see  . 
	*/

  wxPaperSize GetPaperId() const;
	/**
	 * \brief Returns the printer name. If the printer name is the empty string, it indicates that the default
printer should be used. 
	*/

  const wxString& GetPrinterName() const;
	/**
	 * \brief Returns the current print quality. This can be a positive integer, denoting the number of dots per inch, or
one of the following identifiers:

 

On input you should pass one of these identifiers, but on return you may get back a positive integer
indicating the current resolution setting. 
	*/

  wxPrintQuality GetQuality() const;
	/**
	 * \brief Returns true if the print data is valid for using in print dialogs.
This can return false on Windows if the current printer is not set, for example.
On all other platforms, it returns true. 
	*/

  bool Ok() const;
	/**
	 * \brief Sets collation to on or off. 
	 * \param bool   
	*/

  void SetCollate(bool  flag ) ;
	/**
	 * \brief Sets colour printing on or off. 
	 * \param bool   
	*/

  void SetColour(bool  flag ) ;
	/**
	 * \brief Returns the duplex mode. One of wxDUPLEX_SIMPLEX, wxDUPLEX_HORIZONTAL, wxDUPLEX_VERTICAL. 
	 * \param wxDuplexMode  
	*/

  void SetDuplex(wxDuplexMode  mode ) ;
	/**
	 * \brief Sets the default number of copies to be printed out. 
	 * \param int   
	*/

  void SetNoCopies(int  n ) ;
	/**
	 * \brief Sets the orientation. This can be wxLANDSCAPE or wxPORTRAIT. 
	 * \param int   
	*/

  void SetOrientation(int  orientation ) ;
	/**
	 * \brief \index{wxPaperSize}Sets the paper id. This indicates the type of paper to be used. For a mapping between
paper id, paper size and string name, see wxPrintPaperDatabase in   (not yet documented).

  can be one of: 
	 * \param wxPaperSize  
	*/

  void SetPaperId(wxPaperSize  paperId ) ;
	/**
	 * \brief Sets the printer name. This can be the empty string to indicate that the default
printer should be used. 
	 * \param const wxString&   
	*/

  void SetPrinterName(const wxString&  printerName ) ;
	/**
	 * \brief Sets the desired print quality. This can be a positive integer, denoting the number of dots per inch, or
one of the following identifiers:

 

On input you should pass one of these identifiers, but on return you may get back a positive integer
indicating the current resolution setting. 
	 * \param wxPrintQuality  
	*/

  void SetQuality(wxPrintQuality  quality ) ;
};


#endif
