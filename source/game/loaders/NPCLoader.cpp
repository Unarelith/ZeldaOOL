/*
 * =====================================================================================
 *
 *       Filename:  NPCLoader.cpp
 *
 *    Description:
 *
 *        Created:  22/06/2015 13:11:22
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "NPCFactory.hpp"
#include "NPCLoader.hpp"

void NPCLoader::load(XMLElement *npcElement, Scene &scene) {
	u16 tileX = npcElement->IntAttribute("tileX");
	u16 tileY = npcElement->IntAttribute("tileY");

	scene.addObject(NPCFactory::create(tileX, tileY));
}

