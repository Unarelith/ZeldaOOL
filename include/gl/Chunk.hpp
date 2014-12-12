/*
 * =====================================================================================
 *
 *       Filename:  Chunk.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/12/2014 02:00:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef CHUNK_HPP_
#define CHUNK_HPP_

#include <SFML/Graphics/Texture.hpp>

#include "Map.hpp"

class Chunk {
	public:
		Chunk(u16 area, u16 x, u16 y);
		~Chunk();
		
		void update();
		
		short getTileFace(int i, short tile);
		
		void draw();
		void drawCube(float x, float y, float z, short tile);
		
		sf::Texture &texture() { return m_texture; }
		
	private:
		sf::Texture &m_texture;
		
		Map &m_map;
};

#endif // CHUNK_HPP_
