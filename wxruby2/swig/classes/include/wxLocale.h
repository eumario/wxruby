// wxLocale.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxLocale_h_)
#define _wxLocale_h_
class wxLocale
{
public:
	/**
	 * \brief This is the default constructor and it does nothing to initialize the object: 
  must be used to do that. 
	*/

   wxLocale() ;
	/**
	 * \brief See   for parameters description. 
	 * \param int   
	 * \param int   
	*/

   wxLocale(int  language , int  flags = wxLOCALE_LOAD_DEFAULT) ;
	/**
	 * \brief See   for parameters description.

The call of this function has several global side effects which you should
understand: first of all, the application locale is changed - note that this
will affect many of standard C library functions such as printf() or strftime().
Second, this wxLocale object becomes the new current global locale for the
application and so all subsequent calls to wxGetTranslation() will try to
translate the messages using the message catalogs for this locale. 
	 * \param const char   
	 * \param const char   
	 * \param const char   
	 * \param bool   
	 * \param bool   
	*/

   wxLocale(const char  *szName , const char  *szShort = NULL, const char  *szLocale = NULL, bool  bLoadDefault = true, bool  bConvertEncoding = false) ;
	/**
	 * \brief The destructor, like the constructor, also has global side effects: the previously
set locale is restored and so the changes described in 
  documentation are rolled back. 
	*/

  virtual  ~wxLocale() ;
	/**
	 * \brief Add a catalog for use with the current locale: it is searched for in standard
places (current directory first, then the system one), but you may also prepend
additional directories to the search path with 
 .

All loaded catalogs will be used for message lookup by GetString() for the
current locale.

Returns true if catalog was successfully loaded, false otherwise (which might
mean that the catalog is not found or that it isn't in the correct format). 
	 * \param const char   
	*/

  bool AddCatalog(const char  *szDomain ) ;
	/**
	 * \brief Add a prefix to the catalog lookup path: the message catalog files will be
looked up under prefix/&lt;lang&gt;/LC_MESSAGES, prefix/LC_MESSAGES and prefix
(in this order).

This only applies to subsequent invocations of AddCatalog()! 
	 * \param const wxString&   
	*/

  void AddCatalogLookupPathPrefix(const wxString&  prefix ) ;
	/**
	 * \brief Adds custom, user-defined language to the database of known languages. This
database is used in conjunction with the first form of 
 . 

wxLanguageInfo is defined as follows:

 


  should be greater than wxLANGUAGE_USER_DEFINED.

\perlnote{In wxPerl Wx::LanguageInfo has only one method:\par
Wx::LanguageInfo-&gt;new( language, canonicalName, WinLang, WinSubLang, Description )} 
	 * \param const wxLanguageInfo&   
	*/

  static void AddLanguage(const wxLanguageInfo&  info ) ;
	/**
	 * \brief This function may be used to find the language description structure for the
given locale, specified either as a two letter ISO language code (for example,
&quot;pt&quot;), a language code followed by the country code (&quot;pt_BR&quot;) or a full, human
readable, language description (&quot;Portuguese-Brazil&quot;).

Returns the information for the given language or   if this language
is unknown. Note that even if the returned pointer is valid, the caller should
  delete it. 
	 * \param const wxString&   
	*/

  static wxLanguageInfo * FindLanguageInfo(const wxString&  locale ) const;
	/**
	 * \brief Returns the canonical form of current locale name. Canonical form is the
one that is used on UNIX systems: it is a two- or five-letter string in xx or
xx_YY format, where xx is ISO 639 code of language and YY is ISO 3166 code of
the country. Examples are &quot;en&quot;, &quot;en_GB&quot;, &quot;en_US&quot; or &quot;fr_FR&quot;.

This form is internally used when looking up message catalogs.

Compare  . 
	*/

  wxString GetCanonicalName() const;
	/**
	 * \brief Returns   constant of current language.
Note that you can call this function only if you used the form of
  that takes wxLanguage argument. 
	*/

  int GetLanguage() const;
	/**
	 * \brief Returns a pointer to wxLanguageInfo structure containing information about the
given language or   if this language is unknown. Note that even if the
returned pointer is valid, the caller should   delete it.

See   for the wxLanguageInfo
description. 
	 * \param int   
	*/

  static wxLanguageInfo * GetLanguageInfo(int  lang ) const;
	/**
	 * \brief Returns English name of the given language or empty string if this
language is unknown. 
	 * \param int   
	*/

  static wxString GetLanguageName(int  lang ) const;
	/**
	 * \brief Returns the locale name as passed to the constructor or 
 . This is full, human-readable name,
e.g. &quot;English&quot; or &quot;French&quot;. 
	*/

  const char* GetLocale() const;
	/**
	 * \brief Returns the current short name for the locale (as given to the constructor or
the Init() function). 
	*/

  const wxString& GetName() const;
	/**
	 * \brief Retrieves the translation for a string in all loaded domains unless the szDomain
parameter is specified (and then only this catalog/domain is searched).

Returns original string if translation is not available
(in this case an error message is generated the first time
a string is not found; use   to suppress it). 
	 * \param const char   
	 * \param const char   
	*/

  const char* GetString(const char  *szOrigString , const char  *szDomain = NULL) const;
	/**
	 * \brief Returns current platform-specific locale name as passed to setlocale().

Compare  . 
	*/

  wxString GetSysName() const;
	/**
	 * \brief Tries to detect the user's default font encoding.
Returns   value or 
  if it couldn't be determined. 
	*/

  static wxFontEncoding GetSystemEncoding() const;
	/**
	 * \brief Tries to detect the name of the user's default font encoding. This string isn't
particularly useful for the application as its form is platform-dependent and
so you should probably use 
  instead.

Returns a user-readable string value or an empty string if it couldn't be
determined. 
	*/

  static wxString GetSystemEncodingName() const;
	/**
	 * \brief Tries to detect the user's default language setting.
Returns   value or 
   if the language-guessing algorithm failed. 
	*/

  static int GetSystemLanguage() const;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  bool Init(int  language = wxLANGUAGE_DEFAULT, int  flags = wxLOCALE_LOAD_DEFAULT) ;
	/**
	 * \brief The second form is deprecated, use the first one unless you know what you are
doing. 



















The call of this function has several global side effects which you should
understand: first of all, the application locale is changed - note that this
will affect many of standard C library functions such as printf() or strftime().
Second, this wxLocale object becomes the new current global locale for the
application and so all subsequent calls to wxGetTranslation() will try to
translate the messages using the message catalogs for this locale.

Returns true on success or false if the given locale couldn't be set. 
	 * \param const char   
	 * \param const char   
	 * \param const char   
	 * \param bool   
	 * \param bool   
	*/

  bool Init(const char  *szName , const char  *szShort = NULL, const char  *szLocale = NULL, bool  bLoadDefault = true, bool  bConvertEncoding = false) ;
	/**
	 * \brief Check if the given catalog is loaded, and returns true if it is.

According to GNU gettext tradition, each catalog
normally corresponds to 'domain' which is more or less the application name.

See also: 
	 * \param const char*   
	*/

  bool IsLoaded(const char*  domain ) const;
	/**
	 * \brief Returns true if the locale could be set successfully. 
	*/

  bool IsOk() const;
};


#endif
