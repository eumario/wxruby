// wxFlexGridSizer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFlexGridSizer_h_)
#define _wxFlexGridSizer_h_
class wxFlexGridSizer : public wxGridSizer
{
public:
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param int   
	*/

   wxFlexGridSizer(int  rows , int  cols , int  vgap , int  hgap ) ;
	/**
	 * \brief Constructor for a wxGridSizer.   and   determine the number of
columns and rows in the sizer - if either of the parameters is zero, it will be
calculated to form the total number of children in the sizer, thus making the
sizer grow dynamically.   and   define extra space between
all children. 
	 * \param int   
	 * \param int   
	 * \param int   
	*/

   wxFlexGridSizer(int  cols , int  vgap = 0, int  hgap = 0) ;
	/**
	 * \brief Specifies that column   (starting from zero) should be grown if
there is extra space available to the sizer.

The   parameter has the same meaning as the stretch factor for
the   except that if all proportions are 0,
then all columns are resized equally (instead of not being resized at all). 
	 * \param size_t   
	 * \param int   
	*/

  void AddGrowableCol(size_t  idx);
	/**
	 * \brief Specifies that row idx (starting from zero) should be grown if there
is extra space available to the sizer.

See   for the description
of   parameter. 
	 * \param size_t   
	 * \param int   
	*/

  void AddGrowableRow(size_t  idx);
	/**
	 * \brief Returns a wxOrientation value that specifies whether the sizer flexibly
resizes its columns, rows, or both (default). 
	*/

  int GetFlexibleDirection() const;
	/**
	 * \brief  
	*/

  int GetNonFlexibleGrowMode() const;
	/**
	 * \brief Specifies that column idx is no longer growable. 
	 * \param size_t   
	*/

  void RemoveGrowableCol(size_t  idx ) ;
	/**
	 * \brief Specifies that row idx is no longer growable. 
	 * \param size_t   
	*/

  void RemoveGrowableRow(size_t  idx ) ;
	/**
	 * \brief Specifies whether the sizer should flexibly resize its columns, rows, or
both. Argument   can be  ,   
or   (which is the default value). Any other value is ignored. See
  for the
explanation of these values.

Note that this method does not trigger relayout. 
	 * \param int   
	*/

  void SetFlexibleDirection(int  direction ) ;
	/**
	 * \brief Specifies how the sizer should grow in the non flexible direction if
there is one (so
  must have
been called previously). Argument   can be one of those documented in
 , please
see there for their explanation.

Note that this method does not trigger relayout. 
	 * \param int   
	*/

  void SetNonFlexibleGrowMode(int  mode ) ;
};


#endif
