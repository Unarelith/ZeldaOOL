/*
 * =====================================================================================
 *
 *       Filename:  XMLFile.cpp
 *
 *    Description:
 *
 *        Created:  15/09/2014 22:38:51
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Exception.hpp"
#include "XMLFile.hpp"

XMLFile::XMLFile(const std::string &filename) {
	load(filename);
}

void XMLFile::load(const std::string &filename) {
	int code = m_xml.LoadFile(filename.c_str());

	if(code != 0) {
		std::string errorString;

		switch(code) {
			case XML_ERROR_FILE_NOT_FOUND:
				errorString = "File not found.";
				break;
			case XML_ERROR_FILE_COULD_NOT_BE_OPENED:
				errorString = "File couldn't be opened.";
				break;
			case XML_ERROR_FILE_READ_ERROR:
				errorString = "File read error.";
				break;
			case XML_ERROR_ELEMENT_MISMATCH:
				errorString = "Element mismatch.";
				break;
			case XML_ERROR_PARSING_ELEMENT:
				errorString = "Error while parsing element.";
				break;
			case XML_ERROR_PARSING_ATTRIBUTE:
				errorString = "Error while parsing attribute.";
				break;
			case XML_ERROR_IDENTIFYING_TAG:
				errorString = "Error while identifying tag.";
				break;
			case XML_ERROR_PARSING_TEXT:
				errorString = "Error while parsing text.";
				break;
			case XML_ERROR_PARSING_CDATA:
				errorString = "Error while parsing cdata.";
				break;
			case XML_ERROR_PARSING_COMMENT:
				errorString = "Error while parsing comment.";
				break;
			case XML_ERROR_PARSING_DECLARATION:
				errorString = "Error while parsing declaration.";
				break;
			case XML_ERROR_PARSING_UNKNOWN:
				errorString = "Parsing error: Unknown object.";
				break;
			case XML_ERROR_EMPTY_DOCUMENT:
				errorString = "Empty document.";
				break;
			case XML_ERROR_MISMATCHED_ELEMENT:
				errorString = "Element mismatched.";
				break;
			case XML_ERROR_PARSING:
				errorString = "Parsing error.";
				break;
			default:
				errorString = "Unknown error.";
				break;
		}

		throw EXCEPTION("Failed to load", filename, "\nError", code, ":", errorString);
	}
}

