// wxTipProvider.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTipProvider_h_)
#define _wxTipProvider_h_
class wxTipProvider
{
public:
	/**
	 * \brief Constructor. 
	 * \param size_t   
	*/

   wxTipProvider(size_t  currentTip ) ;
	/**
	 * \brief Return the text of the current tip and pass to the next one. This function is
pure virtual, it should be implemented in the derived classes. 
	*/

  virtual wxString GetTip()=0;
	/**
	 * \brief Returns a modified tip. This function will be called immediately after read,
and before being check whether it is a comment, an empty string or a string 
to translate. You can optionally override this in your custom user-derived class 
to optionally to modify the tip as soon as it is read. You can return any 
modification to the string. If you return wxEmptyString, then this tip is 
skipped, and the next one is read. 
	 * \param const wxString&  
	*/

  virtual wxString PreprocessTip(const wxString& tip ) ;
	/**
	 * \brief Returns the index of the current tip (i.e. the one which would be returned by 
GetTip).

The program usually remembers the value returned by this function after calling 
 . Note that it is not the same as the value which
was passed to wxShowTip $+ 1$ because the user might have pressed the &quot;Next&quot;
button in the tip dialog. 
	*/

  size_t GetCurrentTip() const;
};


#endif
