// wxCmdLineParser.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCmdLineParser_h_)
#define _wxCmdLineParser_h_
class wxCmdLineParser
{
public:
	/**
	 * \brief Default constructor. You must use 
  later. 
	*/

   wxCmdLineParser() ;
	/**
	 * \brief Constructor specifies the command line to parse. This is the traditional
(Unix) command line format. The parameters   and   have the
same meaning as for   function. 
	 * \param int   
	 * \param char**   
	*/

   wxCmdLineParser(int  argc , char**  argv ) ;
	/**
	 * \brief Constructor specifies the command line to parse in Windows format. The parameter 
  has the same meaning as the corresponding parameter of 
 . 
	 * \param const wxString&   
	*/

   wxCmdLineParser(const wxString&  cmdline ) ;
	/**
	 * \brief Same as  , but also
specifies the  . 
	 * \param const wxCmdLineEntryDesc*   
	*/

   wxCmdLineParser(const wxCmdLineEntryDesc*  desc ) ;
	/**
	 * \brief Same as  , but also
specifies the  . 
	 * \param const wxCmdLineEntryDesc*   
	 * \param int   
	 * \param char**   
	*/

   wxCmdLineParser(const wxCmdLineEntryDesc*  desc , int  argc , char**  argv ) ;
	/**
	 * \brief Same as  , but also
specifies the  . 
	 * \param const wxCmdLineEntryDesc*   
	 * \param const wxString&   
	*/

   wxCmdLineParser(const wxCmdLineEntryDesc*  desc , const wxString&  cmdline ) ;
	/**
	 * \brief Breaks down the string containing the full command line in words. The words are
separated by whitespace. The quotes can be used in the input string to quote
the white space and the back slashes can be used to quote the quotes. 
	 * \param const wxChar   
	*/

  static wxArrayString ConvertStringToArgs(const wxChar  *cmdline ) ;
	/**
	 * \brief Set command line to parse after using one of the constructors which don't do it. 
	 * \param int   
	 * \param char**   
	*/

  void SetCmdLine(int  argc , char**  argv ) ;
	/**
	 * \brief Set command line to parse after using one of the constructors which don't do it. 
	 * \param const wxString&   
	*/

  void SetCmdLine(const wxString&  cmdline ) ;
	/**
	 * \brief Frees resources allocated by the object.

  destructor is not virtual, don't use this class polymorphically. 
	*/

  virtual  ~wxCmdLineParser() ;
	/**
	 * \brief contains all characters with which an option or switch may
start. Default is   for Unix,   for Windows. 
	 * \param const wxString&   
	*/

  void SetSwitchChars(const wxString&  switchChars ) ;
	/**
	 * \brief Enable or disable support for the long options.

As long options are not (yet) POSIX-compliant, this option allows to disable
them. 
	 * \param bool   
	*/

  void EnableLongOptions(bool  enable = true) ;
	/**
	 * \brief Identical to  . 
	*/

  void DisableLongOptions() ;
	/**
	 * \brief Returns true if long options are enabled, otherwise false. 
	*/

  bool AreLongOptionsEnabled() ;
	/**
	 * \brief is some extra text which will be shown by 
  method. 
	 * \param const wxString&   
	*/

  void SetLogo(const wxString&  logo ) ;
	/**
	 * \brief Construct the command line description

Take the command line description from the wxCMD_LINE_NONE terminated table.

Example of usage: 
	 * \param const wxCmdLineEntryDesc*   
	*/

  void SetDesc(const wxCmdLineEntryDesc*  desc ) ;
	/**
	 * \brief Add a switch   with an optional long name   (no long name if it
is empty, which is default), description   and flags   to the
command line description. 
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param int   
	*/

  void AddSwitch(const wxString&  name , const wxString&  lng = wxEmptyString, const wxString&  desc = wxEmptyString, int  flags = 0) ;
	/**
	 * \brief Add an option   with an optional long name   (no long name if
it is empty, which is default) taking a value of the given type (string by
default) to the command line description. 
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param wxCmdLineParamType   
	 * \param int   
	*/

  void AddOption(const wxString&  name , const wxString&  lng = wxEmptyString, const wxString&  desc = wxEmptyString, wxCmdLineParamType  type = wxCMD_LINE_VAL_STRING, int  flags = 0) ;
	/**
	 * \brief Add a parameter of the given   to the command line description. 
	 * \param const wxString&   
	 * \param wxCmdLineParamType   
	 * \param int   
	*/

  void AddParam(const wxString&  desc = wxEmptyString, wxCmdLineParamType  type = wxCMD_LINE_VAL_STRING, int  flags = 0) ;
	/**
	 * \brief Parse the command line, return 0 if ok, $-1$ if   or   
option was encountered and the help message was given or a positive value if a
syntax error occured. 
	 * \param bool   
	*/

  int Parse(bool  giveUsage = true) ;
	/**
	 * \brief Give the standard usage message describing all program options. It will use the
options and parameters descriptions specified earlier, so the resulting message
will not be helpful to the user unless the descriptions were indeed specified. 
	*/

  void Usage() ;
	/**
	 * \brief Returns true if the given switch was found, false otherwise. 
	 * \param const wxString&   
	*/

  bool Found(const wxString&  name ) const;
	/**
	 * \brief Returns true if an option taking a string value was found and stores the
value in the provided pointer (which should not be NULL). 
	 * \param const wxString&   
	 * \param wxString*   
	*/

  bool Found(const wxString&  name , wxString*  value ) const;
	/**
	 * \brief Returns true if an option taking an integer value was found and stores
the value in the provided pointer (which should not be NULL). 
	 * \param const wxString&   
	 * \param long*   
	*/

  bool Found(const wxString&  name , long*  value ) const;
	/**
	 * \brief Returns true if an option taking a date value was found and stores the
value in the provided pointer (which should not be NULL). 
	 * \param const wxString&   
	 * \param wxDateTime*   
	*/

  bool Found(const wxString&  name , wxDateTime*  value ) const;
	/**
	 * \brief Returns the number of parameters found. This function makes sense mostly if you
had used   flag. 
	*/

  size_t GetParamCount() const;
	/**
	 * \brief Returns the value of Nth parameter (as string only for now). 
	 * \param size_t   
	*/

  wxString GetParam(size_t  n = 0u) const;
};


#endif
