// wxClipboard.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxClipboard_h_)
#define _wxClipboard_h_
class wxClipboard : public wxObject
{
public:
	/**
	 * \brief Constructor. 
	*/

   wxClipboard() ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxClipboard() ;
	/**
	 * \brief Call this function to add the data object to the clipboard. You may call
this function repeatedly after having cleared the clipboard using  .

After this function has been called, the clipboard owns the data, so do not delete
the data explicitly. 
	 * \param wxDataObject*  
	*/

  bool AddData(wxDataObject*  data ) ;
	/**
	 * \brief Clears the global clipboard object and the system's clipboard if possible. 
	*/

  void Clear() ;
	/**
	 * \brief Call this function to close the clipboard, having opened it with  . 
	*/

  void Close() ;
	/**
	 * \brief Flushes the clipboard: this means that the data which is currently on
clipboard will stay available even after the application exits (possibly
eating memory), otherwise the clipboard will be emptied on exit.
Returns false if the operation is unsuccesful for any reason. 
	*/

  bool Flush() ;
	/**
	 * \brief Call this function to fill   with data on the clipboard, if available in the required
format. Returns true on success. 
	 * \param wxDataObject&  
	*/

  bool GetData(wxDataObject&  data ) ;
	/**
	 * \brief Returns true if the clipboard has been opened. 
	*/

  bool IsOpened() const;
	/**
	 * \brief Returns true if the format of the given data object is available on the clipboard. 
	 * \param const wxDataFormat&  
	*/

  bool IsSupported(const wxDataFormat&  format ) ;
	/**
	 * \brief Call this function to open the clipboard before calling   
and  .

Call   when you have finished with the clipboard. You
should keep the clipboard open for only a very short time.

Returns true on success. This should be tested (as in the sample shown above). 
	*/

  bool Open() ;
	/**
	 * \brief Call this function to set the data object to the clipboard. This function will
clear all previous contents in the clipboard, so calling it several times
does not make any sense.

After this function has been called, the clipboard owns the data, so do not delete
the data explicitly. 
	 * \param wxDataObject*  
	*/

  bool SetData(wxDataObject*  data ) ;
	/**
	 * \brief On platforms supporting it (currently only GTK), selects the so called
PRIMARY SELECTION as the clipboard as opposed to the normal clipboard,
if   is true. 
	 * \param bool  
	*/

  void UsePrimarySelection(bool primary = true) ;
};


#endif
