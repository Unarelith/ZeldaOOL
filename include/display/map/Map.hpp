/*
 * =====================================================================================
 *
 *       Filename:  Map.hpp
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
#ifndef MAP_HPP_
#define MAP_HPP_

#include "AnimatedTile.hpp"
#include "Tileset.hpp"
#include "VertexBuffer.hpp"
#include "View.hpp"

class Map {
	public:
		Map() = default;
		Map(u16 area, u16 x, u16 y, u16 width, u16 height, Tileset &tileset, const std::vector<u16> &data);
		
		void load(u16 area, u16 x, u16 y, u16 width, u16 height, Tileset &tileset, const std::vector<u16> &data);
		
		void draw();
		
		void resetTiles();
		void updateTiles();
		void animateTiles();
		
		u16 getTile(u16 tileX, u16 tileY);
		void setTile(u16 tileX, u16 tileY, u16 id);
		
		u16 area() const { return m_area; }
		u16 x() const { return m_x; }
		u16 y() const { return m_y; }
		
		Tileset &tileset() { return *m_tileset; }
		
		View &view() { return m_view; }
		
		static Map &getMap(u16 area, u16 mapX, u16 mapY);
		Map &getSideMap(s8 dx, s8 dy) { return getMap(m_area, m_x + dx, m_y + dy); }
		
	private:
		virtual void updateTile(u16 tileX, u16 tileY, u16 id);
		
		u16 m_area = 0;
		u16 m_x = 0;
		u16 m_y = 0;
		
		u16 m_zoneID = 0;
		
		u16 m_width = 0;
		u16 m_height = 0;
		
		Tileset *m_tileset;
		
		std::vector<u16> m_baseData;
		std::vector<u16> m_data;
		
		View m_view;
		
		VertexBuffer m_vbo;
		
		std::vector<AnimatedTile> m_animatedTiles;
};

#endif // TILEMAP_HPP_
