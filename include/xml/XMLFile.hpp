/*
 * =====================================================================================
 *
 *       Filename:  XMLFile.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:38:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef XMLFILE_HPP_
#define XMLFILE_HPP_

#include <string>

#include "tinyxml2.hpp"

using namespace tinyxml2;

class XMLFile {
	public:
		XMLFile(std::string filename);
		~XMLFile();
		
		XMLHandle FirstChildElement(const char *element) { return m_doc->FirstChildElement(element); }
		
	private:
		XMLDocument m_xml;
		XMLHandle *m_doc;
};

#endif // XMLFILE_HPP_
