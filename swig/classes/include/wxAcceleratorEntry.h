// wxAcceleratorEntry.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxAcceleratorEntry_h_)
#define _wxAcceleratorEntry_h_
class wxAcceleratorEntry
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxAcceleratorEntry() ;
	/**
	 * \brief Constructor. 
	 * \param int  
	 * \param int  
	 * \param int  
	*/

   wxAcceleratorEntry(int  flags , int  keyCode , int  cmd ) ;
	/**
	 * \brief Returns the command identifier for the accelerator table entry. 
	*/

  int GetCommand() const;
	/**
	 * \brief Returns the flags for the accelerator table entry. 
	*/

  int GetFlags() const;
	/**
	 * \brief Returns the keycode for the accelerator table entry. 
	*/

  int GetKeyCode() const;
	/**
	 * \brief Sets the accelerator entry parameters. 
	 * \param int  
	 * \param int  
	 * \param int  
	*/

  void Set(int  flags , int  keyCode , int  cmd ) ;
};


#endif
