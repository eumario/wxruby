// wxDropTarget.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDropTarget_h_)
#define _wxDropTarget_h_
class wxDropTarget
{
public:
	/**
	 * \brief Constructor.   is the data to be associated with the drop target. 
	 * \param wxDataObject*  
	*/

   wxDropTarget(wxDataObject* data = NULL) ;
	/**
	 * \brief Destructor. Deletes the associated data object, if any. 
	*/

  virtual  ~wxDropTarget() ;
	/**
	 * \brief This method may only be called from within  .
By default, this method copies the data from the drop source to the 
  associated with this drop target,
calling its   method. 
	*/

  virtual void GetData() ;
	/**
	 * \brief Called after   returns true. By default this
will usually   and will return the suggested
default value  . 
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxDragResult  
	*/

  virtual wxDragResult OnData(wxCoord  x , wxCoord  y , wxDragResult  def ) ;
	/**
	 * \brief Called when the user drops a data object on the target. Return false to veto the operation. 
	 * \param wxCoord   
	 * \param wxCoord   
	*/

  virtual bool OnDrop(wxCoord  x , wxCoord  y ) ;
	/**
	 * \brief Called when the mouse enters the drop target. By default, this calls  . 
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxDragResult  
	*/

  virtual wxDragResult OnEnter(wxCoord  x , wxCoord  y , wxDragResult  def ) ;
	/**
	 * \brief Called when the mouse is being dragged over the drop target. By default, 
this calls functions return the suggested return value  . 
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxDragResult  
	*/

  virtual wxDragResult OnDragOver(wxCoord  x , wxCoord  y , wxDragResult  def ) ;
	/**
	 * \brief Called when the mouse leaves the drop target. 
	*/

  virtual void OnLeave() ;
	/**
	 * \brief Sets the data   associated with the 
drop target and deletes any previously associated data object. 
	 * \param wxDataObject*  
	*/

  void SetDataObject(wxDataObject*  data ) ;
};


#endif
