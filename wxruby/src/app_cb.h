/**********************************************************************

  app_cb.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

#ifndef WXRUBY_APP_CB_H
#define WXRUBY_APP_CB_H

class wxAppWithCallbacks : public wxApp {
public:
    virtual bool OnInit();
    int MainLoop();
    int OnExit();
    void OnIdle(wxIdleEvent& event);

    DECLARE_EVENT_TABLE()
};



#endif

