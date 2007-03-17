// wxTextValidator.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTextValidator_h_)
#define _wxTextValidator_h_
class wxTextValidator : public wxValidator
{
public:
    wxTextValidator(long style = wxFILTER_NONE, wxString *val = 0);
    wxTextValidator(const wxTextValidator& val);

    ~wxTextValidator();

    // Make a clone of this validator (or return NULL) - currently necessary
    // if you're passing a reference to a validator.
    // Another possibility is to always pass a pointer to a new validator
    // (so the calling code can use a copy constructor of the relevant class).
    virtual wxObject *Clone() const;
    bool Copy(const wxTextValidator& val);

    // Called when the value in the window must be validated.
    // This function can pop up an error message.
    virtual bool Validate(wxWindow *parent);

    // Called to transfer data to the window
    virtual bool TransferToWindow();

    // Called to transfer data to the window
    virtual bool TransferFromWindow();

    // ACCESSORS
    inline long GetStyle() const;
    inline void SetStyle(long style);

    void SetIncludes(const wxArrayString& includes);
    inline wxArrayString& GetIncludes();

    void SetExcludes(const wxArrayString& excludes);
    inline wxArrayString& GetExcludes();

    bool IsInCharIncludes(const wxString& val);
    bool IsNotInCharExcludes(const wxString& val);

    // Filter keystrokes
    void OnChar(wxKeyEvent& event);
};


#endif
