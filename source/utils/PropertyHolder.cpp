/*
 * =====================================================================================
 *
 *       Filename:  PropertyHolder.cpp
 *
 *    Description:
 *
 *        Created:  21/09/2018 12:10:00
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "PropertyHolder.hpp"

void PropertyHolder::loadProperties(tinyxml2::XMLElement *propertyElement) {
	while (propertyElement) {
		std::string propertyName = propertyElement->Attribute("name");
		std::string propertyType = propertyElement->Attribute("type");
		std::string propertyValue = propertyElement->Attribute("value");

		Property property;
		if (propertyType == "bool") {
			property = propertyValue == "true";
		}
		else if (propertyType == "int") {
			property = std::stoi(propertyValue);
		}
		else if (propertyType == "float") {
			property = std::stof(propertyValue);
		}
		else if (propertyType == "string") {
			property = propertyValue;
		}

		addProperty(propertyName, property);

		propertyElement = propertyElement->NextSiblingElement("property");
	}
}

