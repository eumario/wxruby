// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxAnimation_h_)
#define _wxAnimation_h_


class wxAnimation : public wxGDIObject
{
public:
  wxAnimation();
  wxAnimation(const wxAnimation& anim);
  wxAnimation(const wxString& name, 
              wxAnimationType type = wxANIMATION_TYPE_ANY);

  int GetDelay(unsigned int frame) const;
  
  unsigned int GetFrameCount() const;
  wxImage GetFrame(unsigned int frame) const;
  wxSize GetSize() const;

  bool IsOk() const;
  
  bool LoadFile(const wxString& name,
                wxAnimationType type = wxANIMATION_TYPE_ANY);
  bool Load(wxInputStream& stream,
            wxAnimationType type = wxANIMATION_TYPE_ANY);
};

#endif
