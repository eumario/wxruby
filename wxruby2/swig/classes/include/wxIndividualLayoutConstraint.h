// wxIndividualLayoutConstraint.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxIndividualLayoutConstraint_h_)
#define _wxIndividualLayoutConstraint_h_
class wxIndividualLayoutConstraint : public wxObject
{
public:
   wxIndividualLayoutConstraint() ;
  void Above(wxWindow * otherWin , int margin = 0) ;
  void Absolute(int  value ) ;
  void AsIs() ;
  void Below(wxWindow * otherWin , int margin = 0) ;
  void Unconstrained() ;
  void LeftOf(wxWindow * otherWin , int margin = 0) ;
  void PercentOf(wxWindow * otherWin , wxEdge  edge , int  per ) ;
  void RightOf(wxWindow * otherWin , int margin = 0) ;
  void SameAs(wxWindow * otherWin , wxEdge  edge , int margin = 0) ;
  void Set(wxRelationship  rel , wxWindow * otherWin , wxEdge  otherEdge , int value = 0, int margin = 0) ;
};


#endif
