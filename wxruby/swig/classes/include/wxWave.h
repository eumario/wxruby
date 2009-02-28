// wxWave.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxWave_h_)
#define _wxWave_h_
class wxWave : public wxObject
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxWave() ;
	/**
	 * \brief Constructs a wave object from a file or resource. Call   to
determine whether this succeeded. 
	 * \param const wxString&  
	 * \param bool  
	*/

   wxWave(const wxString&  fileName , bool isResource = false) ;
	/**
	 * \brief Destroys the wxWave object. 
	*/

  virtual  ~wxWave() ;
	/**
	 * \brief Constructs a wave object from a file or resource. 
	 * \param const wxString&  
	 * \param bool  
	*/

  bool Create(const wxString&  fileName , bool isResource = false) ;
	/**
	 * \brief Returns true if the object contains a successfully loaded file or resource, false otherwise. 
	*/

  bool IsOk() const;
	/**
	 * \brief Plays the wave file synchronously or asynchronously, looped or single-shot. 
	 * \param bool  
	 * \param bool  
	*/

  bool Play(bool async = true, bool looped = false) const;
};


#endif
