/*
 * =====================================================================================
 *
 *       Filename:  Translator.cpp
 *
 *    Description:
 *
 *        Created:  19/06/2015 00:33:31
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/XMLFile.hpp>

#include "Translator.hpp"

void Translator::setLocale(const std::string &name) {
	dictionary().clear();

	gk::XMLFile doc("resources/locale/" + name + ".xml");

	/* INTERFACE */
	tinyxml2::XMLElement *textElement = doc.FirstChildElement("language").FirstChildElement("text").ToElement();
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

