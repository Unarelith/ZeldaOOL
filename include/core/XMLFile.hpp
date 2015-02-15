/*
 * =====================================================================================
 *
 *       Filename:  XMLFile.hpp
 *
 *    Description:  
 *
 *        Created:  09/02/2015 01:57:33
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
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
		XMLFile() = default;
		XMLFile(const std::string &filename);
		
		void load(const std::string &filename);
		
		XMLHandle FirstChildElement(const char *element) { return m_doc.FirstChildElement(element); }
		
	private:
		XMLDocument m_xml;
		XMLHandle m_doc{m_xml};
};

#endif // XMLFILE_HPP_
