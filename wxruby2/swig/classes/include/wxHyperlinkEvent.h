// Copyright 2007 by Kevin Smith
// released under the MIT-style wxruby2 license

#if !defined(_wxHyperlinkEvent_h_)

#define _wxHyperlinkEvent_h_

class wxHyperlinkEvent : public wxCommandEvent
{
public:
    wxHyperlinkEvent();
    wxHyperlinkEvent(wxWindow* parent, wxWindowID id, const wxString& url);
  
	// Returns the URL associated with the hyperlink control
	// that the user clicked on.
	wxString GetURL() const;
	void SetURL(const wxString &url);

	// default copy ctor, assignment operator and dtor are ok
	virtual wxEvent* Clone() const;

};

#endif
