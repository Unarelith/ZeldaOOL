/*
 * =====================================================================================
 *
 *       Filename:  ChestLoader.cpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 01:16:24
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ChestFactory.hpp"
#include "ChestLoader.hpp"

void ChestLoader::load(XMLElement *chestElement, SceneObjectList &objectList) {
	u16 tileX = chestElement->IntAttribute("tileX");
	u16 tileY = chestElement->IntAttribute("tileY");

	objectList.addObject(ChestFactory::create(tileX, tileY));
}

