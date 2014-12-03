/*
 * =====================================================================================
 *
 *       Filename:  Tileset.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/12/2014 20:09:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef TILESET_HPP_
#define TILESET_HPP_

#include <string>

#include <SFML/Graphics/Texture.hpp>

#include "Types.hpp"

struct Tileset {
	Tileset() {}
	
	Tileset(std::string filename) {
		load(filename);
	};
	
	void load(std::string filename) {
		texture.loadFromFile(filename);
	}
	
	sf::Texture texture;
};

#endif // TILESET_HPP_
