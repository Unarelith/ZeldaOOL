/*
 * =====================================================================================
 *
 *       Filename:  ResourceHandler.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/12/2014 17:30:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "ResourceHandler.hpp"

// Template specializations for ResourceHandler::add
#include "ResourceHandler.inl"

ResourceHandler::ResourceHandler() {
	add<sf::Texture>("link", "graphics/characters/link.png");
	
	add<sf::Texture>("font", "graphics/interface/font.png");
	add<sf::Texture>("hearts", "graphics/interface/hearts.png");
	add<sf::Texture>("numbers", "graphics/interface/numbers.png");
	add<sf::Texture>("stats", "graphics/interface/stats.png");
	
	add<Tileset>("indoor", "graphics/tilesets/indoor.png");
	add<Tileset>("plain", "graphics/tilesets/plain.png");
	add<Tileset>("underground", "graphics/tilesets/underground.png");
}

ResourceHandler::~ResourceHandler() {
}

