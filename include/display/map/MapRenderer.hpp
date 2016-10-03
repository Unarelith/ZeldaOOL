/*
 * =====================================================================================
 *
 *       Filename:  MapRenderer.hpp
 *
 *    Description:
 *
 *        Created:  30/04/2015 19:47:12
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
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
