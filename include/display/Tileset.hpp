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

#include "TileAnimation.hpp"

struct Tileset {
	Tileset() {}
	
	Tileset(std::string filename, u16 *_info) {
		info = _info;
		
		texture.loadFromFile(filename);
	};
	
	void addAnimation(std::initializer_list<u16> frames, u16 delay) {
		anims.push_back(TileAnimation(delay));
		
		for(auto &it : frames) {
			anims.back().frames.push_back(it);
		}
	}
	
	sf::Texture texture;
	
	u16 *info;
	
	std::vector<TileAnimation> anims;
};

#endif // TILESET_HPP_
