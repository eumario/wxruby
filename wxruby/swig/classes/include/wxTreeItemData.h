// wxTreeItemData.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTreeItemData_h_)
#define _wxTreeItemData_h_
class wxTreeItemData : public wxClientData
{
public:
	/**
	 * \brief Default constructor.

\pythonnote{The wxPython version of this constructor optionally
accepts any Python object as a parameter.  This object is then
associated with the tree item using the wxTreeItemData as a
container.

In addition, the following methods are added in wxPython for accessing
the object:

\indented{2cm}{ }
}

\perlnote{In wxPerl the constructor accepts as parameter an optional scalar,
 and stores it as client data. You may retrieve this data by calling
  , and set it by calling  
} 
	*/

   wxTreeItemData() ;
	/**
	 * \brief Virtual destructor. 
	*/

  virtual  ~wxTreeItemData() ;
	/**
	 * \brief Returns the item associated with this node. 
	*/

  const wxTreeItem& GetId() ;
	/**
	 * \brief Sets the item associated with this node. 
	 * \param const wxTreeItemId&  
	*/

  void SetId(const wxTreeItemId&  id ) ;
};


#endif
