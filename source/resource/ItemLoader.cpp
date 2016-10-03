/*
 * =====================================================================================
 *
 *       Filename:  ItemLoader.cpp
 *
 *    Description:
 *
 *        Created:  16/05/2015 17:08:50
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "InventoryComponent.hpp"
#include "ItemLoader.hpp"
#include "XMLFile.hpp"

void ItemLoader::load(const std::string &xmlFilename, ResourceHandler &handler) {
	XMLFile doc(xmlFilename);

	XMLElement *itemElement = doc.FirstChildElement("items").FirstChildElement().ToElement();
	while(itemElement) {
		std::string name = itemElement->Attribute("name");

		if(std::string(itemElement->Name()) == "weapon") {
			unsigned int strength = 0, level = 0;

			itemElement->QueryUnsignedAttribute("strength", &strength);
			itemElement->QueryUnsignedAttribute("level", &level);

			handler.add<Weapon>("weapon-" + name, name, level);
		}

		itemElement = itemElement->NextSiblingElement();
	}
}

