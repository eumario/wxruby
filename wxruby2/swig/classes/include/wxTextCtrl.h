// wxTextCtrl.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTextCtrl_h_)
#define _wxTextCtrl_h_
class wxTextCtrl : public wxControl
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxTextCtrl() ;
	/**
	 * \brief  
	 * \param wxWindow*   
	 * \param wxWindowID  
	 * \param const wxString&   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

   wxTextCtrl(wxWindow*  parent , wxWindowID  id , const wxString&  value = wxT(""), const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxTextCtrlNameStr) ;
	/**
	 * \brief Destructor, destroying the text control. 
	*/

  virtual  ~wxTextCtrl() ;
	/**
	 * \brief Appends the text to the end of the text control. 
	 * \param const wxString&   
	*/

  void AppendText(const wxString&   text ) ;
	/**
	 * \brief Returns   if the selection can be copied to the clipboard. 
	*/

  virtual bool CanCopy() ;
	/**
	 * \brief Returns   if the selection can be cut to the clipboard. 
	*/

  virtual bool CanCut() ;
	/**
	 * \brief Returns   if the contents of the clipboard can be pasted into the
text control. On some platforms (Motif, GTK) this is an approximation
and returns   if the control is editable,   otherwise. 
	*/

  virtual bool CanPaste() ;
	/**
	 * \brief Returns   if there is a redo facility available and the last operation
can be redone. 
	*/

  virtual bool CanRedo() ;
	/**
	 * \brief Returns   if there is an undo facility available and the last operation
can be undone. 
	*/

  virtual bool CanUndo() ;
	/**
	 * \brief Clears the text in the control.

Note that this function will generate a  
event. 
	*/

  virtual void Clear() ;
	/**
	 * \brief Copies the selected text to the clipboard under Motif and MS Windows. 
	*/

  virtual void Copy() ;
	/**
	 * \brief Creates the text control for two-step construction. Derived classes
should call or replace this function. See  
for further details. 
	 * \param wxWindow*   
	 * \param wxWindowID  
	 * \param const wxString&   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  value = wxT(""), const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxTextCtrlNameStr) ;
	/**
	 * \brief Copies the selected text to the clipboard and removes the selection. 
	*/

  virtual void Cut() ;
	/**
	 * \brief Resets the internal `modified' flag as if the current edits had been saved. 
	*/

  void DiscardEdits() ;
	/**
	 * \brief This functions inserts into the control the character which would have been
inserted if the given key event had occured in the text control. The 
  object should be the same as the one passed to  
handler previously by wxWindows.

Please note that this function doesn't currently work correctly for all keys
under any platform but MSW. 
	 * \param const wxKeyEvent&   
	*/

  bool EmulateKeyPress(const wxKeyEvent&  event ) ;
	/**
	 * \brief Returns the style currently used for the new text. 
	*/

  const wxTextAttr&  GetDefaultStyle() const;
	/**
	 * \brief Returns the insertion point. This is defined as the zero based index of the
character position to the right of the insertion point. For example, if
the insertion point is at the end of the text control, it is equal to
both  .Length() and
 .

The following code snippet safely returns the character at the insertion
point or the zero character if the point is at the end of the control. 
	*/

  virtual long GetInsertionPoint() const;
	/**
	 * \brief Returns the zero based index of the last position in the text control,
which is equal to the number of characters in the control. 
	*/

  virtual long GetLastPosition() const;
	/**
	 * \brief Gets the length of the specified line, not including any trailing newline
character(s). 
	 * \param long  
	*/

  int GetLineLength(long  lineNo ) const;
	/**
	 * \brief Returns the contents of a given line in the text control, not including
any trailing newline character(s). 
	 * \param long  
	*/

  wxString GetLineText(long  lineNo ) const;
	/**
	 * \brief Returns the number of lines in the text control buffer. 
	*/

  int GetNumberOfLines() const;
	/**
	 * \brief Returns the string containing the text staring in the positions   and
up to   in the control. The positions must have been returned by another
wxTextCtrl method.

Please note that the positions in a multiline wxTextCtrl do  
correspond to the indices in the string returned by 
  because of the different new line
representations (  or  ) and so this method should be used to
obtain the correct results instead of extracting parts of the entire value. It
may also be more efficient, especially if the control contains a lot of data. 
	 * \param long  
	 * \param long  
	*/

  virtual wxString GetRange(long  from , long  to ) const;
	/**
	 * \brief Gets the current selection span. If the returned values are equal, there was
no selection.

Please note that the indices returned may be used with the other wxTextctrl
methods but don't necessarily represent the correct indices into the string
returned by   for multiline controls
under Windows (at least,) you should use
  to get the selected
text.







\pythonnote{The wxPython version of this method returns a tuple
consisting of the from and to values.}

\perlnote{In wxPerl this method takes no parameter and returns a
2-element list  .} 
	 * \param long*  
	 * \param long*  
	*/

  virtual void GetSelection(long*  from , long*  to ) const;
	/**
	 * \brief Gets the text currently selected in the control. If there is no selection, the
returned string is empty. 
	*/

  virtual wxString GetStringSelection() ;
	/**
	 * \brief  
	 * \param long   
	 * \param wxTextAttr&   
	*/

  bool GetStyle(long  position , wxTextAttr&  style ) ;
	/**
	 * \brief Gets the contents of the control. Notice that for a multiline text control,
the lines will be separated by (Unix-style) $\backslash$n characters, even
under Windows where they are separated by a $\backslash$r$\backslash$n
sequence in the native control. 
	*/

  wxString GetValue() const;
	/**
	 * \brief Returns   if the controls contents may be edited by user (note that it
always can be changed by the program), i.e. if the control hasn't been put in
read-only mode by a previous call to 
 . 
	*/

  bool IsEditable() const;
	/**
	 * \brief Returns   if the text has been modified by user. Note that calling 
  doesn't make the control modified. 
	*/

  bool IsModified() const;
	/**
	 * \brief Returns   if this is a multi line edit control and  
otherwise. 
	*/

  bool IsMultiLine() const;
	/**
	 * \brief Returns   if this is a single line edit control and  
otherwise. 
	*/

  bool IsSingleLine() const;
	/**
	 * \brief Loads and displays the named file, if it exists. 
	 * \param const wxString&   
	*/

  bool LoadFile(const wxString&   filename ) ;
	/**
	 * \brief This event handler function implements default drag and drop behaviour, which
is to load the first dropped file into the control. 
	 * \param wxDropFilesEvent&   
	*/

  virtual void OnDropFiles(wxDropFilesEvent&  event ) ;
	/**
	 * \brief Pastes text from the clipboard to the text item. 
	*/

  virtual void Paste() ;
	/**
	 * \brief  
	 * \param long   
	 * \param long *  
	 * \param long *  
	*/

  bool PositionToXY(long  pos , long * x , long * y ) const;
	/**
	 * \brief If there is a redo facility and the last operation can be redone, redoes the last operation. Does nothing
if there is no redo facility. 
	*/

  virtual void Redo() ;
	/**
	 * \brief Removes the text starting at the first given position up to (but not including)
the character at the last position. 
	 * \param long  
	 * \param long  
	*/

  virtual void Remove(long  from , long  to ) ;
	/**
	 * \brief Replaces the text starting at the first position up to (but not including)
the character at the last position with the given text. 
	 * \param long  
	 * \param long  
	 * \param const wxString&   
	*/

  virtual void Replace(long  from , long  to , const wxString&  value ) ;
	/**
	 * \brief Saves the contents of the control in a text file. 
	 * \param const wxString&   
	*/

  bool SaveFile(const wxString&   filename ) ;
	/**
	 * \brief Changes the default style to use for the new text which is going to be added
to the control using   or
 .

If either of the font, foreground, or background colour is not set in
 , the values of the previous default style are used for them. If
the previous default style didn't set them neither, the global font or colours
of the text control itself are used as fall back.

However if the   parameter is the default wxTextAttr, then the
default style is just reset (instead of being combined with the new style which
wouldn't change it at all). 
	 * \param const wxTextAttr&   
	*/

  bool SetDefaultStyle(const wxTextAttr&  style ) ;
	/**
	 * \brief Makes the text item editable or read-only, overriding the   flag. 
	 * \param const bool  
	*/

  virtual void SetEditable(const bool  editable ) ;
	/**
	 * \brief Sets the insertion point at the given position. 
	 * \param long  
	*/

  virtual void SetInsertionPoint(long  pos ) ;
	/**
	 * \brief Sets the insertion point at the end of the text control. This is equivalent
to  ( ()). 
	*/

  virtual void SetInsertionPointEnd() ;
	/**
	 * \brief This function sets the maximum number of characters the user can enter into the
control. In other words, it allows to limit the text value length to  
not counting the terminating   character.

If   is 0, the previously set max length limit, if any, is discarded
and the user may enter as much text as the underlying native text control
widget supports (typically at least 32Kb).

If the user tries to enter more characters into the text control when it
already is filled up to the maximal length, a
  event is sent to notify the program about it
(giving it the possibility to show an explanatory message, for example) and the
extra input is discarded.

Note that this function may only be used with single line text controls.

\wxheading{Compatibility}

Only implemented in wxMSW/wxGTK starting with wxWindows 2.3.2. 
	 * \param unsigned long   
	*/

  virtual void SetMaxLength(unsigned long  len ) ;
	/**
	 * \brief Selects the text starting at the first position up to (but not including) the
character at the last position. If both parameters are equal to $-1$ all text
in the control is selected. 
	 * \param long  
	 * \param long  
	*/

  virtual void SetSelection(long  from , long  to ) ;
	/**
	 * \brief  
	 * \param long   
	 * \param long   
	 * \param const wxTextAttr&   
	*/

  bool SetStyle(long  start , long  end , const wxTextAttr&  style ) ;
	/**
	 * \brief Sets the text value and marks the control as not-modified (which means that 
  would return   immediately
after the call to SetValue).

Note that this function will generate a  
event. 
	 * \param const wxString&   
	*/

  virtual void SetValue(const wxString&   value ) ;
	/**
	 * \brief Makes the line containing the given position visible. 
	 * \param long  
	*/

  void ShowPosition(long  pos ) ;
	/**
	 * \brief If there is an undo facility and the last operation can be undone, undoes the last operation. Does nothing
if there is no undo facility. 
	*/

  virtual void Undo() ;
	/**
	 * \brief Writes the text into the text control at the current insertion position. 
	 * \param const wxString&   
	*/

  void WriteText(const wxString&   text ) ;
	/**
	 * \brief Converts the given zero based column and line number to a position. 
	 * \param long  
	 * \param long  
	*/

  long XYToPosition(long  x , long  y ) ;
  // the following were missing from the xml
  wxTextCtrl & operator<<(const char *);
  wxTextCtrl & operator<<(int);
  wxTextCtrl & operator<<(double);
  wxTextCtrl & operator<<(bool);
};


#endif
