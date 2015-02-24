/*
 * =====================================================================================
 *
 *       Filename:  ChestLoader.cpp
 *
 *    Description:  
 *
 *        Created:  24/02/2015 01:51:19
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ChestFactory.hpp"
#include "ChestLoader.hpp"

void ChestLoader::load(XMLElement *buttonElement, Scene &scene) {
	u16 tileX = buttonElement->IntAttribute("tileX");
	u16 tileY = buttonElement->IntAttribute("tileY");
	
	scene.addObject(ChestFactory::create(tileX, tileY));
}

