/*
 * =====================================================================================
 *
 *       Filename:  Map.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/09/2014 15:28:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef MAP_HPP_
#define MAP_HPP_

#include "OpenGL.hpp"
#include "Texture.hpp"

class Map {
	public:
		Map();
		Map(std::string filename, Texture &texture, u16 width, u16 height);
		~Map();
		
		void load(std::string filename, Texture &texture, u16 width, u16 height);
		
		void updateTile(u16 id, float x, float y);
		void render();
		
	private:
		Texture *m_texture;
		
		GLuint m_vbo;
		
		u16 m_width;
		u16 m_height;
		
		u16 *m_data;
};

#endif // MAP_HPP_
