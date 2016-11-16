/*
 * =====================================================================================
 *
 *       Filename:  Translator.cpp
 *
 *    Description:  
 *
 *        Created:  19/06/2015 00:33:31
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Translator.hpp"
#include "XMLFile.hpp"

void Translator::setLocale(const std::string &name) {
	dictionary().clear();
	
	XMLFile doc("data/locale/" + name + ".xml");
	
	/* INTERFACE */
	XMLElement *textElement = doc.FirstChildElement("language").FirstChildElement("text").ToElement();
	while(textElement) {
		std::string id = textElement->Attribute("id");
		std::string text = textElement->Attribute("text");
		
		dictionary().emplace(id, text);
		
		textElement = textElement->NextSiblingElement("text");
	}
}

std::string Translator::translate(const std::string &str) {
	if(dictionary().find(str) != dictionary().end()) {
		return dictionary().at(str);
	} else {
		return str;
	}
}

std::string _t(const std::string &str) {
	return Translator::translate(str);
}

