// wxNode.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxNode_h_)
#define _wxNode_h_
class wxNode
{
public:
  T * GetData() const;
  wxNode<T> * GetNext() const;
  wxNode<T> * GetPrevious() ;
  void SetData(T * data ) ;
  int IndexOf() ;
};


#endif
