

%module wxMac;

%{

#ifdef __WXMAC__

#undef T_DATA

#import <Cocoa/Cocoa.h>
#import <Carbon/Carbon.h>
#import <unistd.h>

extern "C" {
extern OSErr    CPSGetCurrentProcess (ProcessSerialNumber* iPSN);
extern OSErr    CPSEnableForegroundOperation (ProcessSerialNumber* iPSN, UInt32 iArg2, UInt32 iArg3, UInt32 iArg4, UInt32 iArg5);
extern OSErr    CPSSetFrontProcess (ProcessSerialNumber* iPSN);
}

void macstart()
{

        SInt32 aIterations = 0;
        BOOL aTaskIsInFront = NO;

        ProcessSerialNumber aTaskPSN;
        GetCurrentProcess(&aTaskPSN);

        CPSEnableForegroundOperation (&aTaskPSN, 0x03, 0x3C, 0x2C, 0x1103);
        CPSSetFrontProcess (&aTaskPSN);
        aTaskIsInFront = YES;

}

#endif

%}

%init %{
#ifdef __WXMAC__
	macstart();
#endif
%}
