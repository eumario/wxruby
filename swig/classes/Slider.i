#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxSlider
%{
#include <wx/wx.h>
#include <wx/slider.h>
%}

%ignore wxSlider::wxSlider();

%include "include/wxSlider.h"

