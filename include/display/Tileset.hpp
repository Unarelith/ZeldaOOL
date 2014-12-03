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

#include "TileAnimation.hpp"

class Tileset {
	public:
		Tileset();
		Tileset(std::string name);
		
		void load(std::string name);
		
		void addAnimation(std::initializer_list<u16> frames, u16 delay);
		
		sf::Texture &texture() { return m_texture; }
		std::vector<TileAnimation> &anims() { return m_anims; }
		
	private:
		sf::Texture m_texture;
		
		std::vector<TileAnimation> m_anims;
};

#endif // TILESET_HPP_
