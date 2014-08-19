/*
 * =====================================================================================
 *
 *       Filename:  Tileset.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/08/2014 20:06:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef TILESET_HPP_
#define TILESET_HPP_

#include <SFML/Graphics.hpp>

#include "Types.hpp"

struct Tileset {
	Tileset() {}
	
	Tileset(std::string filename, u16 *_info) {
		info = _info;
		
		texture.loadFromFile(filename);
	};
	
	sf::Texture texture;
	
	u16 *info;
};

#endif // TILESET_HPP_
