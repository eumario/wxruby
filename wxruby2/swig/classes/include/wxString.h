// wxString.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxString_h_)
#define _wxString_h_
class wxString
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxString() ;
	/**
	 * \brief Copy constructor. 
	 * \param const wxString&  
	*/

   wxString(const wxString&  x ) ;
	/**
	 * \brief Constructs a string of   copies of character  . 
	 * \param char  
	 * \param size_t  
	*/

   wxString(char  ch , size_t n = 1) ;
	/**
	 * \brief Takes first   characters from the C string  .
The default value of wxSTRING_MAXLEN means to take all the string.

Note that this constructor may be used even if   points to a buffer
with binary data (i.e. containing   characters) as long as you provide
the correct value for  . However, the default form of it works
only with strings without intermediate  s because it uses 
  to calculate the effective length and it would not give correct
results otherwise. 
	 * \param const char*  
	 * \param size_t  
	*/

   wxString(const char*  psz , size_t nLength = wxSTRING_MAXLEN) ;
	/**
	 * \brief For compilers using unsigned char: takes first   characters from the C string  .
The default value of wxSTRING_MAXLEN means take all the string. 
	 * \param const unsigned char*  
	 * \param size_t  
	*/

   wxString(const unsigned char*  psz , size_t nLength = wxSTRING_MAXLEN) ;
	/**
	 * \brief Constructs a string from the wide (UNICODE) string. 
	 * \param const wchar_t*  
	*/

   wxString(const wchar_t*  psz ) ;
	/**
	 * \brief String destructor. Note that this is not virtual, so wxString must not be inherited from. 
	*/

  virtual  ~wxString() ;
	/**
	 * \brief Preallocate enough space for wxString to store   characters. This function
may be used to increase speed when the string is constructed by repeated
concatenation as in

 

because it will avoid the need of reallocating string memory many times (in case
of long strings). Note that it does not set the maximal length of a string - it
will still expand if more than   characters are stored in it. Also, it
does not truncate the existing string (use 
  for this) even if its current length is
greater than 
	 * \param size_t  
	*/

  void Alloc(size_t  nLen ) ;
	/**
	 * \brief Concatenates   to this string, returning a reference to it. 
	 * \param const char*  
	*/

  wxString& Append(const char*  psz ) ;
	/**
	 * \brief Concatenates character   to this string,   times, returning a reference
to it. 
	 * \param char  
	 * \param int  
	*/

  wxString& Append(char  ch , int count = 1) ;
	/**
	 * \brief Gets all the characters after the first occurrence of  .
Returns the empty string if   is not found. 
	 * \param char  
	*/

  wxString AfterFirst(char  ch ) const;
	/**
	 * \brief Gets all the characters after the last occurrence of  .
Returns the whole string if   is not found. 
	 * \param char  
	*/

  wxString AfterLast(char  ch ) const;
	/**
	 * \brief Gets all characters before the first occurrence of  .
Returns the whole string if   is not found. 
	 * \param char  
	*/

  wxString BeforeFirst(char  ch ) const;
	/**
	 * \brief Gets all characters before the last occurrence of  .
Returns the empty string if   is not found. 
	 * \param char  
	*/

  wxString BeforeLast(char  ch ) const;
	/**
	 * \brief Returns a pointer to the string data. 
	*/

  const char * c_str() const;
	/**
	 * \brief Empties the string and frees memory occupied by it.

See also: 
	*/

  void Clear() ;
	/**
	 * \brief Case-sensitive comparison.

Returns a positive value if the string is greater than the argument, zero if
it is equal to it or a negative value if it is less than the argument (same semantics
as the standard   function).

See also  ,  . 
	 * \param const char*  
	*/

  int Cmp(const char*  psz ) const;
	/**
	 * \brief Case-insensitive comparison.

Returns a positive value if the string is greater than the argument, zero if
it is equal to it or a negative value if it is less than the argument (same semantics
as the standard   function).

See also  ,  . 
	 * \param const char*  
	*/

  int CmpNoCase(const char*  psz ) const;
	/**
	 * \brief Case-sensitive comparison. Returns 0 if equal, 1 if greater or -1 if less. 
	 * \param const char*  
	 * \param caseCompare  
	*/

  int CompareTo(const char*  psz , caseCompare cmp = exact) const;
	/**
	 * \brief Returns 1 if target appears anyhere in wxString; else 0. 
	 * \param const wxString&  
	*/

  bool Contains(const wxString&  str ) const;
	/**
	 * \brief Makes the string empty, but doesn't free memory occupied by the string.

See also:  . 
	*/

  void Empty() ;
	/**
	 * \brief Searches for the given character. Returns the starting index, or -1 if not found. 
	 * \param char  
	 * \param bool  
	*/

  int Find(char  ch , bool fromEnd = false) const;
	/**
	 * \brief Searches for the given string. Returns the starting index, or -1 if not found. 
	 * \param const char*  
	*/

  int Find(const char*  sz ) const;
	/**
	 * \brief  
	 * \param char  
	*/

  int First(char  c ) ;
	/**
	 * \brief  
	 * \param const char*  
	*/

  int First(const char*  psz ) const;
	/**
	 * \brief Same as  . 
	 * \param const wxString&  
	*/

  int First(const wxString&  str ) const;
	/**
	 * \brief  
	 * \param const wxChar   
	 * \param   
	*/

  static wxString Format(const wxChar  *format ,  ... ) ;
	/**
	 * \brief  
	 * \param const wxChar   
	 * \param va_list   
	*/

  static wxString FormatV(const wxChar  *format , va_list  argptr ) ;
	/**
	 * \brief Returns the number of occurrences of   in the string. 
	 * \param char   
	*/

  int Freq(char  ch ) const;
	/**
	 * \brief Returns the character at position   (read-only). 
	 * \param size_t  
	*/

  char GetChar(size_t  n ) const;
	/**
	 * \brief wxWindows compatibility conversion. Returns a constant pointer to the data in the string. 
	*/

  const char* GetData() const;
	/**
	 * \brief Returns a reference to the character at position  . 
	 * \param size_t  
	*/

  char& GetWritableChar(size_t  n ) ;
	/**
	 * \brief Returns a writable buffer of at least   bytes.
It returns a pointer to a new memory block, and the
existing data will not be copied.

Call   as soon as possible
to put the string back into a reasonable state. 
	 * \param size_t  
	*/

  wxChar* GetWriteBuf(size_t  len ) ;
	/**
	 * \brief  
	 * \param char  
	*/

  size_t Index(char  ch ) const;
	/**
	 * \brief Same as  . 
	 * \param const char*  
	*/

  size_t Index(const char*  sz ) const;
	/**
	 * \brief Search the element in the array, starting from either side.

If   is true, reverse search direction.

If  , comparison is case sensitive (the default).

Returns the index of the first item matched, or wxNOT_FOUND. 
	 * \param const char*  
	 * \param bool  
	 * \param bool  
	*/

  size_t Index(const char*  sz , bool caseSensitive = true, bool fromEnd = false) const;
	/**
	 * \brief Returns true if the string contains only ASCII characters. 
	*/

  bool IsAscii() const;
	/**
	 * \brief Returns true if the string is empty. 
	*/

  bool IsEmpty() const;
	/**
	 * \brief Returns true if the string is empty (same as  ). 
	*/

  bool IsNull() const;
	/**
	 * \brief Returns true if the string is an integer (with possible sign). 
	*/

  bool IsNumber() const;
	/**
	 * \brief Test for string equality, case-sensitive (default) or not.

caseSensitive is true by default (case matters).

Returns true if strings are equal, false otherwise.

See also  ,  , 
	 * \param const char*  
	 * \param bool  
	*/

  bool IsSameAs(const char*  psz , bool caseSensitive = true) const;
	/**
	 * \brief Test whether the string is equal to the single character  . The test is
case-sensitive if   is true (default) or not if it is false.

Returns true if the string is equal to the character, false otherwise.

See also  ,  , 
	 * \param char  
	 * \param bool  
	*/

  bool IsSameAs(char  c , bool caseSensitive = true) const;
	/**
	 * \brief Returns true if the string is a word. TODO: what's the definition of a word? 
	*/

  bool IsWord() const;
	/**
	 * \brief Returns the last character. 
	*/

  char Last() const;
	/**
	 * \brief Returns a reference to the last character (writable). 
	*/

  char& Last() ;
	/**
	 * \brief Returns the first   characters of the string. 
	 * \param size_t  
	*/

  wxString Left(size_t  count ) const;
	/**
	 * \brief Returns the length of the string. 
	*/

  size_t Len() const;
	/**
	 * \brief Returns the length of the string (same as Len). 
	*/

  size_t Length() const;
	/**
	 * \brief Returns this string converted to the lower case. 
	*/

  wxString Lower() const;
	/**
	 * \brief Same as MakeLower. 
	*/

  void LowerCase() ;
	/**
	 * \brief Converts all characters to lower case and returns the result. 
	*/

  wxString& MakeLower() ;
	/**
	 * \brief Converts all characters to upper case and returns the result. 
	*/

  wxString& MakeUpper() ;
	/**
	 * \brief Returns true if the string contents matches a mask containing '&#42;' and '?'. 
	 * \param const char*  
	*/

  bool Matches(const char*  szMask ) const;
	/**
	 * \brief Returns a substring starting at  , with length  , or the rest of
the string if   is the default value. 
	 * \param size_t  
	 * \param size_t  
	*/

  wxString Mid(size_t  first , size_t count = wxSTRING_MAXLEN) const;
	/**
	 * \brief Adds   copies of   to the beginning, or to the end of the string (the default).

Removes spaces from the left or from the right (default). 
	 * \param size_t  
	 * \param char  
	 * \param bool  
	*/

  wxString& Pad(size_t  count , char pad = ', bool fromRight = true) ;
	/**
	 * \brief Prepends   to this string, returning a reference to this string. 
	 * \param const wxString&  
	*/

  wxString& Prepend(const wxString&  str ) ;
	/**
	 * \brief Similar to the standard function  . Returns the number of
characters written, or an integer less than zero on error.

  This function will use a safe version of   (usually called 
 ) whenever available to always allocate the buffer of correct
size. Unfortunately, this function is not available on all platforms and the
dangerous   will be used then which may lead to buffer overflows. 
	 * \param const char*   
	 * \param   
	*/

  int Printf(const char*  pszFormat ,  ... ) ;
	/**
	 * \brief Similar to vprintf. Returns the number of characters written, or an integer less than zero
on error. 
	 * \param const char*   
	 * \param va_list  
	*/

  int PrintfV(const char*  pszFormat , va_list  argPtr ) ;
	/**
	 * \brief Same as Truncate. Removes the portion from   to the end of the string. 
	 * \param size_t  
	*/

  wxString& Remove(size_t  pos ) ;
	/**
	 * \brief Removes the   characters from the string, starting at  . 
	 * \param size_t  
	 * \param size_t  
	*/

  wxString& Remove(size_t  pos , size_t  len ) ;
	/**
	 * \brief Removes the last character. 
	*/

  wxString& RemoveLast() ;
	/**
	 * \brief Replace first (or all) occurrences of substring with another one.

 : global replace (default), or only the first occurrence.

Returns the number of replacements made. 
	 * \param const char*  
	 * \param const char*  
	 * \param bool  
	*/

  size_t Replace(const char*  szOld , const char*  szNew , bool replaceAll = true) ;
	/**
	 * \brief Returns the last   characters. 
	 * \param size_t  
	*/

  wxString Right(size_t  count ) const;
	/**
	 * \brief Sets the character at position  . 
	 * \param size_t  
	 * \param char  
	*/

  void SetChar(size_t  n , char ch ) ;
	/**
	 * \brief Minimizes the string's memory. This can be useful after a call to 
  if too much memory were preallocated. 
	*/

  void Shrink() ;
	/**
	 * \brief The same as Printf. 
	 * \param const char*   
	*/

  void sprintf(const char*   fmt ) ;
	/**
	 * \brief This function can be used to test if the string starts with the specified 
 . If it does, the function will return   and put the rest
of the string (i.e. after the prefix) into   string if it is not 
 . Otherwise, the function returns   and doesn't modify the 
 . 
	 * \param const wxChar   
	 * \param wxString   
	*/

  bool StartsWith(const wxChar  *prefix , wxString  *rest = NULL) const;
	/**
	 * \brief Strip characters at the front and/or end. The same as Trim except that it
doesn't change this string. 
	 * \param stripType  
	*/

  wxString Strip(stripType s = trailing) const;
	/**
	 * \brief Deprecated, use   instead (but note that parameters
have different meaning).

Returns the part of the string between the indices   and  
inclusive. 
	 * \param size_t  
	 * \param size_t  
	*/

  wxString SubString(size_t  from , size_t  to ) const;
	/**
	 * \brief Attempts to convert the string to a floating point number. Returns true on
success (the number is stored in the location pointed to by  ) or false
if the string does not represent such number. 
	 * \param double  
	*/

  bool ToDouble(double  *val ) const;
	/**
	 * \brief Attempts to convert the string to a signed integer in base  . Returns
  on success in which case the number is stored in the location
pointed to by   or   if the string does not represent a
valid number in the given base.

The value of   must be comprised between 2 and 36, inclusive, or
be a special value 0 which means that the usual rules of   numbers are
applied: if the number starts with   it is considered to be in base
16, if it starts with   - in base 8 and in base 10 otherwise. Note
that you may not want to specify the base 0 if you are parsing the numbers
which may have leading zeroes as they can yield unexpected (to the user not
familiar with C) results. 
	 * \param long  
	 * \param int   
	*/

  bool ToLong(long  *val , int  base = 10) const;
	/**
	 * \brief Attempts to convert the string to a ansigned integer in base  .
Returns   on success in which case the number is stored in the
location pointed to by   or   if the string does not
represent a valid number in the given base.

See   for the more detailed
description of the   parameter. 
	 * \param unsigned long  
	 * \param int   
	*/

  bool ToULong(unsigned long  *val , int  base = 10) const;
	/**
	 * \brief Removes spaces from the left or from the right (default). 
	 * \param bool  
	*/

  wxString& Trim(bool fromRight = true) ;
	/**
	 * \brief Truncate the string to the given length. 
	 * \param size_t  
	*/

  wxString& Truncate(size_t  len ) ;
	/**
	 * \brief  
	*/

  void UngetWriteBuf() ;
	/**
	 * \brief Puts the string back into a reasonable state (in which it can be used
normally), after
  was called.

The version of the function without the   parameter will calculate the
new string length itself assuming that the string is terminated by the first
  character in it while the second one will use the specified length
and thus is the only version which should be used with the strings with
embedded  s (it is also slightly more efficient as   
doesn't have to be called). 
	 * \param size_t   
	*/

  void UngetWriteBuf(size_t  len ) ;
	/**
	 * \brief Returns this string converted to upper case. 
	*/

  wxString Upper() const;
	/**
	 * \brief The same as MakeUpper. 
	*/

  void UpperCase() ;
};


#endif
