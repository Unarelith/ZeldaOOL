/*
 * =====================================================================================
 *
 *       Filename:  MapRenderer.hpp
 *
 *    Description:  
 *
 *        Created:  13/02/2015 02:06:53
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef MAPRENDERER_HPP_
#define MAPRENDERER_HPP_

#include "Tileset.hpp"
#include "VertexBuffer.hpp"

class Map;

class MapRenderer {
	public:
		void init(u16 mapWidth, u16 mapHeight);
		
		void updateTile(u16 tileX, u16 tileY, u16 id, Map &map);
		
		void draw(Map &map);
		
	private:
		VertexBuffer m_vbo;
};

#endif // MAPRENDERER_HPP_