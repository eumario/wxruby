// wxMemoryFSHandler.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMemoryFSHandler_h_)
#define _wxMemoryFSHandler_h_
class wxMemoryFSHandler : public wxFileSystemHandler
{
public:
   wxMemoryFSHandler() ;
  static void AddFile(const wxString&  filename , wxImage&  image , long  type ) ;
  static void AddFile(const wxString&  filename , const wxBitmap&  bitmap , long  type ) ;
  static void AddFile(const wxString&  filename , const wxString&  textdata ) ;
  static void AddFile(const wxString&  filename , const void*  binarydata , size_t  size ) ;
  static void RemoveFile(const wxString&  filename ) ;
};


#endif
