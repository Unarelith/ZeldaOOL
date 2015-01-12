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
		TileMap(const TileMap &) = delete;
		TileMap(TileMap &&tilemap);
		TileMap(Tileset &tileset, u16 width, u16 height);
		
		void load(Tileset &tileset, u16 width, u16 height);
		
		virtual void updateTile(u16 tileX, u16 tileY, u16 id);
		
		void draw();
		
		u16 getTile(u16 tileX, u16 tileY);
		void setTile(u16 tileX, u16 tileY, u16 tile);
		
		Tileset &tileset() { return *m_tileset; }
		
		View &view() { return m_view; }
		
		// TO REMOVE LATER
		virtual s16 *data() = 0;
		
	protected:
		Tileset *m_tileset;
		
		u16 m_width;
		u16 m_height;
		
		View m_view;
		
	private:
		VertexBuffer m_vbo;
};

#endif // TILEMAP_HPP_
