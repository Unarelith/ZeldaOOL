/*
 * =====================================================================================
 *
 *       Filename:  TileMap.hpp
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
#ifndef TILEMAP_HPP_
#define TILEMAP_HPP_

#include "OpenGL.hpp"
#include "Shader.hpp"
#include "Texture.hpp"

#include "Application.hpp"

class TileMap {
	public:
		TileMap();
		TileMap(Texture &texture, u16 width, u16 height, s16 *data);
		~TileMap();
		
		void load(Texture &texture, u16 width, u16 height, s16 *data);
		
		void updateTile(float x, float y, u16 id);
		
		void draw();
		
		void setPosition(float x, float y) { m_x = x; m_y = y; }
		void move(float dx, float dy) { m_x += dx; m_y += dy; }
		
	protected:
		Texture *m_texture;
		
		u16 m_width;
		u16 m_height;
		
		Shader m_shader;
		
	private:
		GLuint m_vbo;
		
		s16 *m_data;
		
		float m_x;
		float m_y;
};

#endif // TILEMAP_HPP_
