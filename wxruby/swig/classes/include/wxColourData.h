// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxColourData_h_)
#define _wxColourData_h_
class wxColourData : public wxObject
{
public:
	    wxColourData();
	    wxColourData(const wxColourData& data);
	    ~wxColourData();

	    void SetChooseFull(bool flag);
	    bool GetChooseFull() const;
	    void SetColour(const wxColour& colour);
	    const wxColour& GetColour() const;
	    wxColour& GetColour();

	    // Array of 16 custom colours
	    void SetCustomColour(int i, const wxColour& colour);
	    wxColour GetCustomColour(int i);

	    void operator=(const wxColourData& data);

	public:
	    wxColour        m_dataColour;
	    wxColour        m_custColours[16];
	    bool            m_chooseFull;
};


#endif
