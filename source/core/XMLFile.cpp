/*
 * =====================================================================================
 *
 *       Filename:  XMLFile.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:38:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Exception.hpp"
#include "XMLFile.hpp"

XMLFile::XMLFile(std::string filename) {
	int code;
	
	code = m_xml.LoadFile(filename.c_str());
	if(code != 0) {
		throw EXCEPTION("Failed to load %s.", filename.c_str());
		
		switch(code) {
			case XML_ERROR_FILE_NOT_FOUND:
				throw EXCEPTION("File not found.");
				break;
			case XML_ERROR_FILE_COULD_NOT_BE_OPENED:
				throw EXCEPTION("File couldn't be opened.");
				break;
			case XML_ERROR_FILE_READ_ERROR:
				throw EXCEPTION("File read throw EXCEPTION.");
				break;
			case XML_ERROR_ELEMENT_MISMATCH:
				throw EXCEPTION("Element mismatch.");
				break;
			case XML_ERROR_PARSING_ELEMENT:
				throw EXCEPTION("Error while parsing element.");
				break;
			case XML_ERROR_PARSING_ATTRIBUTE:
				throw EXCEPTION("Error while parsing attribute.");
				break;
			case XML_ERROR_IDENTIFYING_TAG:
				throw EXCEPTION("Error while identifying tag.");
				break;
			case XML_ERROR_PARSING_TEXT:
				throw EXCEPTION("Error while parsing text.");
				break;
			case XML_ERROR_PARSING_CDATA:
				throw EXCEPTION("Error while parsing cdata.");
				break;
			case XML_ERROR_PARSING_COMMENT:
				throw EXCEPTION("Error while parsing comment.");
				break;
			case XML_ERROR_PARSING_DECLARATION:
				throw EXCEPTION("Error while parsing declaration.");
				break;
			case XML_ERROR_PARSING_UNKNOWN:
				throw EXCEPTION("Parsing throw EXCEPTION: Unknown object.");
				break;
			case XML_ERROR_EMPTY_DOCUMENT:
				throw EXCEPTION("Empty document.");
				break;
			case XML_ERROR_MISMATCHED_ELEMENT:
				throw EXCEPTION("Element mismatched.");
				break;
			case XML_ERROR_PARSING:
				throw EXCEPTION("Parsing throw EXCEPTION.");
				break;
			default:
				throw EXCEPTION("Unknown throw EXCEPTION. CODE:", code);
				break;
		}
		
		exit(EXIT_FAILURE);
	}
	
	m_doc = new XMLHandle(&m_xml);
}

XMLFile::~XMLFile() {
	delete m_doc;
}

