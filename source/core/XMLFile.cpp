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
#include "XMLFile.hpp"

XMLFile::XMLFile(std::string filename) {
	int code;
	
	code = m_xml.LoadFile(filename.c_str());
	if(code != 0) {
		throw std::string("Failed to load ") + filename;
		
		switch(code) {
			case XML_ERROR_FILE_NOT_FOUND:
				throw std::string("File not found.");
				break;
			case XML_ERROR_FILE_COULD_NOT_BE_OPENED:
				throw std::string("File couldn't be opened.");
				break;
			case XML_ERROR_FILE_READ_ERROR:
				throw std::string("File read throw std::string.");
				break;
			case XML_ERROR_ELEMENT_MISMATCH:
				throw std::string("Element mismatch.");
				break;
			case XML_ERROR_PARSING_ELEMENT:
				throw std::string("Error while parsing element.");
				break;
			case XML_ERROR_PARSING_ATTRIBUTE:
				throw std::string("Error while parsing attribute.");
				break;
			case XML_ERROR_IDENTIFYING_TAG:
				throw std::string("Error while identifying tag.");
				break;
			case XML_ERROR_PARSING_TEXT:
				throw std::string("Error while parsing text.");
				break;
			case XML_ERROR_PARSING_CDATA:
				throw std::string("Error while parsing cdata.");
				break;
			case XML_ERROR_PARSING_COMMENT:
				throw std::string("Error while parsing comment.");
				break;
			case XML_ERROR_PARSING_DECLARATION:
				throw std::string("Error while parsing declaration.");
				break;
			case XML_ERROR_PARSING_UNKNOWN:
				throw std::string("Parsing throw std::string: Unknown object.");
				break;
			case XML_ERROR_EMPTY_DOCUMENT:
				throw std::string("Empty document.");
				break;
			case XML_ERROR_MISMATCHED_ELEMENT:
				throw std::string("Element mismatched.");
				break;
			case XML_ERROR_PARSING:
				throw std::string("Parsing throw std::string.");
				break;
			default:
				throw std::string("Unknown throw std::string. (CODE: ") + std::to_string(code) + ")";
				break;
		}
	}
	
	m_doc = new XMLHandle(&m_xml);
}

XMLFile::~XMLFile() {
	delete m_doc;
}

