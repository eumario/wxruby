// wxRegEx.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxRegEx_h_)
#define _wxRegEx_h_
class wxRegEx
{
public:
	/**
	 * \brief Default ctor: use   later. 
	*/

   wxRegEx() ;
	/**
	 * \brief Create and compile the regular expression, use 
  to test for compilation errors. 
	 * \param const wxString&   
	 * \param int   
	*/

   wxRegEx(const wxString&  expr , int  flags = wxRE_DEFAULT) ;
	/**
	 * \brief dtor not virtual, don't derive from this class 
	*/

  virtual  ~wxRegEx() ;
	/**
	 * \brief Compile the string into regular expression, return   if ok or   
if string has a syntax error. 
	 * \param const wxString&   
	 * \param int   
	*/

  bool Compile(const wxString&  pattern , int  flags = wxRE_DEFAULT) ;
	/**
	 * \brief Return   if this is a valid compiled regular expression,   
otherwise. 
	*/

  bool IsValid() const;
	/**
	 * \brief Get the start index and the length of the match of the expression
(if   is 0) or a bracketed subexpression (  different
from 0).

May only be called after successful call to   
and only if   was   used in 
 .

Returns   if no match or if an error occured. 
	 * \param size_t*   
	 * \param size_t*   
	 * \param size_t   
	*/

  bool GetMatch(size_t*  start , size_t*  len , size_t  index = 0) const;
	/**
	 * \brief Returns the part of string corresponding to the match where   is
interpreted as above. Empty string is returned if match failed

May only be called after successful call to   
and only if   was   used in 
 . 
	 * \param const wxString&   
	 * \param size_t   
	*/

  wxString GetMatch(const wxString&  text , size_t  index = 0) const;
	/**
	 * \brief Matches the precompiled regular expression against the string  ,
returns   if matches and   otherwise.

Flags may be combination of   and  .

May only be called after successful call to  . 
	 * \param const wxChar*   
	 * \param int   
	*/

  bool Matches(const wxChar*  text , int  flags = 0) const;
	/**
	 * \brief Replaces the current regular expression in the string pointed to by
 , with the text in   and return number of matches
replaced (maybe 0 if none found) or $-1$ on error.

The replacement text may contain back references   which will be
replaced with the value of the corresponding subexpression in the
pattern match.   corresponds to the entire match and   is a
synonym for it. Backslash may be used to quote itself or   character.

  may be used to limit the number of replacements made, setting
it to 1, for example, will only replace first occurrence (if any) of the
pattern in the text while default value of 0 means replace all. 
	 * \param wxString*   
	 * \param const wxString&   
	 * \param size_t   
	*/

  int Replace(wxString*  text , const wxString&  replacement , size_t  maxMatches = 0) const;
	/**
	 * \brief Replace all occurrences: this is actually a synonym for 
 . 
	 * \param wxString*   
	 * \param const wxString&   
	*/

  int ReplaceAll(wxString*  text , const wxString&  replacement ) const;
	/**
	 * \brief Replace the first occurrence. 
	 * \param wxString*   
	 * \param const wxString&   
	*/

  int ReplaceFirst(wxString*  text , const wxString&  replacement ) const;
};


#endif
