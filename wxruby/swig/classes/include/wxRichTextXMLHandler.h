// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxRichTextXMLHandler_h_)
#define _wxRichTextXMLHandler_h_

class wxRichTextXMLHandler : public wxRichTextFileHandler
{
public:
  wxRichTextXMLHandler(const wxString& name = wxT("XML"), 
                       const wxString& ext = wxT("xml"), 
                       int type = wxRICHTEXT_TYPE_XML);

  /// Recursively export an object
  bool ExportXML(wxOutputStream& stream, 
                 wxMBConv* convMem, 
                 wxMBConv* convFile, 
                 wxRichTextObject& obj, 
                 int level);

  bool ExportStyleDefinition(wxOutputStream& stream, 
                             wxMBConv* convMem, 
                             wxMBConv* convFile, 
                             wxRichTextStyleDefinition* def, int level);

  /// Recursively import an object
  bool ImportXML(wxRichTextBuffer* buffer, wxXmlNode* node);
  bool ImportStyleDefinition(wxRichTextStyleSheet* sheet, wxXmlNode* node);

  /// Create style parameters
  wxString CreateStyle(const wxTextAttrEx& attr, bool isPara = false);

  /// Get style parameters
  bool GetStyle(wxTextAttrEx& attr, wxXmlNode* node, bool isPara = false);

  /// Can we save using this handler?
  bool CanSave();
  /// Can we load using this handler?
  bool CanLoad();

  // Implementation
  bool HasParam(wxXmlNode* node, const wxString& param);
  wxXmlNode *GetParamNode(wxXmlNode* node, const wxString& param);
  wxString GetNodeContent(wxXmlNode *node);
  wxString GetParamValue(wxXmlNode *node, const wxString& param);
  wxString GetText(wxXmlNode *node, 
                   const wxString& param = wxEmptyString, 
                   bool translate = false);
  
};

#endif
