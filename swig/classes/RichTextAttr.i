// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxRichTextAttr;
GC_MANAGE(wxRichTextAttr);

%{
#include <wx/richtext/richtextbuffer.h>
%}

// Extra formatting flags not in wxTextAttr
#define wxTEXT_ATTR_PARA_SPACING_AFTER      0x00000800
#define wxTEXT_ATTR_PARA_SPACING_BEFORE     0x00001000
#define wxTEXT_ATTR_LINE_SPACING            0x00002000
#define wxTEXT_ATTR_CHARACTER_STYLE_NAME    0x00004000
#define wxTEXT_ATTR_PARAGRAPH_STYLE_NAME    0x00008000
#define wxTEXT_ATTR_LIST_STYLE_NAME         0x00010000
#define wxTEXT_ATTR_BULLET_STYLE            0x00020000
#define wxTEXT_ATTR_BULLET_NUMBER           0x00040000
#define wxTEXT_ATTR_BULLET_TEXT             0x00080000
#define wxTEXT_ATTR_BULLET_NAME             0x00100000
#define wxTEXT_ATTR_URL                     0x00200000
#define wxTEXT_ATTR_PAGE_BREAK              0x00400000
#define wxTEXT_ATTR_EFFECTS                 0x00800000
#define wxTEXT_ATTR_OUTLINE_LEVEL           0x01000000

#define wxTEXT_ATTR_BULLET_STYLE_NONE               0x00000000
#define wxTEXT_ATTR_BULLET_STYLE_ARABIC             0x00000001
#define wxTEXT_ATTR_BULLET_STYLE_LETTERS_UPPER      0x00000002
#define wxTEXT_ATTR_BULLET_STYLE_LETTERS_LOWER      0x00000004
#define wxTEXT_ATTR_BULLET_STYLE_ROMAN_UPPER        0x00000008
#define wxTEXT_ATTR_BULLET_STYLE_ROMAN_LOWER        0x00000010
#define wxTEXT_ATTR_BULLET_STYLE_SYMBOL             0x00000020
#define wxTEXT_ATTR_BULLET_STYLE_BITMAP             0x00000040
#define wxTEXT_ATTR_BULLET_STYLE_PARENTHESES        0x00000080
#define wxTEXT_ATTR_BULLET_STYLE_PERIOD             0x00000100
#define wxTEXT_ATTR_BULLET_STYLE_STANDARD           0x00000200
#define wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS  0x00000400
#define wxTEXT_ATTR_BULLET_STYLE_OUTLINE            0x00000800
#define wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT         0x00000000
#define wxTEXT_ATTR_BULLET_STYLE_ALIGN_RIGHT        0x00001000
#define wxTEXT_ATTR_BULLET_STYLE_ALIGN_CENTRE       0x00002000

// Line spacing
#define wxTEXT_ATTR_LINE_SPACING_NORMAL         10
#define wxTEXT_ATTR_LINE_SPACING_HALF           15
#define wxTEXT_ATTR_LINE_SPACING_TWICE          20

// Extra text effects
#define wxTEXT_ATTR_EFFECT_NONE                     0x00000000
#define wxTEXT_ATTR_EFFECT_CAPITALS                 0x00000001
#define wxTEXT_ATTR_EFFECT_SMALL_CAPITALS           0x00000002
#define wxTEXT_ATTR_EFFECT_STRIKETHROUGH            0x00000004
#define wxTEXT_ATTR_EFFECT_DOUBLE_STRIKETHROUGH     0x00000008
#define wxTEXT_ATTR_EFFECT_SHADOW                   0x00000010
#define wxTEXT_ATTR_EFFECT_EMBOSS                   0x00000020
#define wxTEXT_ATTR_EFFECT_OUTLINE                  0x00000040
#define wxTEXT_ATTR_EFFECT_ENGRAVE                  0x00000080
#define wxTEXT_ATTR_EFFECT_SUPERSCRIPT              0x00000100
#define wxTEXT_ATTR_EFFECT_SUBSCRIPT                0x00000200

// TextAttrEx not used in wxRuby
%ignore wxRichTextAttr(const wxTextAttrEx& attr);

%include "include/wxRichTextAttr.h"
