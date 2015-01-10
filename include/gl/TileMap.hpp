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
#include "Tileset.hpp"
#include "VertexBuffer.hpp"
#include "View.hpp"

class TileMap {
	public:
		TileMap();
		TileMap(Tileset &tileset, u16 width, u16 height, s16 *data);
		virtual ~TileMap();
		
		void load(Tileset &tileset, u16 width, u16 height, s16 *data);
		
		virtual void updateTile(u16 tileX, u16 tileY, u16 id);
		
		void draw();
		
		u16 getTile(u16 tileX, u16 tileY);
		void setTile(u16 tileX, u16 tileY, u16 tile);
		
		Tileset &tileset() { return *m_tileset; }
		
		View &view() { return m_view; }
		
	protected:
		Tileset *m_tileset;
		
		u16 m_width;
		u16 m_height;
		
		View m_view;
		
	private:
		VertexBuffer m_vbo;
		
		s16 *m_data;
};

#endif // TILEMAP_HPP_
