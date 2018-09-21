/*
 * =====================================================================================
 *
 *       Filename:  NPCLoader.cpp
 *
 *    Description:
 *
 *        Created:  22/06/2015 13:11:22
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "NPCFactory.hpp"
#include "NPCLoader.hpp"

void NPCLoader::load(XMLElement *npcElement, SceneObjectList &objectList) {
	u16 tileX = npcElement->IntAttribute("tileX");
	u16 tileY = npcElement->IntAttribute("tileY");

	objectList.addObject(NPCFactory::create(tileX, tileY));
}

