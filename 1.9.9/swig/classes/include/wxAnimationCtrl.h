// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxAnimationCtrl_h_)
#define _wxAnimationCtrl_h_


class wxAnimationCtrl : public wxControl
{
public:
  wxAnimationCtrl();
  wxAnimationCtrl(wxWindow *parent, 
                  wxWindowID id, 
                  const wxAnimation& anim, 
                  const wxPoint& pos = wxDefaultPosition, 
                  const wxSize& size = wxDefaultSize, 
                  long style = wxAC_DEFAULT_STYLE, 
                  const wxString& name = wxT("animationctrl"));
  bool Create(wxWindow *parent, 
              wxWindowID id, 
              const wxAnimation& anim, 
              const wxPoint& pos = wxDefaultPosition, 
              const wxSize& size = wxDefaultSize, 
              long style = wxAC_DEFAULT_STYLE, 
              const wxString& name = wxT("animationctrl"));
  wxAnimation GetAnimation() const;
  wxBitmap GetInactiveBitmap() const;
  bool IsPlaying() const;
  bool LoadFile(const wxString& filename,
                wxAnimationType type = wxANIMATION_TYPE_ANY);
  bool Play();
  void SetAnimation(const wxAnimation &anim);
  void Stop();
  void SetInactiveBitmap(const wxBitmap &bmp);

};

#endif
