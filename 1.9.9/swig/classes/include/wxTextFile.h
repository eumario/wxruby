// wxTextFile.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTextFile_h_)
#define _wxTextFile_h_
class wxTextFile
{
public:
	/**
	 * \brief Default constructor, use   or 
  with a file name parameter to initialize the object. 
	*/

   wxTextFile() const;
	/**
	 * \brief Constructor does not load the file into memory, use Open() to do it. 
	 * \param const wxString&   
	*/

   wxTextFile(const wxString&  strFile ) const;
	/**
	 * \brief Destructor does nothing. 
	*/

  virtual  ~wxTextFile() const;
	/**
	 * \brief Adds a line to the end of file. 
	 * \param const wxString&   
	 * \param wxTextFileType   
	*/

  void AddLine(const wxString&  str , wxTextFileType  type = typeDefault) const;
	/**
	 * \brief Closes the file and frees memory,  . Use   
if you want to save them. 
	*/

  bool Close() const;
	/**
	 * \brief  
	*/

  bool Create() const;
	/**
	 * \brief Creates the file with the given name or the name which was given in the
 . The array of file lines is initially
empty.

It will fail if the file already exists,   should
be used in this case. 
	 * \param const wxString&   
	*/

  bool Create(const wxString&  strFile ) const;
	/**
	 * \brief Return true if file exists - the name of the file should have been specified
in the constructor before calling Exists(). 
	*/

  bool Exists() const;
	/**
	 * \brief Returns true if the file is currently opened. 
	*/

  bool IsOpened() const;
	/**
	 * \brief Get the number of lines in the file. 
	*/

  size_t GetLineCount() const;
	/**
	 * \brief Retrieves the line number   from the file. The returned line may be
modified but you shouldn't add line terminator at the end - this will be done
by wxTextFile. 
	 * \param size_t   
	*/

  wxString& GetLine(size_t  n ) const;
	/**
	 * \brief Returns the current line: it has meaning only when you're using
GetFirstLine()/GetNextLine() functions, it doesn't get updated when
you're using &quot;direct access&quot; functions like GetLine(). GetFirstLine() and
GetLastLine() also change the value of the current line, as well as
GoToLine(). 
	*/

  size_t GetCurrentLine() const;
	/**
	 * \brief Changes the value returned by   
and used by  / . 
	 * \param size_t   
	*/

  void GoToLine(size_t  n ) const;
	/**
	 * \brief Returns true if the current line is the last one. 
	*/

  bool Eof() const;
	/**
	 * \brief Get the line termination string corresponding to given constant.   is
the value defined during the compilation and corresponds to the native format
of the platform, i.e. it will be wxTextFileType_Dos under Windows,
wxTextFileType_Unix under Unix (including Mac OS X when compiling with the
Apple Developer Tools) and wxTextFileType_Mac under Mac OS (including
Mac OS X when compiling with CodeWarrior). 
	 * \param wxTextFileType   
	*/

  static const char* GetEOL(wxTextFileType  type = typeDefault) const;
	/**
	 * \brief This method together with   
allows more &quot;iterator-like&quot; traversal of the list of lines, i.e. you may
write something like: 
	*/

  wxString& GetFirstLine() const;
	/**
	 * \brief Gets the next line (see   for 
the example). 
	*/

  wxString& GetNextLine() ;
	/**
	 * \brief Gets the previous line in the file. 
	*/

  wxString& GetPrevLine() ;
	/**
	 * \brief Gets the last line of the file. Together with 
  it allows to enumerate the lines
in the file from the end to the beginning like this: 
	*/

  wxString& GetLastLine() ;
	/**
	 * \brief Get the type of the line (see also  ) 
	 * \param size_t   
	*/

  wxTextFileType GetLineType(size_t  n ) const;
	/**
	 * \brief Guess the type of file (which is supposed to be opened). If sufficiently
many lines of the file are in DOS/Unix/Mac format, the corresponding value will
be returned. If the detection mechanism fails wxTextFileType_None is returned. 
	*/

  wxTextFileType GuessType() const;
	/**
	 * \brief Get the name of the file. 
	*/

  const char* GetName() const;
	/**
	 * \brief Insert a line before the line number  . 
	 * \param const wxString&   
	 * \param size_t   
	 * \param wxTextFileType   
	*/

  void InsertLine(const wxString&  str , size_t  n , wxTextFileType  type = typeDefault) const;
	/**
	 * \brief  
	 * \param wxMBConv&  
	*/

  bool Open(wxMBConv& conv = wxConvUTF8) const;
	/**
	 * \brief Open() opens the file with the given name or the name which was given in the
  and also loads file in memory on
success. It will fail if the file does not exist, 
  should be used in this case.

The   argument is only meaningful in Unicode build of wxWindows when
it is used to convert the file to wide character representation. 
	 * \param const wxString&   
	 * \param wxMBConv&  
	*/

  bool Open(const wxString&  strFile , wxMBConv& conv = wxConvUTF8) const;
	/**
	 * \brief Delete line number   from the file. 
	 * \param size_t   
	*/

  void RemoveLine(size_t  n ) const;
	/**
	 * \brief Delete all lines from the file, set current line number to 0. 
	*/

  void Clear() const;
	/**
	 * \brief Change the file on disk. The   parameter allows you to change the
file format (default argument means &quot;don't change type&quot;) and may be used to
convert, for example, DOS files to Unix.

The   argument is only meaningful in Unicode build of wxWindows when
it is used to convert all lines to multibyte representation before writing them
them to physical file.

Returns true if operation succeeded, false if it failed. 
	 * \param wxTextFileType   
	 * \param wxMBConv&  
	*/

  bool Write(wxTextFileType  typeNew = wxTextFileType_None, wxMBConv& conv = wxConvUTF8) const;
};


#endif
