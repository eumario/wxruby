// wxValidator.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxValidator_h_)
#define _wxValidator_h_
class wxValidator : public wxEvtHandler
{
public:
    wxValidator();
    virtual ~wxValidator();

    // Make a clone of this validator (or return NULL) - currently necessary
    // if you're passing a reference to a validator.
    // Another possibility is to always pass a pointer to a new validator
    // (so the calling code can use a copy constructor of the relevant class).
    virtual wxObject *Clone() const;
    bool Copy(const wxValidator& val);

    // Called when the value in the window must be validated.
    // This function can pop up an error message.
    virtual bool Validate(wxWindow *parent);

    // Called to transfer data to the window
    virtual bool TransferToWindow();

    // Called to transfer data from the window
    virtual bool TransferFromWindow();

    // accessors
    wxWindow *GetWindow() const;
    void SetWindow(wxWindowBase *win);

    // validators beep by default if invalid key is pressed, these functions
    // allow to change it
    static bool IsSilent();
    static void SetBellOnError(bool doIt = true);
};


#endif
