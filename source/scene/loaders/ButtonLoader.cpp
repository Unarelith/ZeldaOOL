/*
 * =====================================================================================
 *
 *       Filename:  ButtonLoader.cpp
 *
 *    Description:  
 *
 *        Created:  22/02/2015 17:15:04
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ButtonComponent.hpp"
#include "ButtonFactory.hpp"
#include "ButtonLoader.hpp"

void ButtonLoader::load(XMLElement *buttonElement, Scene &scene) {
	Vector2u16 tile = {(u16)buttonElement->IntAttribute("tileX"),
	                   (u16)buttonElement->IntAttribute("tileY")};
	
	SceneObject &button = scene.addObject(ButtonFactory::create(tile));
	auto &buttonComponent = button.get<ButtonComponent>();
	
	XMLElement *tileChangeElement = buttonElement->FirstChildElement("tileChange");
	while(tileChangeElement) {
		Vector2u16 tile = {(u16)tileChangeElement->IntAttribute("tileX"),
		                   (u16)tileChangeElement->IntAttribute("tileY")};
		u16 newID = tileChangeElement->IntAttribute("newID");
		
		buttonComponent.addTileChange(tile, newID);
		
		tileChangeElement = tileChangeElement->NextSiblingElement("tileChange");
	}
}

