// wxAcceleratorTable.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxAcceleratorTable_h_)
#define _wxAcceleratorTable_h_
class wxAcceleratorTable : public wxObject
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxAcceleratorTable() ;
	/**
	 * \brief Copy constructor. 
	 * \param const wxAcceleratorTable&   
	*/

   wxAcceleratorTable(const wxAcceleratorTable&  bitmap ) ;
	/**
	 * \brief Creates from an array of   objects. 
	 * \param int  
	 * \param wxAcceleratorEntry  
	*/

   wxAcceleratorTable(int  n , wxAcceleratorEntry  entries[] ) ;
	/**
	 * \brief Loads the accelerator table from a Windows resource (Windows only).









\pythonnote{The wxPython constructor accepts a list of
wxAcceleratorEntry objects, or 3-tuples consisting of flags, keyCode,
and cmd values like you would construct wxAcceleratorEntry objects with.}

\perlnote{The wxPerl constructor accepts a list of either
  Wx::AcceleratorEntry objects or references to 3-element arrays
  ( flags, keyCode, cmd ), like the parameters of Wx::AcceleratorEntry::new.} 
	 * \param const wxString&  
	*/

   wxAcceleratorTable(const wxString&  resource ) ;
	/**
	 * \brief Destroys the wxAcceleratorTable object. 
	*/

  virtual  ~wxAcceleratorTable() ;
	/**
	 * \brief Returns true if the accelerator table is valid. 
	*/

  bool Ok() const;
};


#endif
