// wxNode.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxNode_h_)
#define _wxNode_h_
class wxNode
{
public:
	/**
	 * \brief Retrieves the client data pointer associated with the node. 
	*/

  T * GetData() const;
	/**
	 * \brief Retrieves the next node or NULL if this node is the last one. 
	*/

  wxNode<T> * GetNext() const;
	/**
	 * \brief Retrieves the previous node or NULL if this node is the first one in the list. 
	*/

  wxNode<T> * GetPrevious() ;
	/**
	 * \brief Sets the data associated with the node (usually the pointer will have been
set when the node was created). 
	 * \param T *  
	*/

  void SetData(T * data ) ;
	/**
	 * \brief Returns the zero-based index of this node within the list. The return value
will be NOT_FOUND if the node has not been added to a list yet. 
	*/

  int IndexOf() ;
};


#endif
