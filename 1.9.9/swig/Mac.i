// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license


%module wxMac;

%include "common.i"

%{
//NO_CLASS - This tells fixmodule not to expect a class


#ifdef __WXMAC__

#undef T_DATA

#include <CoreServices/CoreServices.h>
#include <Carbon/Carbon.h>
#include <mach-o/dyld.h>

#import <Cocoa/Cocoa.h>
#import <Carbon/Carbon.h>
#import <unistd.h>

extern "C" {
extern OSErr    CPSGetCurrentProcess (ProcessSerialNumber* iPSN);
extern OSErr    CPSEnableForegroundOperation (ProcessSerialNumber* iPSN, UInt32 iArg2, UInt32 iArg3, UInt32 iArg4, UInt32 iArg5);
extern OSErr    CPSSetFrontProcess (ProcessSerialNumber* iPSN);
}
#if wxMINOR_VERSION == 4
extern "C" short gSharedLibraryResource;
#endif

void macstart()
{

        SInt32 aIterations = 0;
        BOOL aTaskIsInFront = NO;

        ProcessSerialNumber aTaskPSN;
        GetCurrentProcess(&aTaskPSN);

        CPSEnableForegroundOperation (&aTaskPSN, 0x03, 0x3C, 0x2C, 0x1103);
        CPSSetFrontProcess (&aTaskPSN);
        aTaskIsInFront = YES;

#if wxMINOR_VERSION==4
        // Open the shared library resource file if it is not yet open
        NSSymbol    theSymbol;
        NSModule    theModule;
        const char *theLibPath;
        CFBundleRef gSharedLibraryBundle = CFBundleGetBundleWithIdentifier(CFSTR("org.wxwidgets.wxruby.framework"));
        if (gSharedLibraryBundle != NULL) {            
		// wxWindows has been bundled into a framework            
		//   load the framework resources            
		gSharedLibraryResource = CFBundleOpenBundleResourceMap(gSharedLibraryBundle);
        }
#endif
}

#endif

%}

%init %{
#ifdef __WXMAC__
	macstart();
#endif
%}
