/*
 * =====================================================================================
 *
 *       Filename:  ChestLoader.cpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 01:16:24
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "ChestFactory.hpp"
#include "ChestLoader.hpp"

void ChestLoader::load(tinyxml2::XMLElement *chestElement, gk::Scene &scene) {
	u16 tileX = chestElement->IntAttribute("tileX");
	u16 tileY = chestElement->IntAttribute("tileY");

	scene.addObject(ChestFactory::create(tileX, tileY));
}

