// wxFSFile.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFSFile_h_)
#define _wxFSFile_h_
class wxFSFile : public wxObject
{
public:
	/**
	 * \brief Constructor. You probably won't use it. See Notes for details.











If you are not sure of the meaning of these params, see the description of the GetXXXX()
functions. 
	 * \param wxInputStream   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param const wxString&   
	*/

   wxFSFile(wxInputStream  *stream , const wxString&  loc , const wxString&  mimetype , const wxString&  anchor ) ;
	/**
	 * \brief Returns anchor (if present). The term of   can be easily
explained using few examples:

 

Usually an anchor is presented only if the MIME type is 'text/html'.
But it may have some meaning with other files;
for example myanim.avi\#200 may refer to position in animation
or reality.wrl\#MyView may refer to a predefined view in VRML. 
	*/

  const wxString& GetAnchor() const;
	/**
	 * \brief Returns full location of the file, including path and protocol. 
Examples : 
	*/

  const wxString& GetLocation() const;
	/**
	 * \brief Returns the MIME type of the content of this file. It is either
extension-based (see wxMimeTypesManager) or extracted from
HTTP protocol Content-Type header. 
	*/

  const wxString& GetMimeType() const;
	/**
	 * \brief Returns time when this file was modified. 
	*/

  wxDateTime GetModificationTime() const;
	/**
	 * \brief Returns pointer to the stream. You can use the returned
stream to directly access data. You may suppose
that the stream provide Seek and GetSize functionality
(even in the case of the HTTP protocol which doesn't provide
this by default. wxHtml uses local cache to work around
this and to speed up the connection). 
	*/

  wxInputStream* GetStream() const;
};


#endif
