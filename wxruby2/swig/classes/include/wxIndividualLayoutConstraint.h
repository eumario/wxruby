// wxIndividualLayoutConstraint.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxIndividualLayoutConstraint_h_)
#define _wxIndividualLayoutConstraint_h_
class wxIndividualLayoutConstraint : public wxObject
{
public:
	/**
	 * \brief Constructor. Not used by the end-user. 
	*/

   wxIndividualLayoutConstraint() ;
	/**
	 * \brief Constrains this edge to be above the given window, with an
optional margin. Implicitly, this is relative to the top edge of the other window. 
	 * \param wxWindow *  
	 * \param int  
	*/

  void Above(wxWindow * otherWin , int margin = 0) ;
	/**
	 * \brief Constrains this edge or dimension to be the given absolute value. 
	 * \param int  
	*/

  void Absolute(int  value ) ;
	/**
	 * \brief Sets this edge or constraint to be whatever the window's value is
at the moment. If either of the width and height constraints
are  , the window will not be resized, but moved instead.
This is important when considering panel items which are intended
to have a default size, such as a button, which may take its size
from the size of the button label. 
	*/

  void AsIs() ;
	/**
	 * \brief Constrains this edge to be below the given window, with an
optional margin. Implicitly, this is relative to the bottom edge of the other window. 
	 * \param wxWindow *  
	 * \param int  
	*/

  void Below(wxWindow * otherWin , int margin = 0) ;
	/**
	 * \brief Sets this edge or dimension to be unconstrained, that is, dependent on
other edges and dimensions from which this value can be deduced. 
	*/

  void Unconstrained() ;
	/**
	 * \brief Constrains this edge to be to the left of the given window, with an
optional margin. Implicitly, this is relative to the left edge of the other window. 
	 * \param wxWindow *  
	 * \param int  
	*/

  void LeftOf(wxWindow * otherWin , int margin = 0) ;
	/**
	 * \brief Constrains this edge or dimension to be to a percentage of the given window, with an
optional margin. 
	 * \param wxWindow *  
	 * \param wxEdge  
	 * \param int  
	*/

  void PercentOf(wxWindow * otherWin , wxEdge  edge , int  per ) ;
	/**
	 * \brief Constrains this edge to be to the right of the given window, with an
optional margin. Implicitly, this is relative to the right edge of the other window. 
	 * \param wxWindow *  
	 * \param int  
	*/

  void RightOf(wxWindow * otherWin , int margin = 0) ;
	/**
	 * \brief Constrains this edge or dimension to be to the same as the edge of the given window, with an
optional margin. 
	 * \param wxWindow *  
	 * \param wxEdge  
	 * \param int  
	*/

  void SameAs(wxWindow * otherWin , wxEdge  edge , int margin = 0) ;
	/**
	 * \brief Sets the properties of the constraint. Normally called by one of the convenience
functions such as Above, RightOf, SameAs. 
	 * \param wxRelationship  
	 * \param wxWindow *  
	 * \param wxEdge  
	 * \param int  
	 * \param int  
	*/

  void Set(wxRelationship  rel , wxWindow * otherWin , wxEdge  otherEdge , int value = 0, int margin = 0) ;
};


#endif
