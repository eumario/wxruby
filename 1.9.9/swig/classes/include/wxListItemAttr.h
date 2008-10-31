class wxListItemAttr : public wxObject
{
public:
	wxListItemAttr();
	wxListItemAttr(wxColour &, wxColour &, wxFont &);
	wxColour GetBackgroundColour();
	wxFont GetFont();
	wxColour GetTextColour();
	bool HasBackgroundColour();
	bool HasFont();
	bool HasTextColour();
	void SetBackgroundColour(wxColour &c);
	void SetFont(wxFont &);
	void SetTextColour(wxColour &);
};
