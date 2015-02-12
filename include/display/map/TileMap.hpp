/*
 * =====================================================================================
 *
 *       Filename:  TileMap.hpp
 *
 *    Description:  
 *
 *        Created:  12/02/2015 22:04:27
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef TILEMAP_HPP_
#define TILEMAP_HPP_

#include "Tileset.hpp"
#include "VertexBuffer.hpp"
#include "View.hpp"

class TileMap {
	public:
		TileMap() = default;
		TileMap(u16 width, u16 height, Tileset &tileset, const std::vector<u16> &data);
		
		void load(u16 width, u16 height, Tileset &tileset, const std::vector<u16> &data);
		
		void draw();
		
		void resetTiles();
		void updateTiles();
		
		u16 getTile(u16 tileX, u16 tileY);
		
		void setTile(u16 tileX, u16 tileY, u16 id);
		
		Tileset &tileset() { return *m_tileset; }
		
		View &view() { return m_view; }
		
		static TileMap &getMap(u16 area, u16 mapX, u16 mapY);
		
	protected:
		u16 m_width = 0;
		u16 m_height = 0;
		
		Tileset *m_tileset;
		
		std::vector<u16> m_baseData;
		std::vector<u16> m_data;
		
		View m_view;
		
		virtual void updateTile(u16 tileX, u16 tileY, u16 id);
		
	private:
		VertexBuffer m_vbo;
};

#endif // TILEMAP_HPP_
