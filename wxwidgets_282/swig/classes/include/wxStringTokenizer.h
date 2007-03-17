// wxStringTokenizer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxStringTokenizer_h_)
#define _wxStringTokenizer_h_
class wxStringTokenizer : public wxObject
{
public:
	/**
	 * \brief Default constructor. You must call 
  before calling any other
methods. 
	*/

   wxStringTokenizer() ;
	/**
	 * \brief Constructor. Pass the string to tokenize, a string containing delimiters
and the mode specifying how the string should be tokenized. 
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param wxStringTokenizerMode   
	*/

   wxStringTokenizer(const wxString&  str , const wxString&  delims = wxT(""), wxStringTokenizerMode  mode = wxTOKEN_DEFAULT) ;
	/**
	 * \brief Returns the number of tokens in the input string. 
	*/

  int CountTokens() const;
	/**
	 * \brief Returns true if the tokenizer has further tokens, false if none are left. 
	*/

  bool HasMoreTokens() const;
	/**
	 * \brief Returns the next token or empty string if the end of string was reached. 
	*/

  wxString GetNextToken() ;
	/**
	 * \brief Returns the current position (i.e. one index after the last returned
token or 0 if GetNextToken() has never been called) in the original
string. 
	*/

  size_t GetPosition() const;
	/**
	 * \brief Returns the part of the starting string without all token already extracted. 
	*/

  wxString GetString() const;
	/**
	 * \brief Initializes the tokenizer.

Pass the string to tokenize, a string containing delimiters,
and the mode specifying how the string should be tokenized. 
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param wxStringTokenizerMode   
	*/

  void SetString(const wxString&  to_tokenize , const wxString&  delims = wxT(""), wxStringTokenizerMode  mode = wxTOKEN_DEFAULT) ;
};


#endif
